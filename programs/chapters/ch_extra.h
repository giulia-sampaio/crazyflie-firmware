#include "mbed.h"
#include "crazyflie.h"

# define F5 1479.977539
# define D5 1174.659058
# define B5 1975.533325
# define E5 1318.510254
# define C5 1108.730591


// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);

// Main program
int main()
{
    // Turn motor on (20% power) and off every second
    while(true) 
    {
        motor1.period(1.0/F5);
        motor1 = 0.2;
        wait(0.5);
    }
}