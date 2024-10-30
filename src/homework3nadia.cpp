/*
 * untitled.cpp
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
#include "rtwtypes.h"
#include "untitled_types.h"
#include "untitled_private.h"
#include <string.h>

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Disabled State Vector */
XDis_untitled_T untitled_XDis;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_ = RT_MODEL_untitled_T();
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

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
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  untitled_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  untitled_step();
  untitled_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  untitled_step();
  untitled_derivatives();

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

/*
 * System initialize for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem'
 */
void untitled_EnabledSubsystem_Init(B_EnabledSubsystem_untitled_T *localB,
  P_EnabledSubsystem_untitled_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
   *  Outport: '<S9>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem'
 */
void untitled_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_untitled_std_msgs_Float64 *rtu_In1, B_EnabledSubsystem_untitled_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S9>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
}

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  SL_Bus_untitled_std_msgs_Float64 rtb_SourceBlock_o2;
  SL_Bus_untitled_std_msgs_Float64 rtb_SourceBlock_o2_e;
  boolean_T rtb_SourceBlock_o1;
  boolean_T rtb_SourceBlock_o1_k;
  SL_Bus_untitled_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_untitled_std_msgs_Float64 rtb_BusAssignment1;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    if (!(untitled_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTickH0 + 1) *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTick0 + 1) *
        untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
    /* MATLABSystem: '<S7>/SourceBlock' */
    rtb_SourceBlock_o1 = Sub_untitled_17.getLatestMessage(&rtb_SourceBlock_o2);

    /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' */
    untitled_EnabledSubsystem(rtb_SourceBlock_o1, &rtb_SourceBlock_o2,
      &untitled_B.EnabledSubsystem_l);

    /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

    /* SignalConversion generated from: '<Root>/Bus Selector' */
    untitled_B.Data = untitled_B.EnabledSubsystem_l.In1.Data;
  }

  /* Integrator: '<S8>/Integrator' */
  if (untitled_DW.Integrator_IWORK != 0) {
    untitled_X.Integrator_CSTATE = untitled_B.Data;
  }

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Integrator: '<S8>/Integrator'
   */
  if (untitled_X.Integrator_CSTATE > untitled_P.Saturation_UpperSat) {
    /* Saturate: '<S8>/Saturation' */
    untitled_B.Saturation = untitled_P.Saturation_UpperSat;
  } else if (untitled_X.Integrator_CSTATE < untitled_P.Saturation_LowerSat) {
    /* Saturate: '<S8>/Saturation' */
    untitled_B.Saturation = untitled_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S8>/Saturation' */
    untitled_B.Saturation = untitled_X.Integrator_CSTATE;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = untitled_B.Saturation;

  /* Outputs for Atomic SubSystem: '<Root>/Publish1' */
  /* MATLABSystem: '<S4>/SinkBlock' */
  Pub_untitled_11.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish1' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  untitled_B.relative_speed = untitled_P.Constant2_Value - untitled_B.Saturation;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
    /* MATLABSystem: '<S6>/SourceBlock' */
    rtb_SourceBlock_o1_k = Sub_untitled_16.getLatestMessage
      (&rtb_SourceBlock_o2_e);

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
    untitled_EnabledSubsystem(rtb_SourceBlock_o1_k, &rtb_SourceBlock_o2_e,
      &untitled_B.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

    /* SignalConversion generated from: '<Root>/Bus Selector1' */
    untitled_B.Data_f = untitled_B.EnabledSubsystem.In1.Data;
  }

  /* Integrator: '<S8>/Integrator1' */
  if (untitled_DW.Integrator1_IWORK != 0) {
    untitled_X.Integrator1_CSTATE = untitled_B.Data_f;
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/length_car'
   *  Integrator: '<S8>/Integrator1'
   *  Sum: '<Root>/Sum1'
   */
  untitled_B.space_gap = (untitled_P.Constant1_Value -
    untitled_X.Integrator1_CSTATE) + untitled_P.length_car_Value;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   */
  untitled_B.a_desired = (untitled_B.space_gap / untitled_P.Constant3_Value -
    untitled_P.Constant_Value_a) + 9.0 * untitled_B.relative_speed;

  /* BusAssignment: '<Root>/Bus Assignment1' */
  rtb_BusAssignment1.Data = untitled_B.a_desired;

  /* Outputs for Atomic SubSystem: '<Root>/Publish2' */
  /* MATLABSystem: '<S5>/SinkBlock' */
  Pub_untitled_12.publish(&rtb_BusAssignment1);

  /* End of Outputs for SubSystem: '<Root>/Publish2' */
  if (rtmIsMajorTimeStep(untitled_M)) {
  }

  /* TransferFcn: '<S8>/Transfer Fcn' */
  untitled_B.TransferFcn = untitled_P.TransferFcn_C *
    untitled_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Update for Integrator: '<S8>/Integrator' */
    untitled_DW.Integrator_IWORK = 0;

    /* Update for Integrator: '<S8>/Integrator1' */
    untitled_DW.Integrator1_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick0)) {
      ++untitled_M->Timing.clockTickH0;
    }

    untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      untitled_M->Timing.clockTick1++;
      if (!untitled_M->Timing.clockTick1) {
        untitled_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = untitled_B.TransferFcn;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = untitled_B.Saturation;

  /* Derivatives for TransferFcn: '<S8>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = untitled_P.TransferFcn_A *
    untitled_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += untitled_B.a_desired;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&untitled_M->solverInfo, (boolean_T**)
      &untitled_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled_M->solverInfo, false);
  untitled_M->intgData.y = untitled_M->odeY;
  untitled_M->intgData.f[0] = untitled_M->odeF[0];
  untitled_M->intgData.f[1] = untitled_M->odeF[1];
  untitled_M->intgData.f[2] = untitled_M->odeF[2];
  untitled_M->contStates = ((X_untitled_T *) &untitled_X);
  untitled_M->contStateDisabled = ((XDis_untitled_T *) &untitled_XDis);
  untitled_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&untitled_M->solverInfo, static_cast<void *>
                    (&untitled_M->intgData));
  rtsiSetSolverName(&untitled_M->solverInfo,"ode3");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  untitled_M->Timing.stepSize0 = 0.2;
  rtmSetFirstInitCond(untitled_M, 1);

  /* block I/O */
  (void) memset((static_cast<void *>(&untitled_B)), 0,
                sizeof(B_untitled_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&untitled_X), 0,
                  sizeof(X_untitled_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&untitled_XDis), 0,
                  sizeof(XDis_untitled_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&untitled_DW), 0,
                sizeof(DW_untitled_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[22];
    char_T b_zeroDelimTopic[18];
    static const char_T b_zeroDelimTopic_1[26] = "/ego_car/initial_velocity";
    static const char_T b_zeroDelimTopic_2[18] = "/ego_car/velocity";
    static const char_T b_zeroDelimTopic_3[26] = "/ego_car/initial_position";
    static const char_T b_zeroDelimTopic_4[22] = "/ego_car/acceleration";

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S7>/SourceBlock' */
    untitled_DW.obj_j.matlabCodegenIsDeleted = false;
    untitled_DW.objisempty = true;
    untitled_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      untitled_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_untitled_17.createSubscriber(&untitled_B.b_zeroDelimTopic[0], 1);
    untitled_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish1' */
    /* Start for MATLABSystem: '<S4>/SinkBlock' */
    untitled_DW.obj_c.matlabCodegenIsDeleted = false;
    untitled_DW.objisempty_i = true;
    untitled_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Pub_untitled_11.createPublisher(&b_zeroDelimTopic[0], 1);
    untitled_DW.obj_c.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    untitled_DW.obj_p.matlabCodegenIsDeleted = false;
    untitled_DW.objisempty_o = true;
    untitled_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      untitled_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_untitled_16.createSubscriber(&untitled_B.b_zeroDelimTopic[0], 1);
    untitled_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<Root>/Publish2' */
    /* Start for MATLABSystem: '<S5>/SinkBlock' */
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.objisempty_j = true;
    untitled_DW.obj.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_4[i];
    }

    Pub_untitled_12.createPublisher(&b_zeroDelimTopic_0[0], 1);
    untitled_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish2' */
  }

  /* InitializeConditions for Integrator: '<S8>/Integrator' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  if (rtmIsFirstInitCond(untitled_M)) {
    untitled_X.Integrator_CSTATE = 0.0;
    untitled_X.Integrator1_CSTATE = 0.0;
  }

  untitled_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S8>/Integrator' */

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  untitled_DW.Integrator1_IWORK = 1;

  /* InitializeConditions for TransferFcn: '<S8>/Transfer Fcn' */
  untitled_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  untitled_EnabledSubsystem_Init(&untitled_B.EnabledSubsystem_l,
    &untitled_P.EnabledSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  untitled_EnabledSubsystem_Init(&untitled_B.EnabledSubsystem,
    &untitled_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(untitled_M)) {
    rtmSetFirstInitCond(untitled_M, 0);
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S7>/SourceBlock' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish1' */
  /* Terminate for MATLABSystem: '<S4>/SinkBlock' */
  if (!untitled_DW.obj_c.matlabCodegenIsDeleted) {
    untitled_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish1' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!untitled_DW.obj_p.matlabCodegenIsDeleted) {
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish2' */
  /* Terminate for MATLABSystem: '<S5>/SinkBlock' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish2' */
}
