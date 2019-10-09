/***********************************************************************/
/*                                                                     */
/*  FILE        :vecttbl.c                                             */
/*  DATE        :Mon, May 10, 2010                                     */
/*  DESCRIPTION :Initialize of Vector Table                            */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.50).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
                  


/*********************************************************************
*
* Device     : RX/RX600
*
* File Name  : vecttbl.c
*
* Abstract   : Initialize of Vector Table.
*
* History    : 1.00  (2009-08-07)
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright(c) 2009 Renesas Technology Corp.
*               And Renesas Solutions Corp.,All Rights Reserved. 
*
*********************************************************************/

#include "vect.h"

#pragma section C FIXEDVECT

void* const Fixed_Vectors[] = {
//;0xffffffd0  Exception(Supervisor Instruction)
    (void*) Excep_SuperVisorInst,
//;0xffffffd4  Reserved
    Dummy,
//;0xffffffd8  Reserved
    Dummy,
//;0xffffffdc  Exception(Undefined Instruction)
    (void*) Excep_UndefinedInst,
//;0xffffffe0  Reserved
    Dummy,
//;0xffffffe4  Exception(Floating Point)
    (void*) Excep_FloatingPoint,
//;0xffffffe8  Reserved
    Dummy,
//;0xffffffec  Reserved
    Dummy,
//;0xfffffff0  Reserved
    Dummy,
//;0xfffffff4  Reserved
    Dummy,
//;0xfffffff8  NMI
    (void*) NonMaskableInterrupt,
//;0xfffffffc  RESET
//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
PowerON_Reset_PC                                                                                                                             
//;<<VECTOR DATA END (POWER ON RESET)>>
};
