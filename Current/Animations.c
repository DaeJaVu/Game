#include "Switches.h"
#include <stdint.h>
#include <stdbool.h>
#include "Game.h"
#include "Sprites.h"
#include "LED.h"
#include "Timer.h"
#include "..//tm4c123gh6pm.h"
#include "screens.h"



void Move(void);

void Draw(void);

void Score_Init(void);

/////////////////////////////// DRAW //////////////////////////////////////

void Draw(void){
		Nokia5110_ClearBuffer();
		// while(Countdown != 1){}
    if(Player.life > 0){			
				Nokia5110_PrintBMP(X_MIN, Y_MAX, Ground, 0);
				if(Pipe.x  ==  70) {
						while(Countdown != 0){} // needed, important
						Pipe.var = ((Random()>>24)%15)+1;  // returns random num in range 1 to 15
						// Pipe.var = 5;
						
						if((Pipe.var == 1) || (Pipe.var == 2)){
								d = (2*Pipe.var) + 16;
						}
						else if(Pipe.var == 15){
								d = 22;
						}
						else {
								d = 21;
						}
						
						switch(Pipe.var){
										
				    case 1:  
								Pipe.top = Pipe0;
								Pipe.yTop = 0;
								Pipe.bottom = Pipe29b;
								// d = 18;
								break;
						
						case 2: 
								Pipe.top = Pipe0;
								Pipe.yTop = 0;
								Pipe.bottom = Pipe27b;
								// d = 20;
								break;
						
						case 3: 
								Pipe.top = Pipe2;
								Pipe.yTop = 1;
								Pipe.bottom = Pipe25b;
								// d = 21;
								break;
						
						case 4: 
								Pipe.top = Pipe4;
								Pipe.yTop = 3;
								Pipe.bottom = Pipe23b;
								// d = 21;
								break;
						
						case 5: 
								Pipe.top = Pipe6;
								Pipe.yTop = 5;
								Pipe.bottom = Pipe21b;
								// d = 21;
								break;
						
						case 6: 
								Pipe.top = Pipe8;
								Pipe.yTop = 7;
								Pipe.bottom = Pipe19b;
								// d = 21;
								break;
						
						case 7: 
								Pipe.top = Pipe10;
								Pipe.yTop = 9;
								Pipe.bottom = Pipe17b;
								// d = 21;
								break;

							case 8:
								Pipe.top = Pipe12;
								Pipe.yTop = 11;
								Pipe.bottom = Pipe15b;
								// d = 21;
								break;
							
							case 9:
								Pipe.top = Pipe14;
								Pipe.yTop = 13;
								Pipe.bottom = Pipe13b;
								// d = 21;
								break;
							
							case 10:
								Pipe.top = Pipe16;
								Pipe.yTop = 15;
								Pipe.bottom = Pipe11b;
								// d = 21;
								break;
							
							case 11:
								Pipe.top = Pipe18;
								Pipe.yTop = 17;
								Pipe.bottom = Pipe9b;
								// d = 21;
								break;
							
							case 12:
								Pipe.top = Pipe20;
								Pipe.yTop = 19;
								Pipe.bottom = Pipe7b;
								// d = 21;
								break;
							
							case 13:
								Pipe.top = Pipe22;
								Pipe.yTop = 21;
								Pipe.bottom = Pipe5b;
								// d = 21;
								break;
							
							case 14:
								Pipe.top = Pipe24;
								Pipe.yTop = 23;
								Pipe.bottom = Pipe3b;
								break;
							
							case 15:
								Pipe.top = Pipe25;
								Pipe.yTop = 24;
								Pipe.bottom = Pipe0b;
								// d = 22;
								break;
							}
							// edge of Player.y  = -bot + 47
							

			}

			Nokia5110_PrintBMP(Pipe.x, Pipe.yTop, Pipe.top, 0);
			Nokia5110_PrintBMP(Pipe.x, Pipe.yBot, Pipe.bottom, 0);

			if(SW2 == 0) // SW2 is pressed
			{
					Nokia5110_PrintBMP(Player.x, Player.y, Player.image[2], 0);

			}
			else 
			{
//				 Nokia5110_PrintBMP(Player.x, Player.y, Player.image[1], 0);
				Nokia5110_PrintBMP(Player.x, Player.y, Player.image[2], 0);
			}
    }
  Nokia5110_DisplayBuffer();      // draw buffer
	
}

/////////////////////////////// MOVE /////////////////////////////////////

void Move(void)
	{
	
// Collision Detection
// if (( (Player.x +12) > Pipe.x) && ((Player.x + 12) < (Pipe.x + 12) ))
	if (( (Player.x +12) > Pipe.x) && (Player.x < (Pipe.x + 12) ))
		{			
			if ((Player.y - 7) < Pipe.yTop)
				{
							GameOver();
				}	
				if (Player.y > (Pipe.yTop + d)) // 18
				{
							GameOver();
				}	
		 }	
						
if((Player.y < Y_MAX) && (Player.y >= Y_MIN)){ 
			
	if(Pipe.x < X_MAX) {    
			Pipe.x  -= 1; // move left
	}
	else{
			Pipe.x = 70;
	};
	while(Countdown==1){
			if(SW1==0){
					Countdown=0;
			}
	}
	if ((SW2 == 0) && (SW1 != 0)){  //SW2 is pressed
			// for cyan: green, blue on
			Cyan_on();
//			GPIO_PORTF_DATA_R &= ~0x02; // Turn off red LED.
//			GPIO_PORTF_DATA_R |= 0x08;	// Turn off green LED.
//			GPIO_PORTF_DATA_R |= 0x04; // Turn on blue LED.
				
			Player.y -= 3;   // move up
						
	}
	else if (SW1 == 0){ //&& (TIMER2_CTL_R &= ~0x00000001)) // && stops timer but blocked pause

			TIMER2_CTL_R &= ~0x00000001;
			Delay100ms(1);
				
			if(SW1 == 0)
			{ 
				  Delay100ms(1);
					buttonPress = 1;
					PauseMenu();
		  }
					
			if(buttonPress == 1)
			{

					Delay100ms(1);
					PauseMenu();
			}
	}
	else{
		
		LED_off();
				
//			   GPIO_PORTF_DATA_R &= ~0x04; // Turn off blue LED.
//				 // GPIO_PORTF_DATA_R &= ~0x02; // Turn off red LED.
//				 GPIO_PORTF_DATA_R &= ~0x08;	// Turn off green LED.
				
				 Player.y += 1; // move down 1  // 0 to freeze bird
	}
			
}
else{
    GameOver();
}
}

/////////////////////////////////// SCORE ///////////////////////////

void Score_Init(void){

if(Player.life != 0)
			{		
				if (Pipe.x == Player.x) 
				{
					Green_on();
			//		Cyan_off();
//					GPIO_PORTF_DATA_R |= 0x08; // turn on green led
//					GPIO_PORTF_DATA_R &= ~0x04; // Turn off blue LED.
					score = score + 1;
				}
			}
	
		if (score > best){
		best = score;
			}
		
 if(Player.life > 0){  // ingame score
				if(score < 10)
				{
			Nokia5110_SetCursor(11, 0);
			Nokia5110_OutUDec(score);
					
				Nokia5110_SetCursor(0, 0); // renders screen
				}
				if((score < 100) && (score >= 10) )
				{
				 Nokia5110_SetCursor(10, 0);
				Nokia5110_OutUDec(score);
				Nokia5110_SetCursor(0, 0); // renders screen
				}	
			}
				
	}
