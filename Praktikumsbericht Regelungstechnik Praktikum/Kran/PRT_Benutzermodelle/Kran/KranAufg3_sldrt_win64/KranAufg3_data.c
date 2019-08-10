/*
 * KranAufg3_data.c
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

/* Block parameters (auto storage) */
P_KranAufg3_T KranAufg3_P = {
  /*  Computed Parameter: pooled1
   * Referenced by:
   *   '<S1>/Encoder'
   *   '<S1>/LimitFlag'
   *   '<S1>/LimitSwitch'
   *   '<S1>/PWM'
   *   '<S1>/PWMPrescaler'
   *   '<S1>/ResetEncoder'
   *   '<S1>/ResetSwitchFlag '
   *   '<S1>/SetLimit'
   *   '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Variable: T_S
                                        * Referenced by:
                                        *   '<S1>/Encoder'
                                        *   '<S1>/LimitFlag'
                                        *   '<S1>/LimitSwitch'
                                        *   '<S1>/PWM'
                                        *   '<S1>/PWMPrescaler'
                                        *   '<S1>/ResetEncoder'
                                        *   '<S1>/ResetSwitchFlag '
                                        *   '<S1>/SetLimit'
                                        *   '<S1>/ThermFlag '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S1>/Encoder'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Encoder 500PPR'
                                        */
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 1 )
                                        * Referenced by: '<S1>/X Scale'
                                        */
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 2 )
                                        * Referenced by: '<S1>/Y Scale'
                                        */
  2.2150329724344985E-5,               /* Expression: Crane3D_ScaleCoeff( 3 )
                                        * Referenced by: '<S1>/Z Scale'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S1>/LimitSwitch'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/LimitSwitchGain'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 4 )
                                        * Referenced by: '<S1>/X Angle Scale'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 5 )
                                        * Referenced by: '<S1>/Y Angle Scale'
                                        */
  0.39269908169872414,                 /* Expression: pi/8
                                        * Referenced by: '<S2>/Switch'
                                        */
  0.39269908169872414,                 /* Expression: pi/8
                                        * Referenced by: '<S2>/Switch1'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S1>/PWM'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S1>/LimitFlag'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitFlag'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S1>/LimitFlagSource'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: Crane3D_RangeBit
   * Referenced by: '<S1>/LimitSource'
   */
  { 242.0, 384.0, 776.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S1>/SetLimit'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/SetLimit'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S1>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S1>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S1>/ResetEncoder'
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */

  /*  Expression: [0 0 0 0 0]
   * Referenced by: '<S1>/ResetSource'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S1>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S1>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },
  57344.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S1>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 }
};
