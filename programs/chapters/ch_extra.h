#include "crazyflie.h"
#include "mbed.h"

#define Fs3 369.994385
#define Cs5 1108.730591
#define B4 987.766602
#define Fs4 739.988831
#define D3 293.664734
#define D5 1174.659058

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Main program
int main() {
  // Turn motor on (20% power) and off every second
  while (true) {

    motor1.period(1.0 / Fs3);
    motor1 = 0.1;
    wait(0.6);
    motor1 = 0;

    motor2.period(1.0 / Cs5);
    motor2 = 0.1;
    wait(0.15);
    motor2 = 0;
 
    motor3.period(1.0 / B4);
    motor3 = 0.1;
    wait(0.15);
    motor3 = 0;

    motor4.period(1.0 / Cs5);
    motor4 = 0.1;
    wait(0.3);
    motor4 = 0;

    motor1.period(1.0 / Fs4);
    motor1 = 0.1;
    wait(0.3);
    motor1 = 0;

    motor2.period(1.0 / D3);
    motor2 = 0.1;
    wait(0.6);
    motor2 = 0;

    motor3.period(1.0 / D5);
    motor3 = 0.1;
    wait(0.15);
    motor3 = 0;

    motor4.period(1.0 / Cs5);
    motor4 = 0.1;
    wait(0.15);
    motor4 = 0;

    motor1.period(1.0 / D5);
    motor1 = 0.1;
    wait(0.15);
    motor1 = 0;

    motor2.period(1.0 / Cs5);
    motor2 = 0.1;
    wait(0.3);
    motor2 = 0;

    motor3.period(1.0 / B4);
    motor3 = 0.1;
    wait(0.3);
    motor3 = 0;
  }
}