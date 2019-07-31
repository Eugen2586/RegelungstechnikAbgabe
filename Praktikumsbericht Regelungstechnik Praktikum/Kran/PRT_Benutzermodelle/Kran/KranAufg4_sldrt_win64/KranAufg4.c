/*
 * KranAufg4.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "KranAufg4".
 *
 * Model version              : 1.43
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Jul 29 12:25:31 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "KranAufg4.h"
#include "KranAufg4_private.h"
#include "KranAufg4_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_KranAufg4_T KranAufg4_B;

/* Block states (auto storage) */
DW_KranAufg4_T KranAufg4_DW;

/* Real-time model */
RT_MODEL_KranAufg4_T KranAufg4_M_;
RT_MODEL_KranAufg4_T *const KranAufg4_M = &KranAufg4_M_;

/* Model output function */
void KranAufg4_output(void)
{
  real_T rtb_Encoder500PPR[5];
  real_T rtb_DiscreteTransferFcn;
  real_T Fcn;
  int32_T i;

  /* S-Function (Crane3D_Encoder): '<S1>/Encoder' */

  /* Level2 S-Function Block: '<S1>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Encoder 500PPR' */
  for (i = 0; i < 5; i++) {
    rtb_Encoder500PPR[i] = KranAufg4_P.Encoder500PPR_Gain *
      KranAufg4_B.Encoder[i];
  }

  /* End of Gain: '<S1>/Encoder 500PPR' */

  /* Gain: '<S1>/X Scale' */
  KranAufg4_B.XScale = KranAufg4_P.XScale_Gain * rtb_Encoder500PPR[0];

  /* Gain: '<S1>/Y Scale' */
  KranAufg4_B.YScale = KranAufg4_P.YScale_Gain * rtb_Encoder500PPR[1];

  /* Gain: '<S1>/Z Scale' */
  KranAufg4_B.ZScale = KranAufg4_P.ZScale_Gain * rtb_Encoder500PPR[2];

  /* Constant: '<Root>/Constant' */
  KranAufg4_B.ux = KranAufg4_P.Constant_Value_g;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_DiscreteTransferFcn = KranAufg4_P.Constant3_Value_o - KranAufg4_B.YScale;

  /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' incorporates:
   *  Fcn: '<S2>/Fcn'
   */
  KranAufg4_DW.DiscreteTransferFcn_tmp = (rtb_DiscreteTransferFcn * 1.14 -
    KranAufg4_P.DiscreteTransferFcn_DenCoef[1] *
    KranAufg4_DW.DiscreteTransferFcn_states) /
    KranAufg4_P.DiscreteTransferFcn_DenCoef[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
   *  Product: '<S2>/Product'
   */
  rtb_DiscreteTransferFcn = (KranAufg4_P.DiscreteTransferFcn_NumCoef[0] *
    KranAufg4_DW.DiscreteTransferFcn_tmp +
    KranAufg4_P.DiscreteTransferFcn_NumCoef[1] *
    KranAufg4_DW.DiscreteTransferFcn_states) + rtb_DiscreteTransferFcn *
    KranAufg4_P.Kpy;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_DiscreteTransferFcn > KranAufg4_P.Saturation_UpperSat) {
    Fcn = KranAufg4_P.Saturation_UpperSat;
  } else if (rtb_DiscreteTransferFcn < KranAufg4_P.Saturation_LowerSat) {
    Fcn = KranAufg4_P.Saturation_LowerSat;
  } else {
    Fcn = rtb_DiscreteTransferFcn;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S1>/Y Angle Scale' */
  KranAufg4_B.YAngleScale = KranAufg4_P.YAngleScale_Gain * rtb_Encoder500PPR[4];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_DiscreteTransferFcn = KranAufg4_P.Constant2_Value_p -
    KranAufg4_B.YAngleScale;

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' incorporates:
   *  Fcn: '<S3>/Fcn'
   */
  KranAufg4_DW.DiscreteTransferFcn_tmp_e = (rtb_DiscreteTransferFcn * -0.927 -
    KranAufg4_P.DiscreteTransferFcn_DenCoef_a[1] *
    KranAufg4_DW.DiscreteTransferFcn_states_n) /
    KranAufg4_P.DiscreteTransferFcn_DenCoef_a[0];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
   *  Product: '<S3>/Product'
   *  Sum: '<S3>/Sum'
   */
  KranAufg4_B.uy = ((KranAufg4_P.DiscreteTransferFcn_NumCoef_j[0] *
                     KranAufg4_DW.DiscreteTransferFcn_tmp_e +
                     KranAufg4_P.DiscreteTransferFcn_NumCoef_j[1] *
                     KranAufg4_DW.DiscreteTransferFcn_states_n) +
                    rtb_DiscreteTransferFcn * KranAufg4_P.Kpa) + Fcn;

  /* Constant: '<Root>/Constant1' */
  KranAufg4_B.Constant1 = KranAufg4_P.Constant1_Value_o;

  /* S-Function (Crane3D_Switch): '<S1>/LimitSwitch' */

  /* Level2 S-Function Block: '<S1>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/LimitSwitchGain' */
  KranAufg4_B.LimitSwitchGain[0] = KranAufg4_P.LimitSwitchGain_Gain *
    KranAufg4_B.LimitSwitch[0];
  KranAufg4_B.LimitSwitchGain[1] = KranAufg4_P.LimitSwitchGain_Gain *
    KranAufg4_B.LimitSwitch[1];
  KranAufg4_B.LimitSwitchGain[2] = KranAufg4_P.LimitSwitchGain_Gain *
    KranAufg4_B.LimitSwitch[2];

  /* Gain: '<S1>/X Angle Scale' */
  KranAufg4_B.XAngleScale = KranAufg4_P.XAngleScale_Gain * rtb_Encoder500PPR[3];

  /* Switch: '<S4>/Switch' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  if (fabs(KranAufg4_B.XAngleScale) > KranAufg4_P.Switch_Threshold) {
    KranAufg4_B.Switch = KranAufg4_P.Constant_Value;
  } else {
    KranAufg4_B.Switch = KranAufg4_P.Constant1_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S4>/Switch1' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   */
  if (fabs(KranAufg4_B.YAngleScale) > KranAufg4_P.Switch1_Threshold) {
    KranAufg4_B.Switch1 = KranAufg4_P.Constant2_Value;
  } else {
    KranAufg4_B.Switch1 = KranAufg4_P.Constant3_Value;
  }

  /* End of Switch: '<S4>/Switch1' */
  /* Stop: '<S4>/Stop Simulation' */
  if (KranAufg4_B.Switch != 0.0) {
    rtmSetStopRequested(KranAufg4_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation' */

  /* Stop: '<S4>/Stop Simulation1' */
  if (KranAufg4_B.Switch1 != 0.0) {
    rtmSetStopRequested(KranAufg4_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation1' */

  /* S-Function (Crane3D_PWM): '<S1>/PWM' */

  /* Level2 S-Function Block: '<S1>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Saturate: '<S1>/Saturation' */
  if (KranAufg4_B.ux > KranAufg4_P.Saturation_UpperSat_n) {
    KranAufg4_B.Saturation[0] = KranAufg4_P.Saturation_UpperSat_n;
  } else if (KranAufg4_B.ux < KranAufg4_P.Saturation_LowerSat_n) {
    KranAufg4_B.Saturation[0] = KranAufg4_P.Saturation_LowerSat_n;
  } else {
    KranAufg4_B.Saturation[0] = KranAufg4_B.ux;
  }

  if (KranAufg4_B.uy > KranAufg4_P.Saturation_UpperSat_n) {
    KranAufg4_B.Saturation[1] = KranAufg4_P.Saturation_UpperSat_n;
  } else if (KranAufg4_B.uy < KranAufg4_P.Saturation_LowerSat_n) {
    KranAufg4_B.Saturation[1] = KranAufg4_P.Saturation_LowerSat_n;
  } else {
    KranAufg4_B.Saturation[1] = KranAufg4_B.uy;
  }

  if (KranAufg4_B.Constant1 > KranAufg4_P.Saturation_UpperSat_n) {
    KranAufg4_B.Saturation[2] = KranAufg4_P.Saturation_UpperSat_n;
  } else if (KranAufg4_B.Constant1 < KranAufg4_P.Saturation_LowerSat_n) {
    KranAufg4_B.Saturation[2] = KranAufg4_P.Saturation_LowerSat_n;
  } else {
    KranAufg4_B.Saturation[2] = KranAufg4_B.Constant1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (Crane3D_LimitFlag): '<S1>/LimitFlag' */

  /* Level2 S-Function Block: '<S1>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg4_B.LimitFlagSource[0] = KranAufg4_P.LimitFlagSource_Value[0];

  /* Constant: '<S1>/LimitSource' */
  KranAufg4_B.LimitSource[0] = KranAufg4_P.LimitSource_Value[0];

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg4_B.LimitFlagSource[1] = KranAufg4_P.LimitFlagSource_Value[1];

  /* Constant: '<S1>/LimitSource' */
  KranAufg4_B.LimitSource[1] = KranAufg4_P.LimitSource_Value[1];

  /* Constant: '<S1>/LimitFlagSource' */
  KranAufg4_B.LimitFlagSource[2] = KranAufg4_P.LimitFlagSource_Value[2];

  /* Constant: '<S1>/LimitSource' */
  KranAufg4_B.LimitSource[2] = KranAufg4_P.LimitSource_Value[2];

  /* S-Function (Crane3D_SetLimit): '<S1>/SetLimit' */

  /* Level2 S-Function Block: '<S1>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (Crane3D_PWMPrescaler): '<S1>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/PWMPrescalerSource' */
  KranAufg4_B.PWMPrescalerSource = KranAufg4_P.PWMPrescalerSource_Value;

  /* S-Function (Crane3D_ResetEncoder): '<S1>/ResetEncoder' */

  /* Level2 S-Function Block: '<S1>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ResetSource' */
  for (i = 0; i < 5; i++) {
    KranAufg4_B.ResetSource[i] = KranAufg4_P.ResetSource_Value[i];
  }

  /* End of Constant: '<S1>/ResetSource' */

  /* S-Function (Crane3D_ResetSwitchFlag): '<S1>/ResetSwitchFlag ' */

  /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ResetSwitchFlagSource' */
  KranAufg4_B.ResetSwitchFlagSource[0] =
    KranAufg4_P.ResetSwitchFlagSource_Value[0];
  KranAufg4_B.ResetSwitchFlagSource[1] =
    KranAufg4_P.ResetSwitchFlagSource_Value[1];
  KranAufg4_B.ResetSwitchFlagSource[2] =
    KranAufg4_P.ResetSwitchFlagSource_Value[2];

  /* S-Function (Crane3D_ThermFlag): '<S1>/ThermFlag ' */

  /* Level2 S-Function Block: '<S1>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ThermFlagSource' */
  KranAufg4_B.ThermFlagSource[0] = KranAufg4_P.ThermFlagSource_Value[0];
  KranAufg4_B.ThermFlagSource[1] = KranAufg4_P.ThermFlagSource_Value[1];
  KranAufg4_B.ThermFlagSource[2] = KranAufg4_P.ThermFlagSource_Value[2];
}

/* Model update function */
void KranAufg4_update(void)
{
  /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  KranAufg4_DW.DiscreteTransferFcn_states = KranAufg4_DW.DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' */
  KranAufg4_DW.DiscreteTransferFcn_states_n =
    KranAufg4_DW.DiscreteTransferFcn_tmp_e;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++KranAufg4_M->Timing.clockTick0)) {
    ++KranAufg4_M->Timing.clockTickH0;
  }

  KranAufg4_M->Timing.t[0] = KranAufg4_M->Timing.clockTick0 *
    KranAufg4_M->Timing.stepSize0 + KranAufg4_M->Timing.clockTickH0 *
    KranAufg4_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void KranAufg4_initialize(void)
{
  {
    int32_T i;

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg4_B.LimitFlagSource[0] = KranAufg4_P.LimitFlagSource_Value[0];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg4_B.LimitSource[0] = KranAufg4_P.LimitSource_Value[0];

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg4_B.LimitFlagSource[1] = KranAufg4_P.LimitFlagSource_Value[1];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg4_B.LimitSource[1] = KranAufg4_P.LimitSource_Value[1];

    /* Start for Constant: '<S1>/LimitFlagSource' */
    KranAufg4_B.LimitFlagSource[2] = KranAufg4_P.LimitFlagSource_Value[2];

    /* Start for Constant: '<S1>/LimitSource' */
    KranAufg4_B.LimitSource[2] = KranAufg4_P.LimitSource_Value[2];

    /* Start for Constant: '<S1>/PWMPrescalerSource' */
    KranAufg4_B.PWMPrescalerSource = KranAufg4_P.PWMPrescalerSource_Value;

    /* Start for Constant: '<S1>/ResetSource' */
    for (i = 0; i < 5; i++) {
      KranAufg4_B.ResetSource[i] = KranAufg4_P.ResetSource_Value[i];
    }

    /* End of Start for Constant: '<S1>/ResetSource' */
    /* Start for Constant: '<S1>/ResetSwitchFlagSource' */
    KranAufg4_B.ResetSwitchFlagSource[0] =
      KranAufg4_P.ResetSwitchFlagSource_Value[0];
    KranAufg4_B.ResetSwitchFlagSource[1] =
      KranAufg4_P.ResetSwitchFlagSource_Value[1];
    KranAufg4_B.ResetSwitchFlagSource[2] =
      KranAufg4_P.ResetSwitchFlagSource_Value[2];

    /* Start for Constant: '<S1>/ThermFlagSource' */
    KranAufg4_B.ThermFlagSource[0] = KranAufg4_P.ThermFlagSource_Value[0];
    KranAufg4_B.ThermFlagSource[1] = KranAufg4_P.ThermFlagSource_Value[1];
    KranAufg4_B.ThermFlagSource[2] = KranAufg4_P.ThermFlagSource_Value[2];
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  KranAufg4_DW.DiscreteTransferFcn_states =
    KranAufg4_P.DiscreteTransferFcn_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' */
  KranAufg4_DW.DiscreteTransferFcn_states_n =
    KranAufg4_P.DiscreteTransferFcn_InitialStates_a;
}

/* Model terminate function */
void KranAufg4_terminate(void)
{
  /* Terminate for S-Function (Crane3D_Encoder): '<S1>/Encoder' */
  /* Level2 S-Function Block: '<S1>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_Switch): '<S1>/LimitSwitch' */
  /* Level2 S-Function Block: '<S1>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_PWM): '<S1>/PWM' */
  /* Level2 S-Function Block: '<S1>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_LimitFlag): '<S1>/LimitFlag' */
  /* Level2 S-Function Block: '<S1>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_SetLimit): '<S1>/SetLimit' */
  /* Level2 S-Function Block: '<S1>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_PWMPrescaler): '<S1>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ResetEncoder): '<S1>/ResetEncoder' */
  /* Level2 S-Function Block: '<S1>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ResetSwitchFlag): '<S1>/ResetSwitchFlag ' */
  /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (Crane3D_ThermFlag): '<S1>/ThermFlag ' */
  /* Level2 S-Function Block: '<S1>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = KranAufg4_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  KranAufg4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  KranAufg4_update();
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
  KranAufg4_initialize();
}

void MdlTerminate(void)
{
  KranAufg4_terminate();
}

/* Registration function */
RT_MODEL_KranAufg4_T *KranAufg4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)KranAufg4_M, 0,
                sizeof(RT_MODEL_KranAufg4_T));
  rtsiSetSolverName(&KranAufg4_M->solverInfo,"FixedStepDiscrete");
  KranAufg4_M->solverInfoPtr = (&KranAufg4_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = KranAufg4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    KranAufg4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    KranAufg4_M->Timing.sampleTimes = (&KranAufg4_M->Timing.sampleTimesArray[0]);
    KranAufg4_M->Timing.offsetTimes = (&KranAufg4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    KranAufg4_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    KranAufg4_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(KranAufg4_M, &KranAufg4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = KranAufg4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    KranAufg4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(KranAufg4_M, 10.0);
  KranAufg4_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  KranAufg4_M->Sizes.checksums[0] = (2104128675U);
  KranAufg4_M->Sizes.checksums[1] = (3964254063U);
  KranAufg4_M->Sizes.checksums[2] = (3061114180U);
  KranAufg4_M->Sizes.checksums[3] = (2804016967U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    KranAufg4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(KranAufg4_M->extModeInfo,
      &KranAufg4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(KranAufg4_M->extModeInfo, KranAufg4_M->Sizes.checksums);
    rteiSetTPtr(KranAufg4_M->extModeInfo, rtmGetTPtr(KranAufg4_M));
  }

  KranAufg4_M->solverInfoPtr = (&KranAufg4_M->solverInfo);
  KranAufg4_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&KranAufg4_M->solverInfo, 0.01);
  rtsiSetSolverMode(&KranAufg4_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  KranAufg4_M->blockIO = ((void *) &KranAufg4_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      KranAufg4_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      KranAufg4_B.ResetEncoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      KranAufg4_B.ResetSource[i] = 0.0;
    }

    KranAufg4_B.XScale = 0.0;
    KranAufg4_B.YScale = 0.0;
    KranAufg4_B.ZScale = 0.0;
    KranAufg4_B.ux = 0.0;
    KranAufg4_B.YAngleScale = 0.0;
    KranAufg4_B.uy = 0.0;
    KranAufg4_B.Constant1 = 0.0;
    KranAufg4_B.LimitSwitch[0] = 0.0;
    KranAufg4_B.LimitSwitch[1] = 0.0;
    KranAufg4_B.LimitSwitch[2] = 0.0;
    KranAufg4_B.LimitSwitchGain[0] = 0.0;
    KranAufg4_B.LimitSwitchGain[1] = 0.0;
    KranAufg4_B.LimitSwitchGain[2] = 0.0;
    KranAufg4_B.XAngleScale = 0.0;
    KranAufg4_B.Switch = 0.0;
    KranAufg4_B.Switch1 = 0.0;
    KranAufg4_B.PWM[0] = 0.0;
    KranAufg4_B.PWM[1] = 0.0;
    KranAufg4_B.PWM[2] = 0.0;
    KranAufg4_B.Saturation[0] = 0.0;
    KranAufg4_B.Saturation[1] = 0.0;
    KranAufg4_B.Saturation[2] = 0.0;
    KranAufg4_B.LimitFlag[0] = 0.0;
    KranAufg4_B.LimitFlag[1] = 0.0;
    KranAufg4_B.LimitFlag[2] = 0.0;
    KranAufg4_B.LimitFlagSource[0] = 0.0;
    KranAufg4_B.LimitFlagSource[1] = 0.0;
    KranAufg4_B.LimitFlagSource[2] = 0.0;
    KranAufg4_B.LimitSource[0] = 0.0;
    KranAufg4_B.LimitSource[1] = 0.0;
    KranAufg4_B.LimitSource[2] = 0.0;
    KranAufg4_B.SetLimit[0] = 0.0;
    KranAufg4_B.SetLimit[1] = 0.0;
    KranAufg4_B.SetLimit[2] = 0.0;
    KranAufg4_B.PWMPrescaler = 0.0;
    KranAufg4_B.PWMPrescalerSource = 0.0;
    KranAufg4_B.ResetSwitchFlag[0] = 0.0;
    KranAufg4_B.ResetSwitchFlag[1] = 0.0;
    KranAufg4_B.ResetSwitchFlag[2] = 0.0;
    KranAufg4_B.ResetSwitchFlagSource[0] = 0.0;
    KranAufg4_B.ResetSwitchFlagSource[1] = 0.0;
    KranAufg4_B.ResetSwitchFlagSource[2] = 0.0;
    KranAufg4_B.ThermFlag[0] = 0.0;
    KranAufg4_B.ThermFlag[1] = 0.0;
    KranAufg4_B.ThermFlag[2] = 0.0;
    KranAufg4_B.ThermFlagSource[0] = 0.0;
    KranAufg4_B.ThermFlagSource[1] = 0.0;
    KranAufg4_B.ThermFlagSource[2] = 0.0;
  }

  /* parameters */
  KranAufg4_M->defaultParam = ((real_T *)&KranAufg4_P);

  /* states (dwork) */
  KranAufg4_M->dwork = ((void *) &KranAufg4_DW);
  (void) memset((void *)&KranAufg4_DW, 0,
                sizeof(DW_KranAufg4_T));
  KranAufg4_DW.DiscreteTransferFcn_states = 0.0;
  KranAufg4_DW.DiscreteTransferFcn_states_n = 0.0;
  KranAufg4_DW.DiscreteTransferFcn_tmp = 0.0;
  KranAufg4_DW.DiscreteTransferFcn_tmp_e = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    KranAufg4_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &KranAufg4_M->NonInlinedSFcns.sfcnInfo;
    KranAufg4_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(KranAufg4_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &KranAufg4_M->Sizes.numSampTimes);
    KranAufg4_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(KranAufg4_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,KranAufg4_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(KranAufg4_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(KranAufg4_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(KranAufg4_M));
    rtssSetStepSizePtr(sfcnInfo, &KranAufg4_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(KranAufg4_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &KranAufg4_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &KranAufg4_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &KranAufg4_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &KranAufg4_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &KranAufg4_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &KranAufg4_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &KranAufg4_M->solverInfoPtr);
  }

  KranAufg4_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&KranAufg4_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    KranAufg4_M->childSfunctions =
      (&KranAufg4_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        KranAufg4_M->childSfunctions[i] =
          (&KranAufg4_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: KranAufg4/<S1>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "KranAufg4/Crane 3D/Encoder");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "KranAufg4/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = KranAufg4_B.Saturation;
          sfcnUPtrs[1] = &KranAufg4_B.Saturation[1];
          sfcnUPtrs[2] = &KranAufg4_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "KranAufg4/Crane 3D/PWM");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = KranAufg4_B.LimitFlagSource;
          sfcnUPtrs[1] = &KranAufg4_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &KranAufg4_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "KranAufg4/Crane 3D/LimitFlag");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = KranAufg4_B.LimitSource;
          sfcnUPtrs[1] = &KranAufg4_B.LimitSource[1];
          sfcnUPtrs[2] = &KranAufg4_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "KranAufg4/Crane 3D/SetLimit");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &KranAufg4_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &KranAufg4_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "KranAufg4/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = KranAufg4_B.ResetSource;
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
          &KranAufg4_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "KranAufg4/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = KranAufg4_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &KranAufg4_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &KranAufg4_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "KranAufg4/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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

    /* Level2 S-Function Block: KranAufg4/<S1>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = KranAufg4_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = KranAufg4_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = KranAufg4_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = KranAufg4_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &KranAufg4_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, KranAufg4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &KranAufg4_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &KranAufg4_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &KranAufg4_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &KranAufg4_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &KranAufg4_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &KranAufg4_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = KranAufg4_B.ThermFlagSource;
          sfcnUPtrs[1] = &KranAufg4_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &KranAufg4_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &KranAufg4_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) KranAufg4_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "KranAufg4/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,KranAufg4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &KranAufg4_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)KranAufg4_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)KranAufg4_P.pooled1);
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
  KranAufg4_M->Sizes.numContStates = (0);/* Number of continuous states */
  KranAufg4_M->Sizes.numY = (0);       /* Number of model outputs */
  KranAufg4_M->Sizes.numU = (0);       /* Number of model inputs */
  KranAufg4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  KranAufg4_M->Sizes.numSampTimes = (1);/* Number of sample times */
  KranAufg4_M->Sizes.numBlocks = (60); /* Number of blocks */
  KranAufg4_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  KranAufg4_M->Sizes.numBlockPrms = (81);/* Sum of parameter "widths" */
  return KranAufg4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
