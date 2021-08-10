#ifndef GPIO_H
#define GPIO_H

#define MAX_BUF        64

/****** gpio.h/PinValue
 *  NAME
 *    PinValue -- Alternatives for 0 and 1
******
*/
enum PinValue{
    fLOW  = 0,
    fHIGH = 1,
};

/****** gpio.h/PinDirection
 *  NAME
 *    PinDirection -- Alternatives for "in" and "out"
******
*/
enum PinDirection {
    PIN_IN  = 0,
    PIN_OUT = 1,
};

/****** gpio.h/GPIOPin
 *  NAME
 *    GPIOPin -- This is an enum to match the names to the gpio pins of the beagle bone black.
 *  NOTE
 *    The BeagleBone Black got two pin sockets P9 and P8
 *    In the enum definition the GPIO pins are sorted by their socket
******
*/
enum GPIOPin {
    GPIO_4 = 4,
    GPIO_5 = 5,
    GPIO_6 = 6,
    GPIO_22 = 22,
    GPIO_23 = 23,
    GPIO_24 = 24,
    GPIO_25 = 25,
    GPIO_26 = 26,
    GPIO_27 = 27,
};

 /****c* gpio.h/GPIO
  *  NAME
  *    GPIO -- This class provides operations to controll the gpio pins on the beagelbone black.
  *  DESCRIPTION
  *    The class GPIO is an interface between the developed software and the beaglebone black.
  *    It provides operations to controll the gpio pins of the beaglebone black. 
  *    Furthermore it provides attributes with the values of last known status of the gpio.
  *  METHODS
  *    gpioExport()
  *    gpioUnexport()
  *    gpioSetDirection()
  *    gpioGetDirection()
  *    gpioSetValue()
  *    gpioGetValue()
  *    gpioSetEdge()
  *    gpioActiveLow()
  *  ATTRIBUTES
  *     GPIOPin          - gültige Werde sind in GPIOPin aufgelistet
  *     directionPath    
  *     valuePath        
  *     edgePath         
  *     activelowPath     
  *  NOTES
  *     edge und activelow wurden bisher nicht benötigt. Werden diese Optionen dennoch irgendwann mal benötigt, müssen, zum auslesen, passende Methoden geschrieben werden
  ******
  * 
  */ 
class GPIO
{



public:
    GPIO();
    GPIO(GPIOPin _m_pin);
    

   
    GPIOPin m_pin;


    void gpioExport();
    void gpioUnexport();
    void gpioSetPin(GPIOPin _m_pin);
    GPIOPin gpioGetPin();
    bool gpioSetDirection(PinDirection _direction);
    bool gpioGetDirection();
    bool gpioSetValue(PinValue _value);
    bool gpioGetValue();
    int gpioSetEdge(char _edge);
    int gpioActiveLow(unsigned int _activeLow);

private:

    std::string directionPath;
    std::string valuePath;
    std::string edgePath;
    std::string activelowPath;
    std::string exportPath;
    std::string unexportPath;

    
};

#endif // GPIO_H
