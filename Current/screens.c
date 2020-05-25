#include <stdint.h>
#include "..//tm4c123gh6pm.h"
#include "Timer.h"
#include "LED.h"
#include "Switches.h"
#include "Game.h"

void TitleScreen(void);
void PauseMenu(void);
void GameOver(void);





///////////////////////////////// Title Screen /////////////////////////////

void TitleScreen(void){
	
	Countdown = 1;

	score = 0;
	
  Nokia5110_ClearBuffer();
		
	Nokia5110_PrintBMP(16, 22, Birdy, 0);
	Nokia5110_PrintBMP(48, 22, Flap, 0);
  Nokia5110_PrintBMP(27, 40, Start, 0);
		
  Nokia5110_DisplayBuffer();   // draw buffer
	
	

	// PORTF_DATA = 0;
	while(SW2 != 0){seed++;
		Rainbow();
//		PORTF_DATA = 0;
//		PORTF_DATA = (s << 1);
//		 s = (bit2(~s) >> 2) | (((bit2(~s) >> 1) & bit1(s) | (bit2(s) >> 1) & (bit0(~s) << 1))) | ((bit2(s) & (bit1(~s) << 1) | bit2(~s) & (bit0(s) << 2))); //flash all combinations
//		Delay100ms(3); // 3 red, yellow, green, cyan, blue, pink, white, off
	};					 // displays until SW2 is pressed		
}

///////////////////////// PAUSE MENU ///////////////////////////////

void PauseMenu(void){
  Nokia5110_ClearBuffer();
		
	Nokia5110_PrintBMP(23, 16, Paused, 0);  // 18
	Nokia5110_PrintBMP(17, 28, Continue, 0);			
	
  Nokia5110_PrintBMP(10, 44, No, 0);				// 10, 47
	Nokia5110_PrintBMP(52, 44, Yes, 0);			// 52, 47
		
  Nokia5110_DisplayBuffer();   // draw buffer

		if(SW1 == 0)
		{
			Delay100ms(0.01); // 0.1 
			if(SW1 == 0){
				main();
			}
		}

	while((SW1!= 0) && (SW2 != 0)){
	// yellow
	Yellow_on();
//	GPIO_PORTF_DATA_R |= 0x02; // turn on red led
//	GPIO_PORTF_DATA_R &= ~0x04; // turn off  blue led
//	GPIO_PORTF_DATA_R |= 0x08; // turn on green led
	}
}

///////////////////////// GAME OVER SCREEN //////////////////////////

void GameOver(void){
	Player.life = 0;
	
	Nokia5110_ClearBuffer();
	Nokia5110_PrintBMP(14, 17, Game_Over, 0);		// y = 21
	Nokia5110_DisplayBuffer();   // draw buffer
	
	Nokia5110_SetCursor(8, 3);
	Nokia5110_OutUDec(score);
	Nokia5110_SetCursor(1, 3);
  Nokia5110_OutString("Score:");
	
	if(best < 10)
				{
				Nokia5110_SetCursor(8, 5);
				Nokia5110_OutUDec(best);
				Nokia5110_SetCursor(0, 0); // renders screen
				}
				if((best < 100) && (best >= 10) )
				
				{
				Nokia5110_SetCursor(8, 5);
				Nokia5110_OutUDec(best);
				Nokia5110_SetCursor(0, 0); // renders screen
				}

	Nokia5110_SetCursor(1, 5);
  Nokia5110_OutString("Best:"); 

  Nokia5110_SetCursor(0, 0); // renders screen

	if ((SW2 == 0) && (SW1 != 0)) 
	{
		Delay100ms(0.1);
		Red_off();
		// GPIO_PORTF_DATA_R &= ~0x02; // turn off red led
		score=0;
		main();
	}

	while(SW2 !=0){
		Red_on();
		// GPIO_PORTF_DATA_R |= 0x02; // Turn on red LED
		}
	
}
