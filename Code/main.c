
#include "stdafx.h"
#include "MFRC522.h"


/*
void AntennaOn()
{
	uint8_t value = MFRC_GET(TxControlReg);
	if((value & 0x03 != 0x03))						//prüfen ob untere 2 Bits gesetzt sind
	{
		MFRC_PUT(TxControlReg, value | 0x03);		//Wenn nicht, Bits setzen -> Antenna on
	}

}


void AntennaOff()
{
	uint8_t value = MFRC_GET(TxControlReg);

	if(value & 0x03 != 0)							//Sofern unteren 2 Bits nicht auf 0 gesetzt sind
	{
		MFRC_PUT(TxControlReg, value & ~0x03);		//werden diese hier auf 0 gesetzt
	}
	

}
*/
void allocateData(uint8_t* data, uint8_t anz)
{
	data = (uint8_t*) malloc(anz*sizeof(uint8_t));
}




int main()
{

	int ret;
	int adr;
	uint8_t anz;
	int value;


	ret = SPI_init();
	if(ret == -1)
	{
		printf("FEhler");
	}
	uint8_t* data;
	uint8_t* data_read;


	anz = 30;

	allocateData(data, anz);
	allocateData(data_read, anz);


	for(int i =0;i < 30;i++)
	{
		*(data+i) = 0xFF;
	}
	
	writeFIFO(data, anz);
	readFIFO(data_read, anz);


	for(int i =0 ;i<anz;i++)
	{
		printf("Value: %u \n", *(data_read+i));
	}


    return 0;
}

