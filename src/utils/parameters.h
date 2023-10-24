#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Coeficientes para cálculo do PWM necessário para cada velocidade de rotação
const float a = 1.4183e-07;
const float b = 2.2982e-10;
const float c = 0.0;

// Constante de sustentação
const float Kl = 1.6147e-08;

// Constante de arrasto
const float Kd = 1.2527e-10;

// Frequência de corte filtro passa-baixa
const int wc = 10;

// Frequência de corte filtro passa-alta
const float wc_a = 0.1;

// Delta t discretização
const float dt = 0.002;

// Fator de suavização filtro passa-baixa e passa-alta
const float alpha = wc*dt/(1 + wc*dt);

// Momentos de Inércia 
const float Ixx = 16e-6;
const float Iyy = 16e-6;
const float Izz = 29e-6;    

#endif