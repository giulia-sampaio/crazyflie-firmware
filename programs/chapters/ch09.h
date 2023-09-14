#include "crazyflie.h"
#include "mbed.h"

// Declare mixer
Mixer mixer;

// Main program
int main() {
  // Actuate motor with 50% mg total thrust force (N) and zero torques
  //mixer.actuate(0.5 * m * g, 0, 0, 0);
  mixer.actuate(0, 0, 0, 0.005);
  wait(5);
  // Turn off all motors
  mixer.actuate(0, 0, 0, 0);
  // End of program
  while (true) {
  }
}