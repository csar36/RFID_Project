#include "stdafx.h"
#include "spi.h"
#include "gpio.h"
#include "timer.h"

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
	
	for(int i = 0; i< 10; i++)
	{
		setGpio(21,1);
		delay(2, sec);
		setGpio(21,0);
		delay(500, msec);
	}




  return 0;
}

