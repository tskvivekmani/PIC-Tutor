// LCD Module connections
sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D4 at RB4_bit;
// End LCD module connections
// LCD Pin direction
sbitLCD_RS_Direction at TRISB2_bit;
sbitLCD_EN_Direction at TRISB3_bit;
sbit LCD_D7_Direction at TRISB7_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB4_bit;
// End of LCD Pin direction
void main() {
    lcdInit();
    Delay_ms(1000);
    while(1){
        start();
        Delay_ms(1000);
    }
}
//Code to initialize LCD during start up
void lcdInit(){
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
}

void start(){
    Lcd_Out(1,1,”   Welcome to   ”);
    char *name = ” TSK India Elc. ”;
    Lcd_Cmd(_LCD_SECOND_ROW);
    for(int i=0;i<16;i++)
    {
        Lcd_Chr_Cp(name[i]);
        Delay_ms(500);
    }
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_RETURN_HOME);
}
