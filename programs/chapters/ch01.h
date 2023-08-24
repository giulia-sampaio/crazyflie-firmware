#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led(LED_RED_R, !false)
DigitalOut led(LED_RED_L, !false)
DigitalOut led(LED_GREEN_R, !false)
DigitalOut led(LED_GREEN_L, !false)

// Define all motors as PWM objects


// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {

    }
}
