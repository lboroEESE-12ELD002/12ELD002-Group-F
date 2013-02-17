// *************************************************************************************************
// The original stopwatch program has been altered to act as the 'counts remaining' specification, which is 
//why the counts remaining functions are still referred to as 'stopwatch' 

//Fortitude Under Pressure - Luke Ellis, Chizi Ebubeogu
// *************************************************************************************************

// Include section

// system
#include "project.h"
#include <string.h>

// driver
#include "stopwatch.h"
#include "ports.h"
#include "display.h"
#include "timer.h"
// logic
#include "menu.h"

#include "acceleration.h"
#include "vti_as.h"
#include "clock.h"
#include "buzzer.h"
#include "alarm.h"

// *************************************************************************************************
// Prototypes section
void start_stopwatch(void);
void stop_stopwatch(void);
void reset_stopwatch(void);
void stopwatch_tick(void);
void update_stopwatch_timer(void);
void mx_stopwatch(u8 line);
void sx_stopwatch(u8 line);

void display_stopwatch(u8 line, u8 update);

// *************************************************************************************************
// Defines section
int c = 0;
// *************************************************************************************************
// Global Variable section
struct stopwatch sStopwatch;
struct stopwatch s;

// *************************************************************************************************
// update counts remaining 
// *************************************************************************************************
void update_stopwatch_timer(void)
{
	u16 value;
	
	// Load CCR register with next capture time
	if (sStopwatch.viewStyle == DISPLAY_DEFAULT_VIEW) 
	{
		//If accelerometer is in the threshold, speed up the timer
		if (sAccel.xyz[0] < 0x64 && s.counter < 5)
		{
			//(5 times as fast)
			value = TA0CCR2 + STOPWATCH_FAST;
			
			if (sStopwatch.swtIs1Hz) 
			{
				value -= 5;
				sStopwatch.swtIs1Hz = 0;	
				sStopwatch.swtIs10Hz = 0;	
			}
			else if (sStopwatch.swtIs10Hz) 
			{
				value -= 3;
				sStopwatch.swtIs10Hz = 0;	
			} 	
					
			// Update CCR
			TA0CCR2 = value;
			
		}
		//If accelerometer is in the threshold for between 5 and 10 seconds, speed up the timer further
		else if(sAccel.xyz[0] < 0x64 && s.counter < 10 && s.counter >= 5)
		{
			value = TA0CCR2 + STOPWATCH_FASTEST;
			
			if (sStopwatch.swtIs1Hz) 
			{
				value -= 5;
				sStopwatch.swtIs1Hz = 0;	
				sStopwatch.swtIs10Hz = 0;	
			}
			else if (sStopwatch.swtIs10Hz) 
			{
				value -= 3;
				sStopwatch.swtIs10Hz = 0;	
			} 	
					
			// Update CCR
			TA0CCR2 = value;
		}
		//If accelerometer has been in the highest threshold for 5 seconds, counts remaining will drop to 00:00:00 
		else if(sAccel.xyz[0] < 0x64 && s.counter == 10)
		{
			stop_stopwatch();
			sStopwatch.time[2] = '0';
			sStopwatch.time[3] = '0';
			sStopwatch.time[4] = '0';
			sStopwatch.time[5] = '0';
			sStopwatch.time[6] = '0';
			sStopwatch.time[7] = '0';
			
			//pause time elapsed
			s.count = 0;
			s.counter = 0;
		}
			
		else 
		{
			//Timer runs at 1Hz
			value = TA0CCR2 + STOPWATCH_100HZ_TICK;
			
			if (sStopwatch.swtIs1Hz) 
			{
				value -= 5;
				sStopwatch.swtIs1Hz = 0;	
				sStopwatch.swtIs10Hz = 0;	
			}
			else if (sStopwatch.swtIs10Hz) 
			{
				value -= 3;
				sStopwatch.swtIs10Hz = 0;	
			}
			 			
			// Update CCR
			TA0CCR2 = value;
			
			//reset acceleration state
			s.counter = 0;	
		} 
}
}
// *************************************************************************************************
// *************************************************************************************************
// @fn          stopwatch_tick
// @brief       Called by 1/100Hz interrupt handler. 
//				Counts remaining timing routine will count down from 10:00:00
// @param       none
// @return      none
// *************************************************************************************************
void stopwatch_tick(void)
{
	static u8 delay = 0;
					
	// Default view (< 20 minutes): display and count MM:SS:hh
	if (sStopwatch.viewStyle == DISPLAY_DEFAULT_VIEW)
	{	
		
		// Subtract 1/100 sec 
		sStopwatch.time[7]--;
				
		if (delay++ > 17) 
		{
			sStopwatch.drawFlag = 8;
			delay = 0;
		}
	
		// Subtract 1/10 sec 
		if (sStopwatch.time[7] == 0x2F)
		{
			sStopwatch.time[7]= '9';
			sStopwatch.time[6]--; 
																			
			// 1/10Hz trigger 
			sStopwatch.swtIs10Hz = 1;
			
			// Update draw flag
			sStopwatch.drawFlag = 7;
		}
		
		// Second overflow?
		if (sStopwatch.time[6] == 0x2F)
		{
			// Reset draw flag
			sStopwatch.drawFlag = 1;
	
			// 1Hz trigger 
			sStopwatch.swtIs1Hz = 1;
			
			// Add data
			sStopwatch.time[6]= '9';
			sStopwatch.time[5]--;							// second  L (0 - 9)
			//Sound audible based on up button press
			if(s.a == 1)
			{
			//sound a 'beep' upon every second counted down
			start_buzzer(1, BUZZER_ON_TICKS, BUZZER_OFF_TICKS);
			}
			//Initialise acceleration sensor
			if (!is_acceleration_measurement()) 
			{
				// Clear previous acceleration value
				sAccel.data = 0;
				
				// Start sensor
				as_start();
				
				// Set timeout counter
				sAccel.timeout = ACCEL_MEASUREMENT_TIMEOUT;
				
				// Set mode
				sAccel.mode = ACCEL_MODE_ON;
				
				// Start with Y-axis values
				sAccel.view_style = DISPLAY_ACCEL_Y;
			}		
			//Is the accelerometer in the correct threshold?													
			if (sAccel.xyz[0] < 0x64)
			{
				update_stopwatch_timer();
			}
											
			if (sStopwatch.time[5] == 0x2F) 
			{
				sStopwatch.drawFlag++;						// 2
				sStopwatch.time[5] = '9';
				sStopwatch.time[4]--;						// second  H (0 - 5)
				if (sStopwatch.time[4] == 0x2F) 
				{
					sStopwatch.drawFlag ++;					// 3
					sStopwatch.time[4] = '5';
					sStopwatch.time[3]--;					// minutes L (0 - 9)
				
															
					if (sStopwatch.time[3] == 0x2F) 
					{
						sStopwatch.drawFlag++;				// 4
						sStopwatch.time[3] = '9';
						sStopwatch.time[2]--;				// minutes H (0 - 5)
						
						if (sStopwatch.time[2] == 0x2F) 
						{
							sStopwatch.drawFlag++;			// 5
							sStopwatch.time[2] = '0';
							sStopwatch.time[3] = '0';
							sStopwatch.time[4] = '0';
							sStopwatch.time[5] = '0';
							sStopwatch.time[6] = '0';
							sStopwatch.time[7] = '0';
							
							//pause time elapsed
							s.count = 0;
							
							//sound continuous tone when counts remaining drops to 0seconds
							sBuzzer.state = BUZZER_MODE_SINGLE_CONTINUOUS;
							
							//clear heart icon blink symbol
							display_symbol(LCD_ICON_HEART, SEG_ON_BLINK_OFF);
							
							//clear heart icon blink symbol
							display_symbol(LCD_ICON_HEART, SEG_OFF);
								
						}
					}
			}
		}
			
	}
}		
	
	// Always set display update flag
	display.flag.update_stopwatch = 1;
}
		
// *************************************************************************************************
// @fn          reset_stopwatch
// @brief       Clears counts remaining  counter and sets counts remaining  state to off.
// @param       none
// @return      none
// *************************************************************************************************
void reset_stopwatch(void)
{
	// Clear counter
	memcpy(sStopwatch.time, "00100000", sizeof(sStopwatch.time));

	// Clear trigger
	sStopwatch.swtIs10Hz 	= 0;		// 1/10Hz trigger
	sStopwatch.swtIs1Hz  	= 0;		// 1Hz trigger
	
	// Init stopwatch state 'Off'
	sStopwatch.state 	  	= STOPWATCH_STOP;	
	
	reset_clock();
	
	s.a = 0;
	
	s.count = 0;	
	
	sStopwatch.viewStyle 	= DISPLAY_DEFAULT_VIEW;
}

// *************************************************************************************************
// @fn          is_stopwatch
// @brief       Is counts remaining  operating and visible?
// @param       none
// @return      1=STOPWATCH_RUN, 0=other states
// *************************************************************************************************
u8 is_stopwatch(void)
{
	return ((sStopwatch.state == STOPWATCH_RUN) && (ptrMenu_L2 == &menu_L2_Stopwatch));
}

// *************************************************************************************************
// @fn          sx_stopwatch
// @brief       Stopwatch direct function. 
// @param       u8 line	LINE2
// @return      none
// *************************************************************************************************
void sx_stopwatch(u8 line)
{	
	//SW1 activates counts remaining and time elapsed upon the first button press ONLY	
	if(button.flag.down)
	{
		s.count = s.count + 1;
		
			if (s.count == 1)
			{
				// (Re)start stopwatch
				start_stopwatch();
			}	
								
	}
	
}

// *************************************************************************************************
// @fn          start_stopwatch
// @brief       Starts counts remaining timer interrupt and sets stopwatch state to on.
// @param       none
// @return      none
// *************************************************************************************************
void start_stopwatch(void)
{		
	if (s.count > 0)
	{	
		// Set stopwatch run flag
		sStopwatch.state = STOPWATCH_RUN;	
		
		// Init CCR register with current time
		TA0CCR2 = TA0R;
			
		// Load CCR register with next capture time
		update_stopwatch_timer();
		
		// Reset IRQ flag    
		TA0CCTL2 &= ~CCIFG; 
		          
		// Enable timer interrupt    
		TA0CCTL2 |= CCIE; 
				
		//set heart icon blink symbol
		display_symbol(LCD_ICON_HEART, SEG_ON_BLINK_ON);

	}

}

// *************************************************************************************************
// @fn          stop_stopwatch
// @brief       Stops counts remaining timer interrupt and sets counts remaining state to off.
//				Does not reset stopwatch count.
// @param       none
// @return      none
// *************************************************************************************************
void stop_stopwatch(void)
{
	// Clear timer interrupt enable   
	TA0CCTL2 &= ~CCIE; 
	
	// Clear stopwatch run flag
	sStopwatch.state = STOPWATCH_STOP;	
		
	//clear heart icon blink symbol
	display_symbol(LCD_ICON_HEART, SEG_ON_BLINK_OFF);
	
	//clear heart icon blink symbol
	display_symbol(LCD_ICON_HEART, SEG_OFF);
	
	// Call draw routine immediately
	display_stopwatch(LINE2, DISPLAY_LINE_UPDATE_FULL);
		
}

// *************************************************************************************************
// @fn          mx_stopwatch
// @brief       Counts remaining set routine. Mx stops counts remaining and resets count.
// @param       u8 line	LINE2
// @return      none
// *************************************************************************************************
void mx_stopwatch(u8 line)
{
	// Stop stopwatch
	stop_stopwatch();
	
	s.count = 0;
			
	// Reset stopwatch count
	reset_stopwatch();	
	
	reset_clock();
	
	// Display "00:00:00"
	display_stopwatch(line, DISPLAY_LINE_UPDATE_FULL);
}

// *************************************************************************************************
// @fn          display_stopwatch
// @brief       Counts remaining display routine.
// @param       u8 line	LINE2
//				u8 update	DISPLAY_LINE_UPDATE_PARTIAL, DISPLAY_LINE_UPDATE_FULL
// @return      none
// *************************************************************************************************
void display_stopwatch(u8 line, u8 update)
{
	// Partial line update only
	if (update == DISPLAY_LINE_UPDATE_PARTIAL && sAccel.xyz[0] < 0x64)
	{	
		if (display.flag.update_stopwatch)
		{
			if (sStopwatch.viewStyle == DISPLAY_DEFAULT_VIEW)
			{
				// Check draw flag to minimize workload
				if(sStopwatch.drawFlag != 0) 
				{
					switch(sStopwatch.drawFlag) 
					{
						//Display counts remaining 
						case 2: display_char(LCD_SEG_L2_3, sStopwatch.time[2], SEG_ON);
						case 1: display_char(LCD_SEG_L2_2, sStopwatch.time[3], SEG_ON);
						case 7: display_char(LCD_SEG_L2_1, sStopwatch.time[4], SEG_ON);
						case 8:	display_char(LCD_SEG_L2_0, sStopwatch.time[5], SEG_ON);
					}
				}
				
			}
		}
	}
	// Redraw whole line
	else if (update == DISPLAY_LINE_UPDATE_FULL)	
	{
		if (sStopwatch.viewStyle == DISPLAY_DEFAULT_VIEW)
		{
			//Display counts remaining 
			display_char(LCD_SEG_L2_3, sStopwatch.time[2], SEG_ON);
			display_char(LCD_SEG_L2_2, sStopwatch.time[3], SEG_ON);
			display_char(LCD_SEG_L2_1, sStopwatch.time[4], SEG_ON);
			display_char(LCD_SEG_L2_0, sStopwatch.time[5], SEG_ON);
		}
		display_symbol(LCD_SEG_L2_COL0, SEG_ON);
	}
}
