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

}

int readFIFO(int fd, unsigned char* FifoData, unsigned char anz)
{


}

