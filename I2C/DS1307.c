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
