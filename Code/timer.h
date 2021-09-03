#include "stdafx.h"


enum TimerOption
{
   sec = 0,
   msec,
   usec,
};

void delay(uint32_t duration, TimerOption option);
