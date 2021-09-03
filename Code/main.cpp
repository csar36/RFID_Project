#include "stdafx.h"
#include "spi.h"
#include "gpio.h"

int main()
{
    int retVel;
    int speed, mode, fd;
    unsigned char TxData[]= {0, 0, 0};
    unsigned char RxData[]= {0, 0, 0};


    //Daten präperierien
    for(int i =0 ;i < 3; i++)
    { 
      TxData[i] = 0xEE;
     // printf("Data %d: %u \n",i, TxData[i]);
    }
    //printf("%u \t %u \t \n", TxData[0], TxData[1]);
    fd = configSPI(0);
    spiWR(fd, TxData, RxData, 3);
    printf("%u \t %u \t %u \t \n", TxData[0], TxData[1], TxData[2]);
    printf("%u \t %u \t %u \t \n", RxData[0], RxData[1], RxData[2]);
	initGpio(21,1);
	setGpio(21,1);



  return 0;
}

