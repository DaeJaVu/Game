/*----------------------------------------------------------------------------
 * Name:    demo.c
 * Purpose: USB HID Demo
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008 - 2013 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <sam3s.h>

#include "type.h"

#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"

#include "demo.h"


U8 InReport;                                /* HID Input Report */
                                            /*   Bit0..1: Buttons */
                                            /*   Bit2..7: Reserved */

U8 OutReport;                               /* HID Out Report */
                                            /*   Bit0..1: LEDs */
                                            /*   Bit2..7: Reserved */


/*
 *  Get HID Input Report -> InReport
 */

void GetInReport (void) {
  U32 key;

  InReport = 0x00;
  key = PIOB->PIO_PDSR;                                /* Read Pin Data              */
  if ((key & PIO_PB3) == 0) InReport |= 0x01;          /* Check if USRPB1 is pressed */
  key = PIOC->PIO_PDSR;                                /* Read Pin Data              */
  if ((key & PIO_PC12) == 0) InReport |= 0x02;         /* Check if USRPB2 is pressed */
}


/*
 *  Set HID Output Report <- OutReport
 */

void SetOutReport (void) {

#ifdef __REV_A
  if (OutReport & 0x01)
    PIOC->PIO_CODR = PIO_PC20;                         /* Turn LED#1 On  */
  else
    PIOC->PIO_SODR = PIO_PC20;                         /* Turn LED#1 Off */

  if (OutReport & 0x02)
    PIOC->PIO_CODR = PIO_PC21;                         /* Turn LED#2 On  */
  else 
    PIOC->PIO_SODR = PIO_PC21;                         /* Turn LED#3 Off */
#else
  if (OutReport & 0x01)
    PIOA->PIO_CODR = PIO_PC19;                         /* Turn LED#1 On  */
  else
    PIOA->PIO_SODR = PIO_PC19;                         /* Turn LED#1 Off */

  if (OutReport & 0x02)
    PIOA->PIO_CODR = PIO_PC20;                         /* Turn LED#1 On  */
  else 
    PIOA->PIO_SODR = PIO_PC20;                         /* Turn LED#1 Off */
#endif
}


/*------------------------------------------------------------------------------
  Main Program
 *------------------------------------------------------------------------------*/
int main (void) {

  SystemCoreClockUpdate();

  PMC->PMC_WPMR = 0x504D4300;                          /* Disable write protect */
  /* Enable Clock for PIO */
  PMC->PMC_PCER0 = ((1 << ID_PIOB) |                   /* enable clock for USRPB1 */
                    (1 << ID_PIOC)  );                 /* enable clock for USRPB2 */

  PIOB->PIO_IDR  = 
  PIOB->PIO_ODR  = 
  PIOB->PIO_PER  =   PIO_PB3;                          /* Setup Pins PB3 for Button USRPB1  */

  PIOC->PIO_IDR  = 
  PIOC->PIO_ODR  = 
  PIOC->PIO_PER  =   PIO_PC12;                         /* Setup Pins PC12 for Button USRPB2 */

  /* Enable Clock for PIO */
#ifdef __REV_A
  PMC->PMC_PCER0 = (1 << ID_PIOC);                     /* enable clock for LEDs   */

  PIOC->PIO_IDR   =                                    /* Setup Pins PC20..PC21 for LEDs */
  PIOC->PIO_OER   =
  PIOC->PIO_PER   = PIO_PC20 | PIO_PC21;
  PIOC->PIO_SODR  = PIO_PC20 | PIO_PC21;               /* Turn LEDs Off           */
#else
  PMC->PMC_PCER0 = (1 << ID_PIOA);                     /* enable clock for LEDs   */

  PIOA->PIO_IDR   =                                    /* Setup Pins PC20..PC21 for LEDs */
  PIOA->PIO_OER   =
  PIOA->PIO_PER   = PIO_PA19 | PIO_PA20;
  PIOA->PIO_SODR  = PIO_PA19 | PIO_PA20;               /* Turn LEDs Off           */
#endif

  USB_Init();                                          /* USB Initialization      */
  USB_Connect(__TRUE);                                 /* USB Connect             */

  while (1);                                           /* Loop forever            */
}