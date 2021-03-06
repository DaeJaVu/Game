/*----------------------------------------------------------------------------
 * Name:    IRQ.C
 * Purpose: IRQ Handler
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2010 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include "LPC11xx.h"                    /* LPC11xx definitions                */


volatile unsigned short AD_last;        /* Last converted value               */
volatile unsigned char  clock_1s;       /* Flag activated each second         */

/* Import function for turning LEDs on or off                                 */
extern void LED_Out (unsigned int num);


/*----------------------------------------------------------------------------
  SysTick IRQ: Executed periodically (10ms) 
 *----------------------------------------------------------------------------*/
void SysTick_Handler (void) {
  static unsigned long ticks;
  static unsigned long timetick;
  static unsigned char leds = 0x01;

  if (ticks++ >= 99) {                  /* Set Clock1s to 1 every 1 second    */
    ticks    = 0;
    clock_1s = 1;
  }

  /* Blink the LEDs depending on ADC_ConvertedValue                           */
  if (timetick++ >= (AD_last >> 6)) {
    timetick   = 0;
    leds     <<= 1;
    if (leds == 0) leds = 0x01;
    LED_Out (leds);
  }

  LPC_ADC->CR |=  (1UL << 24);          /* Start A/D Conversion               */
}

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is done 
 *----------------------------------------------------------------------------*/
void ADC_IRQHandler(void) {
  unsigned int ADC_reg;

  ADC_reg = LPC_ADC->STAT;              /* Read ADC status clears interrupt   */

  ADC_reg = LPC_ADC->GDR;               /* Read conversion result             */
  AD_last = (ADC_reg >> 6) & 0x3FF;     /* Store converted value              */
}
