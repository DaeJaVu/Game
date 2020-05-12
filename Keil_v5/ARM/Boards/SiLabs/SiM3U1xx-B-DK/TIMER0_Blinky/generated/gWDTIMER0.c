//-------------------------------------------------------------------------------
// Copyright (c) 2012 by Silicon Laboratories
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v10/License_Agreement_v10.htm
//
//
// Original content and implementation provided by Silicon Laboratories
//-------------------------------------------------------------------------------

//==============================================================================
// WARNING:
//
// This file is auto-generated by AppBuilder and should not be modified.
// Any hand modifications will be lost if the project is regenerated.
//==============================================================================

#include "gWDTIMER0.h"

// Include peripheral access modules used in this file
#include <SI32_WDTIMER_A_Type.h>
#include <si32_device.h>

//==============================================================================
// Configuration Functions
//==============================================================================
void WDTIMER0_enter_default_mode_from_reset(void)
{
  SI32_WDTIMER_A_stop_counter(SI32_WDTIMER_0);
}
