/*
 * utils.h
 *
 *  Created on: Aug 5, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(reg,bit_no)               reg|=(1<<bit_no)
#define Clr_Bit(reg,bit_no)               reg&=~(1<<bit_no)
#define Get_Bit(Reg,bit_no)               1&(Reg>>bit_no)
#define Toggle_Bit(reg,bit_no)            reg^=(1<<bit_no)
#define Assign_Bit(reg,bit_no,value)      do{if(value==0) (reg&=(~(1<<bit_no))); \
                                            if(value==1) (reg|=(1<<bit_no));}while(0)
//****************************************************

#define Set_Lnibble(reg)                  reg|=0x0F
#define Clr_Lnibble(reg)                  reg&=0xF0
#define Get_Lnibble(reg)                  (reg)&0x0F
#define Toggle_Lnibble(reg)               reg^=0x0F
#define Assign_Lnibble(reg,value)         reg = (reg&0xF0)|(value&0x0F)

//****************************************************

#define Set_Hnibble(reg)                  reg|=0xF0
#define Clr_Hnibble(reg)               	  reg&=0x0F
#define Get_Hnibble(reg)                  (reg&(0xF0))>>4
#define Toggle_Hnibble(reg)               reg^=0xF0
#define Assign_Hnibble(reg,value)         reg = (reg&0x0F)|((value&0x0F)<<4)

//****************************************************

//shift right and shift left
#define Rotate_Right(reg,no)               reg=(reg<<(8*sizeof(reg)-(no)))|(reg>>(no))
#define Rotate_Left(reg,no)               reg=(reg<<(no))|(reg>>(8*sizeof(reg)-(no)))

//****************************************************

#define print(reg)            printf(#reg)
#define concatination(x,y)    (x##y)

//*****************************************************

#endif /* UTILS_H_ */
