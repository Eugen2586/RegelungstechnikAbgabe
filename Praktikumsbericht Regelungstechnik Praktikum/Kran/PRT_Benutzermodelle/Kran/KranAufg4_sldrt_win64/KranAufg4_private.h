/*
 * KranAufg4_private.h
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

#ifndef RTW_HEADER_KranAufg4_private_h_
#define RTW_HEADER_KranAufg4_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void Crane3D_Encoder(SimStruct *rts);
extern void Crane3D_Switch(SimStruct *rts);
extern void Crane3D_PWM(SimStruct *rts);
extern void Crane3D_LimitFlag(SimStruct *rts);
extern void Crane3D_SetLimit(SimStruct *rts);
extern void Crane3D_PWMPrescaler(SimStruct *rts);
extern void Crane3D_ResetEncoder(SimStruct *rts);
extern void Crane3D_ResetSwitchFlag(SimStruct *rts);
extern void Crane3D_ThermFlag(SimStruct *rts);

#endif                                 /* RTW_HEADER_KranAufg4_private_h_ */
