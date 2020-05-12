/*------------------------------------------------------------------------------
 * Name:    KBD.c
 * Purpose: Keyboard functions for the 
 *          Freescale Kinetis TWR-K70F120M board
 * Note(s): 
 *------------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <MK70F12.H>
#include "KBD.h"

#define NUM_KEYS    2                   /* Number of available keys           */

#define SW1         1
#define SW2         2


/*------------------------------------------------------------------------------
 * KBD_Init:        Initialize keyboard/buttons
 *----------------------------------------------------------------------------*/

void KBD_Init (void) {

  /* Enable clock and init GPIO inputs                                        */
  SIM->SCGC5 |=   SIM_SCGC5_PORTD_MASK; /* Enable Port D Clock                */
  SIM->SCGC5 |=   SIM_SCGC5_PORTE_MASK; /* Enable Port E Clock                */

  PTD->PDDR  &= ~(1 <<  0);             /* PTD0  input                        */
  PTE->PDDR  &= ~(1 << 26);             /* PTE26 input                        */

  PORTD->PCR[ 0]  = PORT_PCR_MUX(1)  |  /* PTD0  is GPIO pin                  */
                    PORT_PCR_PS_MASK |  /* pull up on PTD0                    */
                    PORT_PCR_PE_MASK;

  PORTE->PCR[26]  = PORT_PCR_MUX(1)  |  /* PTE26 is GPIO pin                  */
                    PORT_PCR_PS_MASK |  /* pull up on PTE26                   */
                    PORT_PCR_PE_MASK;
}


/*------------------------------------------------------------------------------
 * KBD_Uninit:      Uninitialize keyboard/buttons
 *----------------------------------------------------------------------------*/

void KBD_Uninit (void) {

  PORTD->PCR[ 0] = 0;                   /* PTD0  is at reset state            */
  PORTE->PCR[26] = 0;                   /* PTE26 is at reset state            */
}


/*------------------------------------------------------------------------------
 * KBD_GetKeys:     Get keyboard state
 *----------------------------------------------------------------------------*/

uint32_t KBD_GetKeys (void) {

  /* Read board keyboard inputs */
  uint32_t val = 0;

  if (!(PTD->PDIR & (1 <<  0))) {
    /* SW1 */
    val |= SW1;
  }
  if (!(PTE->PDIR & (1 << 26))) {
    /* SW2 */
    val |= SW2;
  }
  return (val);
}


/*------------------------------------------------------------------------------
 * KBD_Num:         Get number of available keys
 *----------------------------------------------------------------------------*/

uint32_t KBD_Num (void) {

  return (NUM_KEYS);
}


/*------------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/