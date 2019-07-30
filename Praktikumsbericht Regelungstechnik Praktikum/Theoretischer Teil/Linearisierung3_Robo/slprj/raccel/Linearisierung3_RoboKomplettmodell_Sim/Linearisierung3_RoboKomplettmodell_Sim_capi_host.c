#include "Linearisierung3_RoboKomplettmodell_Sim_capi_host.h"
static Linearisierung3_RoboKomplettmodell_Sim_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Linearisierung3_RoboKomplettmodell_Sim_host_InitializeDataMapInfo(&(root), "Linearisierung3_RoboKomplettmodell_Sim");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
