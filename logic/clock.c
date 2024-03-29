// *************************************************************************************************
// The original clock program has been altered to act as the 'time elapsed' specification, which is 
//why the functions are still referred to as 'clock' functions

//Fortitude Under Pressure - Luke Ellis, Chizi Ebubeogu 
// *************************************************************************************************

// Include section

// system
#include "project.h"

// driver
#include "ports.h"
#include "display.h"
#include "timer.h"

// logic
#include "menu.h"
#include "clock.h"
#include "user.h"
#include "bluerobin.h"
#include "date.h"
#include "stopwatch.h"
#include "rfsimpliciti.h"
#include "simpliciti.h"
#include "rfbsl.h"
#include "radio.h"
#include "acceleration.h"
#include "buzzer.h"
#include "alarm.h"

// *************************************************************************************************
// Prototypes section
void reset_clock(void);
void clock_tick(void);
void mx_time(u8 line);
void sx_time(u8 line);

void calc_24H_to_12H(u8 * hours, u8 * timeAM);
void conv_24H_to_12H(u8 * hours24, u8 * hours12, u8 * timeAMorPM);
//Wireless xyz mode
void start_simpliciti_tx_only(simpliciti_mode_t mode);

// *************************************************************************************************
// Global Variable section
struct time sTime;

// Display values for time format selection
const u8 selection_Timeformat[][4] =
{
	"24H", "12H"
};


// *************************************************************************************************
// Extern section
extern void (*fptr_lcd_function_line1)(u8 line, u8 update);
extern void (*fptr_lcd_function_line2)(u8 line, u8 update);

// *************************************************************************************************
// @fn          reset_clock
// @brief       Resets time elapsed to 00:00:00
// @param       none
// @return      none
// *************************************************************************************************
void reset_clock(void) 
{
	// Set global system time to 0
	sTime.system_time = 0;
	
	//reset timing variables
	s.count = 0;
	s.a = 0;
	s.counter = 0;
	
	// Set main 24H time to start value
	sTime.hour   = 0; 
	sTime.minute = 10; 
	sTime.second = 0;

	// Display style of both lines is default (HH:MM)
	sTime.line1ViewStyle = DISPLAY_DEFAULT_VIEW;
	
	// Reset timeout detection
	sTime.last_activity 		  = 0;
}


// *************************************************************************************************
// @fn          clock_tick
// @brief       Time elapsed clock routine will count down from 10:00:00
// *************************************************************************************************
void clock_tick(void) 
{	
	if (s.count > 0)
	{
			sTime.drawFlag = 2;
			
			if (sTime.minute + sTime.second != 0)
			{
		
			// Subtract 1 second
			sTime.second--;
			
			// Add 1 minute
			if (sTime.second > 60) // if seconds are not between 0 and 60 when 1 sec is subtracted
			{
				sTime.second = 59;
				sTime.minute--;							
			}
			//If the accelerometer threshold is reached, increment counter
			else if (sAccel.xyz[0] < 0x64)
			{
				s.counter++;
			}
						
			}
			else if (sTime.minute == 0 && sTime.second == 0)
			{
				//Sound continuous tone when time elapsed reaches 00:00:00
				sBuzzer.state = BUZZER_MODE_SINGLE_CONTINUOUS;
			}	
	}
	
}

// *************************************************************************************************
// @fn          convert_hour_to_12H_format
// @brief       Convert internal 24H time to 12H time.
// @param       u8 hour		Hour in 24H format
// @return      u8				Hour in 12H format
// *************************************************************************************************
u8 convert_hour_to_12H_format(u8 hour)
{
	// 00:00 .. 11:59 --> AM 12:00 .. 11:59
	if (hour == 0)			return (hour + 12);
	else if (hour <= 12)	return (hour);	
	// 13:00 .. 23:59 --> PM 01:00 .. 11:59
	else  					return (hour - 12);
}

// *************************************************************************************************
// @fn          is_hour_am
// @brief       Checks if internal 24H time is AM or PM
// @param       u8 hour		Hour in 24H format
// @return      u8				1 = AM, 0 = PM
// *************************************************************************************************
u8 is_hour_am(u8 hour)
{
	// 00:00 .. 11:59 --> AM 12:00 .. 11:59
	if (hour < 12)	return (1);
	// 12:00 .. 23:59 --> PM 12:00 .. 11:59
	else  			return (0);
}

// *************************************************************************************************
// @fn          display_selection_Timeformat
// @brief       Display time format 12H / 24H. 
// @param       u8 segments			Target segments where to display information
//				u32 index			0 or 1, index for value string
//				u8 digits			Not used
//				u8 blanks			Not used
// @return      none
// *************************************************************************************************
void display_selection_Timeformat1(u8 segments, u32 index, u8 digits, u8 blanks)
{
	if (index < 2) display_chars(segments, (u8 *)selection_Timeformat[index], SEG_ON_BLINK_ON);
}


// *************************************************************************************************
// @fn          mx_time
// @brief       Clock set routine.
// @param       u8 line		LINE1, LINE2
// @return      none
// *************************************************************************************************
void mx_time(u8 line)
{
	u8 select;
	s32 timeformat;
	s16 timeformat1;
	s32 hours;
	s32 minutes;
	s32 seconds;
	u8 * str;
	
	// Clear display
	clear_display_all();
		
	// Convert global time to local variables
	// Global time keeps on ticking in background until it is overwritten
	if (sys.flag.use_metric_units)
	{
		timeformat 	= TIMEFORMAT_24H;
	}
	else
	{
		timeformat 	= TIMEFORMAT_12H;
	}
	timeformat1	= timeformat;
	hours 		= sTime.hour; 
	minutes 	= sTime.minute;
	seconds 	= sTime.second;
	
	// Init value index
	select = 0;	
		
	// Loop values until all are set or user breaks	set
	while(1) 
	{
		// Idle timeout: exit without saving 
		if (sys.flag.idle_timeout)
		{
			// Roll back time format
			if (timeformat1 == TIMEFORMAT_24H) 	sys.flag.use_metric_units = 1;
			else								sys.flag.use_metric_units = 0;
			display_symbol(LCD_SYMB_AM, SEG_OFF);
			break;
		}
		
		switch (select)
		{
			case 0:		// Clear LINE1 and LINE2 and AM icon - required when coming back from set_value(seconds)
						clear_display();
						display_symbol(LCD_SYMB_AM, SEG_OFF);
						
						// Set 24H / 12H time format
						set_value(&timeformat, 1, 0, 0, 1, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_SELECTION + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_1, display_selection_Timeformat1);
						
						// Modify global time format variable immediately to update AM/PM icon correctly
						if (timeformat == TIMEFORMAT_24H) 	sys.flag.use_metric_units = 1;
						else								sys.flag.use_metric_units = 0;
						select = 1;
						break;
			
			case 1:		str = itoa(minutes, 2, 0);
						display_chars(LCD_SEG_L1_3_2, str, SEG_ON);

						str = itoa(seconds, 2, 0);
						display_chars(LCD_SEG_L1_1_0, str, SEG_ON);
						display_symbol(LCD_SEG_L1_COL, SEG_ON);
									
						break;
			
			case 2:		// Set minutes
						set_value(&minutes, 2, 0, 0, 59, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_2, display_value1);
						select = 3;
						
						break;
			
			case 3:		// Set seconds
						set_value(&seconds, 2, 0, 0, 59, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_1_0, display_value1);
						select = 0;
						break;
		}
	}
	
	// Clear button flags
	button.all_flags = 0;
}

// *************************************************************************************************
// @fn          sx_time
// @brief       Time elapsed user routine.
// @param       line		LINE1
// @return      none
// *************************************************************************************************
void sx_time(u8 line)
{	
		if(button.flag.up)
		{
			s.a = s.a + 1;
			
			if (s.a == 1)
			{
				//Send xyz data via Rf access point
				//start_simpliciti_tx_only(SIMPLICITI_ACCELERATION);
							
			}
			else if(s.a == 2)
			{
				s.a=0;
				//reset_rf();
				
				//sRFsmpl.mode = SIMPLICITI_OFF;
			}
		}
		else
		{
		}
}

// *************************************************************************************************
// @fn          display_time
// @brief       Time elapsed display routine. Supports 24H and 12H time format. 
// @param       u8 line			LINE1
//				u8 update		DISPLAY_LINE_UPDATE_FULL, DISPLAY_LINE_UPDATE_PARTIAL
// @return      none
// *************************************************************************************************
void display_time(u8 line, u8 update)
{
	u8 hour12;
	
	// Partial update
 	if (update == DISPLAY_LINE_UPDATE_PARTIAL) 
	{
		if(sTime.drawFlag != 0) 
		{
			if (sTime.line1ViewStyle == DISPLAY_DEFAULT_VIEW)
			{
				switch(sTime.drawFlag) 
				{
					case 3: if (sys.flag.use_metric_units)
							{
							}
							else
							{
								hour12 = convert_hour_to_12H_format(sTime.hour);
							}
							
					case 2: display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L1_3_2), itoa(sTime.minute, 2, 0), SEG_ON);
							display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L1_1_0), itoa(sTime.second, 2, 0), SEG_ON); 
				}
			}
			else
			{
				// Seconds are always updated
				display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L1_3_2), itoa(sTime.minute, 2, 0), SEG_ON);
				display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L1_1_0), itoa(sTime.second, 2, 0), SEG_ON);
			}
		}	
	}
	else if (update == DISPLAY_LINE_UPDATE_FULL)			
	{
		// Full update
		if (sTime.line1ViewStyle == DISPLAY_DEFAULT_VIEW)
		{	
			// Display 24H/12H time
			if (sys.flag.use_metric_units)
			{
			}
			else
			{
				// Display 12H time "HH" + AM/PM information
				hour12 = convert_hour_to_12H_format(sTime.hour);
				//display_chars(switch_seg(line, LCD_SEG_L2_3_2, LCD_SEG_L2_3_2), itoa(hour12, 2, 0), SEG_ON); 
				// Display AM/PM information
				if (line == LINE1)
				{
				}
			}
							
			// Display minute new add second
			display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L1_3_2), itoa(sTime.minute, 2, 0), SEG_ON); 
			display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L1_1_0), itoa(sTime.second, 2, 0), SEG_ON);
			display_symbol(switch_seg(line, LCD_SEG_L1_COL, LCD_SEG_L1_COL), SEG_ON);
		}
		else
		{
			// Display seconds new add minute
			display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L1_3_2), itoa(sTime.minute, 2, 0), SEG_ON); 
			display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L1_1_0), itoa(sTime.second, 2, 0), SEG_ON);
			display_symbol(switch_seg(line, LCD_SEG_L1_COL, LCD_SEG_L1_COL), SEG_ON);
		}
	}
	else if (update == DISPLAY_LINE_CLEAR)
	{
		display_symbol(switch_seg(line, LCD_SEG_L1_COL, LCD_SEG_L1_COL), SEG_OFF_BLINK_OFF);
		// Change display style to default (HH:MM)
		sTime.line1ViewStyle = DISPLAY_DEFAULT_VIEW;
		// Clean up AM/PM icon
		display_symbol(LCD_SYMB_AM, SEG_OFF);
	}
	
}

		
