#pragma once
#include "stdafx.h"
#include <fcntl.h>                // Needed for SPI port
#include <sys/ioctl.h>            // Needed for SPI port
#include <linux/spi/spidev.h>     // Needed for SPI port





enum SpiMode{
    MODE_0 = 0,
    MODE_1,
    MODE_2,
    MODE_3,
};

int configSPI(SpiMode mode);
void spiWR(unsigned char* TxData, unsigned char* RxData, int len);
