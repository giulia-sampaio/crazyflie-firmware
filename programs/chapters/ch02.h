#include "crazyflie.h"
#include "mbed.h"

// Define motor as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Definição dos parâmetros usados para determinar o PWM relativo a cada
// velocidade
// float a = 1.4183e-07;
// float b = 2.2982e-10;
// float c = 0;

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega) {
  float PWM = a * pow(omega, 2) + b * omega + c;
  return PWM;
}

// Main program
int main() {

  // Set PWM frequency to 500 Hz
  //   motor1.period(1.0 / 500.0);
  //   motor2.period(1.0 / 500.0);
  //   motor3.period(1.0 / 500.0);
  //   motor4.period(1.0 / 500.0);

  // Atividades capítulos 2 e 3
  // Turn on motor with 1.000 rad /s for 5s
  //   motor1.write(control_motor(1000.0));
  //   motor2.write(control_motor(1000.0));
  //   motor3.write(control_motor(1000.0));
  //   motor4.write(control_motor(1000.0));
  //   wait(7);

  // Turn off motor
  //   motor1 = 0.0;
  //   motor2 = 0.0;
  //   motor3 = 0.0;
  //   motor4 = 0.0;
  //   wait(5);

  // Turn on motor with 1.200 rad /s for 0.5s
  //   motor1.write(control_motor(1200.0));
  //   motor2.write(control_motor(1200.0));
  //   motor3.write(control_motor(1200.0));
  //   motor4.write(control_motor(1200.0));
  //   wait(7);

  // Turn off motor
  //   motor1 = 0.0;
  //   motor2 = 0.0;
  //   motor3 = 0.0;
  //   motor4 = 0.0;
  //   wait(5);

  // Turn on motor with 1.400 rad /s for 5s
  //   motor1.write(control_motor(1400.0));
  //   motor2.write(control_motor(1400.0));
  //   motor3.write(control_motor(1400.0));
  //   motor4.write(control_motor(1400.0));
  //   wait(7);

  // Turn off motor
  //   motor1 = 0.0;
  //   motor2 = 0.0;
  //   motor3 = 0.0;
  //   motor4 = 0.0;
  //   wait(5);

  // Turn on motor with 1.600 rad /s for 5s
  //   motor1.write(control_motor(1600.0));
  //   motor2.write(control_motor(1600.0));
  //   motor3.write(control_motor(1600.0));
  //   motor4.write(control_motor(1600.0));
  //   wait(7);

  // Turn off motor
  //   motor1 = 0.0;
  //   motor2 = 0.0;
  //   motor3 = 0.0;
  //   motor4 = 0.0;
  //   wait(5);

  // Turn on motor with 1.800 rad /s for 5s
  //   motor1.write(control_motor(1800.0));
  //   motor2.write(control_motor(1800.0));
  //   motor3.write(control_motor(1800.0));
  //   motor4.write(control_motor(1800.0));
  //   wait(7);

  // Turn off motor
  //   motor1 = 0.0;
  //   motor2 = 0.0;
  //   motor3 = 0.0;
  //   motor4 = 0.0;
  //   wait(5);

  // Turn on motor with 2.000 rad /s for 5s
  //   motor1.write(control_motor(2000.0));
  //   motor2.write(control_motor(2000.0));
  //   motor3.write(control_motor(2000.0));
  //   motor4.write(control_motor(2000.0));
  //   wait(7);

  // Atividade capitulo 4:
  wait(3);
  motor1.write(control_motor(1000.0));
  motor2.write(control_motor(2000.0));
  motor3.write(control_motor(1000.0));
  motor4.write(control_motor(2000.0));
  wait(2);

  // Turn off motor
  motor1 = 0.0;
  motor2 = 0.0;
  motor3 = 0.0;
  motor4 = 0.0;

  // End of program

  while (true) {
  }
}
