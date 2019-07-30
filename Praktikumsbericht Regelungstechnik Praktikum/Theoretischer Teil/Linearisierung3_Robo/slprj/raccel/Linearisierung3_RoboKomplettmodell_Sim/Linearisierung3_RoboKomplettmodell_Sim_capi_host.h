#include "__cf_Linearisierung3_RoboKomplettmodell_Sim.h"
#ifndef RTW_HEADER_Linearisierung3_RoboKomplettmodell_Sim_cap_host_h_
#define RTW_HEADER_Linearisierung3_RoboKomplettmodell_Sim_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
Linearisierung3_RoboKomplettmodell_Sim_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void Linearisierung3_RoboKomplettmodell_Sim_host_InitializeDataMapInfo (
Linearisierung3_RoboKomplettmodell_Sim_host_DataMapInfo_T * dataMap , const
char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
