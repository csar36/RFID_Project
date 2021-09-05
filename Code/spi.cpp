#include "spi.h"


static const uint8_t     spiBPW   = 8 ;
static const uint16_t    spiDelay = 0 ;
//static const uint8_t     LSBFirst = 1 ;
static const uint32_t    speed = 100000;


int configSPI(SpiMode _mode)
{
  int fd;
  int mode = (int)_mode;
    if ((fd = open ("/dev/spidev0.0", O_RDWR)) < 0)
    {
      printf("Fehler");
    }

  if (ioctl (fd, SPI_IOC_WR_MODE, &mode)            < 0)
    {
      printf("Fehler");
    }
 if (ioctl (fd, SPI_IOC_RD_MODE, &mode)            < 0)
    {
      printf("Fehler");
    }
  
  if (ioctl (fd, SPI_IOC_WR_BITS_PER_WORD, &spiBPW) < 0)
    {
      printf("Fehler");
    }


  if (ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)   < 0)
    {
      printf("Fehler");
    }

  spiDriver = fd;
  return fd;
}

void spiWR(int fd, unsigned char* TxData, unsigned char* RxData, int len)
{
  struct spi_ioc_transfer spi ;

  memset (&spi, 0, sizeof (spi)) ;

  spi.tx_buf        = (unsigned long)TxData;
  spi.rx_buf        = (unsigned long)RxData;
  spi.len           = len ;
  spi.delay_usecs   = spiDelay ;
  spi.speed_hz      = speed;
  spi.bits_per_word = spiBPW ;
  spi.cs_change     = 0;

  if((ioctl(fd, SPI_IOC_MESSAGE(1), &spi)<0))
  {
    printf("Fehler");
  }
}
