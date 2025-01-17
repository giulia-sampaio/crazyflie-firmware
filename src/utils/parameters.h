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
const float a2 = 1.4183e-07;
const float a1 = 2.2982e-10;

// Constante de sustentação
const float Kl = 1.6147e-08;

// Constante de arrasto
const float Kd = 1.2527e-10;

// Frequência de corte filtro passa-baixa
const int wc = 1.0;

// Delta t discretização
const float dt = 0.002;

// Fator de suavização filtro passa-baixa e passa-alta
const float alpha = wc*dt/(1.0 + wc*dt);

// Momentos de Inércia 
const float Ixx = 16e-6;
const float Iyy = 16e-6;
const float Izz = 29e-6;    

// Requisitos controlador 
const float Ts_phi_theta = 0.3;  //0.6
const float Ts_psi = 0.6;
const float Ts_x_y_z = 2.0;
const float OS = 0.005;

const float zeta = abs(log(OS))/sqrt(pow(log(OS), 2) + pow(pi, 2));

const float wn_phi_theta = 4.0/(Ts_phi_theta * zeta);
const float wn_psi = 4.0/(Ts_psi * zeta);
const float wn_x_y_z = 4.0/(Ts_x_y_z * zeta);

// Ganhos Controlador Atitude
const float kp_phi = pow(wn_phi_theta, 2); // Proporcional 
const float kd_phi = 2.0 * zeta * wn_phi_theta; // Derivativo

const float kp_theta = pow(wn_phi_theta, 2); // Proporcional 
const float kd_theta = 2.0 * zeta * wn_phi_theta; // Derivativo

const float kp_psi = pow(wn_psi, 2); // Proporcional 
const float kd_psi = 2.0 * zeta * wn_psi; // Derivativo

// Delta t - Correção Altitude
const float dt_range = 0.05;

// Filtro passa-baixa ordem 2 - Controlador Altitude
const int wc_alt = 10.0;
const float zeta_alt = sqrt(2.0)/2.0;

// Ganhos Observador de Estados (ordem 2) - Controlador de Altitude
const int l_1 = pow(wc_alt, 2);
const float l_2 = 2.0 * zeta_alt * wc_alt;

// Ganhos Controlador Altitude
const float kp_vert = pow(wn_x_y_z, 2);
const float kd_vert = 2.0 * zeta * wn_x_y_z;

// Controlador Horizontal 
const float sigma = 2.0 * tan((42.0 * pi / 180.0 )/ 2.0) / (420.0 * dt);
const float wc_hor = 50.0;
const float L = wc_hor;

const float Ts_hor = 2.2; 
const float wn_hor = 4.0/(Ts_hor * zeta);

const float kp_hor = pow(wn_hor, 2);
const float kd_hor = 2.0 * zeta * wn_hor;

// Controle de trajetória
const float t0 = 2.0;
const float tv = 5.0;
const float tp = 2.0;
const float h = 0.5;
const float d = 2.0;

#endif