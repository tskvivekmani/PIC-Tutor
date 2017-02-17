//Address reference
//https://electrosome.com/wp-content/uploads/2012/05/Time-Keeper-Registers.png

//https://electrosome.com/wp-content/uploads/2012/05/Reading-Data-from-DS1307.jpg
unsigned short read_ds1307(unsigned short address)
{
  unsigned short temp;
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(address);
  I2C1_Repeated_Start();
  I2C1_Wr(0xD1);
  temp = I2C1_Rd(0);
  I2C1_Stop();
  return(temp);
}
 
//https://electrosome.com/wp-content/uploads/2012/05/data-write.png
void write_ds1307(unsigned short address, unsigned short w_data)
{
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(address);
  I2C1_Wr(w_data);
  I2C1_Stop();
}

unsigned char BCD2UpperCh(unsigned char bcd){
  return ( (bcd>>4) +'0');
}

unsigned char BCD2LowerCh(unsigned char bcd){
  return ( (bcd & 0x0F) +'0');
}

int Binary2BCD(int a){
  int t1,t2;
  t1 = a%10;
  t1 = t1 & 0x0F;
  a = a/10;
  t2 = a%10;
  t2 = 0xF0 & t2;
  t1 = t1 | t2;
  return t1;
}

int BCD2Binary(int a){
  int r,t;
  t = a & 0x0F;
  r = t;
  a = 0xF0 & a;
  t = a >> 4;
  t = 0x0F & t;
  r = t*10 + r;
  return r;
}

char* getTime(){
  char time[] = "00:00:00 AM";
  short fullHr = read_ds1307(2);
  short hr = fullHr & 0b00011111;
  short ap = fullHr & 0b00100000;
  short min = read_ds1307(1);
  short sec=read_ds1307(0);
  time[0] = BCD2UpperCh(hr);
  time[1] = BCD2LowerCh(hr);
  time[3] = BCD2UpperCh(min);
  time[4] = BCD2LowerCh(min);
  time[6] = BCD2UpperCh(sec);
  time[7] = BCD2LowerCh(sec);
  time[10] = 'M';
  if(ap)
    time[9] = 'P';
  else
    time[9] = 'A';
  return time;
}

char* getDate(){
  char date[] = "00/00/00";
  short day=read_ds1307(4),month=read_ds1307(5),year=read_ds1307(6);
  date[0] = BCD2UpperCh(day);
  date[1] = BCD2LowerCh(day);
  date[3] = BCD2UpperCh(month);
  date[4] = BCD2LowerCh(month);
  date[6] = BCD2UpperCh(year);
  date[7] = BCD2LowerCh(year);
  return date;
}

void main(){
  I2C1_Init(100000);
  Lcd_out(1,1,"Time:");
  Lcd_out(1,6,getTime());
  Lcd_out(2,1,"Date:");
  Lcd_out(2,1,getDate());
}
