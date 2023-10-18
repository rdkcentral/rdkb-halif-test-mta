#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
//#include "cmock.h"
#include "mta_hal.h"


INT mta_hal_InitDB(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT mta_hal_GetDHCPInfo(PMTAMGMT_MTA_DHCP_INFO pInfo)
{
  /*TODO: Implement Me!*/
  (void)pInfo;
  return (INT)0;
}

INT mta_hal_GetDHCPV6Info(PMTAMGMT_MTA_DHCPv6_INFO pInfo)
{
  /*TODO: Implement Me!*/
  (void)pInfo;
  return (INT)0;
}

ULONG mta_hal_LineTableGetNumberOfEntries(void)
{
  /*TODO: Implement Me!*/
  return (ULONG)0;
}

INT mta_hal_LineTableGetEntry(ULONG Index, PMTAMGMT_MTA_LINETABLE_INFO pEntry)
{
  /*TODO: Implement Me!*/
  (void)Index;
  (void)pEntry;
  return (INT)0;
}

INT mta_hal_TriggerDiagnostics(ULONG Index)
{
  /*TODO: Implement Me!*/
  (void)Index;
  return (INT)0;
}

INT mta_hal_GetServiceFlow(ULONG* Count, PMTAMGMT_MTA_SERVICE_FLOW* ppCfg)
{
  /*TODO: Implement Me!*/
  (void)Count;
  (void)ppCfg;
  return (INT)0;
}

INT mta_hal_DectGetEnable(BOOLEAN* pBool)
{
  /*TODO: Implement Me!*/
  (void)pBool;
  return (INT)0;
}

INT mta_hal_DectSetEnable(BOOLEAN bBool)
{
  /*TODO: Implement Me!*/
  (void)bBool;
  return (INT)0;
}

INT mta_hal_DectGetRegistrationMode(BOOLEAN* pBool)
{
  /*TODO: Implement Me!*/
  (void)pBool;
  return (INT)0;
}

INT mta_hal_DectSetRegistrationMode(BOOLEAN bBool)
{
  /*TODO: Implement Me!*/
  (void)bBool;
  return (INT)0;
}

INT mta_hal_DectDeregisterDectHandset(ULONG uValue)
{
  /*TODO: Implement Me!*/
  (void)uValue;
  return (INT)0;
}

INT mta_hal_GetDect(PMTAMGMT_MTA_DECT pDect)
{
  /*TODO: Implement Me!*/
  (void)pDect;
  return (INT)0;
}

INT mta_hal_GetDectPIN(char* pPINString)
{
  /*TODO: Implement Me!*/
  (void)pPINString;
  return (INT)0;
}

INT mta_hal_SetDectPIN(char* pPINString)
{
  /*TODO: Implement Me!*/
  (void)pPINString;
  return (INT)0;
}

INT mta_hal_GetHandsets(ULONG* pulCount, PMTAMGMT_MTA_HANDSETS_INFO* ppHandsets)
{
  /*TODO: Implement Me!*/
  (void)pulCount;
  (void)ppHandsets;
  return (INT)0;
}

INT mta_hal_GetCalls(ULONG InstanceNumber, ULONG* Count, PMTAMGMT_MTA_CALLS* ppCfg)
{
  /*TODO: Implement Me!*/
  (void)InstanceNumber;
  (void)Count;
  (void)ppCfg;
  return (INT)0;
}

INT mta_hal_GetCALLP(ULONG LineNumber, PMTAMGMT_MTA_CALLP pCallp)
{
  /*TODO: Implement Me!*/
  (void)LineNumber;
  (void)pCallp;
  return (INT)0;
}

INT mta_hal_GetDSXLogs(ULONG* Count, PMTAMGMT_MTA_DSXLOG* ppDSXLog)
{
  /*TODO: Implement Me!*/
  (void)Count;
  (void)ppDSXLog;
  return (INT)0;
}

INT mta_hal_GetDSXLogEnable(BOOLEAN* pBool)
{
  /*TODO: Implement Me!*/
  (void)pBool;
  return (INT)0;
}

INT mta_hal_SetDSXLogEnable(BOOLEAN Bool)
{
  /*TODO: Implement Me!*/
  (void)Bool;
  return (INT)0;
}

INT mta_hal_ClearDSXLog(BOOLEAN Bool)
{
  /*TODO: Implement Me!*/
  (void)Bool;
  return (INT)0;
}

INT mta_hal_GetCallSignallingLogEnable(BOOLEAN* pBool)
{
  /*TODO: Implement Me!*/
  (void)pBool;
  return (INT)0;
}

INT mta_hal_SetCallSignallingLogEnable(BOOLEAN Bool)
{
  /*TODO: Implement Me!*/
  (void)Bool;
  return (INT)0;
}

INT mta_hal_ClearCallSignallingLog(BOOLEAN Bool)
{
  /*TODO: Implement Me!*/
  (void)Bool;
  return (INT)0;
}

INT mta_hal_GetMtaLog(ULONG* Count, PMTAMGMT_MTA_MTALOG_FULL* ppCfg)
{
  /*TODO: Implement Me!*/
  (void)Count;
  (void)ppCfg;
  return (INT)0;
}

INT mta_hal_BatteryGetInstalled(BOOLEAN* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetTotalCapacity(ULONG* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetActualCapacity(ULONG* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetRemainingCharge(ULONG* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetRemainingTime(ULONG* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetNumberofCycles(ULONG* Val)
{
  /*TODO: Implement Me!*/
  (void)Val;
  return (INT)0;
}

INT mta_hal_BatteryGetPowerStatus(CHAR* Val, ULONG* len)
{
  /*TODO: Implement Me!*/
  (void)Val;
  (void)len;
  return (INT)0;
}

INT mta_hal_BatteryGetCondition(CHAR* Val, ULONG* len)
{
  /*TODO: Implement Me!*/
  (void)Val;
  (void)len;
  return (INT)0;
}

INT mta_hal_BatteryGetStatus(CHAR* Val, ULONG* len)
{
  /*TODO: Implement Me!*/
  (void)Val;
  (void)len;
  return (INT)0;
}

INT mta_hal_BatteryGetLife(CHAR* Val, ULONG* len)
{
  /*TODO: Implement Me!*/
  (void)Val;
  (void)len;
  return (INT)0;
}

INT mta_hal_BatteryGetInfo(PMTAMGMT_MTA_BATTERY_INFO pInfo)
{
  /*TODO: Implement Me!*/
  (void)pInfo;
  return (INT)0;
}

INT mta_hal_BatteryGetPowerSavingModeStatus(ULONG* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

INT mta_hal_Get_MTAResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT mta_hal_Get_LineResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT mta_hal_ClearCalls(ULONG InstanceNumber)
{
  /*TODO: Implement Me!*/
  (void)InstanceNumber;
  return (INT)0;
}

INT mta_hal_getDhcpStatus(MTAMGMT_MTA_STATUS* output_pIpv4status, MTAMGMT_MTA_STATUS* output_pIpv6status)
{
  /*TODO: Implement Me!*/
  (void)output_pIpv4status;
  (void)output_pIpv6status;
  return (INT)0;
}

INT mta_hal_getConfigFileStatus(MTAMGMT_MTA_STATUS* poutput_status)
{
  /*TODO: Implement Me!*/
  (void)poutput_status;
  return (INT)0;
}

INT mta_hal_getLineRegisterStatus(MTAMGMT_MTA_STATUS* output_status_array, int array_size)
{
  /*TODO: Implement Me!*/
  (void)output_status_array;
  (void)array_size;
  return (INT)0;
}

INT mta_hal_devResetNow(BOOLEAN bResetValue)
{
  /*TODO: Implement Me!*/
  (void)bResetValue;
  return (INT)0;
}

INT mta_hal_getMtaOperationalStatus(MTAMGMT_MTA_STATUS* operationalStatus)
{
  /*TODO: Implement Me!*/
  (void)operationalStatus;
  return (INT)0;
}

INT mta_hal_getMtaProvisioningStatus(MTAMGMT_MTA_PROVISION_STATUS* provisionStatus)
{
  /*TODO: Implement Me!*/
  (void)provisionStatus;
  return (INT)0;
}

INT mta_hal_start_provisioning(PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters)
{
  /*TODO: Implement Me!*/
  (void)pParameters;
  return (INT)0;
}

void mta_hal_LineRegisterStatus_callback_register(mta_hal_getLineRegisterStatus_callback callback_proc)
{
  /*TODO: Implement Me!*/
  (void)callback_proc;
}

