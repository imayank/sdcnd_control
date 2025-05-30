/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/
    bool flag = true; // to check if it is the first time controller is used.
    /*
    * Errors
    */
    float cte;               //cross track error
    float prev_cte,diff_cte; // previous cross track error and derivative error
    float cum_cte;           // integral error
    /*
    * Coefficients
    */
    double tau_p, tau_d, tau_i;
    /*
    * Output limits
    */
    double output_lim_max, output_lim_min;
    /*
    * Delta time
    */
    double time_delta;
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


