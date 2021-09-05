#include "MFRC522.h"



int writeRegister(int fd, unsigned char address, unsigned char data)                   
{
    unsigned char adr = address;
    adr &= 0x7F; 

    unsigned char TxData[2] = {adr, data};
    unsigned char RxData[2] = {0,0};  //can be ignored

    spiWR(fd, TxData, RxData, 2);

    return 0;               //return value could be used for error handling
  
}

unsigned char readRegister(int fd, unsigned char address)
{
    unsigned char adr = address;
    adr |= 0x80;                        //read Modus

    unsigned char TxData[2]={adr, 0};
    unsigned char RxData[2]={0,0};

    spiWR(fd, TxData, RxData, 2);

    return RxData[1];
}

int writeFIFO(int fd, unsigned char* data, unsigned char anz)
{
    unsigned char adr;
    adr = FIFODataReg;
    adr &= 0x7F;                        //prepare address for write
    unsigned int FifoLevel;
    unsigned char* RxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));
    unsigned char* TxData = (unsigned char*)malloc((anz+1)*sizeof(unsigned char));
  

    FifoLevel = readRegister(fd, FIFOLevelReg);

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

    spiWR(fd, TxData, RxData, anz+1);
    FifoLevel = readRegister(fd, FIFOLevelReg);
    printf("Okay ---> %X\n", FifoLevel);

    free(RxData);
    free(TxData);
    RxData = NULL;
    TxData = NULL;

    return 0;
}

int readFIFO(int fd, unsigned char* FifoData, unsigned char anz)
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

    spiWR(fd, TxData, RxData, anz+1);

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

int flushFIFO(int fd)
{
    writeRegister(fd, FIFOLevelReg, 0x80);
    return 0;
}



