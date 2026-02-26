/*
 * File: Controller.c
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

#include "Controller.h"
#include "rtwtypes.h"
#include "Controller_private.h"

/* Named constants for Chart: '<S1>/Chart1' */
#define Controller_IN_S0011            ((uint8_T)1U)
#define Controller_IN_S0101            ((uint8_T)2U)
#define Controller_IN_S0110            ((uint8_T)3U)
#define Controller_IN_S1001            ((uint8_T)4U)
#define Controller_IN_S1010            ((uint8_T)5U)
#define Controller_IN_S1100            ((uint8_T)6U)

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
static RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Forward declaration for local functions */
static void Controller_S0101(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW);
static void Controller_S0110(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW);
static void Controller_S1001(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW);
static void Controller_S1010(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW);

/* Function for Chart: '<S1>/Chart1' */
static void Controller_S0101(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[3] -
       rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0110;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[3] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1100;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[1] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1001;
  } else if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[1] -
              rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0011;
  } else if ((rtu_x_feedback[3] >= rtu_off_limits[3]) && (rty_h_cmd[3] == 1.0))
  {
    rty_h_cmd[3] = 0.0;
  } else if ((rtu_x_feedback[3] <= rtu_on_limits[3]) && (rty_h_cmd[3] == 0.0)) {
    rty_h_cmd[3] = 1.0;
  } else if ((rtu_x_feedback[1] <= rtu_on_limits[1]) && (rty_h_cmd[1] == 0.0)) {
    rty_h_cmd[1] = 1.0;
  } else if ((rtu_x_feedback[1] >= rtu_off_limits[1]) && (rty_h_cmd[1] == 1.0))
  {
    rty_h_cmd[1] = 0.0;
  }

  /* End of Chart: '<S1>/Chart1' */
}

/* Function for Chart: '<S1>/Chart1' */
static void Controller_S0110(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[2] -
       rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1100;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[2] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0101;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[1] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1010;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[1] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0011;
  } else if ((rtu_x_feedback[2] >= rtu_off_limits[2]) && (rty_h_cmd[2] == 1.0))
  {
    rty_h_cmd[2] = 0.0;
  } else if ((rtu_x_feedback[2] <= rtu_on_limits[2]) && (rty_h_cmd[2] == 0.0)) {
    rty_h_cmd[2] = 1.0;
  } else if ((rtu_x_feedback[1] <= rtu_on_limits[1]) && (rty_h_cmd[1] == 0.0)) {
    rty_h_cmd[1] = 1.0;
  } else if ((rtu_x_feedback[1] >= rtu_off_limits[1]) && (rty_h_cmd[1] == 1.0))
  {
    rty_h_cmd[1] = 0.0;
  }

  /* End of Chart: '<S1>/Chart1' */
}

/* Function for Chart: '<S1>/Chart1' */
static void Controller_S1001(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[0] -
       rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0011;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[0] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0101;
  } else if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[3] -
              rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1010;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[3] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1100;
  } else if ((rtu_x_feedback[3] <= rtu_on_limits[3]) && (rty_h_cmd[3] == 0.0)) {
    rty_h_cmd[3] = 1.0;
  } else if ((rtu_x_feedback[3] >= rtu_off_limits[3]) && (rty_h_cmd[3] == 1.0))
  {
    rty_h_cmd[3] = 0.0;
  } else if ((rtu_x_feedback[0] >= rtu_off_limits[0]) && (rty_h_cmd[0] == 1.0))
  {
    rty_h_cmd[0] = 0.0;
  } else if ((rtu_x_feedback[0] <= rtu_on_limits[0]) && (rty_h_cmd[0] == 0.0)) {
    rty_h_cmd[0] = 1.0;
  }

  /* End of Chart: '<S1>/Chart1' */
}

/* Function for Chart: '<S1>/Chart1' */
static void Controller_S1010(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[0] -
       rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0110;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[0] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S0011;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[2] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1001;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[2] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Controller = Controller_IN_S1100;
  } else if ((rtu_x_feedback[0] >= rtu_off_limits[0]) && (rty_h_cmd[0] == 1.0))
  {
    rty_h_cmd[0] = 0.0;
  } else if ((rtu_x_feedback[0] <= rtu_on_limits[0]) && (rty_h_cmd[0] == 0.0)) {
    rty_h_cmd[0] = 1.0;
  } else if ((rtu_x_feedback[2] <= rtu_on_limits[2]) && (rty_h_cmd[2] == 0.0)) {
    rty_h_cmd[2] = 1.0;
  } else if ((rtu_x_feedback[2] >= rtu_off_limits[2]) && (rty_h_cmd[2] == 1.0))
  {
    rty_h_cmd[2] = 0.0;
  }

  /* End of Chart: '<S1>/Chart1' */
}

/* System initialize for atomic system: '<Root>/Controller' */
void Controller_Controller_Init(real_T rty_h_cmd[4])
{
  /* SystemInitialize for Chart: '<S1>/Chart1' */
  rty_h_cmd[0] = 0.0;
  rty_h_cmd[1] = 1.0;
  rty_h_cmd[2] = 1.0;
  rty_h_cmd[3] = 0.0;
}

/* Output and update for atomic system: '<Root>/Controller' */
void Controller_Controller(const real_T rtu_x_feedback[4], const real_T
  rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T rtu_get_params
  [4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Controller_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if (localDW->is_active_c3_Controller == 0) {
    localDW->is_active_c3_Controller = 1U;
    localDW->is_c3_Controller = Controller_IN_S0110;
  } else {
    switch (localDW->is_c3_Controller) {
     case Controller_IN_S0011:
      if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[3] -
           rtu_x_feedback[1] >= rtu_dif_params[1])) {
        rty_h_cmd[3] = 0.0;
        rty_h_cmd[1] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S0110;
      } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[3]
                  - rtu_x_feedback[0] >= rtu_dif_params[0])) {
        rty_h_cmd[3] = 0.0;
        rty_h_cmd[0] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S1010;
      } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[2]
                  - rtu_x_feedback[1] >= rtu_dif_params[1])) {
        rty_h_cmd[2] = 0.0;
        rty_h_cmd[1] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S0101;
      } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[2]
                  - rtu_x_feedback[0] >= rtu_dif_params[0])) {
        rty_h_cmd[2] = 0.0;
        rty_h_cmd[0] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S1001;
      } else if ((rtu_x_feedback[2] >= rtu_off_limits[2]) && (rty_h_cmd[2] ==
                  1.0)) {
        rty_h_cmd[2] = 0.0;
      } else if ((rtu_x_feedback[2] <= rtu_on_limits[2]) && (rty_h_cmd[2] == 0.0))
      {
        rty_h_cmd[2] = 1.0;
      } else if ((rtu_x_feedback[3] <= rtu_on_limits[3]) && (rty_h_cmd[3] == 0.0))
      {
        rty_h_cmd[3] = 1.0;
      } else if ((rtu_x_feedback[3] >= rtu_off_limits[3]) && (rty_h_cmd[3] ==
                  1.0)) {
        rty_h_cmd[3] = 0.0;
      }
      break;

     case Controller_IN_S0101:
      Controller_S0101(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
                       rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Controller_IN_S0110:
      Controller_S0110(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
                       rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Controller_IN_S1001:
      Controller_S1001(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
                       rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Controller_IN_S1010:
      Controller_S1010(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
                       rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     default:
      /* case IN_S1100: */
      if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[0] -
           rtu_x_feedback[2] >= rtu_dif_params[2])) {
        rty_h_cmd[0] = 0.0;
        rty_h_cmd[2] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S0110;
      } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[0]
                  - rtu_x_feedback[3] >= rtu_dif_params[3])) {
        rty_h_cmd[0] = 0.0;
        rty_h_cmd[3] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S0101;
      } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[1]
                  - rtu_x_feedback[3] >= rtu_dif_params[3])) {
        rty_h_cmd[1] = 0.0;
        rty_h_cmd[3] = 1.0;
        localDW->is_c3_Controller = Controller_IN_S1001;
      } else if ((rtu_x_feedback[0] >= rtu_off_limits[0]) && (rty_h_cmd[0] ==
                  1.0)) {
        rty_h_cmd[0] = 0.0;
      } else if ((rtu_x_feedback[0] <= rtu_on_limits[0]) && (rty_h_cmd[0] == 0.0))
      {
        rty_h_cmd[0] = 1.0;
      } else if ((rtu_x_feedback[1] <= rtu_on_limits[1]) && (rty_h_cmd[1] == 0.0))
      {
        rty_h_cmd[1] = 1.0;
      } else if ((rtu_x_feedback[1] >= rtu_off_limits[1]) && (rty_h_cmd[1] ==
                  1.0)) {
        rty_h_cmd[1] = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart1' */
}

/* Model step function */
void Controller_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Controller' */

  /* Inport: '<Root>/x_feedback' incorporates:
   *  Inport: '<Root>/dif_params'
   *  Inport: '<Root>/get_params'
   *  Inport: '<Root>/off_limits'
   *  Inport: '<Root>/on_limits'
   *  Outport: '<Root>/h_cmd'
   */
  Controller_Controller(Controller_U.Temperature4, Controller_U.on_limits,
                        Controller_U.off_limits, Controller_U.get_params,
                        Controller_U.dif_params, Controller_Y.h_cmd,
                        &Controller_DW.Controller_i);

  /* End of Outputs for SubSystem: '<Root>/Controller' */

  /* Outport: '<Root>/h' */
  Controller_Y.h = 0.0;
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Controller' */

  /* SystemInitialize for Outport: '<Root>/h_cmd' */
  Controller_Controller_Init(Controller_Y.h_cmd);

  /* End of SystemInitialize for SubSystem: '<Root>/Controller' */
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
