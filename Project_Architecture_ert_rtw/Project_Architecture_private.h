/*
 * File: Project_Architecture_private.h
 *
 * Code generated for Simulink model 'Project_Architecture'.
 *
 * Model version                  : 1.41
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Feb 14 10:06:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Project_Architecture_private_h_
#define Project_Architecture_private_h_
#include "rtwtypes.h"
#include "Project_Architecture.h"
#include "Project_Architecture_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void Project_Archite_Controller_Init(real_T rty_h_cmd[4]);
extern void Project_Architecture_Controller(const real_T rtu_x_feedback[4],
  const real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW);

/* private model entry point functions */
extern void Project_Architecture_derivatives(void);

#endif                                 /* Project_Architecture_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
