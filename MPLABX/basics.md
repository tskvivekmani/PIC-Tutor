# Getting started with MPLAB XC8
@ LCD Commands
  (Refr: https://electrosome.com/lcd-pic-mplab-xc8/)

 + Lcd_Clear() : To clear the display.
 + Lcd_Set_Cursor(int row, int column) : This function is used to set row and column of the cursor on the LCD screen. By using this function we can change the position of the character or string displayed by following functions.
 + Lcd_Write_Char(char) : To write a character to LCD on the current position.
 + Lcd_Write_String(char *string) : To write string to LCD on the current position.
 + Lcd_Shift_Right() : To shift contents on the LCD screen Right once without changing the data in the Display RAM.
 + Lcd_Shift_Left() : To shift contents on the LCD screen Left once without changing the data in the Display RAM.
