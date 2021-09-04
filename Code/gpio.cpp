#include "gpio.h"





int initGpio(int gpioNum, GPIODirection direction)
{
    std::string exportCmd;
    std::string directionCmd;
    std::string exportPath =  "/sys/class/gpio/export";
    std::string path =  "/sys/class/gpio/gpio" + std::to_string(gpioNum);

    if(opendir(path.c_str()) == NULL)
    {
        exportCmd = "echo " + std::to_string(gpioNum) + " > " + exportPath;
        system(exportCmd.c_str());
    }
    

    if(direction)
    {
        directionCmd = "echo out > " + path + "/direction";
        system(directionCmd.c_str());
    }
    else
    {
        directionCmd = "echo in > " + path + "/direction";
        system(directionCmd.c_str());
    }

    return 0;           //could be used for error handling
}


int setGpio(int gpioNum, GPIOEnable value)
{
    std::string valueCmd;
    std::string path =  "/sys/class/gpio/gpio" + std::to_string(gpioNum);

    if(opendir(path.c_str()) == NULL)
    {
        printf("GPIOPin existiert nicht oder wurde nicht exportiert!! \n");
        return 1;
    }

    if(value)
    {
        valueCmd = "echo 1 > /sys/class/gpio/gpio" + std::to_string(gpioNum) + "/value";
        system(valueCmd.c_str());
    }
    else
    {
        valueCmd = "echo 0 > /sys/class/gpio/gpio" + std::to_string(gpioNum) + "/value";
        system(valueCmd.c_str());
    }
    return 0;
}