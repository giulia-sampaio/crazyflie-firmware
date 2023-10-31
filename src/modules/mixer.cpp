#include "mixer.h"

// Class constructor
Mixer ::Mixer()
    : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4) {
  motor_1.period(1.0 / 500.0);
  motor_2.period(1.0 / 500.0);
  motor_3.period(1.0 / 500.0);
  motor_4.period(1.0 / 500.0);
  motor_1 = 0.0;
  motor_2 = 0.0;
  motor_3 = 0.0;
  motor_4 = 0.0;
  armed = false;
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer ::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  if (armed) {
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
  }
}

// Convert total trust force (N) and torques (N.m) to angular velocities (
// rad/s)
void Mixer ::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  float omega_1_2 = f_t / (4 * Kl) - tau_phi / (4 * Kl * l) -
                    tau_theta / (4 * Kl * l) - tau_psi / (4 * Kd);
  if (omega_1_2 > 0) {
    omega_1 = sqrt(omega_1_2);
  } else {
    omega_1 = 0;
  }
  float omega_2_2 = f_t / (4 * Kl) - tau_phi / (4 * Kl * l) +
                    tau_theta / (4 * Kl * l) + tau_psi / (4 * Kd);
  if (omega_2_2 > 0) {
    omega_2 = sqrt(omega_2_2);
  } else {
    omega_2 = 0;
  }
  float omega_3_2 = f_t / (4 * Kl) + tau_phi / (4 * Kl * l) +
                    tau_theta / (4 * Kl * l) - tau_psi / (4 * Kd);
  if (omega_3_2 > 0) {
    omega_3 = sqrt(omega_3_2);
  } else {
    omega_3 = 0;
  }
  float omega_4_2 = f_t / (4 * Kl) + tau_phi / (4 * Kl * l) -
                    tau_theta / (4 * Kl * l) + tau_psi / (4 * Kd);
  if (omega_4_2 > 0) {
    omega_4 = sqrt(omega_4_2);
  } else {
    omega_4 = 0;
  }
}

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer ::control_motor(float omega) {
  float PWM = a2 * pow(omega, 2) + a1 * omega;
  return PWM;
}

void Mixer ::arm() { armed = true; }

void Mixer ::disarm() {
  actuate(0, 0, 0, 0);
  armed = false;
}
