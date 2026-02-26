/*
 * File: Project_Architecture.h
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

#ifndef Project_Architecture_h_
#define Project_Architecture_h_
#ifndef Project_Architecture_COMMON_INCLUDES_
#define Project_Architecture_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                               /* Project_Architecture_COMMON_INCLUDES_ */

#include "Project_Architecture_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block states (default storage) for system '<Root>/Controller' */
typedef struct {
  uint8_T is_active_c3_Project_Architectu;/* '<S1>/Chart1' */
  uint8_T is_c3_Project_Architecture;  /* '<S1>/Chart1' */
} DW_Controller_Project_Archite_T;

/* Block signals (default storage) */
typedef struct {
  real_T term_heater[4];               /* '<S2>/Gain' */
  real_T u_vec[4];                     /* '<S2>/Gain1' */
  real_T x_dot[4];                     /* '<S2>/Sum2' */
  real_T h_cmd[4];                     /* '<S1>/Chart1' */
} B_Project_Architecture_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T h_prev[4];                    /* '<S3>/checker' */
  DW_Controller_Project_Archite_T Controller;/* '<Root>/Controller' */
} DW_Project_Architecture_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S2>/Integrator' */
} X_Project_Architecture_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S2>/Integrator' */
} XDot_Project_Architecture_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<S2>/Integrator' */
} XDis_Project_Architecture_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Project_Architecture_T_ {
  real_T A[16];                        /* Variable: A
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T A_row_sum[4];                 /* Variable: A_row_sum
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T b[4];                         /* Variable: b
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T c[4];                         /* Variable: c
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T dif_val[4];                   /* Variable: dif_val
                                        * Referenced by: '<Root>/dif_val'
                                        */
  real_T get_val[4];                   /* Variable: get_val
                                        * Referenced by: '<Root>/get_val'
                                        */
  real_T off[4];                       /* Variable: off
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T off_val[4];                   /* Variable: off_val
                                        * Referenced by: '<Root>/off_val'
                                        */
  real_T on_val[4];                    /* Variable: on_val
                                        * Referenced by: '<Root>/on_val'
                                        */
  real_T u_temp;                       /* Variable: u_temp
                                        * Referenced by: '<Root>/u_temp'
                                        */
  real_T x0[4];                        /* Variable: x0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Gain1_Gain[4];                /* Expression: ones(4,1)
                                        * Referenced by: '<S2>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Project_Architecture_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Project_Architecture_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Project_Architecture_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Project_Architecture_T Project_Architecture_P;

/* Block signals (default storage) */
extern B_Project_Architecture_T Project_Architecture_B;

/* Continuous states (default storage) */
extern X_Project_Architecture_T Project_Architecture_X;

/* Disabled states (default storage) */
extern XDis_Project_Architecture_T Project_Architecture_XDis;

/* Block states (default storage) */
extern DW_Project_Architecture_T Project_Architecture_DW;

/* Model entry point functions */
extern void Project_Architecture_initialize(void);
extern void Project_Architecture_step(void);
extern void Project_Architecture_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Project_Architecture_T *const Project_Architecture_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Project_Architecture'
 * '<S1>'   : 'Project_Architecture/Controller'
 * '<S2>'   : 'Project_Architecture/RoomModel'
 * '<S3>'   : 'Project_Architecture/SafetyGateway'
 * '<S4>'   : 'Project_Architecture/Controller/Chart1'
 * '<S5>'   : 'Project_Architecture/SafetyGateway/checker'
 */
#endif                                 /* Project_Architecture_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
