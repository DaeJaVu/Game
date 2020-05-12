/******************************************************************************/
/* BLINKY.C: LED Flasher                                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include "stdio.h"
#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD.h"

#define __FI        1                   /* Font index 16x24                   */

#define LED_NUM     4                   /* Number of user LEDs                */
const unsigned long led_mask[] = { 1UL <<  6, 1UL <<  7, 1UL << 8, 1UL << 9};

extern unsigned char ClockLEDOn;
extern unsigned char ClockLEDOff;
extern unsigned char ClockANI;
extern unsigned char Bg_16bpp_t[];
extern unsigned char Bg_16bpp_l[];
extern unsigned char Bg_16bpp_r[];
extern unsigned char Bg_16bpp_b[];
extern unsigned char ARM_Ani_16bpp[];


int main (void) {
  int num     = -1; 
  int dir     =  1;
  int pic     =  0;

  SysTick_Config(SystemCoreClock/100);  /* Generate interrupt each 10 ms      */

  /* Setup GPIO for LEDs                                                      */
  RCC->APB2ENR |= (1 << 7);             /* Enable GPIOF clock                 */

  GPIOF->ODR   &= ~0x000003C0;          /* switch off LEDs                    */
  GPIOF->CRL   &= ~0xFF000000;          /* Configure the GPIO for LEDs        */
  GPIOF->CRL   |=  0x33000000;
  GPIOF->CRH   &= ~0x000000FF;
  GPIOF->CRH   |=  0x00000033;

  GLCD_Init   ();
  GLCD_Clear  (White);
  GLCD_Bitmap (  0,   0, 320,  69, Bg_16bpp_t+70);
  GLCD_Bitmap (  0,  69,   4, 102, Bg_16bpp_l+70);
  GLCD_Bitmap (316,  69,   4, 102, Bg_16bpp_r+70);
  GLCD_Bitmap (  0, 171, 320,  69, Bg_16bpp_b+70);

  for (;;) {                            /* Loop forever                       */
    if (ClockANI) {
      ClockANI = 0;
      if (pic++ > 8) pic = 0;
        GLCD_Bitmap (99, 99, 120, 45, &ARM_Ani_16bpp[pic*(120*45*2)]);
    }

    if (ClockLEDOn) {    /* Blink LED every 1 second (for 0.5s)*/
      ClockLEDOn  = 0;

      /* Calculate 'num': 0,1,...,LED_NUM-1,LED_NUM-1,...,1,0,0,...           */
      num += dir;
      if (num == LED_NUM) { dir = -1; num =  LED_NUM-1; } 
      else if   (num < 0) { dir =  1; num =  0;         }
    
      GPIOF->BSRR = led_mask[num];
    }
    if (ClockLEDOff) {
      ClockLEDOff = 0;
      GPIOF->BRR  = led_mask[num];
    }
  }
}