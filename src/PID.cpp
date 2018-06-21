#include "PID.h"
//#include <cmath>
#include <iostream>
#include <vector>
//#include <numeric>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p_init, double i_init, double d_init) {
  Kp = p_init;
  Ki = i_init;
  Kd = d_init;

  total_err = 0;
  prev_cte = 0;
  steps_cntr = 0;
}

/*
Updating each error term associated with each of the PID coefficients
*/
double PID::UpdateError(double cte) {

  double steer = 0;

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;

  steer = -Kp*p_error - Kd*d_error - Ki*i_error;

  // Normalizing the steering angle as 1 maps to +25 degrees and -1 maps to -25 degrees in the simulator.
  if(steer > 1.0){
    steer = 1.0;
  }
  else if(steer < -1.0){
    steer = -1.0;
  }


  prev_cte = cte;
  return steer;
}

// Calculate the average total error over the passed iterations
double PID::TotalError(double cte) {
  steps_cntr += 1;
  total_err +=  total_err;

  return total_err/steps_cntr;
}
