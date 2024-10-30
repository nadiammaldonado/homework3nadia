/*
 * untitled.h
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

#ifndef untitled_h_
#define untitled_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "untitled_types.h"
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

/* Block signals for system '<S6>/Enabled Subsystem' */
struct B_EnabledSubsystem_untitled_T {
  SL_Bus_untitled_std_msgs_Float64 In1;/* '<S9>/In1' */
};

/* Block signals (default storage) */
struct B_untitled_T {
  char_T b_zeroDelimTopic[26];
  real_T Data;
  real_T Saturation;                   /* '<S8>/Saturation' */
  real_T relative_speed;               /* '<Root>/Sum2' */
  real_T Data_f;
  real_T space_gap;                    /* '<Root>/Sum3' */
  real_T TransferFcn;                  /* '<S8>/Transfer Fcn' */
  real_T a_desired;                    /* '<Root>/MATLAB Function1' */
  B_EnabledSubsystem_untitled_T EnabledSubsystem_l;/* '<S7>/Enabled Subsystem' */
  B_EnabledSubsystem_untitled_T EnabledSubsystem;/* '<S6>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_untitled_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S5>/SinkBlock' */
  ros_slroscpp_internal_block_P_T obj_c;/* '<S4>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_j;/* '<S7>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_p;/* '<S6>/SourceBlock' */
  int_T Integrator_IWORK;              /* '<S8>/Integrator' */
  int_T Integrator1_IWORK;             /* '<S8>/Integrator1' */
  boolean_T objisempty;                /* '<S7>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S6>/SourceBlock' */
  boolean_T objisempty_j;              /* '<S5>/SinkBlock' */
  boolean_T objisempty_i;              /* '<S4>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_untitled_T {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S8>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_untitled_T {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S8>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_untitled_T {
  boolean_T Integrator_CSTATE;         /* '<S8>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S8>/Integrator1' */
  boolean_T TransferFcn_CSTATE;        /* '<S8>/Transfer Fcn' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters for system: '<S6>/Enabled Subsystem' */
struct P_EnabledSubsystem_untitled_T_ {
  SL_Bus_untitled_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                            * Referenced by: '<S9>/Out1'
                                            */
};

/* Parameters (default storage) */
struct P_untitled_T_ {
  SL_Bus_untitled_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                   * Referenced by: '<S1>/Constant'
                                                   */
  SL_Bus_untitled_std_msgs_Float64 Constant_Value_h;/* Computed Parameter: Constant_Value_h
                                                     * Referenced by: '<S2>/Constant'
                                                     */
  SL_Bus_untitled_std_msgs_Float64 Constant_Value_ha;/* Computed Parameter: Constant_Value_ha
                                                      * Referenced by: '<S6>/Constant'
                                                      */
  SL_Bus_untitled_std_msgs_Float64 Constant_Value_h2;/* Computed Parameter: Constant_Value_h2
                                                      * Referenced by: '<S7>/Constant'
                                                      */
  real_T Saturation_UpperSat;          /* Expression: 80
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T length_car_Value;             /* Expression: 7
                                        * Referenced by: '<Root>/length_car'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value_a;             /* Expression: 10
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S8>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S8>/Transfer Fcn'
                                        */
  P_EnabledSubsystem_untitled_T EnabledSubsystem_l;/* '<S7>/Enabled Subsystem' */
  P_EnabledSubsystem_untitled_T EnabledSubsystem;/* '<S6>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_untitled_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_untitled_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_untitled_T untitled_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_untitled_T untitled_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_untitled_T untitled_X;

/* Disabled states (default storage) */
extern XDis_untitled_T untitled_XDis;

/* Block states (default storage) */
extern struct DW_untitled_T untitled_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void untitled_initialize(void);
  extern void untitled_step(void);
  extern void untitled_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_untitled_T *const untitled_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Blank Message'
 * '<S2>'   : 'untitled/Blank Message1'
 * '<S3>'   : 'untitled/MATLAB Function1'
 * '<S4>'   : 'untitled/Publish1'
 * '<S5>'   : 'untitled/Publish2'
 * '<S6>'   : 'untitled/Subscribe1'
 * '<S7>'   : 'untitled/Subscribe2'
 * '<S8>'   : 'untitled/ego_car'
 * '<S9>'   : 'untitled/Subscribe1/Enabled Subsystem'
 * '<S10>'  : 'untitled/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* untitled_h_ */
