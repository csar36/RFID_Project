#include "stdafx.h"

#define GPIO_PATH "/sys/class/gpio/"

enum GPIOEnable{
    LOW = 0,
    HIGH,
};

enum GPIODirection{
    INPUT = 0,
    OUTPUT,
};

int initGpio(int gpioNum, GPIODirection direction);
int setGpio(int gpioNum, GPIOEnable value);
