# Lcd_Init();
This function initializes the LCD module connected to the above defined pins of the PIC Microcontroller.

#Lcd_Out(char row, char column, char *text);
This functions prints the text (string) in a particular row and column.

#void Lcd_Out_Cp(char *text);
This function prints the text (string) in the current cursor position. When we write data to LCD Screen, it automatically increments the cursor position.

#void Lcd_Chr(char row, char column, char out_char);
It prints the character (out_char) in the specified row and column of the LCD Screen.

#void Lcd_Chr_Cp(char out_char);
It prints the character (out_char) in the current cursor position.

#void Lcd_Cmd(char out_char);
This function is used to send commands to LCD. You can use any one of the following constants as command.

 - _LCD_TURN_ON – Turns ON the LCD Display.
 - _LCD_TURN_OFF – Turns OFF the LCD Display.
 - _LCD_FIRST_ROW – Moves the cursor to the first row.
 - _LCD_SECOND_ROW – Moves the cursor to the the second row.
 - _LCD_THIRD_ROW – Moves the cursor to the third row.
 - _LCD_FOURTH_ROW – Moves the cursor to the fourth row.
 - _LCD_CLEAR – Clears the LCD Display.
 - _LCD_CURSOR_OFF – Turns ON the cursor.
 - _LCD_UNDERLINE_ON – Turns ON the cursor underline.
 - _LCD_BLINK_CURSOR_ON – Turns ON the cursor blink.
 - _LCD_MOVE_CURSOR_LEFT – Moves cursor LEFT without changing the data.
 - _LCD_MOVE_CURSOR_RIGHT – Moves cursor RIGHT without changing the data.
 - _LCD_SHIFT_LEFT – Shifts the display left without changing the data in the display RAM.
 - _LCD_SHIFT_RIGHT – Shifts the display right without changing the data in the display RAM.
 - _LCD_RETURN_HOME – Returns the cursor and shifted display to Home position.
