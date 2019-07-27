#include "__cf_Linearisierung3_RoboKomplettmodell_Sim.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Linearisierung3_RoboKomplettmodell_Sim_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Linearisierung3_RoboKomplettmodell_Sim.h"
#include "Linearisierung3_RoboKomplettmodell_Sim_capi.h"
#include "Linearisierung3_RoboKomplettmodell_Sim_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Fcn" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Fcn1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Fcn" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Sum1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 ,
0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 9 ,
TARGET_STRING ( "Linearisierung3_RoboKomplettmodell_Sim/Step" ) ,
TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Step" ) , TARGET_STRING ( "Before" )
, 0 , 0 , 0 } , { 11 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Step" ) , TARGET_STRING ( "After" ) ,
0 , 0 , 0 } , { 12 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Motorsystem/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"Linearisierung3_RoboKomplettmodell_Sim/Roboterarm/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [
] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lbnip45ppg , & rtB . falnacbn3v ,
& rtB . ff1g0rhaxr , & rtB . dx5whzyu5r , & rtB . ghyilyedm3 , & rtB .
aombjigbvg , & rtB . hh2r1bduht , & rtB . almcigsjcz , & rtB . a3eswz50qp , &
rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , & rtP .
Integrator_IC_gsygf3oxve , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Integrator_IC , & rtP . Integrator1_IC , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 9 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 8 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 3892312185U , 2611847350U , 2060001642U , 2064429463U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo *
Linearisierung3_RoboKomplettmodell_Sim_GetCAPIStaticMap ( ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Linearisierung3_RoboKomplettmodell_Sim_InitializeDataMapInfo ( ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Linearisierung3_RoboKomplettmodell_Sim_host_InitializeDataMapInfo (
Linearisierung3_RoboKomplettmodell_Sim_host_DataMapInfo_T * dataMap , const
char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
