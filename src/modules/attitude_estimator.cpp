#include "attitude_estimator.h"

// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  phi = 0;
  theta = 0;
  psi = 0;
  p = 0;
  q = 0;
  r = 0;
}

// Initialize class
void AttitudeEstimator ::init() {
  imu.init();
  for (int i = 0; i < 500; i++) {
    imu.read();
    p_bias = p_bias + imu.gx / 500.0;
    q_bias = q_bias + imu.gy / 500.0;
    r_bias = r_bias + imu.gz / 500.0;
    wait(dt);
  }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();

  // Acelerômetro
  float phi_a = atan2(-imu.ay, -imu.az); // Não muda para linear e não linear
  // float theta_a = atan2(imu.ax, -imu.az); // Linear
  float theta_a =
      atan2(imu.ax, -((imu.az > 0) - (imu.az < 0)) +
                        sqrt(pow(imu.ay, 2) + pow(imu.az, 2))); // Não linar

  // Giroscópio
  p = imu.gx - p_bias;
  q = imu.gy - q_bias;
  r = imu.gz - r_bias;

  // float phi_g = phi + p * dt; //linear
  float phi_g =
      phi + (p + sin(phi) * tan(theta) * q + cos(phi) * tan(theta) * r) * dt;
  float theta_g = theta + (cos(phi) * q + sin(phi) * r) * dt;
  float psi_g =
      psi +
      (sin(phi) * (1 / cos(theta)) * q + cos(phi) * (1 / cos(theta)) * r) * dt;

  // ângulos
  phi = (1 - alpha) * phi_g + alpha * phi_a;
  theta = (1 - alpha) * theta_g + alpha * theta_a;
  psi = psi_g;
}
