/*
 * untitled_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Tue Oct 29 11:38:12 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S2>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_ha
   * Referenced by: '<S6>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_h2
   * Referenced by: '<S7>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 80
   * Referenced by: '<S8>/Saturation'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant2'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant1'
   */
  2.0,

  /* Expression: 7
   * Referenced by: '<Root>/length_car'
   */
  7.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant3'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant'
   */
  10.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S8>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S8>/Transfer Fcn'
   */
  0.5,

  /* Start of '<S7>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S10>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S7>/Enabled Subsystem' */

  /* Start of '<S6>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S9>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  /* End of '<S6>/Enabled Subsystem' */
};
