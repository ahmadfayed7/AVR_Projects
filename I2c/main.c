/*
 */

#include <avr/io.h>
#include <util/delay.h>
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave
void TWI_init ()
{

    TWBR =2;
    TWSR =0;
    TWAR =0x01;
    TWCR = 1<<TWEN;
}
void TWI_start()
{
    TWCR =(1<<TWINT) | (1<<TWSTA) |(1<<TWEN);
    while(!(TWCR &(1<<TWINT)));
}
void TWI_stop()
{
    TWCR =(1<<TWINT) | (1<<TWSTO) |(1<<TWEN);
   // while(!(TWCR &(1<<TWINT)));
}
void TWI_write(unsigned char data)
{
 TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
   while(!(TWCR &(1<<TWINT)));
}
unsigned char read_with_ack ()
{
 TWCR = (1 << TWINT) | (1 << TWEN) |(1 << TWEA);

 while(!(TWCR &(1<<TWINT)));
   return TWDR;
}
unsigned char read_without_ack ()
{
   TWCR = (1 << TWINT) | (1 << TWEN);
    while(!(TWCR &(1<<TWINT)));
   return TWDR;
}
void EEPROM_init()
{
    TWI_init();
}
unsigned char TWI_Get_Status(void)
{
    unsigned char status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
unsigned char EEPROM_write(unsigned int addr,unsigned char data)
{
   TWI_start();
   if(TWI_Get_Status()!=TW_START)
     return 0;
   TWI_write((unsigned char)(0xA0 | ((addr & 0x0700)>>7)));
    if(TWI_Get_Status()!=TW_MT_SLA_W_ACK)
     return 0;
   TWI_write((unsigned char)addr);
   if(TWI_Get_Status()!=TW_MT_DATA_ACK)
     return 0;
    TWI_write(data);
     if(TWI_Get_Status()!=TW_MT_DATA_ACK)
     return 0;
    TWI_stop();
    return 1;

}
unsigned char EEPROM_read(unsigned int addr,unsigned char * data)
{

TWI_start();
if(TWI_Get_Status()!=TW_START)
     return 0;
 TWI_write((unsigned char)(0xA0 | ((addr & 0x0700)>>7)));
    if(TWI_Get_Status()!=TW_MT_SLA_W_ACK)
     return 0;

TWI_write((unsigned char)addr);
   if(TWI_Get_Status()!=TW_MT_DATA_ACK)
     return 0;

     TWI_start();
if(TWI_Get_Status()!=TW_REP_START)
     return 0;

 TWI_write((unsigned char)(0xA0 | ((addr & 0x0700)>>7 )|1));
    if(TWI_Get_Status()!=TW_MT_SLA_R_ACK)
     return 0;

 *data =read_without_ack();
  if(TWI_Get_Status()!=TW_MR_DATA_NACK)
     return 0;

   TWI_stop();
   return 1;

}
int main(void)
{

   unsigned char val = 0;

	DDRD  = 0xFF;
	PORTD = 0x00;
    EEPROM_init();
    EEPROM_write(0x0311,0x01);
   _delay_ms(10);
   EEPROM_read(0x0311,&val);
    while(1)
    {
       PORTD = val;
    }

    return 0;
}
