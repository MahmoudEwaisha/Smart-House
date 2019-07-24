/*
 * DELAY.c
 *
 *  Created on: Aug 5, 2017
 *      Author: Mahmoud Ewaisha
 */


#include "types.h"

extern void Delay (u32 time)
{
  volatile u32 i ;
  volatile  u32 count;
  // count = ((time*1000)-36)/10.8;
   count = ((time*1000)-19)/10.7;
	for (i=0;i<count;i++)
	{
		asm("nop");
	}


	/*	u32 i , count ;
		count=(u32)(((1000.0*time)-0.51273)/2.679309);
		for (i=0;i<count;i++)
		{
			asm("nop");
		}
*/

}
/*
void Delay (u32 delay)
{
	volatile u32 i;
	for (i=0; i< delay*1000; i++)
	{
		asm("nop");  //assembly "no operation"
	}
}*/
