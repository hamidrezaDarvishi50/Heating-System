/*
 * File: Controller_private.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Feb 14 07:11:52 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Controller_private_h_
#define Controller_private_h_
#include "rtwtypes.h"
#include "Controller.h"
#include "Controller_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern void Controller_Controller_Init(real_T rty_h_cmd[4]);
extern void Controller_Controller(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW);

#endif                                 /* Controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
