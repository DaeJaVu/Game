/*----------------------------------------------------------------------------
 * Name:    BTN.h
 * Purpose: Button driver header file
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

#ifndef __BTN_H
#define __BTN_H

#define BTN_NUM     2                   /* Number of user Buttons             */

extern void     BTN_Init(void);
extern uint32_t BTN_Get (void);

#endif