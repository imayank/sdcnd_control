/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   tau_p = Kpi;
   tau_d = Kdi;
   tau_i = Kii;
   output_lim_max = output_lim_maxi;
   output_lim_min = output_lim_mini;
   cte = 0.0;
   diff_cte=0.0;
   cum_cte=0.0;
   time_delta = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   // if first time called set previous error to the current error 
   if (flag==true){
      prev_cte = cte;
      flag = false;
   }
   this->cte = cte;
   cum_cte += (time_delta*cte); // integral of error so mutiply by dt
   if(time_delta==0)
    diff_cte = 0;
   else
    diff_cte = (cte - prev_cte)/time_delta; // slope of the curve (derivative) so divide by the dt  
   
   prev_cte = cte; 
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
    control = -1 * (tau_p*cte + tau_i * cum_cte + tau_d * diff_cte); // calculate control
    
    // clamp the error if mot in accepted range.
    if (control < output_lim_min){
      control = output_lim_min;}
    else{
      if (control > output_lim_max)
       control = output_lim_max;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   time_delta = new_delta_time;
}