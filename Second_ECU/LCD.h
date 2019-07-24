/*
 * LCD.h
 *
 *  Created on: Dec 31, 2016
 *      Author: Mahmoud Khaled
 */

#ifndef LCD_H_
#define LCD_H_

u8 string_cmp(u8 *str1, u8 *str2, u8 size1, u8 size2);
extern void LCD_WriteCommand (u8 command);
extern void LCD_WriteData (u8 data);
extern void LCD_Init(void);
void LCD_Display(u8 str1[], u8 str2[], u8 size);


#endif /* LCD_H_ */
