#include "stdafx.h"
#include "MFRC522.h"

using std::cout;
using std::endl;


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
void allocateData(uint8_t** data, uint8_t anz)
{
	*data = (uint8_t*) malloc(anz*sizeof(uint8_t));
}

int main()
{

	int ret;
	int adr;
	uint8_t anz;
	int value;
	uint8_t* data;
	uint8_t* data_read;

	ret = SPI_init();
	if(ret == -1)
	{
		printf("Fehler bei der Initialiserung der SPI");
	}



	anz = 30;

	allocateData(&data, anz);
	allocateData(&data_read, anz);

	for(int i =0;i < 30;i++)
	{	
		if(i % 3 == 0)
		{
			*(data+i) = 0xFF;
		}
		else{
			*(data+i) = 0x00;
		}
		
	}

	writeFIFO(data, anz);
	readFIFO(data_read, anz);
	

	for(int i =0 ;i<anz;i++)
	{
		cout << static_cast<int>(*(data_read+i)) << endl;
	}

	free(data);
	free(data_read);
	data = NULL;
	data_read = NULL;

    return 0;
}

