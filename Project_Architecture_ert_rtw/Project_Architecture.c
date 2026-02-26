/*
 * File: Project_Architecture.c
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

#include "Project_Architecture.h"
#include "rtwtypes.h"
#include "Project_Architecture_private.h"
#include <math.h>

/* Named constants for Chart: '<S1>/Chart1' */
#define Project_Architecture_IN_S0011  ((uint8_T)1U)
#define Project_Architecture_IN_S0101  ((uint8_T)2U)
#define Project_Architecture_IN_S0110  ((uint8_T)3U)
#define Project_Architecture_IN_S1001  ((uint8_T)4U)
#define Project_Architecture_IN_S1010  ((uint8_T)5U)
#define Project_Architecture_IN_S1100  ((uint8_T)6U)

/* Block signals (default storage) */
B_Project_Architecture_T Project_Architecture_B;

/* Continuous states */
X_Project_Architecture_T Project_Architecture_X;

/* Disabled State Vector */
XDis_Project_Architecture_T Project_Architecture_XDis;

/* Block states (default storage) */
DW_Project_Architecture_T Project_Architecture_DW;

/* Real-time model */
static RT_MODEL_Project_Architecture_T Project_Architecture_M_;
RT_MODEL_Project_Architecture_T *const Project_Architecture_M =
  &Project_Architecture_M_;

/* Forward declaration for local functions */
static void Project_Architecture_S0101(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW);
static void Project_Architecture_S0110(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW);
static void Project_Architecture_S1001(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW);
static void Project_Architecture_S1010(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Project_Architecture_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Project_Architecture_step();
  Project_Architecture_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Project_Architecture_step();
  Project_Architecture_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Chart: '<S1>/Chart1' */
static void Project_Architecture_S0101(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[3] -
       rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0110;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[3] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1100;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[1] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1001;
  } else if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[1] -
              rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0011;
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
static void Project_Architecture_S0110(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[2] -
       rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1100;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[2] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0101;
  } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[1] -
              rtu_x_feedback[0] >= rtu_dif_params[0])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[0] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1010;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[1] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[1] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0011;
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
static void Project_Architecture_S1001(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[0] -
       rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0011;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[0] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0101;
  } else if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[3] -
              rtu_x_feedback[2] >= rtu_dif_params[2])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[2] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1010;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[3] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[3] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1100;
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
static void Project_Architecture_S1010(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[0] -
       rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0110;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[0] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[0] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0011;
  } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[2] -
              rtu_x_feedback[3] >= rtu_dif_params[3])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[3] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1001;
  } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[2] -
              rtu_x_feedback[1] >= rtu_dif_params[1])) {
    rty_h_cmd[2] = 0.0;
    rty_h_cmd[1] = 1.0;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1100;
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
void Project_Archite_Controller_Init(real_T rty_h_cmd[4])
{
  /* SystemInitialize for Chart: '<S1>/Chart1' */
  rty_h_cmd[0] = 0.0;
  rty_h_cmd[1] = 1.0;
  rty_h_cmd[2] = 1.0;
  rty_h_cmd[3] = 0.0;
}

/* Output and update for atomic system: '<Root>/Controller' */
void Project_Architecture_Controller(const real_T rtu_x_feedback[4], const
  real_T rtu_on_limits[4], const real_T rtu_off_limits[4], const real_T
  rtu_get_params[4], const real_T rtu_dif_params[4], real_T rty_h_cmd[4],
  DW_Controller_Project_Archite_T *localDW)
{
  /* Chart: '<S1>/Chart1' */
  if (localDW->is_active_c3_Project_Architectu == 0) {
    localDW->is_active_c3_Project_Architectu = 1U;
    localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0110;
  } else {
    switch (localDW->is_c3_Project_Architecture) {
     case Project_Architecture_IN_S0011:
      if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[3] -
           rtu_x_feedback[1] >= rtu_dif_params[1])) {
        rty_h_cmd[3] = 0.0;
        rty_h_cmd[1] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0110;
      } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[3]
                  - rtu_x_feedback[0] >= rtu_dif_params[0])) {
        rty_h_cmd[3] = 0.0;
        rty_h_cmd[0] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1010;
      } else if ((rtu_x_feedback[1] <= rtu_get_params[1]) && (rtu_x_feedback[2]
                  - rtu_x_feedback[1] >= rtu_dif_params[1])) {
        rty_h_cmd[2] = 0.0;
        rty_h_cmd[1] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0101;
      } else if ((rtu_x_feedback[0] <= rtu_get_params[0]) && (rtu_x_feedback[2]
                  - rtu_x_feedback[0] >= rtu_dif_params[0])) {
        rty_h_cmd[2] = 0.0;
        rty_h_cmd[0] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1001;
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

     case Project_Architecture_IN_S0101:
      Project_Architecture_S0101(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
        rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Project_Architecture_IN_S0110:
      Project_Architecture_S0110(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
        rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Project_Architecture_IN_S1001:
      Project_Architecture_S1001(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
        rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     case Project_Architecture_IN_S1010:
      Project_Architecture_S1010(rtu_x_feedback, rtu_on_limits, rtu_off_limits,
        rtu_get_params, rtu_dif_params, rty_h_cmd, localDW);
      break;

     default:
      /* case IN_S1100: */
      if ((rtu_x_feedback[2] <= rtu_get_params[2]) && (rtu_x_feedback[0] -
           rtu_x_feedback[2] >= rtu_dif_params[2])) {
        rty_h_cmd[0] = 0.0;
        rty_h_cmd[2] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0110;
      } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[0]
                  - rtu_x_feedback[3] >= rtu_dif_params[3])) {
        rty_h_cmd[0] = 0.0;
        rty_h_cmd[3] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S0101;
      } else if ((rtu_x_feedback[3] <= rtu_get_params[3]) && (rtu_x_feedback[1]
                  - rtu_x_feedback[3] >= rtu_dif_params[3])) {
        rty_h_cmd[1] = 0.0;
        rty_h_cmd[3] = 1.0;
        localDW->is_c3_Project_Architecture = Project_Architecture_IN_S1001;
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Project_Architecture_step(void)
{
  real_T y[4];
  real_T Integrator_CSTATE;
  int32_T exitg2;
  int16_T c_k;
  boolean_T b_y;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(Project_Architecture_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Project_Architecture_M->solverInfo,
                          ((Project_Architecture_M->Timing.clockTick0+1)*
      Project_Architecture_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Project_Architecture_M)) {
    Project_Architecture_M->Timing.t[0] = rtsiGetT
      (&Project_Architecture_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Project_Architecture_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Controller' */
    /* Integrator: '<S2>/Integrator' incorporates:
     *  Constant: '<Root>/dif_val'
     *  Constant: '<Root>/get_val'
     *  Constant: '<Root>/off_val'
     *  Constant: '<Root>/on_val'
     */
    Project_Architecture_Controller(Project_Architecture_X.Integrator_CSTATE,
      Project_Architecture_P.on_val, Project_Architecture_P.off_val,
      Project_Architecture_P.get_val, Project_Architecture_P.dif_val,
      Project_Architecture_B.h_cmd, &Project_Architecture_DW.Controller);

    /* End of Outputs for SubSystem: '<Root>/Controller' */

    /* Outputs for Atomic SubSystem: '<Root>/SafetyGateway' */
    /* MATLAB Function: '<S3>/checker' */
    Project_Architecture_B.term_heater[0] = Project_Architecture_B.h_cmd[0];
    Project_Architecture_B.term_heater[0] = rt_roundd_snf
      (Project_Architecture_B.term_heater[0]);
    y[0] = fabs(Project_Architecture_B.h_cmd[0] -
                Project_Architecture_B.term_heater[0]);
    Project_Architecture_B.term_heater[1] = Project_Architecture_B.h_cmd[1];
    Project_Architecture_B.term_heater[1] = rt_roundd_snf
      (Project_Architecture_B.term_heater[1]);
    y[1] = fabs(Project_Architecture_B.h_cmd[1] -
                Project_Architecture_B.term_heater[1]);
    Project_Architecture_B.term_heater[2] = Project_Architecture_B.h_cmd[2];
    Project_Architecture_B.term_heater[2] = rt_roundd_snf
      (Project_Architecture_B.term_heater[2]);
    y[2] = fabs(Project_Architecture_B.h_cmd[2] -
                Project_Architecture_B.term_heater[2]);
    Project_Architecture_B.term_heater[3] = Project_Architecture_B.h_cmd[3];
    Project_Architecture_B.term_heater[3] = rt_roundd_snf
      (Project_Architecture_B.term_heater[3]);
    y[3] = fabs(Project_Architecture_B.h_cmd[3] -
                Project_Architecture_B.term_heater[3]);
    b_y = false;
    c_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c_k < 4)) {
      if (y[c_k] > 1.0E-6) {
        b_y = true;
        exitg1 = true;
      } else {
        c_k++;
      }
    }

    if (b_y) {
      Project_Architecture_B.term_heater[0] = Project_Architecture_DW.h_prev[0];
      Project_Architecture_B.term_heater[1] = Project_Architecture_DW.h_prev[1];
      Project_Architecture_B.term_heater[2] = Project_Architecture_DW.h_prev[2];
      Project_Architecture_B.term_heater[3] = Project_Architecture_DW.h_prev[3];
    } else if (((Project_Architecture_B.term_heater[0] +
                 Project_Architecture_B.term_heater[1]) +
                Project_Architecture_B.term_heater[2]) +
               Project_Architecture_B.term_heater[3] > 2.0) {
      Project_Architecture_B.term_heater[0] = Project_Architecture_DW.h_prev[0];
      Project_Architecture_B.term_heater[1] = Project_Architecture_DW.h_prev[1];
      Project_Architecture_B.term_heater[2] = Project_Architecture_DW.h_prev[2];
      Project_Architecture_B.term_heater[3] = Project_Architecture_DW.h_prev[3];
    } else {
      c_k = 0;
      do {
        exitg2 = 0L;
        if (c_k < 4) {
          if ((Project_Architecture_X.Integrator_CSTATE[c_k] >=
               Project_Architecture_P.off[c_k]) &&
              (Project_Architecture_B.term_heater[c_k] == 1.0)) {
            Project_Architecture_B.term_heater[0] =
              Project_Architecture_DW.h_prev[0];
            Project_Architecture_B.term_heater[1] =
              Project_Architecture_DW.h_prev[1];
            Project_Architecture_B.term_heater[2] =
              Project_Architecture_DW.h_prev[2];
            Project_Architecture_B.term_heater[3] =
              Project_Architecture_DW.h_prev[3];
            exitg2 = 1L;
          } else {
            c_k++;
          }
        } else {
          Project_Architecture_DW.h_prev[0] =
            Project_Architecture_B.term_heater[0];
          Project_Architecture_DW.h_prev[1] =
            Project_Architecture_B.term_heater[1];
          Project_Architecture_DW.h_prev[2] =
            Project_Architecture_B.term_heater[2];
          Project_Architecture_DW.h_prev[3] =
            Project_Architecture_B.term_heater[3];
          exitg2 = 1L;
        }
      } while (exitg2 == 0L);
    }

    /* End of MATLAB Function: '<S3>/checker' */
    /* End of Outputs for SubSystem: '<Root>/SafetyGateway' */

    /* Gain: '<S2>/Gain' */
    Project_Architecture_B.term_heater[0] *= Project_Architecture_P.c[0];

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<Root>/u_temp'
     */
    Project_Architecture_B.u_vec[0] = Project_Architecture_P.Gain1_Gain[0] *
      Project_Architecture_P.u_temp;

    /* Gain: '<S2>/Gain' */
    Project_Architecture_B.term_heater[1] *= Project_Architecture_P.c[1];

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<Root>/u_temp'
     */
    Project_Architecture_B.u_vec[1] = Project_Architecture_P.Gain1_Gain[1] *
      Project_Architecture_P.u_temp;

    /* Gain: '<S2>/Gain' */
    Project_Architecture_B.term_heater[2] *= Project_Architecture_P.c[2];

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<Root>/u_temp'
     */
    Project_Architecture_B.u_vec[2] = Project_Architecture_P.Gain1_Gain[2] *
      Project_Architecture_P.u_temp;

    /* Gain: '<S2>/Gain' */
    Project_Architecture_B.term_heater[3] *= Project_Architecture_P.c[3];

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<Root>/u_temp'
     */
    Project_Architecture_B.u_vec[3] = Project_Architecture_P.Gain1_Gain[3] *
      Project_Architecture_P.u_temp;
  }

  for (c_k = 0; c_k < 4; c_k++) {
    /* Integrator: '<S2>/Integrator' incorporates:
     *  Gain: '<S2>/Gain3'
     */
    Integrator_CSTATE = Project_Architecture_X.Integrator_CSTATE[c_k];

    /* Sum: '<S2>/Sum2' incorporates:
     *  Gain: '<S2>/Gain2'
     *  Gain: '<S2>/Gain3'
     *  Gain: '<S2>/Gain4'
     *  Integrator: '<S2>/Integrator'
     *  Sum: '<S2>/Sum'
     *  Sum: '<S2>/Sum1'
     */
    Project_Architecture_B.x_dot[c_k] = (((((Project_Architecture_P.A[c_k + 4] *
      Project_Architecture_X.Integrator_CSTATE[1] + Project_Architecture_P.A[c_k]
      * Project_Architecture_X.Integrator_CSTATE[0]) +
      Project_Architecture_P.A[c_k + 8] *
      Project_Architecture_X.Integrator_CSTATE[2]) +
      Project_Architecture_P.A[c_k + 12] *
      Project_Architecture_X.Integrator_CSTATE[3]) -
      Project_Architecture_P.A_row_sum[c_k] * Integrator_CSTATE) +
      (Project_Architecture_B.u_vec[c_k] - Integrator_CSTATE) *
      Project_Architecture_P.b[c_k]) + Project_Architecture_B.term_heater[c_k];
  }

  if (rtmIsMajorTimeStep(Project_Architecture_M)) {
    rt_ertODEUpdateContinuousStates(&Project_Architecture_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Project_Architecture_M->Timing.clockTick0;
    Project_Architecture_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Project_Architecture_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Project_Architecture_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Project_Architecture_derivatives(void)
{
  XDot_Project_Architecture_T *_rtXdot;
  _rtXdot = ((XDot_Project_Architecture_T *) Project_Architecture_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Project_Architecture_B.x_dot[0];
  _rtXdot->Integrator_CSTATE[1] = Project_Architecture_B.x_dot[1];
  _rtXdot->Integrator_CSTATE[2] = Project_Architecture_B.x_dot[2];
  _rtXdot->Integrator_CSTATE[3] = Project_Architecture_B.x_dot[3];
}

/* Model initialize function */
void Project_Architecture_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Project_Architecture_M->solverInfo,
                          &Project_Architecture_M->Timing.simTimeStep);
    rtsiSetTPtr(&Project_Architecture_M->solverInfo, &rtmGetTPtr
                (Project_Architecture_M));
    rtsiSetStepSizePtr(&Project_Architecture_M->solverInfo,
                       &Project_Architecture_M->Timing.stepSize0);
    rtsiSetdXPtr(&Project_Architecture_M->solverInfo,
                 &Project_Architecture_M->derivs);
    rtsiSetContStatesPtr(&Project_Architecture_M->solverInfo, (real_T **)
                         &Project_Architecture_M->contStates);
    rtsiSetNumContStatesPtr(&Project_Architecture_M->solverInfo,
      &Project_Architecture_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Project_Architecture_M->solverInfo,
      &Project_Architecture_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Project_Architecture_M->solverInfo,
      &Project_Architecture_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Project_Architecture_M->solverInfo,
      &Project_Architecture_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Project_Architecture_M->solverInfo, (boolean_T**)
      &Project_Architecture_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Project_Architecture_M->solverInfo,
                          (&rtmGetErrorStatus(Project_Architecture_M)));
    rtsiSetRTModelPtr(&Project_Architecture_M->solverInfo,
                      Project_Architecture_M);
  }

  rtsiSetSimTimeStep(&Project_Architecture_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Project_Architecture_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Project_Architecture_M->solverInfo, false);
  Project_Architecture_M->intgData.y = Project_Architecture_M->odeY;
  Project_Architecture_M->intgData.f[0] = Project_Architecture_M->odeF[0];
  Project_Architecture_M->intgData.f[1] = Project_Architecture_M->odeF[1];
  Project_Architecture_M->intgData.f[2] = Project_Architecture_M->odeF[2];
  Project_Architecture_M->contStates = ((X_Project_Architecture_T *)
    &Project_Architecture_X);
  Project_Architecture_M->contStateDisabled = ((XDis_Project_Architecture_T *)
    &Project_Architecture_XDis);
  Project_Architecture_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Project_Architecture_M->solverInfo, (void *)
                    &Project_Architecture_M->intgData);
  rtsiSetSolverName(&Project_Architecture_M->solverInfo,"ode3");
  rtmSetTPtr(Project_Architecture_M, &Project_Architecture_M->Timing.tArray[0]);
  Project_Architecture_M->Timing.stepSize0 = 0.1;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Project_Architecture_X.Integrator_CSTATE[0] = Project_Architecture_P.x0[0];
  Project_Architecture_X.Integrator_CSTATE[1] = Project_Architecture_P.x0[1];
  Project_Architecture_X.Integrator_CSTATE[2] = Project_Architecture_P.x0[2];
  Project_Architecture_X.Integrator_CSTATE[3] = Project_Architecture_P.x0[3];

  /* SystemInitialize for Atomic SubSystem: '<Root>/Controller' */
  Project_Archite_Controller_Init(Project_Architecture_B.h_cmd);

  /* End of SystemInitialize for SubSystem: '<Root>/Controller' */
}

/* Model terminate function */
void Project_Architecture_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
