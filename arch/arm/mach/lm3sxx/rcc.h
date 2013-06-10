/**
 *	Defines the Reset and Clock Control Register definitions for LM3Sxx
 *
 *
 *
 **/
#ifndef _RCC_H_
#define _RCC_H_

#include <bitthunder.h>

typedef struct _LM3Sxx_RCC_REGS {
	BT_u32 DID0;
	BT_u32 DID1;
	BT_u32 DC0;
	BT_STRUCT_RESERVED_u32(0, 0x08, 0x10);
	BT_u32 DC1;
	BT_u32 DC2;
	BT_u32 DC3;
	BT_u32 DC4;
	BT_u32 DC5;
	BT_u32 DC6;
	BT_u32 DC7;
	BT_u32 DC8;
	BT_u32 PBORCTL;
	BT_STRUCT_RESERVED_u32(1, 0x30, 0x40);
	BT_u32 SRCR0;
	BT_u32 SRCR1;
	BT_u32 SRCR2;
	BT_STRUCT_RESERVED_u32(2, 0x48, 0x50);
	BT_u32 RIS;

#define	LM3Sxx_RCC_RIS_PLLLRIS				0x00000040

	BT_u32 IMC;
	BT_u32 MISC;

#define	LM3Sxx_RCC_MISC_PLLLMIS				0x00000040


	BT_u32 RESC;
	BT_u32 RCC;

#define	LM3Sxx_RCC_RCC_USESYSDIV			0x00400000
#define	LM3Sxx_RCC_RCC_PWRDN				0x00002000
#define	LM3Sxx_RCC_RCC_BYPASS				0x00000800
#define	LM3Sxx_RCC_RCC_IOSCDIS				0x00000002
#define	LM3Sxx_RCC_RCC_MOSCDIS				0x00000001

#define	LM3Sxx_RCC_RCC_XTAL_M				0x000007C0
#define	LM3Sxx_RCC_RCC_OSCSRC_M				0x00000030
#define	LM3Sxx_RCC_RCC_OSCSRC_30			0x00000030

#define	LM3Sxx_RCC_RCC_SYSDIV_M				0x07800000

	BT_u32 PLLCFG;
	BT_STRUCT_RESERVED_u32(3, 0x64, 0x6C);
	BT_u32 GPIOHBCTL;
	BT_u32 RCC2;

#define	LM3Sxx_RCC_RCC2_USERCC2				0x80000000
#define	LM3Sxx_RCC_RCC2_DIV400				0x40000000
#define	LM3Sxx_RCC_RCC2_PWRDN2				0x00002000
#define	LM3Sxx_RCC_RCC2_BYPASS2				0x00000800

#define	LM3Sxx_RCC_RCC2_OSCSRC2_M			0x00000070
#define	LM3Sxx_RCC_RCC2_OSCSRC2_30			0x00000030
#define	LM3Sxx_RCC_RCC2_OSCSRC2_32			0x00000070

#define	LM3Sxx_RCC_RCC2_SYSDIV2_M			0x1F800000
#define	LM3Sxx_RCC_RCC2_SYSDIV2LSB			0x00400000

	BT_STRUCT_RESERVED_u32(4, 0x70, 0x7C);
	BT_u32 MOSCCTL;
	BT_STRUCT_RESERVED_u32(5, 0x7C, 0x100);
	BT_u32 RCGC[3];

#define	LM3Sxx_RCC_RCGC_UART0EN				0x00000001
#define	LM3Sxx_RCC_RCGC_UART1EN				0x00000002
#define	LM3Sxx_RCC_RCGC_UART2EN				0x00000004
#define	LM3Sxx_RCC_RCGC_SPI0EN				0x00000010
#define	LM3Sxx_RCC_RCGC_SPI1EN				0x00000020

#define	LM3Sxx_RCC_RCGC_MACEN				0x10000000
#define	LM3Sxx_RCC_RCGC_PHYEN				0x40000000



#define	LM3Sxx_RCC_RCGC_TIMER0EN			0x00010000
#define	LM3Sxx_RCC_RCGC_TIMER1EN			0x00020000
#define	LM3Sxx_RCC_RCGC_TIMER2EN			0x00040000
#define	LM3Sxx_RCC_RCGC_TIMER3EN			0x00080000

	BT_STRUCT_RESERVED_u32(6, 0x108, 0x110);
	BT_u32 SCGC[3];
	BT_STRUCT_RESERVED_u32(7, 0x118, 0x120);
	BT_u32 DCGC[3];
	BT_STRUCT_RESERVED_u32(8, 0x128, 0x144);
	BT_u32 DSLPCLKCFG;
	BT_STRUCT_RESERVED_u32(9, 0x144, 0x150);
	BT_u32 PIOSCCAL;
	BT_STRUCT_RESERVED_u32(10, 0x150, 0x170);
	BT_u32 I2SMCLKCFG;
	BT_STRUCT_RESERVED_u32(11, 0x170, 0x190);
	BT_u32 DC9;
	BT_STRUCT_RESERVED_u32(12, 0x190, 0x1A0);
	BT_u32 NVMSTAT;

} LM3Sxx_RCC_REGS;

#define LM3Sxx_RCC_BASE	0x400FE000
#define LM3Sxx_RCC 		((LM3Sxx_RCC_REGS *) (LM3Sxx_RCC_BASE))

BT_u32 BT_LM3Sxx_EnablePeripheral(BT_u32 ulPeripheral);
BT_u32 BT_LM3Sxx_GetMainFrequency(void);
BT_u32 BT_LM3Sxx_GetSystemFrequency(void);
void BT_LM3Sxx_SetSystemFrequency(BT_u32 ulConfig);


#endif
