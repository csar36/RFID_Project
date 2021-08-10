//Set SPI data mode
//	BCM2835_SPI_MODE0 = 0,  // CPOL = 0, CPHA = 0, Clock idle low, data is clocked in on rising edge, output data (change) on falling edge
//	BCM2835_SPI_MODE1 = 1,  // CPOL = 0, CPHA = 1, Clock idle low, data is clocked in on falling edge, output data (change) on rising edge
//	BCM2835_SPI_MODE2 = 2,  // CPOL = 1, CPHA = 0, Clock idle high, data is clocked in on falling edge, output data (change) on rising edge
//	BCM2835_SPI_MODE3 = 3,  // CPOL = 1, CPHA = 1, Clock idle high, data is clocked in on rising, edge output data (change) on falling edge

//	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);		//(SPI_MODE_# | SPI_CS_HIGH)=Chip Select active high, (SPI_MODE_# | SPI_NO_CS)=1 device per bus no Chip Select



#include "PISPI.h"
//passt
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

//passt
unsigned char MFRC_GET(char adr)
{
		adr|=read;
		unsigned char Buffer[]={0x00,0x00};
		
		Buffer[0]=adr;
		Buffer[1]=adr;

		wiringPiSPIDataRW(0,Buffer,2);
		
		return Buffer[1];
}
//passt
void MFRC_PUT(char adr, char data)
{
	adr &= 0x7F;
	unsigned char Buffer[]={0x00,0x00};
	
	Buffer[0]=adr;
	Buffer[1]=data;
	

	
	wiringPiSPIDataRW(0,Buffer,2);
	
	
}
//passt
void MFRC_WRITE_FIFO(char* data, char anz)
{
	int adr = FIFODataReg;
	unsigned char Buffer[65];									//kann nur max 65 bytes gr0ß sein
	adr &= 0x7F;
	Buffer[0]=adr;
	for(int i = anz+1;i>0;i--)
	{
		Buffer[i] = data[i-1]; 
	}
	
	
	wiringPiSPIDataRW(0,Buffer,anz+1);
		//(channel, data*, len)
}


//passt
void MFRC_READ_FIFO(char* data,char anz)
{ 
	int adr = FIFODataReg;
	adr|=read;
	unsigned char Buffer[]={0x00,0x00};
	
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



