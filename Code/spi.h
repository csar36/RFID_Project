#pragma once
#include "stdafx.h"
#include <fcntl.h>                // Needed for SPI port
#include <sys/ioctl.h>            // Needed for SPI port
#include <linux/spi/spidev.h>     // Needed for SPI port

int configSPI(int mode);
void spiWR(int fd, unsigned char* TxData, unsigned char* RxData, int len);
