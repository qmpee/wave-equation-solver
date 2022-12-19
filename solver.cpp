#include <cmath>
#include <iostream>
const int N = 100;    // number of space intervals
const int M = 1000;   // number of time intervals
const double L = 1.0; // length of space interval
const double T = 1.0; // lenght of time interval
const double c = 1.0; // speed of wave
// Initialize the wave function at time t = 0;
void initialize(double *psi) {
  for (int i = 0; i < N; i++) {
    double x = i * L / N;
    psi[i] = sin(2 * M_PI * x / L);
  }
}

int main() {
  double psi[N]; // wave function at current time;
  double psi_prev[N];
  // Initialize the wave function
  initialize(psi);
  // solve the wave equation using the finite difference method
  for (int t = 0; t < M; t++) {
    // store the current wave function in the previous array
    for (int i = 0; i < N; i++) {
      psi_prev[i] = psi[i];
    }
    // update teh wave function at each space interval
    for (int i = 1; i < N - 1; i++) {
      double d2x =
          (psi_prev[i + 1] - 2 * psi_prev[i] + psi_prev[i - 1]) / (L * L);
      psi[i] = 2 * psi_prev[i] - psi[i] + c * c * T * T * d2x;
    }
    // Apply boundary conditions
    psi[0] = 0;
    psi[N - 1] = 0;
  }
  // print the final wave function
  for (int i = 0; i < N; i++) {
    std::cout << psi[i] << std::endl;
  }
  return 0;
}


