#include "crazyflie.h"
#include "mbed.h"

// Define motor as PWM output object
PwmOut motor(MOTOR1);

// Definição das constantes usadas
float a = 0;
float b = 0;
float c = 0;

// Variável para armazenar PWM usado
float PWM = 0;

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega) {
  PWM = a * pow(omega, 2) + b * omega + c;
  return PWM;
}

// Main program
int main() {
  // Set PWM frequency to 500 Hz
  motor.period(1.0 / 500.0);
  // Turn on motor with 1.000 rad /s for 0.5s
  motor = control_motor(1000.0);
  wait(0.5);
  // Turn off motor
  motor = 0.0;
  // End of program
  while (true) {
  }
}
