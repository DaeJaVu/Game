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
#include <LPC177x_8x.h>                      /* LPC177x_8x definitions        */

#include "KBD.h"

__task void init (void) {
  static U8 but_ex;
         U8 but;
         U8 buf[1];

  os_tsk_prio_self(100);
  usbd_init();                          /* USB Device Initialization          */
  usbd_connect(__TRUE);                 /* USB Device Connect                 */
  os_tsk_prio_self(1);
  while (1) {                           /* Loop forever                       */
    but = KBD_GetKeys();
    if (but ^ but_ex) {
      buf[0] = but;
      usbd_hid_get_report_trigger(0, buf, 1);
      but_ex = but;
    }  
  }
}

int main (void) {

  os_sys_init(init);                    /* Init RTX and start 'init'          */
}
