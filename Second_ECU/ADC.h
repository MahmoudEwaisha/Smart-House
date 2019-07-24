/*
 * ADC.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Mahmoud Khaled
 */

#ifndef ADC_H_
#define ADC_H_


#define ADMUX		*((u8*)(0x27))
#define	ADCSRA		*((u8*)(0x26))
#define	ADCH		*((u8*)(0x25))
#define	ADCL		*((u8*)(0x24))
#define SFIOR    	*((u8*)(0x50))

/*ADC initialization*/
extern void ADC_voidInitializeADC (void);


/*ADC READ*/
extern u8 ADC_u8ReadADC (void);


#endif /* ADC_H_ */
