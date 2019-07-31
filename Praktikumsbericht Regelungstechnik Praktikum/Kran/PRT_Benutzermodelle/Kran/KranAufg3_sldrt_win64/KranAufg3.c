/*
 * KranAufg3.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "KranAufg3".
 *
 * Model version              : 1.41
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Jul 29 09:06:09 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "KranAufg3.h"
#include "KranAufg3_private.h"
#include "KranAufg3_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_KranAufg3_T KranAufg3_B;

/* Block states (auto storage) */
DW_KranAufg3_T KranAufg3_DW;

/* Real-time model */
RT_MODEL_KranAufg3_T KranAufg3_M_;
RT_MODEL_KranAufg3_T *const KranAufg3_M = &KranAufg3_M_;

/* Model output function */
void KranAufg3_output(void)
{
  real_T rtb_Encoder500PPR[5];
  int32_T i;

  /* S-Function (Crane3D_Encoder): '<S1>/Encoder' */

  /* Level2 S-Function Block: '<S1>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Encoder 500PPR' */
  for (i = 0; i < 5; i++) {
    rtb_Encoder500PPR[i] = KranAufg3_P.Encoder500PPR_Gain *
      KranAufg3_B.Encoder[i];
  }

  /* End of Gain: '<S1>/Encoder 500PPR' */

  /* Gain: '<S1>/X Scale' */
  KranAufg3_B.XScale = KranAufg3_P.XScale_Gain * rtb_Encoder500PPR[0];

  /* Gain: '<S1>/Y Scale' */
  KranAufg3_B.YScale = KranAufg3_P.YScale_Gain * rtb_Encoder500PPR[1];

  /* Gain: '<S1>/Z Scale' */
  KranAufg3_B.ZScale = KranAufg3_P.ZScale_Gain * rtb_Encoder500PPR[2];

  /* Constant: '<Root>/Constant' */
  KranAufg3_B.ux = KranAufg3_P.Constant_Value_g;

  /* Fcn: '<Root>/Fcn' */
  KranAufg3_B.uy = (1.0 - KranAufg3_B.YScale) * 1.5;

  /* Constant: '<Root>/Constant1' */
  KranAufg3_B.Constant1 = KranAufg3_P.Constant1_Value_o;

  /* S-Function (Crane3D_Switch): '<S1>/LimitSwitch' */

  /* Level2 S-Function Block: '<S1>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/LimitSwitchGain' */
  KranAufg3_B.LimitSwitchGain[0] = KranAufg3_P.LimitSwitchGain_Gain *
    KranAufg3_B.LimitSwitch[0];
  KranAufg3_B.LimitSwitchGain[1] = KranAufg3_P.LimitSwitchGain_Gain *
    KranAufg3_B.LimitSwitch[1];
  KranAufg3_B.LimitSwitchGain[2] = KranAufg3_P.LimitSwitchGain_Gain *
    KranAufg3_B.LimitSwitch[2];

  /* Gain: '<S1>/X Angle Scale' */
  KranAufg3_B.XAngleScale = KranAufg3_P.XAngleScale_Gain * rtb_Encoder500PPR[3];

  /* Gain: '<S1>/Y Angle Scale' */
  KranAufg3_B.YAngleScale = KranAufg3_P.YAngleScale_Gain * rtb_Encoder500PPR[4];

  /* Switch: '<S2>/Switch' incorporates:
   *  Abs: '<S2>/Abs'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   */
  if (fabs(KranAufg3_B.XAngleScale) > KranAufg3_P.Switch_Threshold) {
    KranAufg3_B.Switch = KranAufg3_P.Constant_Value;
  } else {
    KranAufg3_B.Switch = KranAufg3_P.Constant1_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Abs: '<S2>/Abs1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   */
  if (fabs(KranAufg3_B.YAngleScale) > KranAufg3_P.Switch1_Threshold) {
    KranAufg3_B.Switch1 = KranAufg3_P.Constant2_Value;
  } else {
    KranAufg3_B.Switch1 = KranAufg3_P.Constant3_Value;
  }

  /* End of Switch: '<S2>/Switch1' */
  /* Stop: '<S2>/Stop Simulation' */
  if (KranAufg3_B.Switch != 0.0) {
    rtmSetStopRequested(KranAufg3_M, 1);
  }

  /* End of Stop: '<S2>/Stop Simulation' */

  /* Stop: '<S2>/Stop Simulation1' */
  if (KranAufg3_B.Switch1 != 0.0) {
    rtmSetStopRequested(KranAufg3_M, 1);
  }

  /* End of Stop: '<S2>/Stop Simulation1' */

  /* S-Function (Crane3D_PWM): '<S1>/PWM' */

  /* Level2 S-Function Block: '<S1>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Saturate: '<S1>/Saturation' */
  if (KranAufg3_B.ux > KranAufg3_P.Saturation_UpperSat) {
    KranAufg3_B.Saturation[0] = KranAufg3_P.Saturation_UpperSat;
  } else if (KranAufg3_B.ux < KranAufg3_P.Saturation_LowerSat) {
    KranAufg3_B.Saturation[0] = KranAufg3_P.Saturation_LowerSat;
  } else {
    KranAufg3_B.Saturation[0] = KranAufg3_B.ux;
  }

  if (KranAufg3_B.uy > KranAufg3_P.Saturation_UpperSat) {
    KranAufg3_B.Saturation[1] = KranAufg3_P.Saturation_UpperSat;
  } else if (KranAufg3_B.uy < KranAufg3_P.Saturation_LowerSat) {
    KranAufg3_B.Saturation[1] = KranAufg3_P.Saturation_LowerSat;
  } else {
    KranAufg3_B.Saturation[1] = KranAufg3_B.uy;
  }

  if (KranAufg3_B.Constant1 > KranAufg3_P.Saturation_UpperSat) {
    KranAufg3_B.Saturation[2] = KranAufg3_P.Saturation_UpperSat;
  } else if (KranAufg3_B.Constant1 < KranAufg3_P.Saturation_LowerSat) {
    KranAufg3_B.Saturation[2] = KranAufg3_P.Saturation_LowerSat;
  } else {
    KranAufg3_B.Saturation[2] = KranAufg3_B.Constant1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (Crane3D_LimitFlag): '<S1>/LimitFlag' */

  /* Level2 S-Function Block: '<S1>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg3_B.LimitFlagSource[0] = KranAufg3_P.LimitFlagSource_Value[0];

  /* Constant: '<S1>/LimitSource' */
  KranAufg3_B.LimitSource[0] = KranAufg3_P.LimitSource_Value[0];

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg3_B.LimitFlagSource[1] = KranAufg3_P.LimitFlagSource_Value[1];

  /* Constant: '<S1>/LimitSource' */
  KranAufg3_B.LimitSource[1] = KranAufg3_P.LimitSource_Value[1];

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg3_B.LimitFlagSource[2] = KranAufg3_P.LimitFlagSource_Value[2];

  /* Constant: '<S1>/LimitSource' */
  KranAufg3_B.LimitSource[2] = KranAufg3_P.LimitSource_Value[2];

  /* S-Function (Crane3D_SetLimit): '<S1>/SetLimit' */

  /* Level2 S-Function Block: '<S1>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (Crane3D_PWMPrescaler): '<S1>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/PWMPrescalerSource' */
  KranAufg3_B.PWMPrescalerSource = KranAufg3_P.PWMPrescalerSource_Value;

  /* S-Function (Crane3D_ResetEncoder): '<S1>/ResetEncoder' */

  /* Level2 S-Function Block: '<S1>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ResetSource' */
  for (i = 0; i < 5; i++) {
    KranAufg3_B.ResetSource[i] = KranAufg3_P.ResetSource_Value[i];
  }

  /* End of Constant: '<S1>/ResetSource' */

  /* S-Function (Crane3D_ResetSwitchFlag): '<S1>/ResetSwitchFlag ' */

  /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ResetSwitchFlagSource' */
  KranAufg3_B.ResetSwitchFlagSource[0] =
    KranAufg3_P.ResetSwitchFlagSource_Value[0];
  KranAufg3_B.ResetSwitchFlagSource[1] =
    KranAufg3_P.ResetSwitchFlagSource_Value[1];
  KranAufg3_B.ResetSwitchFlagSource[2] =
    KranAufg3_P.ResetSwitchFlagSource_Value[2];

  /* S-Function (Crane3D_ThermFlag): '<S1>/ThermFlag ' */

  /* Level2 S-Function Block: '<S1>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ThermFlagSource' */
  KranAufg3_B.ThermFlagSource[0] = KranAufg3_P.ThermFlagSource_Value[0];
  KranAufg3_B.ThermFlagSource[1] = KranAufg3_P.ThermFlagSource_Value[1];
  KranAufg3_B.ThermFlagSource[2] = KranAufg3_P.ThermFlagSource_Value[2];
}

/* Model update function */
void KranAufg3_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++KranAufg3_M->Timing.clockTick0)) {
    ++KranAufg3_M->Timing.clockTickH0;
  }

  KranAufg3_M->Timing.t[0] = KranAufg3_M->Timing.clockTick0 *
    KranAufg3_M->Timing.stepSize0 + KranAufg3_M->Timing.clockTickH0 *
    KranAufg3_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void KranAufg3_initialize(void)
{
  {
    int32_T i;

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg3_B.LimitFlagSource[0] = KranAufg3_P.LimitFlagSource_Value[0];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg3_B.LimitSource[0] = KranAufg3_P.LimitSource_Value[0];

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg3_B.LimitFlagSource[1] = KranAufg3_P.LimitFlagSource_Value[1];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg3_B.LimitSource[1] = KranAufg3_P.LimitSource_Value[1];

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg3_B.LimitFlagSource[2] = KranAufg3_P.LimitFlagSource_Value[2];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg3_B.LimitSource[2] = KranAufg3_P.LimitSource_Value[2];

    /* Start for Constant: '<S1>/PWMPrescalerSource' */
    KranAufg3_B.PWMPrescalerSource = KranAufg3_P.PWMPrescalerSource_Value;

    /* Start for Constant: '<S1>/ResetSource' */
    for (i = 0; i < 5; i++) {
      KranAufg3_B.ResetSource[i] = KranAufg3_P.ResetSource_Value[i];
    }

    /* End of Start for Constant: '<S1>/ResetSource' */
    /* Start for Constant: '<S1>/ResetSwitchFlagSource' */
    KranAufg3_B.ResetSwitchFlagSource[0] =
      KranAufg3_P.ResetSwitchFlagSource_Value[0];
    KranAufg3_B.ResetSwitchFlagSource[1] =
      KranAufg3_P.ResetSwitchFlagSource_Value[1];
    KranAufg3_B.ResetSwitchFlagSource[2] =
      KranAufg3_P.ResetSwitchFlagSource_Value[2];

    /* Start for Constant: '<S1>/ThermFlagSource' */
    KranAufg3_B.ThermFlagSource[0] = KranAufg3_P.ThermFlagSource_Value[0];
    KranAufg3_B.ThermFlagSource[1] = KranAufg3_P.ThermFlagSource_Value[1];
    KranAufg3_B.ThermFlagSource[2] = KranAufg3_P.ThermFlagSource_Value[2];
  }
}

/* Model terminate function */
void KranAufg3_terminate(void)
{
  /* Terminate for S-Function (Crane3D_Encoder): '<S1>/Encoder' */
  /* Level2 S-Function Block: '<S1>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_Switch): '<S1>/LimitSwitch' */
  /* Level2 S-Function Block: '<S1>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_PWM): '<S1>/PWM' */
  /* Level2 S-Function Block: '<S1>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_LimitFlag): '<S1>/LimitFlag' */
  /* Level2 S-Function Block: '<S1>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_SetLimit): '<S1>/SetLimit' */
  /* Level2 S-Function Block: '<S1>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_PWMPrescaler): '<S1>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ResetEncoder): '<S1>/ResetEncoder' */
  /* Level2 S-Function Block: '<S1>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ResetSwitchFlag): '<S1>/ResetSwitchFlag ' */
  /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ThermFlag): '<S1>/ThermFlag ' */
  /* Level2 S-Function Block: '<S1>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = KranAufg3_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  KranAufg3_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  KranAufg3_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  KranAufg3_initialize();
}

void MdlTerminate(void)
{
  KranAufg3_terminate();
}

/* Registration function */
RT_MODEL_KranAufg3_T *KranAufg3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)KranAufg3_M, 0,
                sizeof(RT_MODEL_KranAufg3_T));
  rtsiSetSolverName(&KranAufg3_M->solverInfo,"FixedStepDiscrete");
  KranAufg3_M->solverInfoPtr = (&KranAufg3_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = KranAufg3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    KranAufg3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    KranAufg3_M->Timing.sampleTimes = (&KranAufg3_M->Timing.sampleTimesArray[0]);
    KranAufg3_M->Timing.offsetTimes = (&KranAufg3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    KranAufg3_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    KranAufg3_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(KranAufg3_M, &KranAufg3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = KranAufg3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    KranAufg3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(KranAufg3_M, 10.0);
  KranAufg3_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  KranAufg3_M->Sizes.checksums[0] = (954250852U);
  KranAufg3_M->Sizes.checksums[1] = (1330828620U);
  KranAufg3_M->Sizes.checksums[2] = (2300349961U);
  KranAufg3_M->Sizes.checksums[3] = (2846223111U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    KranAufg3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(KranAufg3_M->extModeInfo,
      &KranAufg3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(KranAufg3_M->extModeInfo, KranAufg3_M->Sizes.checksums);
    rteiSetTPtr(KranAufg3_M->extModeInfo, rtmGetTPtr(KranAufg3_M));
  }

  KranAufg3_M->solverInfoPtr = (&KranAufg3_M->solverInfo);
  KranAufg3_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&KranAufg3_M->solverInfo, 0.01);
  rtsiSetSolverMode(&KranAufg3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  KranAufg3_M->blockIO = ((void *) &KranAufg3_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      KranAufg3_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      KranAufg3_B.ResetEncoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      KranAufg3_B.ResetSource[i] = 0.0;
    }

    KranAufg3_B.XScale = 0.0;
    KranAufg3_B.YScale = 0.0;
    KranAufg3_B.ZScale = 0.0;
    KranAufg3_B.ux = 0.0;
    KranAufg3_B.uy = 0.0;
    KranAufg3_B.Constant1 = 0.0;
    KranAufg3_B.LimitSwitch[0] = 0.0;
    KranAufg3_B.LimitSwitch[1] = 0.0;
    KranAufg3_B.LimitSwitch[2] = 0.0;
    KranAufg3_B.LimitSwitchGain[0] = 0.0;
    KranAufg3_B.LimitSwitchGain[1] = 0.0;
    KranAufg3_B.LimitSwitchGain[2] = 0.0;
    KranAufg3_B.XAngleScale = 0.0;
    KranAufg3_B.YAngleScale = 0.0;
    KranAufg3_B.Switch = 0.0;
    KranAufg3_B.Switch1 = 0.0;
    KranAufg3_B.PWM[0] = 0.0;
    KranAufg3_B.PWM[1] = 0.0;
    KranAufg3_B.PWM[2] = 0.0;
    KranAufg3_B.Saturation[0] = 0.0;
    KranAufg3_B.Saturation[1] = 0.0;
    KranAufg3_B.Saturation[2] = 0.0;
    KranAufg3_B.LimitFlag[0] = 0.0;
    KranAufg3_B.LimitFlag[1] = 0.0;
    KranAufg3_B.LimitFlag[2] = 0.0;
    KranAufg3_B.LimitFlagSource[0] = 0.0;
    KranAufg3_B.LimitFlagSource[1] = 0.0;
    KranAufg3_B.LimitFlagSource[2] = 0.0;
    KranAufg3_B.LimitSource[0] = 0.0;
    KranAufg3_B.LimitSource[1] = 0.0;
    KranAufg3_B.LimitSource[2] = 0.0;
    KranAufg3_B.SetLimit[0] = 0.0;
    KranAufg3_B.SetLimit[1] = 0.0;
    KranAufg3_B.SetLimit[2] = 0.0;
    KranAufg3_B.PWMPrescaler = 0.0;
    KranAufg3_B.PWMPrescalerSource = 0.0;
    KranAufg3_B.ResetSwitchFlag[0] = 0.0;
    KranAufg3_B.ResetSwitchFlag[1] = 0.0;
    KranAufg3_B.ResetSwitchFlag[2] = 0.0;
    KranAufg3_B.ResetSwitchFlagSource[0] = 0.0;
    KranAufg3_B.ResetSwitchFlagSource[1] = 0.0;
    KranAufg3_B.ResetSwitchFlagSource[2] = 0.0;
    KranAufg3_B.ThermFlag[0] = 0.0;
    KranAufg3_B.ThermFlag[1] = 0.0;
    KranAufg3_B.ThermFlag[2] = 0.0;
    KranAufg3_B.ThermFlagSource[0] = 0.0;
    KranAufg3_B.ThermFlagSource[1] = 0.0;
    KranAufg3_B.ThermFlagSource[2] = 0.0;
  }

  /* parameters */
  KranAufg3_M->defaultParam = ((real_T *)&KranAufg3_P);

  /* states (dwork) */
  KranAufg3_M->dwork = ((void *) &KranAufg3_DW);
  (void) memset((void *)&KranAufg3_DW, 0,
                sizeof(DW_KranAufg3_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    KranAufg3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &KranAufg3_M->NonInlinedSFcns.sfcnInfo;
    KranAufg3_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(KranAufg3_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &KranAufg3_M->Sizes.numSampTimes);
    KranAufg3_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(KranAufg3_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,KranAufg3_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(KranAufg3_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(KranAufg3_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(KranAufg3_M));
    rtssSetStepSizePtr(sfcnInfo, &KranAufg3_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(KranAufg3_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &KranAufg3_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &KranAufg3_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &KranAufg3_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &KranAufg3_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &KranAufg3_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &KranAufg3_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &KranAufg3_M->solverInfoPtr);
  }

  KranAufg3_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&KranAufg3_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    KranAufg3_M->childSfunctions =
      (&KranAufg3_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        KranAufg3_M->childSfunctions[i] =
          (&KranAufg3_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "KranAufg3/Crane 3D/Encoder");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "KranAufg3/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_Switch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = KranAufg3_B.Saturation;
          sfcnUPtrs[1] = &KranAufg3_B.Saturation[1];
          sfcnUPtrs[2] = &KranAufg3_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "KranAufg3/Crane 3D/PWM");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = KranAufg3_B.LimitFlagSource;
          sfcnUPtrs[1] = &KranAufg3_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &KranAufg3_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "KranAufg3/Crane 3D/LimitFlag");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_LimitFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = KranAufg3_B.LimitSource;
          sfcnUPtrs[1] = &KranAufg3_B.LimitSource[1];
          sfcnUPtrs[2] = &KranAufg3_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "KranAufg3/Crane 3D/SetLimit");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_SetLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &KranAufg3_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &KranAufg3_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "KranAufg3/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = KranAufg3_B.ResetSource;
            for (i1=0; i1 < 5; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "KranAufg3/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = KranAufg3_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &KranAufg3_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &KranAufg3_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "KranAufg3/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_ResetSwitchFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: KranAufg3/<S1>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = KranAufg3_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = KranAufg3_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = KranAufg3_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = KranAufg3_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg3_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg3_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg3_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg3_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg3_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg3_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg3_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = KranAufg3_B.ThermFlagSource;
          sfcnUPtrs[1] = &KranAufg3_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &KranAufg3_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg3_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg3_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "KranAufg3/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,KranAufg3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg3_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg3_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg3_P.pooled1);
      }

      /* registration */
      Crane3D_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  KranAufg3_M->Sizes.numContStates = (0);/* Number of continuous states */
  KranAufg3_M->Sizes.numY = (0);       /* Number of model outputs */
  KranAufg3_M->Sizes.numU = (0);       /* Number of model inputs */
  KranAufg3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  KranAufg3_M->Sizes.numSampTimes = (1);/* Number of sample times */
  KranAufg3_M->Sizes.numBlocks = (45); /* Number of blocks */
  KranAufg3_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  KranAufg3_M->Sizes.numBlockPrms = (65);/* Sum of parameter "widths" */
  return KranAufg3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
