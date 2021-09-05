#include "MFRC522.h"

int writeRegister(unsigned char address, unsigned char data)                   
{
    unsigned char adr = address;
    adr &= 0x7F; 

    unsigned char TxData[2] = {adr, data};
    unsigned char RxData[2] = {0,0};  //can be ignored

    spiWR(TxData, RxData, 2);

    return 0;               //return value could be used for error handling
  
}

unsigned char readRegister(unsigned char address)
{
    unsigned char adr = address;
    adr |= 0x80;                        //read Modus

    unsigned char TxData[2]={adr, 0};
    unsigned char RxData[2]={0,0};

    spiWR(TxData, RxData, 2);

    return RxData[1];
}

int writeFIFO(unsigned char* data, unsigned char anz)
{
    unsigned char adr;
    adr = FIFODataReg;
    adr &= 0x7F;                        //prepare address for write
    unsigned int FifoLevel;
    unsigned char* RxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));
    unsigned char* TxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));
  

    FifoLevel = readRegister(FIFOLevelReg);

    if((64-FifoLevel) < anz)
    {
        printf("zu wenig Platz im FIFO Speicher\n Bytes stored in FIFO: %X \n", FifoLevel);
        return -1;
    }


    *(TxData) = adr;
    for(int i = 0; i<anz;i++)
    {
        *(TxData+i+1) = *(data+i);
    }

    spiWR(TxData, RxData, anz+1);


    free(RxData);
    free(TxData);
    RxData = NULL;
    TxData = NULL;

    return 0;
}

int readFIFO(unsigned char* FifoData, unsigned char anz)
{
    unsigned char adr = FIFODataReg;
    adr |= 0x80;

    unsigned char* RxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));
    unsigned char* TxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));

    for(int i = 0; i<=anz; i++)
    {
        *(TxData+i) = adr;
        *(RxData+i) = 0;
    }

    spiWR(TxData, RxData, anz+1);

    for(int i = 0; i<anz; i++)
    {
        *(FifoData + i) = *(RxData+i+1);
    }


    free(RxData);
    free(TxData);
    RxData = NULL;
    TxData = NULL;

    return 0;
}

int flushFIFO()
{
    writeRegister(FIFOLevelReg, 0x80);
    return 0;
}



void mfrcReset()
{
    writeRegister(CommandReg, SoftReset);

    do{
        delay(150, MSEC);
    }while((readRegister(CommandReg) & 1 << 4));
}

void AntennaOn()
{
    unsigned char value = readRegister(TxControlReg);

    if ((value & 0x03) != 0x03) {
		writeRegister(TxControlReg, value | 0x03);
	}
}

int mfrcInit()
{
    mfrcReset();
    writeRegister(TxModeReg, 0);
    writeRegister(RxModeReg, 0);

    writeRegister(ModWidthReg, 0x26);

    writeRegister(TModeReg, 0x80);
    writeRegister(TPrescalerReg, 0xA9);
    writeRegister(TReload_Hi, 0x03);
    writeRegister(TReload_Lo, 0xE8);

    writeRegister(TxASKReg, 0x40);
    writeRegister(ModeReg, 0x3D);

    AntennaOn();

    return 0;
}

int mfrcSelftest()
{
    mfrcReset();                                            //perform Soft-Reset    
    unsigned char Nullen[25];                               //Fill FIFO with 25 times 0

    for(int i = 0; i < 25; i++)
    {
        Nullen[i] = 0;
    }

    flushFIFO();                                            //delete FIFO

    writeFIFO(Nullen, 25);                                  //write zeroes to fifo

    writeRegister(CommandReg, Mem);                         //

    writeRegister(AutoTestReg, 0x09);

    writeRegister(FIFODataReg, 0);

    writeRegister(CommandReg, CalcCRC);

    delay(300, MSEC);


    writeRegister(CommandReg, IDLE);
    writeRegister(AutoTestReg, 0);  
    unsigned char FIFOData[64];

    readFIFO(FIFOData, 64);
printf("*******************FIFO OUTPUT - SELFTEST**********************");
for(int i = 0; i < 64; i++)
{
    if((i % 8 == 0))
    {
        printf("\n %X \t  ", FIFOData[i]);
    }
    else
    {
        printf("%X \t  ", FIFOData[i]);
    }
}

printf("\n ***************************************************************\n");
    

    return 0;
}