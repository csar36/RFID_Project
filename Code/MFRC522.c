#include "stdafx.h"

#include "MFRC522.h"

int SPI_init()
{
	
	int chan = 0;
	int speed = 6000000; //500000 Hz
	int mode = 0;//1
	int ret;
	
	if(wiringPiSetup() == -1) return -1;
	
	ret = wiringPiSPISetupMode (chan, speed, mode);
	return ret;
	
}


uint8_t readRegister(uint8_t adr)
{
		adr|=read;
		uint8_t Buffer[]={0x00,0x00};
		
		Buffer[0]=adr;
		Buffer[1]=adr;

		wiringPiSPIDataRW(0,Buffer,2);
		
		return Buffer[1];
}
//passt
void writeRegister(uint8_t adr, uint8_t data)
{
	adr &= 0x7F;
	uint8_t Buffer[]={0x00,0x00};
	
	Buffer[0]=adr;
	Buffer[1]=data;
	

	
	wiringPiSPIDataRW(0,Buffer,2);
	
	
}
//passt

void readFIFO(uint8_t* data,uint8_t anz)
{ 
	int adr = FIFODataReg;
	adr|=read;
	uint8_t Buffer[]={0x00,0x00};
	
	Buffer[0]=adr;
	Buffer[1]=0;

	wiringPiSPIDataRW(0,Buffer,2);
	Buffer[0]=adr;
	for(int i=0;i<anz;i++)
	{
		wiringPiSPIDataRW(0,Buffer,2);
		data[i]=Buffer[1];
		Buffer[0]=adr;	
	}
	
}


void writeFIFO(uint8_t* data, uint8_t anz)
{
	uint8_t adr = FIFODataReg;
	uint8_t Buffer[65];									//kann nur max 65 bytes gr0ß sein
	adr &= 0x7F;
	Buffer[0]=adr;
	for(int i = anz+1;i>0;i--)
	{
		Buffer[i] = data[i-1]; 
	}
	
	
	wiringPiSPIDataRW(0,Buffer,anz+1);
		//(channel, data*, len)
}
