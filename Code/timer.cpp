#include "timer.h"

void delay(uint32_t duration, TimerOption unit)
{   
    clock_t start_t = clock();
    clock_t diff;
    double time = 0;

    do{
        diff = clock() - start_t;
        time = (double) diff / CLOCKS_PER_SEC;

        switch(unit)
        {
            case SEC: break;
            case MSEC:  time = time * pow(10,3); break;
            case USEC: time = time * pow(10,6); break; 
            default: std::cout << "TIMER_UNIT_ERROR" << std::endl; break;
        }
    }while(time < duration);
 
    return;
    
}