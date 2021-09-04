#include "stdafx.h"


enum TimerOption
{
   SEC = 0,
   MSEC,
   USEC,
};

void delay(uint32_t duration, TimerOption option);
