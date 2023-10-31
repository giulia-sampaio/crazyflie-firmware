#include "crazyflie.h"
#include "mbed.h"

// Declare mixer
Mixer mixer;

// Main program
int main() {
  // Actuate motor with 50% mg total thrust force (N) and zero torques
  mixer.arm();
  //mixer.actuate(0.2 * m * g, 0, 0, 0);
  //mixer.actuate(0.2, 0, 0, 0);    //OK
  //mixer.actuate(0, 0.005, 0, 0);  //OK
  //mixer.actuate(0, 0, 0.005, 0);    //OK
  mixer.actuate(0, 0, 0, -0.001); 
  wait(5);
  // Turn off all motors
  mixer.disarm();
  // End of program
  while (true) {
  }
}