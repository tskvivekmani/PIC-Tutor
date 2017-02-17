//Address reference
//https://electrosome.com/wp-content/uploads/2012/05/Time-Keeper-Registers.png

//https://electrosome.com/wp-content/uploads/2012/05/Reading-Data-from-DS1307.jpg
unsigned short read_ds1307(unsigned short address)
{
  unsigned short temp
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

