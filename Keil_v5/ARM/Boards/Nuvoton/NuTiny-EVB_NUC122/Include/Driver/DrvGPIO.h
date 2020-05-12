/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#ifndef DRVGPIO_H
#define DRVGPIO_H

#include "NUC122.h"

/*---------------------------------------------------------------------------------------------------------*/
/*  Define Version number								                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define DRVGPIO_MAJOR_NUM       1
#define DRVGPIO_MINOR_NUM       02
#define DRVGPIO_BUILD_NUM       002

/*---------------------------------------------------------------------------------------------------------*/
/*  Version define with SysInfra				                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define DRVGPIO_VERSION_NUM     _SYSINFRA_VERSION(DRVGPIO_MAJOR_NUM, DRVGPIO_MINOR_NUM, DRVGPIO_BUILD_NUM)
							   
/*---------------------------------------------------------------------------------------------------------*/
/*  Define Error Code									                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define E_DRVGPIO_ARGUMENT          _SYSINFRA_ERRCODE(TRUE, MODULE_ID_DRVGPIO, 1)
#define E_DRVGPIO_GROUP_PIN         _SYSINFRA_ERRCODE(TRUE, MODULE_ID_DRVGPIO, 2)
#define E_DRVGPIO_BUSY              _SYSINFRA_ERRCODE(TRUE, MODULE_ID_DRVGPIO, 3)   

typedef void (*GPIO_GPAB_CALLBACK)(uint32_t u32GPAStatus, uint32_t u32GPBStatus);
typedef void (*GPIO_GPCD_CALLBACK)(uint32_t u32GPCStatus, uint32_t u32GPDStatus);
typedef void (*GPIO_EINT0_CALLBACK)(void);
typedef void (*GPIO_EINT1_CALLBACK)(void);

/* Define GPIO[n] Pin I/O Bit Output/Input Control. */
#define _DRVGPIO_DOUT(PortNum, PinNum)      (*((volatile uint32_t *) ((GPIO_BIT_ADDR_BASE+(0x40*PortNum)) + (0x4*PinNum))))    
#define GPA_0	            _DRVGPIO_DOUT(0, 0)
#define GPA_1	            _DRVGPIO_DOUT(0, 1)
#define GPA_2	            _DRVGPIO_DOUT(0, 2)
#define GPA_3	            _DRVGPIO_DOUT(0, 3)
#define GPA_4	            _DRVGPIO_DOUT(0, 4)
#define GPA_5	            _DRVGPIO_DOUT(0, 5)
#define GPA_6	            _DRVGPIO_DOUT(0, 6)
#define GPA_7	            _DRVGPIO_DOUT(0, 7)
#define GPA_8	            _DRVGPIO_DOUT(0, 8)
#define GPA_9	            _DRVGPIO_DOUT(0, 9)
#define GPA_10	            _DRVGPIO_DOUT(0, 10)
#define GPA_11	            _DRVGPIO_DOUT(0, 11)
#define GPA_12	            _DRVGPIO_DOUT(0, 12)
#define GPA_13	            _DRVGPIO_DOUT(0, 13)
#define GPA_14	            _DRVGPIO_DOUT(0, 14)
#define GPA_15	            _DRVGPIO_DOUT(0, 15)
#define GPB_0	            _DRVGPIO_DOUT(1, 0)
#define GPB_1	            _DRVGPIO_DOUT(1, 1)
#define GPB_2	            _DRVGPIO_DOUT(1, 2)
#define GPB_3	            _DRVGPIO_DOUT(1, 3)
#define GPB_4	            _DRVGPIO_DOUT(1, 4)
#define GPB_5	            _DRVGPIO_DOUT(1, 5)
#define GPB_6	            _DRVGPIO_DOUT(1, 6)
#define GPB_7	            _DRVGPIO_DOUT(1, 7)
#define GPB_8	            _DRVGPIO_DOUT(1, 8)
#define GPB_9	            _DRVGPIO_DOUT(1, 9)
#define GPB_10	            _DRVGPIO_DOUT(1, 10)
#define GPB_11	            _DRVGPIO_DOUT(1, 11)
#define GPB_12	            _DRVGPIO_DOUT(1, 12)
#define GPB_13	            _DRVGPIO_DOUT(1, 13)
#define GPB_14	            _DRVGPIO_DOUT(1, 14)
#define GPB_15	            _DRVGPIO_DOUT(1, 15)
#define GPC_0	            _DRVGPIO_DOUT(2, 0)
#define GPC_1	            _DRVGPIO_DOUT(2, 1)
#define GPC_2	            _DRVGPIO_DOUT(2, 2)
#define GPC_3	            _DRVGPIO_DOUT(2, 3)
#define GPC_4	            _DRVGPIO_DOUT(2, 4)
#define GPC_5	            _DRVGPIO_DOUT(2, 5)
#define GPC_6	            _DRVGPIO_DOUT(2, 6)
#define GPC_7	            _DRVGPIO_DOUT(2, 7)
#define GPC_8	            _DRVGPIO_DOUT(2, 8)
#define GPC_9	            _DRVGPIO_DOUT(2, 9)
#define GPC_10	            _DRVGPIO_DOUT(2, 10)
#define GPC_11	            _DRVGPIO_DOUT(2, 11)
#define GPC_12	            _DRVGPIO_DOUT(2, 12)
#define GPC_13	            _DRVGPIO_DOUT(2, 13)
#define GPC_14	            _DRVGPIO_DOUT(2, 14)
#define GPC_15	            _DRVGPIO_DOUT(2, 15)
#define GPD_0	            _DRVGPIO_DOUT(3, 0)
#define GPD_1	            _DRVGPIO_DOUT(3, 1)
#define GPD_2	            _DRVGPIO_DOUT(3, 2)
#define GPD_3	            _DRVGPIO_DOUT(3, 3)
#define GPD_4	            _DRVGPIO_DOUT(3, 4)
#define GPD_5	            _DRVGPIO_DOUT(3, 5)
#define GPD_6	            _DRVGPIO_DOUT(3, 6)
#define GPD_7	            _DRVGPIO_DOUT(3, 7)
#define GPD_8	            _DRVGPIO_DOUT(3, 8)
#define GPD_9	            _DRVGPIO_DOUT(3, 9)
#define GPD_10	            _DRVGPIO_DOUT(3, 10)
#define GPD_11	            _DRVGPIO_DOUT(3, 11)
#define GPD_12	            _DRVGPIO_DOUT(3, 12)
#define GPD_13	            _DRVGPIO_DOUT(3, 13)
#define GPD_14	            _DRVGPIO_DOUT(3, 14)
#define GPD_15	            _DRVGPIO_DOUT(3, 15)

typedef enum 
{
	E_GPA = 0,
	E_GPB = 1, 
	E_GPC = 2, 
	E_GPD = 3, 
} E_DRVGPIO_PORT;

typedef enum 
{
    E_IO_INPUT = 0,
    E_IO_OUTPUT,
    E_IO_OPENDRAIN,
    E_IO_QUASI
} E_DRVGPIO_IO;

typedef enum 
{
    E_IO_RISING = 0,
    E_IO_FALLING,
    E_IO_BOTH_EDGE
} E_DRVGPIO_INT_TYPE;

typedef enum
{
    E_MODE_EDGE = 0,
    E_MODE_LEVEL
} E_DRVGPIO_INT_MODE;

typedef enum
{
    E_DBCLKSRC_HCLK = 0, 
    E_DBCLKSRC_10K = 1
} E_DRVGPIO_DBCLKSRC;	   

typedef enum
{
    E_FUNC_GPIO,    E_FUNC_I2C1,
    E_FUNC_UART0,   E_FUNC_UART0_RX_TX, E_FUNC_UART0_RTS_CTS,
    E_FUNC_UART1,   E_FUNC_UART1_RX_TX, E_FUNC_UART1_RTS_CTS,
    E_FUNC_SPI0,    E_FUNC_SPI0_SS1, 
    E_FUNC_SPI1,    E_FUNC_SPI1_SS1_PB9,  E_FUNC_SPI1_SS1_PB4_QFN33,
    E_FUNC_EXTINT0, E_FUNC_EXTINT1, 
    E_FUNC_TMR0,    E_FUNC_TMR1,    E_FUNC_TMR2,  
    E_FUNC_PWM01,   E_FUNC_PWM23,
    E_FUNC_PWM0,    E_FUNC_PWM1,    E_FUNC_PWM2,    E_FUNC_PWM3,
} E_DRVGPIO_FUNC;
			  
/*---------------------------------------------------------------------------------------------------------*/
/* Define GPIO functions prototype                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
int32_t DrvGPIO_Open(E_DRVGPIO_PORT port, int32_t i32Bit, E_DRVGPIO_IO mode);
int32_t DrvGPIO_Close(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_SetBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_GetBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_ClrBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_SetPortBits(E_DRVGPIO_PORT port, int32_t i32Data);
int32_t DrvGPIO_GetPortBits(E_DRVGPIO_PORT port);
int32_t DrvGPIO_GetDoutBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_GetPortDoutBits(E_DRVGPIO_PORT port);
int32_t DrvGPIO_SetBitMask(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_GetBitMask(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_ClrBitMask(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_SetPortMask(E_DRVGPIO_PORT port, int32_t i32MaskData);
int32_t DrvGPIO_GetPortMask(E_DRVGPIO_PORT port);
int32_t DrvGPIO_ClrPortMask(E_DRVGPIO_PORT port, int32_t i32MaskData);
int32_t DrvGPIO_EnableDigitalInputBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_DisableDigitalInputBit(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_EnableDebounce(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_DisableDebounce(E_DRVGPIO_PORT port, int32_t i32Bit);
int32_t DrvGPIO_SetDebounceTime(uint32_t u32CycleSelection, E_DRVGPIO_DBCLKSRC ClockSource);
int32_t DrvGPIO_GetDebounceSampleCycle(void);
int32_t DrvGPIO_EnableInt(E_DRVGPIO_PORT port, int32_t i32Bit, E_DRVGPIO_INT_TYPE TriggerType, E_DRVGPIO_INT_MODE Mode);
int32_t DrvGPIO_DisableInt(E_DRVGPIO_PORT port, int32_t i32Bit);
void DrvGPIO_SetIntCallback(GPIO_GPAB_CALLBACK pfGPABCallback, GPIO_GPCD_CALLBACK pfGPCDCallback);
void DrvGPIO_EnableEINT0(E_DRVGPIO_INT_TYPE TriggerType, E_DRVGPIO_INT_MODE Mode, GPIO_EINT0_CALLBACK pfEINT0Callback);
void DrvGPIO_DisableEINT0(void);
void DrvGPIO_EnableEINT1(E_DRVGPIO_INT_TYPE TriggerType, E_DRVGPIO_INT_MODE Mode, GPIO_EINT1_CALLBACK pfEINT1Callback);
void DrvGPIO_DisableEINT1(void);
int32_t DrvGPIO_GetIntStatus(E_DRVGPIO_PORT port);
int32_t DrvGPIO_InitFunction(E_DRVGPIO_FUNC function);
int32_t DrvGPIO_GetVersion(void);

#endif







