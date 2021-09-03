#include "stdafx.h"

#define GPIO_PATH "/sys/class/gpio/"

int initGpio(int gpioNum, bool direction);
int setGpio(int gpioNum, bool value);
