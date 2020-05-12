/* -----------------------------------------------------------------------------
 * Copyright (c) 2014 ARM Ltd.
 *
 * This software is provided 'as-is', without any express or implied warranty. 
 * In no event will the authors be held liable for any damages arising from 
 * the use of this software. Permission is granted to anyone to use this 
 * software for any purpose, including commercial applications, and to alter 
 * it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not 
 *    claim that you wrote the original software. If you use this software in
 *    a product, an acknowledgment in the product documentation would be 
 *    appreciated but is not required. 
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be 
 *    misrepresented as being the original software. 
 * 
 * 3. This notice may not be removed or altered from any source distribution.
 *   
 *
 * $Date:        15. April 2014
 * $Revision:    V1.00
 *  
 * Project:      Flash Programming Functions for A2FxxxM3
 * --------------------------------------------------------------------------- */

/* History:
 *  Version 1.00
 *    Initial release
 */ 

#include "..\FlashOS.H"        // FlashOS Structures
#include "a2fxxxm3.h"

#define FLASH_PAGE_SIZE_BYTE   128

#define STACK_SIZE   64        // Stack Size


unsigned long base_adr;        // Base Address


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {
  base_adr = adr;

  switch (fnc) {
    case 1:
      WATCHDOG->WDOGENABLE = 0x4C6E55FA;        // Disable watchdog
      break;
    case 3:
      SYSREG->ENVM_REMAP_SYS_CR = 0x00000001;   // Remap eNVM to 0x00000000
      break; 
  }

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  return (0);
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  return (0);                           // Automatic Erase during Program Cycle
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  unsigned long   page;
  unsigned char * Flash;

  Flash = (unsigned char *)(adr + 0x60000000);
  page  = (adr - base_adr) & ~(FLASH_PAGE_SIZE_BYTE - 1);

  // Reset status bits
  ENVM_REGS->STATUS  = 0xFFFFFFFF;

  // Unlock Page Command
  ENVM_REGS->CONTROL = 0x02000000 | page;

  // Wait until the end of Command
  while (ENVM_REGS->STATUS & 1);

  // Copy to the Write Buffer
  while (sz --) {
    *Flash++ = *buf++;
  }
  // Program Page Command
  ENVM_REGS->CONTROL = 0x10000000 | page;

  // Wait until the end of Command
  while (ENVM_REGS->STATUS & 1);

  // Check for Errors
  if (ENVM_REGS->STATUS & 0x8074) return (1);

  return (0);
}