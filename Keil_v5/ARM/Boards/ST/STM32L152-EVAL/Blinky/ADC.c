/*----------------------------------------------------------------------------
 * Name:    ADC.c
 * Purpose: low level ADC functions
 * Note(s): possible defines select the used ADC interface:
 *            __ADC_IRQ   - ADC works in Interrupt mode
 *                        - ADC works in DMA mode (default)
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 20009-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include "stm32l1xx.h"                    /* STM32L1xx.h definitions          */
#include "ADC.h"

uint16_t AD_last;                         /* Last converted value             */
uint8_t  AD_done = 0;                     /* AD conversion done flag          */

/*----------------------------------------------------------------------------
  Function that initializes ADC
    5 MHz operation, 20�s startup time, 600ns track and hold time
 *----------------------------------------------------------------------------*/
void ADC_Init (void) {

  RCC->AHBENR  |= ( 1UL <<    1);         /* Enable GPIOB clock               */
  GPIOB->MODER |= ( 3UL << 2*12);         /* PB.12 is Analog mode             */

#ifndef __ADC_IRQ
  /* DMA1 Channel1 configuration ---------------------------------------------*/
  RCC->AHBENR  |= (1UL << 24);            /* enable DMA1 clock                */

  DMA1_Channel1->CMAR  = (uint32_t)&AD_last;    /* Set memory     address     */
  DMA1_Channel1->CPAR  = (uint32_t)&(ADC1->DR); /* Set peripheral address     */
  DMA1_Channel1->CNDTR = 1;               /* Transmit 1 data item             */
  DMA1_Channel1->CCR   = 0x00002522;      /* configure DMA channel            */
  NVIC_EnableIRQ(DMA1_Channel1_IRQn);     /* enable DMA1 Channel Interrupt    */
  DMA1_Channel1->CCR  |= (1UL << 0);      /* enable DMA channel 1             */
#endif

  /* Setup and initialize ADC converter                                       */
  RCC->CR      |= ( 1UL <<    0);         /* Enable Internal high-speed clock */
  RCC->APB2ENR |= ( 1UL <<  9);           /* enable periperal clock for ADC1  */

  ADC1->CR1     = ( 1UL <<  8);           /* Scan mode on, 12 Bit             */
  ADC1->CR2     =  0;

  ADC1->SQR1    =  0;                     /* Regular chn. Sequence length = 1 */
  ADC1->SQR2    =  0;                     /* Clear register                   */
  ADC1->SQR3    =  0;                     /* Clear register                   */
  ADC1->SQR4    =  0;                     /* Clear register                   */
  ADC1->SQR5    = (18UL <<  0);           /* 1. conversion = channel 18       */
  ADC1->SMPR1   =  0;                     /* Clear register                   */
  ADC1->SMPR2   = ( 4UL << 24);           /* Chn 18 sample time is 48 cyc     */

#ifndef __ADC_IRQ
  ADC1->CR2    |= ( 3UL <<  8);           /* DMA mode enable, cont. DMA req.  */
#else
  ADC1->CR1    |= ( 1UL <<  5);           /* enable for EOC Interrupt         */
  NVIC_EnableIRQ(ADC1_IRQn);              /* enable ADC Interrupt             */
#endif

  ADC1->CR2    |= ( 1UL <<  0);           /* ADC enable                       */
}


/*----------------------------------------------------------------------------
  start AD Conversion
 *----------------------------------------------------------------------------*/
void ADC_StartCnv (void) {

  if ((ADC1->SR & ((1 << 6) | (1 << 8))) == (1 << 6)) {
    ADC1->CR2    |=  (1UL << 30);         /* Start A/D conversion             */ 
  }
}


/*----------------------------------------------------------------------------
  stop AD Conversion
 *----------------------------------------------------------------------------*/
void ADC_StopCnv (void) {

  ADC1->CR2    &= ~(1UL << 30);           /* Stop  A/D conversion             */ 
}


/*----------------------------------------------------------------------------
  get converted AD value
 *----------------------------------------------------------------------------*/
uint16_t ADC_GetCnv (void) {

  while (!(AD_done));                     /* Wait for Conversion end          */
  AD_done = 0;

  return(AD_last);
}


#ifndef __ADC_IRQ
/*----------------------------------------------------------------------------
  DMA IRQ: Executed when a transfer is completet
 *----------------------------------------------------------------------------*/
void DMA1_Channel1_IRQHandler(void) {

  if (DMA1->ISR & (1 << 1)) {             /* TCIF interrupt?                  */
    AD_done = 1;

    DMA1->IFCR  = (1 << 1);               /* clear TCIF interrupt             */
  }
}
#endif


#ifdef __ADC_IRQ
/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is done
 *----------------------------------------------------------------------------*/
void ADC1_IRQHandler(void) {

  if (ADC1->SR & (1 << 1)) {              /* ADC1 EOC interrupt?              */
    AD_last = ADC1->DR;
    AD_done = 1;

    ADC1->SR &= ~(1 << 1);                /* clear EOC interrupt              */
  }

}
#endif