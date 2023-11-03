#include "vertical_estimator.h"

// Class constructor
VerticalEstimator ::VerticalEstimator() : range(E_SDA, E_SCL) {
  z = 0;
  w = 0;
}

// Initialize class
void VerticalEstimator ::init() { range.init(); }

// Predict vertical position and velocity from model
void VerticalEstimator ::predict(float f_t) {
  z = z + w * dt_range;
  if (z > 0.05) {
    w = w + (-g + f_t / m) * dt_range;
  }
}

// Correct vertical position and velocity with measurement
void VerticalEstimator ::correct(float phi, float theta) {
  range.read();
  if (range.d < 2.0) {
    float zm = range.d * cos(phi) * cos(theta);
    z = z + l_2 * dt_range * (zm - z);
    w = w + l_1 * dt_range * (zm - z);
  }
}