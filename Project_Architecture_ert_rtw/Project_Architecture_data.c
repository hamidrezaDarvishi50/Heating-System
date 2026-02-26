/*
 * File: Project_Architecture_data.c
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

/* Block parameters (default storage) */
P_Project_Architecture_T Project_Architecture_P = {
  /* Variable: A
   * Referenced by: '<S2>/Gain3'
   */
  { 0.0, 0.3, 0.4, 0.3, 0.3, 0.0, 0.5, 0.0, 0.4, 0.5, 0.0, 0.3, 0.3, 0.0, 0.3,
    0.0 },

  /* Variable: A_row_sum
   * Referenced by: '<S2>/Gain4'
   */
  { 1.0, 0.8, 1.2, 0.6 },

  /* Variable: b
   * Referenced by: '<S2>/Gain2'
   */
  { 0.3, 0.2, 0.5, 0.4 },

  /* Variable: c
   * Referenced by: '<S2>/Gain'
   */
  { 9.0, 7.0, 11.0, 7.0 },

  /* Variable: dif_val
   * Referenced by: '<Root>/dif_val'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Variable: get_val
   * Referenced by: '<Root>/get_val'
   */
  { 17.0, 16.0, 16.0, 17.0 },

  /* Variable: off
   * Referenced by: '<S3>/Constant'
   */
  { 20.0, 20.0, 20.0, 20.0 },

  /* Variable: off_val
   * Referenced by: '<Root>/off_val'
   */
  { 20.0, 20.0, 20.0, 20.0 },

  /* Variable: on_val
   * Referenced by: '<Root>/on_val'
   */
  { 19.0, 19.0, 19.0, 19.0 },

  /* Variable: u_temp
   * Referenced by: '<Root>/u_temp'
   */
  6.0,

  /* Variable: x0
   * Referenced by: '<S2>/Integrator'
   */
  { 16.5, 16.5, 16.5, 16.5 },

  /* Expression: ones(4,1)
   * Referenced by: '<S2>/Gain1'
   */
  { 1.0, 1.0, 1.0, 1.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
