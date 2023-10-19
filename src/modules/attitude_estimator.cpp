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
    p_bias = p_bias + imu.gx;
    wait(dt);
  }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();
  // Acelerômetro - FALTA DETERMINAR WC ADEQUADO - MATLAB
  // float phi_a = atan2(-imu.ay, -imu.az);
  // phi = (1 - alpha)*phi + phi_a*alpha;

  // Giroscópio
  p = imu.gx - p_bias;
  float phi_g = phi_g + p * dt;
  phi = phi_g*(1 - alpha_a);  // alpha passa-alta é igual ao alpha passa-baixa???
}