/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    USBD_Demo.c
 *      Purpose: USB Device Demonstration
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include <stm32f10x.h>                         /* STM32F10x Definitions      */
#include "LCD.h"

/* Push Button Definitions                                                    */
#define S3              0x2000          /* PC13: S3                           */
#define S2              0x0001          /* PA0 : S2                           */

int main (void) {
  static U8 but_ex;
         U8 but;
         U8 buf[1];

  lcd_init  ();
  lcd_clear ();
  lcd_print ("USB Device Demo ");
  set_cursor(0, 1);
  lcd_print ("  www.keil.com  ");

  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */

  while (1) {                           /* Loop forever                       */
    but = (((GPIOA->IDR ^ S2)      ) & 0x01) |
          (((GPIOC->IDR ^ S3) >> 12) & 0x02) ;
    if (but ^ but_ex) {
      buf[0] = but;
      usbd_hid_get_report_trigger(0, buf, 1);
      but_ex = but;
    }
  };
}
