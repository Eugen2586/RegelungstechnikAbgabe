#include "__cf_Linearisierung3_RoboKomplettmodell_Sim.h"
#ifndef RTW_HEADER_Linearisierung3_RoboKomplettmodell_Sim_h_
#define RTW_HEADER_Linearisierung3_RoboKomplettmodell_Sim_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Linearisierung3_RoboKomplettmodell_Sim_COMMON_INCLUDES_
#define Linearisierung3_RoboKomplettmodell_Sim_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Linearisierung3_RoboKomplettmodell_Sim_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Linearisierung3_RoboKomplettmodell_Sim
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T aombjigbvg ; real_T ff1g0rhaxr ; real_T hh2r1bduht ;
real_T a3eswz50qp ; real_T almcigsjcz ; real_T ghyilyedm3 ; real_T falnacbn3v
; real_T dx5whzyu5r ; real_T lbnip45ppg ; } B ; typedef struct { struct {
void * LoggedData ; } lv3zwph1sf ; struct { void * LoggedData ; } e331xbplik
; struct { void * LoggedData ; } jpc05hhx2m ; int_T c1v3bsl5bw ; } DW ;
typedef struct { real_T k21wehejbd ; real_T jqtsttfsm3 ; real_T e3odexozdv ;
} X ; typedef struct { real_T k21wehejbd ; real_T jqtsttfsm3 ; real_T
e3odexozdv ; } XDot ; typedef struct { boolean_T k21wehejbd ; boolean_T
jqtsttfsm3 ; boolean_T e3odexozdv ; } XDis ; typedef struct { real_T
k21wehejbd ; real_T jqtsttfsm3 ; real_T e3odexozdv ; } CStateAbsTol ; typedef
struct { real_T ortg0ci3zn ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
Integrator_IC ; real_T Integrator_IC_gsygf3oxve ; real_T Integrator1_IC ;
real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
Linearisierung3_RoboKomplettmodell_Sim_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern size_t gblCurrentSFcnIdx ;
extern size_t * gblChildIdxToInfoIdx ; extern DataMapInfo * rt_dataMapInfoPtr
; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
