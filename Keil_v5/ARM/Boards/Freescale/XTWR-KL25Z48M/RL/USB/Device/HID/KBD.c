/*-----------------------------------------------------------------------------
 * Name:    KBD.c
 * Purpose: Low level keyboard functions
 * Note(s):
 *-----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <MKL25Z4.H>
#include "KBD.h"

#define NUM_KEYS  2                     /* Number of available keys           */

#define SW2  0x01
#define SW3  0x02



/*-----------------------------------------------------------------------------
 *       KBD_Init:  Initialize keyboard/buttons
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void KBD_Init (void) {
  /* Enable clock and init GPIO inputs                                        */
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK |  /* Enable Port C Clock                */
                SIM_SCGC5_PORTA_MASK;   /* Enable Port A Clock                */

  PTC->PDDR &= ~(1UL << 3);             /* PTC3 as input                      */
  PTC->PDDR &= ~(1UL << 4);             /* PTA4 as input                      */

  PORTC->PCR[3]  = PORT_PCR_MUX(1)   |  /* PTC3 is GPIO pin                   */
                   PORT_PCR_PS_MASK  |  /* pull up on PTC1                    */
                   PORT_PCR_PE_MASK;

  PORTA->PCR[4]  = PORT_PCR_MUX(1)   |  /* PTA4 is GPIO pin                   */
                   PORT_PCR_PS_MASK  |  /* pull up on PTC2                    */
                   PORT_PCR_PE_MASK;
}


/*-----------------------------------------------------------------------------
 *       KBD_UnInit:  Uninitialize keyboard/buttons
 *
 * Parameters: (none)
 * Return:     (none)
 *----------------------------------------------------------------------------*/
void KBD_UnInit (void) {
  PORTC->PCR[3] = 0;                    /* PTC3 is at reset state             */
  PORTA->PCR[4] = 0;                    /* PTA4 is at reset state             */
}


/*-----------------------------------------------------------------------------
 *       KBD_GetKeys:  Get keyboard state
 *
 * Parameters: (none)
 * Return:      Keys bitmask
 *----------------------------------------------------------------------------*/
uint32_t KBD_GetKeys (void) {
  /* Read board keyboard inputs */
  uint32_t val = 0;

  if (!(PTA->PDIR & (1UL << 4))) {
    /* SW2 */
    val |= SW2;
  }
  if (!(PTC->PDIR & (1UL << 3))) {
    /* SW3 */
    val |= SW3;
  }
  return (val);
}


/*-----------------------------------------------------------------------------
 *       KBD_Num:  Get number of available keys
 *
 * Parameters: (none)
 * Return:      number of keys
 *----------------------------------------------------------------------------*/
uint32_t KBD_Num (void) {
  return (NUM_KEYS);
}

/*-----------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/