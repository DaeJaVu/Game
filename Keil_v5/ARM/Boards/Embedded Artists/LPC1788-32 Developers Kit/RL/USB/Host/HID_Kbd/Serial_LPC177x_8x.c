/*----------------------------------------------------------------------------
 * Name:    Serial.c
 * Purpose: Low Level Serial Routines
 * Note(s): possible defines select the used communication interface:
 *            __DBG_ITM   - ITM SWO interface
              __UART0     - UART0 (UART-to-USB Bridge) 
 *                        - UART2 (RS232 DSUB-9) default
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC177x_8x.h>
#include "Serial.h"

#ifdef __DBG_ITM
volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input        */
#endif

#ifdef __UART0
  #define UART    LPC_UART0
#else
  #define UART    LPC_UART2
#endif


/*------------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/

void SER_Init (void) {

#ifndef __DBG_ITM
  LPC_SC->PCONP   |=  ( 1UL << 15);        /* enable power to IOCON           */

#ifdef __UART0                             /* UART0 */
  LPC_SC->PCONP   |=  ( 1UL <<  3);        /* enable power to UART0           */
  LPC_IOCON->P0_2  =  ( 1UL <<  0);        /* Pin P0.2 used as TXD0           */
  LPC_IOCON->P0_3  =  ( 1UL <<  0);        /* Pin P0.3 used as RXD0           */
#else                                      /* UART2 */
  LPC_SC->PCONP   |=  ( 1UL << 24);        /* enable power to UART2           */
  LPC_IOCON->P0_10 =  ( 1UL <<  0);        /* Pin P0.10 used as TXD2          */
  LPC_IOCON->P0_11 =  ( 1UL <<  0);        /* Pin P0.11 used as RXD2          */
#endif

  UART->LCR   = 0x83;                      /* 8 bits, no Parity, 1 Stop bit   */
  UART->DLL   = 21;                        /* 115200 Baud Rate @ 60.0 MHZ PCLK*/
  UART->FDR   = 0x95;                      /* FR 1,556, DIVADDVAL=5, MULVAL=9 */
  UART->DLM   = 0;                         /* High divisor latch = 0          */
  UART->LCR   = 0x03;                      /* DLAB = 0                        */
#endif
}


/*------------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to the Serial Port
 *----------------------------------------------------------------------------*/

int32_t SER_PutChar (int32_t ch) {

#ifdef __DBG_ITM
  return (ITM_SendChar(ch));
#else
  while (!(UART->LSR & 0x20));
  UART->THR = ch;
  return (ch);
#endif
}


/*------------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from the Serial Port (non-blocking)
 *----------------------------------------------------------------------------*/

int32_t SER_GetChar (void) {

#ifdef __DBG_ITM
  if (ITM_CheckChar()) { 
    return (ITM_ReceiveChar());
  }
#else
  if (UART->LSR & 0x01) { 
    return (UART->RBR);
  }
#endif
  return (-1);
}

/*------------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
