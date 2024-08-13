/*
# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2023 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# */

/**
* @file test_l1_mta_hal.c
* @page mta_hal Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the mta_hal APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [MTAhalSpec.md](../../../docs/pages/MTAhalSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include "mta_hal.h"
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <stdbool.h>

static int gTestGroup = 1;
static int gTestID = 1;

extern int init_mta_hal_init(void);

/**
* @brief Test function to verify the initialization of shared DBs using mta_hal_InitDB()
*
* This test verifies if the shared DBs are successfully initialized using the mta_hal_InitDB() function. The function should return RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 001 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking the mta_hal_InitDB | NONE | RETURN_OK  | Should Pass |
*/
void test_l1_mta_hal_positive1_InitDB(void)
{
    gTestID = 1 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT ret = 0;
    UT_LOG_DEBUG("Invoking mta_hal_InitDB...");
    ret = mta_hal_InitDB();
    UT_LOG_DEBUG("The Result : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of mta_hal_InitDB when it is called multiple times.
*
* This test case is to verify whether mta_hal_InitDB function can handle multiple initializations correctly. The function should return
* RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 002 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_InitDB twice | None |  RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_InitDB(void)
{
    gTestID = 2 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_InitDB... First time");
    ret = mta_hal_InitDB();
    UT_LOG_DEBUG("The Result-1 : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_DEBUG("Invoking mta_hal_InitDB again...");
    ret = mta_hal_InitDB();
    UT_LOG_DEBUG("The Result-2 : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_DEBUG("mta_hal_InitDB successfully handled multiple initializations.");

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Tests the positive scenario of the mta_hal_GetDHCPInfo function.
*
* This test aims to validate the mta_hal_GetDHCPInfo function when invoked with valid arguments.  The function should return RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 003 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_GetDHCPInfo with valid pointer | pInfo = valid Pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetDHCPInfo(void)
{
    gTestID = 3 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT result = 0;
    PMTAMGMT_MTA_DHCP_INFO pInfo = (PMTAMGMT_MTA_DHCP_INFO)malloc(sizeof (MTAMGMT_MTA_DHCP_INFO));
    if(pInfo != NULL)
    {
        UT_LOG_DEBUG("Invoking mta_hal_GetDHCPInfo with valid arguments.");
        result = mta_hal_GetDHCPInfo(pInfo);
        UT_LOG_DEBUG(" Result for mta_hal_GetDHCPInfo : %d ",result);
        UT_ASSERT_EQUAL(result, RETURN_OK);

        UT_LOG_DEBUG("pInfo->IPAddress is : %u",pInfo->IPAddress.Value);
        UT_LOG_DEBUG("pInfo->Gateway is : %u",pInfo->Gateway.Value);
        UT_LOG_DEBUG("pInfo->PrimaryDNS is : %u",pInfo->PrimaryDNS.Value);
        UT_LOG_DEBUG("pInfo->SecondaryDNS is : %u",pInfo->SecondaryDNS.Value);
        UT_LOG_DEBUG("pInfo->PrimaryDHCPServer is : %u",pInfo->PrimaryDHCPServer.Value);
        UT_LOG_DEBUG("pInfo->SecondaryDHCPServer is : %u",pInfo->SecondaryDHCPServer.Value);

        free(pInfo);
    }
    else
    {
        UT_LOG_DEBUG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetDHCPInfo function when invoked with a NULL pointer argument.
*
* This test case verifies whether the mta_hal_GetDHCPInfo function returns an error when it is invoked with a NULL pointer argument.
* The objective is to ensure that the function handles this scenario correctly.  The function should return  RETURN_ERR .
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 004 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetDHCPInfo with NULL pointer | pInfo = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetDHCPInfo(void)
{
    gTestID = 4 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PMTAMGMT_MTA_DHCP_INFO pInfo = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Test: Invoking mta_hal_GetDHCPInfo with NULL pointer. ");
    result = mta_hal_GetDHCPInfo(pInfo);
    UT_LOG_DEBUG("Return value: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case verifies the functionality of the mta_hal_GetDHCPV6Info API for positive scenario.
*
* The objective of this test is to validate that the mta_hal_GetDHCPV6Info API returns the DHCPv6 information correctly when invoking with
* valid parameters.  The function should return RETURN_OK.
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 005@n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetDHCPV6Info API  with valid pointer | pInfo = valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetDHCPV6Info(void)
{
    gTestID = 5 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT status = 0;
    PMTAMGMT_MTA_DHCPv6_INFO pInfo = (PMTAMGMT_MTA_DHCPv6_INFO )malloc(sizeof(MTAMGMT_MTA_DHCPv6_INFO));
    if(pInfo != NULL)
    {

        UT_LOG_DEBUG("Invoking the mta_hal_GetDHCPV6Info ()");
        status = mta_hal_GetDHCPV6Info(pInfo);
        UT_LOG_DEBUG("Return status : %d ",status);
        free(pInfo);
        UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    else
    {
        UT_LOG_DEBUG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed")
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is used to verify the behavior of the mta_hal_GetDHCPV6Info function when a null pointer is passed for the pInfo parameter.
*
* The objective of this test is to ensure that the function returns an error code when a null pointer is passed as input for the pInfo
* parameter. The function should return RETURN_ERR in this case.
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 006 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_GetDHCPV6Info  with NULL | pInfo = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetDHCPV6Info(void)
{
    gTestID = 6 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT result = 0;
    UT_LOG_DEBUG("Invoking the mta_hal_GetDHCPV6Info with NULL");
    result = mta_hal_GetDHCPV6Info(NULL);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case verifies the functionality of the GetServiceFlow API with valid parameters.
*
* The purpose of this test is to ensure that the GetServiceFlow API returns the expected output when invoked with valid parameters.
* The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 007 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetServiceFlow with valid parameters | Count = 0, &ppCfg = Valid double pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetServiceFlow(void)
{
    gTestID = 7 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG Count = 0;
    PMTAMGMT_MTA_SERVICE_FLOW ppCfg = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetServiceFlow with valid parameters.");
    status = mta_hal_GetServiceFlow(&Count, &ppCfg);
    UT_LOG_DEBUG("Return value : %d ", status);
    UT_LOG_DEBUG("checking wether the pointer is NULL pointer or not");
    UT_ASSERT_PTR_NOT_NULL_FATAL(ppCfg);
    UT_LOG_DEBUG("Direction = %s",ppCfg->Direction);
    if(!strcmp("Upstream",ppCfg->Direction) || !strcmp("Downstream",ppCfg->Direction))
    {
        UT_LOG_DEBUG("ppCfg->Direction is a valid value : %s",ppCfg->Direction);
        UT_PASS("ppCfg->Direction is valid");
    }
    else
    {
        UT_LOG_DEBUG("ppCfg->Direction is an invalid value: %s",ppCfg->Direction);
        UT_FAIL("ppCfg->Direction is invalid");
    }
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetServiceFlow function when NULL pointers are passed as *Count.
*
* This test case is used to verify that the mta_hal_GetServiceFlow function returns an error code when invoked with NULL pointer as *Count
* and ppCfg is valid double pointer. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 008 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_GetServiceFlow with Count as NULL pointer | ppCfg = valid double pointer, *Count = NULL pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetServiceFlow(void)
{
    gTestID = 8 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *Count = NULL;
    PMTAMGMT_MTA_SERVICE_FLOW ppCfg = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetServiceFlow with *count =  NULL pointer.");
    status = mta_hal_GetServiceFlow(Count, &ppCfg);
    UT_LOG_DEBUG("Return value : %d ", status);

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetServiceFlow function when ppcfg is a NULL pointer.
*
* This test case is used to verify that the mta_hal_GetServiceFlow function returns an error code when invoked with NULL pointer for ppcfg and
* Count is valid pointer. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 009 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_GetServiceFlow with NULL pointer ppcfg | ppCfg = NULL pointer, &Count = valid pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_GetServiceFlow(void)
{
    gTestID = 9 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG Count = 0;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetServiceFlow with ppCfg =  NULL pointer.");
    status = mta_hal_GetServiceFlow(&Count, NULL);
    UT_LOG_DEBUG("Return value : %d ", status);

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetHandsets API with a valid handset number.
*
* The objective of this test case is to verify that the mta_hal_GetHandsets API returns the expected status and the correct values in
* ppHandsets when a valid handset number is provided as input. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 010 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetHandsets API with valid parameters | pulCount = 1, ppHandsets = valid double pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetHandsets(void)
{
    gTestID = 10 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned long pulCount = 1;
    PMTAMGMT_MTA_HANDSETS_INFO ppHandsets= NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetHandsets with pulCount : 1  ppHandsets = vaild souble pointer");
    status = mta_hal_GetHandsets(&pulCount, &ppHandsets);
    UT_LOG_DEBUG("Result status : %d", status);

    UT_ASSERT_EQUAL(RETURN_OK, status);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to validate the behavior of the mta_hal_GetHandsets function when the minimum number of handsets is returned.
*
* This test case checks if the mta_hal_GetHandsets function returns the correct status and updates the pulCount and ppHandsets variables
* correctly when the minimum number of handsets is using. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 011 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetHandsets with valid input parameters | pulCount = 0, ppHandsets = valid double pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_GetHandsets(void)
{
    gTestID = 11 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned long* pulCount = malloc(sizeof(unsigned long));
    INT status = 0;
    if (pulCount != NULL)
    {
        *pulCount = 0;
        PMTAMGMT_MTA_HANDSETS_INFO ppHandsets = NULL;
        UT_LOG_DEBUG("Invoking the mta_hal_GetHandsets");
        status = mta_hal_GetHandsets(pulCount, &ppHandsets);
        UT_LOG_DEBUG("Status: %d ", status);
        UT_LOG_DEBUG("mta_hal_GetHandsets with pulCount=%lu, ppHandsets=%s", *pulCount, (ppHandsets != NULL) ? "valid" : "NULL");
        UT_ASSERT_EQUAL(RETURN_OK, status);
        free(pulCount);
    }
    else
    {
        UT_LOG_DEBUG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the mta_hal_GetHandsets function when the 'pulCount' parameter is NULL.
*
* The mta_hal_GetHandsets function is tested in this test case to verify the behavior when the 'pulCount' parameter is NULL. The objective
* of this test case is to ensure that the function handles the NULL 'pulCount' parameter correctly and returns RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 012 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetHandsets with NULL pulCount parameter | pulCount = NULL, ppHandsets = Valid double pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetHandsets(void)
{
    gTestID = 12;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *pulCount = NULL;
    PMTAMGMT_MTA_HANDSETS_INFO ppHandsets = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetHandsets ");
    status = mta_hal_GetHandsets(pulCount, &ppHandsets);
    UT_LOG_DEBUG("Status: %d ", status);
    UT_LOG_DEBUG("mta_hal_GetHandsets returns ppHandsets=%s", (ppHandsets != NULL) ? "valid" : "NULL");
    UT_ASSERT_EQUAL(RETURN_ERR, status);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetHandsets function when the ppHandsets parameter is NULL.
*
* The objective of this test is to ensure that the function correctly handles the case when the ppHandsets parameter is NULL.
* The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 013 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify  mta_hal_GetHandsets API behavior when ppHandsets is NULL | pulCount = 1, ppHandsets = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_GetHandsets(void)
{
    gTestID = 13;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned long* pulCount = malloc(sizeof(unsigned long));
    INT status = 0;
    if(pulCount != NULL)
    {
        *pulCount = 1;
        UT_LOG_DEBUG("Invoking the mta_hal_GetHandsets ");
        status = mta_hal_GetHandsets(pulCount, NULL);
        UT_LOG_DEBUG("Status: %d ", status);
        UT_LOG_DEBUG("mta_hal_GetHandsets returned pulCount=%lu", *pulCount);
        UT_ASSERT_EQUAL(RETURN_ERR, status);
        free(pulCount);
    }
    else
    {
        UT_LOG_DEBUG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This function tests the mta_hal_GetDSXLogs API with valid input parameters.
*
* This test function verifies the functionality of the mta_hal_GetDSXLogs API by invoking it with valid input parameters. The function
* should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 014 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetDSXLogs with valid input parameters | count = 0, pDSXLog = Valid double pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetDSXLogs(void)
{
    gTestID = 14;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG count = 0;
    PMTAMGMT_MTA_DSXLOG pDSXLog = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetDSXLogs with valid input parameters...");
    result = mta_hal_GetDSXLogs(&count, &pDSXLog);
    UT_LOG_DEBUG("Returned value: %d", result);
    UT_LOG_DEBUG("Number of Log Entries: %lu", count);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetDSXLogs function when called with invalid *count = NULL pointer.
*
* This test case checks if the mta_hal_GetDSXLogs function returns an expected error code when called with invalid input parameters.
* The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 015 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetDSXLogs with invalid input parameters (NULL) for count | count = NULL, pDSXLog = valid double pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetDSXLogs(void)
{
    gTestID = 15;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *count = NULL;
    PMTAMGMT_MTA_DSXLOG pDSXLog = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetDSXLogs with invalid input parameters (*count = NULL)...");
    result = mta_hal_GetDSXLogs(count, &pDSXLog);
    UT_LOG_DEBUG("Returned value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetDSXLogs function when called with pDSXLog = NULL pointer.
*
* This test case checks if the mta_hal_GetDSXLogs function returns an expected error code when called with invalid input parameters.
* The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 016 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetDSXLogs with invalid input parameters (NULL) for pDSXLog | count = 0, pDSXLog = NULL pointer| RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_GetDSXLogs(void)
{
    gTestID = 16;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG count = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetDSXLogs with  pDSXLog = NULL...");
    result = mta_hal_GetDSXLogs(&count, NULL);
    UT_LOG_DEBUG("Returned value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetDSXLogEnable function with valid parameters.
*
* This test case is used to verify the functionality of the mta_hal_GetDSXLogEnable function by checking the return value and the value
* pointed to by pBool. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 017 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Provide a valid pointer for pBool and call mta_hal_GetDSXLogEnable function | pBool = valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetDSXLogEnable(void)
{
    gTestID = 17;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN pBool = TRUE;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetDSXLogEnable with valid memory location for pBool");
    ret = mta_hal_GetDSXLogEnable(&pBool);
    UT_LOG_DEBUG("Return Value: %d", ret);
    UT_LOG_DEBUG("Output Value: %d", pBool);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of mta_hal_GetDSXLogEnable when a NULL pointer is provided for pBool.
*
* This test case checks whether the mta_hal_GetDSXLogEnable function returns RETURN_ERR when a NULL pointer is provided for pBool.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 018 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, they need to select this test case via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data     | Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetDSXLogEnable with NULL | pBool = NULL  | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetDSXLogEnable(void)
{
    gTestID = 18;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN *pBool = NULL;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_GetDSXLogEnable with NULL pointer for pBool");
    ret = mta_hal_GetDSXLogEnable(pBool);
    UT_LOG_DEBUG("Return Value: %d", ret);
    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_SetDSXLogEnable function when invoked with a valid input parameter.
*
* This test case is used to verify that the function mta_hal_SetDSXLogEnable correctly Enables the DSX log when the input boolean value is
* set to TRUE. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 019 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_SetDSXLogEnable with Bool Value TRUE | Bool = TRUE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_SetDSXLogEnable(void)
{
    gTestID = 19;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = TRUE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_SetDSXLogEnable with Bool = TRUE\n");
    result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_SetDSXLogEnable function when invoked with a valid input parameter.
*
* This test case is used to verify that the function mta_hal_SetDSXLogEnable correctly disables the DSX log when the input boolean value is
* set to FALSE. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 020 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation/Step | Description | Test Data | Expected Result  | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* |  01  | Invoking the mta_hal_SetDSXLogEnable API with Bool Value = FALSE | Bool = FALSE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_SetDSXLogEnable(void)
{
    gTestID = 20;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = FALSE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_SetDSXLogEnable with Bool = FALSE\n");
    result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the behavior of the mta_hal_SetDSXLogEnable function when an invalid boolean value is passed as an argument.
*
* The objective of this test is to ensure that the mta_hal_SetDSXLogEnable function properly handles an invalid boolean value and returns
* RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 021 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_SetDSXLogEnable with invalid boolean value | Bool = 2 | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_SetDSXLogEnable(void)
{
    gTestID = 21;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = 2;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_SetDSXLogEnable with invalid value: Bool = 2\n");
    result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test function to verify the functionality of mta_hal_ClearDSXLog API when the Bool parameter is set to TRUE.
*
* This test function verifies the functionality of mta_hal_ClearDSXLog API by setting the Bool parameter to TRUE and calling the API.
* The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 022 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* |  01    | Invoking the mta_hal_ClearDSXLog with TRUE Bool | Bool = TRUE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_ClearDSXLog(void)
{
    gTestID = 22;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = TRUE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearDSXLog with Bool parameter set to TRUE");
    result = mta_hal_ClearDSXLog(Bool);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test the function mta_hal_ClearDSXLog with Bool parameter set to FALSE
*
* This test case verifies the behavior of the mta_hal_ClearDSXLog function when the Bool parameter is set to FALSE.The function should return
* RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 023 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_ClearDSXLog with Bool parameter set to FALSE | Bool = FALSE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_ClearDSXLog(void)
{
    gTestID = 23;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = FALSE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearDSXLog with Bool parameter set to FALSE");
    result = mta_hal_ClearDSXLog(Bool);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is to verify the behavior of the mta_hal_ClearDSXLog() function when an invalid boolean value is passed as a parameter.
*
* The objective of this test is to check if the function handles the case of an invalid boolean value correctly by returning the error code
* RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 024 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data | Expected Result   | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01  | Invoking mta_hal_ClearDSXLog  with Invalid value | Bool = 2 | RETURN_ERR  | Should Fail  |
*/
void test_l1_mta_hal_negative1_ClearDSXLog(void)
{
    gTestID = 24;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = 2;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearDSXLog with invalid Bool parameter value (2)");
    result = mta_hal_ClearDSXLog(Bool);
    UT_LOG_DEBUG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetCallSignallingLogEnable API when invoked with a valid parameter.
*
* This test case verifies the functionality of the mta_hal_GetCallSignallingLogEnable API. The objective of this test is to ensure that
* the API returns the correct result and value at the memory location. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 025 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_GetCallSignallingLogEnable with value as TRUE | pBool = TRUE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetCallSignallingLogEnable(void)
{
    gTestID = 25;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN pBool = TRUE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetCallSignallingLogEnable API with TRUE");
    result = mta_hal_GetCallSignallingLogEnable(&pBool);
    UT_LOG_DEBUG("Result : %d ",result);
    UT_LOG_DEBUG("Boolean pBool value  : %d", pBool);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetCallSignallingLogEnable function when the pBool parameter is set to NULL
*
* This test case checks if the mta_hal_GetCallSignallingLogEnable function returns the expected error code when the pBool parameter is set
* to NULL. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 026 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_GetCallSignallingLogEnable with pBool as NULL pointer | pBool = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetCallSignallingLogEnable(void)
{
    gTestID = 26;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN *pBool = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetCallSignallingLogEnable API with NULL");
    result = mta_hal_GetCallSignallingLogEnable(pBool);
    UT_LOG_DEBUG("Result : %d ",result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of mta_hal_SetCallSignallingLogEnable API when invoked with a valid input parameter.
*
* This test case verifies whether mta_hal_SetCallSignallingLogEnable API is able to enable the call signalling log successfully and whether
* it returns RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 027 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_SetCallSignallingLogEnable API with enable value TRUE | enable = TRUE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_SetCallSignallingLogEnable(void)
{
    gTestID = 27;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN enable = TRUE;
    INT result = 0;
    UT_LOG_DEBUG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of the "mta_hal_SetCallSignallingLogEnable" function when invoked with a valid input parameter.
*
* This test case verifies the functionality of the "mta_hal_SetCallSignallingLogEnable" API by setting the Call Signalling Log Enable to FALSE
* and checking if the result is RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 028 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* |  01    | Invoking the mta_hal_SetCallSignallingLogEnable API with FALSE | enable = FALSE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_SetCallSignallingLogEnable(void)
{
    gTestID = 28;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN enable = FALSE;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Testing the function `mta_hal_SetCallSignallingLogEnable` with invalid boolean value.
*
* This test case is designed to verify the behavior of `mta_hal_SetCallSignallingLogEnable` function when an invalid boolean value is passed
* as input. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 029 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_SetCallSignallingLogEnable with invalid boolean value as input | enable = 2 | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_SetCallSignallingLogEnable(void)
{
    gTestID = 29;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN enable = 2;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of the mta_hal_ClearCallSignallingLog() API when invoked with a valid input parameter.
*
* The purpose of this test is to ensure that the mta_hal_ClearCallSignallingLog() function is able to clear the call signalling log when
* the Bool parameter is set to TRUE. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 030 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call the mta_hal_ClearCallSignallingLog() function with Bool parameter set to TRUE. | Bool = TRUE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_ClearCallSignallingLog(void)
{
    gTestID = 30;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = TRUE;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_ClearCallSignallingLog with TRUE");
    ret = mta_hal_ClearCallSignallingLog(Bool);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of mta_hal_ClearCallSignallingLog function when the input parameter is set to FALSE.
*
* This test case verifies that the mta_hal_ClearCallSignallingLog function returns RETURN_OK when the input parameter is set to FALSE.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 031 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_ClearCallSignallingLog function with Bool set to FALSE | Bool = FALSE | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_ClearCallSignallingLog(void)
{
    gTestID = 31;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = FALSE;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_ClearCallSignallingLog FALSE ");
    ret = mta_hal_ClearCallSignallingLog(Bool);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to validate the behavior of the mta_hal_ClearCallSignallingLog function when provided with an invalid BOOLEAN value.
*
* This test case verifies that the mta_hal_ClearCallSignallingLog function returns RETURN_ERR when an invalid Bool value is provided.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 032 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_ClearCallSignallingLog with an invalid BOOLEAN value | Bool = 2 | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_ClearCallSignallingLog(void)
{
    gTestID = 32;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Bool = 2;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_ClearCallSignallingLog Bool = 2 ");
    ret = mta_hal_ClearCallSignallingLog(Bool);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetMtaLog API when invoked with a valid  parameter.
*
* This test case checks if the mta_hal_GetMtaLog function returns the expected result when invoked with a valid input parameter. The function
* should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 033 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetMtaLog with valid inputs | count = 0, pLog = valid double pointer |  RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_GetMtaLog(void)
{
    gTestID = 33;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG count = 0;
    PMTAMGMT_MTA_MTALOG_FULL pLog = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetMtaLog");
    result = mta_hal_GetMtaLog(&count, &pLog);
    UT_LOG_DEBUG("Result : %d ", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to check the behaviour of mta_hal_GetMtaLog when *Count = NULL pointer.
*
* This test case checks whether the function mta_hal_GetMtaLog handles NULL pointers correctly and returns the expected error code RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 034 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetMtaLog function with count as NULL pointer| *count = NULL, pLog = valid double pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_GetMtaLog(void)
{
    gTestID = 34;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *count = NULL;
    PMTAMGMT_MTA_MTALOG_FULL pLog = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetMtaLog");
    result = mta_hal_GetMtaLog(count, &pLog);
    UT_LOG_DEBUG("Result : %d ", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to check the behaviour of mta_hal_GetMtaLog when pLog is NULL pointer.
*
* This test case checks whether the function mta_hal_GetMtaLog handles NULL pointers correctly and returns the expected error code RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 035 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetMtaLog function with pLog = NULL | count = valid pointer, pLog = NULL pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_GetMtaLog(void)
{
    gTestID = 35;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG count = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_GetMtaLog with pLog as NULL pointer");
    result = mta_hal_GetMtaLog(&count, NULL);
    UT_LOG_DEBUG("Result : %d ", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of mta_hal_BatteryGetInstalled API when invoked with a valid parameter.
*
* This test case is used to verify the functionality of the mta_hal_BatteryGetInstalled API. The API is responsible for retrieving the
* installed status of the battery. The objective of this test is to ensure that the API returns the expected result and does not produce
* any errors or crashes.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 036 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetInstalled API with valid parameter | Val = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetInstalled(void)
{
    gTestID = 36;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN Val = 0;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetInstalled with Val=%d", Val);
    ret = mta_hal_BatteryGetInstalled(&Val);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_LOG_DEBUG("mta_hal_BatteryGetInstalled value : %u ",Val);
    UT_ASSERT_TRUE(Val == TRUE || Val == FALSE);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test validates the behavior of the mta_hal_BatteryGetInstalled function when invoked with NULL pointer.
*
* The mta_hal_BatteryGetInstalled function is tested in this test case to verify its behavior when NULL pointers are passed as arguments.
* The objective of this test is to ensure that the function handles NULL pointers correctly and returns the expected error code RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 037 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetInstalled with NULL pointer | val = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetInstalled(void)
{
    gTestID = 37;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN *Val = NULL;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetInstalled with Val= %d", Val);
    ret = mta_hal_BatteryGetInstalled(Val);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to check the functionality of mta_hal_BatteryGetTotalCapacity function with a valid  parameter.
*
* The objective of this test is to check the functionality of the mta_hal_BatteryGetTotalCapacity function by invoking it with valid input
* parameters and verifying the return value and the value of Val.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 038 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetTotalCapacity with valid  parameters | val = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetTotalCapacity(void)
{
    gTestID = 38;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG val = 0 ;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetTotalCapacity with Val=%p", &val);
    result = mta_hal_BatteryGetTotalCapacity(&val);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_LOG_DEBUG("Val: %lu", val);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the functionality of the mta_hal_BatteryGetTotalCapacity function when NULL is provided for the
* 'val' parameter.
*
* The objective of this test is to ensure that the function handles the invalid input parameter correctly and returns the expected result
* RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 039 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetTotalCapacity with NULL pointer| val = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetTotalCapacity(void)
{
    gTestID = 39;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG* val = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetTotalCapacity with Val=NULL");
    result = mta_hal_BatteryGetTotalCapacity(val);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of mta_hal_BatteryGetActualCapacity with valid parameter.
*
* This test verifies if the mta_hal_BatteryGetActualCapacity function returns a valid battery capacity by invoking
* mta_hal_BatteryGetActualCapacity and checking the return status and actual capacity against the expected range.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 040 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result  | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* |  01  | Invoking mta_hal_BatteryGetActualCapacity with valid memory location | capacity = 0 | RETURN_OK | should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetActualCapacity(void)
{
    gTestID = 40;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG capacity = 0;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetActualCapacity with valid memory location...");
    status = mta_hal_BatteryGetActualCapacity(&capacity);
    UT_LOG_DEBUG("Expected Output: Capacity within the range 0 to (2^32)-1");
    UT_LOG_DEBUG("Actual Output: capacity = %lu", capacity);
    UT_LOG_DEBUG("Return Status: %s", (status == RETURN_OK) ? "RETURN_OK" : "RETURN_ERR");
    UT_ASSERT_TRUE(capacity >= 0 && capacity <= (UINT32_MAX));
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Tests the mta_hal_BatteryGetActualCapacity function when passed a NULL pointer
*
* This test case is designed to verify the behavior of the mta_hal_BatteryGetActualCapacity function when a NULL pointer is passed as an
* argument. The expected behavior is that the function should return RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 041 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetActualCapacity with NULL pointer | Val = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetActualCapacity(void)
{
    gTestID = 41;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *capacity = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetTotalCapacity with NULL pointer for Val...");
    status = mta_hal_BatteryGetActualCapacity(capacity);
    UT_LOG_DEBUG("Return Status: %s", (status == RETURN_ERR) ? "RETURN_ERR" : "RETURN_OK");
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of the mta_hal_BatteryGetRemainingCharge API when a valid memory location is passed as an argument.
*
* This test verifies that the mta_hal_BatteryGetRemainingCharge API returns the expected result and updates the value at the provided memory
* location.The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 042 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetRemainingCharge API with a valid memory location for Val | val = 0 |  RETURN_OK  | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetRemainingCharge(void)
{
    gTestID = 42;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG val = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetRemainingCharge with valid memory location for Val = %d", val);
    result = mta_hal_BatteryGetRemainingCharge(&val);
    UT_LOG_DEBUG("Returned Value: %d, Val: %lu", result, val);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for negative scenario of BatteryGetRemainingCharge function.
*
* This test case is used to verify the behavior of BatteryGetRemainingCharge function when a NULL pointer is passed as an argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 043 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify behavior of mta_hal_BatteryGetRemainingCharge API when a NULL pointer is passed | val=NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetRemainingCharge(void)
{
    gTestID = 43;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG* val = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetRemainingCharge with NULL pointer for Val");
    result = mta_hal_BatteryGetRemainingCharge(val);
    UT_LOG_DEBUG("Returned Value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test the functionality of the mta_hal_BatteryGetRemainingTime API when invoked with a valid parameter.
*
*  This test case is used to verify the behavior of mta_hal_BatteryGetRemainingTime function with valid parameter.The function should return
* RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 044 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetRemainingTime function  with valid value | Val=0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetRemainingTime(void)
{
    gTestID = 44;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG val = 0;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetRemainingTime with input parameters (Val=%p)", &val);
    ret = mta_hal_BatteryGetRemainingTime(&val);
    UT_LOG_DEBUG("Returned value: %d, Val: %lu", ret, val);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for verifying the behavior of mta_hal_BatteryGetRemainingTime function when NULL pointer is passed as the argument
*
* This test is aimed at verifying the functionality of mta_hal_BatteryGetRemainingTime function when a NULL pointer is passed as the argument.
* The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 045 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetRemainingTime with NULL pointer | val = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetRemainingTime(void)
{
    gTestID = 45;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG* val = NULL;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetRemainingTime with input parameters (Val=%p)", val);
    ret = mta_hal_BatteryGetRemainingTime(val);
    UT_LOG_DEBUG("Returned value: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test function to validate the mta_hal_BatteryGetNumberofCycles API with a valid  parameter.
*
* This test case validates the functionality of the mta_hal_BatteryGetNumberofCycles API with a valid  parameter. The function should return
* RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 046 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetNumberofCycles with valid parameter | val = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetNumberofCycles(void)
{
    gTestID = 46;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG val = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetNumberofCycles ");
    result = mta_hal_BatteryGetNumberofCycles(&val);
    UT_LOG_DEBUG("result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of mta_hal_BatteryGetNumberofCycles when passed a null pointer.
*
* This test case checks if the mta_hal_BatteryGetNumberofCycles function returns the expected error code when a null pointer is passed as
* the parameter. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 047 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
*
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetNumberofCycles when a null pointer is passed. | val = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetNumberofCycles(void)
{
    gTestID = 47;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG* val = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetNumberofCycles ");
    result = mta_hal_BatteryGetNumberofCycles(val);
    UT_LOG_DEBUG("result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This function tests the functionality of the mta_hal_BatteryGetPowerStatus API with valid parameter..
*
* This test case verifies the behavior of the mta_hal_BatteryGetPowerStatus API by calling it with valid memory locations for Val and len.
* The return value, as well as the values of Val and len, are checked to ensure the correct operation of the API.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 048 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
*  | Variation / Step | Description  | Test Data   | Expected Result   | Notes  |
*  | :----: | :---------: | :----------: |:--------------: | :-----: |
*  |  01  | Invoking the mta_hal_BatteryGetPowerStatus with valid memory locations for Val and len | Val = valid memory , len = valid memory  |  RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetPowerStatus(void)
{
    gTestID = 48;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[8] = {"\0"};
    ULONG len =0;
    INT ret =0;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetPowerStatus ");
    ret = mta_hal_BatteryGetPowerStatus(Val, &len);
    UT_LOG_DEBUG("Result : %d", ret);
    UT_LOG_DEBUG("power source is : %s", Val);
    if(!strcmp(Val,"AC") || !strcmp(Val,"Battery") || !strcmp(Val,"Unknown"))
    {
        UT_LOG_DEBUG("power source validation success");
        UT_PASS("power source validation success");
    }
    else
    {
        UT_LOG_DEBUG("power source validation failed");
        UT_FAIL("power source validation failed");
    }
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This function tests the functionality of the mta_hal_BatteryGetPowerStatus API with invalid Val.
*
* This test case verifies the behavior of the mta_hal_BatteryGetPowerStatus when we pass Val as NULL pointer. The function should return
* RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 049 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_BatteryGetPowerStatus API with NULL pointers for Val and valid pointer for len | Val = NULL pointer , len = valid pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetPowerStatus(void)
{
    gTestID = 49;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT ret = 0;
    CHAR *Val = NULL;
    ULONG len = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetPowerStatus Val = NULL pointer Len = valid pointer");
    ret = mta_hal_BatteryGetPowerStatus(Val, &len);
    UT_LOG_DEBUG("Result : %d ",ret );
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This function tests the functionality of the mta_hal_BatteryGetPowerStatus API with invalid len.
*
* This test case verifies the behavior of the mta_hal_BatteryGetPowerStatus when we pass len as NULL pointer. The function should return
* RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 050 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_BatteryGetPowerStatus API with NULL pointers for len and valid pointer for val | Val = valid pointer , len = NULL pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_BatteryGetPowerStatus(void)
{
    gTestID = 50;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT ret = 0;
    CHAR Val[8] = {"\0"};
    ULONG *len = NULL;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetPowerStatus Val = valid pointer Len = NULL pointer");
    ret = mta_hal_BatteryGetPowerStatus(Val, len);
    UT_LOG_DEBUG("Result : %d ",ret );
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the behavior of the mta_hal_BatteryGetCondition with  valid parameter.
*
* This test case checks the functionality of the mta_hal_BatteryGetCondition function by invoking it and verifying the output values and
* return status. The function should return RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 051 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
*  | Variation / Step | Description | Test Data | Expected Result | Notes |
*  | :----: | :---------: | :----------: |:--------------: | :-----: |
*  | 01 | Invoke the mta_hal_BatteryGetCondition API with valid memory locations | Val =Valid buffer, len = valid buffer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetCondition(void)
{
    gTestID = 51;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[32] = {"\0"};
    ULONG len = 32;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetCondition with Valid buffer Val and  len = %lu", len);
    result = mta_hal_BatteryGetCondition(Val, &len);
    UT_LOG_DEBUG("Result : %d ", result);

    UT_LOG_DEBUG("checking wether output character pointer 'Val' is NULL or not");
    UT_ASSERT_PTR_NOT_NULL_FATAL(Val);

    UT_LOG_DEBUG("Battery condition : %s ", Val);
    if(!strcmp(Val, "Good") || !strcmp(Val, "Bad"))
    {
        UT_LOG_DEBUG("The Battery COndtion is valid ");
        UT_PASS("The Battery COndtion is valid ");
    }
    else
    {
        UT_LOG_DEBUG("The Battery COndtion is invalid");
        UT_FAIL("The Battery COndtion is invalid");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case checks the functionality of the mta_hal_BatteryGetCondition API when invoked with NULL pointer for len.
*
* The objective of this test is to verify if the API can handle NULL pointers correctly and return the expected result RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 052 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data   | Expected Result    | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01   | Invoking mta_hal_BatteryGetCondition with NULL pointer for len  | Val = valid pointer , *len = NULL   | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetCondition(void)
{
    gTestID = 52;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[32] = {"\0"};
    ULONG *len = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetCondition with Val = valid buffer, len = NULL. Return status:");
    result = mta_hal_BatteryGetCondition(Val, len);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case checks the functionality of the mta_hal_BatteryGetCondition API when invoked with NULL pointer for val.
*
* The objective of this test is to verify if the API can handle NULL pointers correctly and return the expected result RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 053 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data   | Expected Result    | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01   | Invoking mta_hal_BatteryGetCondition with NULL pointer for val  | Val = NULL pointer, *len = valid pointer   | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_BatteryGetCondition(void)
{
    gTestID = 53;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR *Val = NULL;
    ULONG len = 32;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetCondition with Val = NULL pointer, len = valid pointer. Return status:");
    result = mta_hal_BatteryGetCondition(Val, &len);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the mta_hal_BatteryGetStatus() API when invoked with  valid parameter.
*
* The objective of this test case is to ensure that the mta_hal_BatteryGetStatus() function returns the correct battery status when the
* battery is in good condition. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 054 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetStatus with valid parameters | Val = Valid pointer, len = Valid pointer | RETURN_OK | Should pass |
*/
void test_l1_mta_hal_positive1_BatteryGetStatus(void)
{
    gTestID = 54;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[12] ={"\0"};
    ULONG len = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetStatus with valid character pointer for Val and len...");
    result = mta_hal_BatteryGetStatus(Val, &len);
    UT_LOG_DEBUG("Result : %d", result );
    UT_LOG_DEBUG("checking wether output character pointer 'Val' is NULL or not");
    UT_ASSERT_PTR_NOT_NULL_FATAL(Val);

    UT_LOG_DEBUG("Value of len is %lu", len);
    UT_LOG_DEBUG("Batery status : %s ", Val);
    if(!strcmp(Val, "Missing") || !strcmp(Val, "Idle") || !strcmp(Val, "Charging") || !strcmp(Val, "Discharging") || !strcmp(Val, "Unknown"))
    {
        UT_LOG_DEBUG("Batery status is valid");
        UT_PASS("Batery status is valid");
    }
    else
    {
        UT_LOG_DEBUG("Battery Status is invalid");
        UT_FAIL("Batery status is invalid");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to validate the behavior of the mta_hal_BatteryGetStatus function when passed NULL pointers for len.
*
* This test case is intended to verify the behavior of the mta_hal_BatteryGetStatus function when it is invoked with NULL pointers for len
* and valid pointer for Val. It is expected that the function returns RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 055 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetStatus with NULL pointer for len | Val = valid pointer , len = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetStatus(void)
{
    gTestID = 55;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[12] = {"\0"};
    ULONG* len = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetStatus with NULL pointers for  len...");
    result = mta_hal_BatteryGetStatus(Val, len);
    UT_LOG_DEBUG("Result : %d", result );
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to validate the behavior of the mta_hal_BatteryGetStatus function when passed NULL pointers for val.
*
* This test case is intended to verify the behavior of the mta_hal_BatteryGetStatus function when it is invoked with NULL pointers for Val
* and valid pointer for len. It is expected that the function returns RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 056 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetStatus with NULL pointer for val | Val = NULL pointer , len = valid pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_BatteryGetStatus(void)
{
    gTestID = 56;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR* Val = NULL;
    ULONG len = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetStatus with NULL pointers for Val ...");
    result = mta_hal_BatteryGetStatus(Val, &len);
    UT_LOG_DEBUG("Result : %d", result );
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_BatteryGetLife API when invoked with  valid parameter.
*
* This test case is used to verify the functionality of the mta_hal_BatteryGetLife function. It checks if the function returns the correct
* values for Val and len variables.The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 057 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetLife with valid memory locations for Val and len | Val = valid pointer , len = valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetLife(void)
{
    gTestID = 57;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[32] = {"\0"};
    ULONG len = 32;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetLife with valid memory locations for Val and len...");
    result = mta_hal_BatteryGetLife(Val, &len);
    UT_LOG_DEBUG("Return value: %d", result);

    UT_LOG_DEBUG("checking wether output character pointer 'Val' is NULL or not");
    UT_ASSERT_PTR_NOT_NULL_FATAL(Val);

    UT_LOG_DEBUG("Value of Val: %s", Val);
    UT_LOG_DEBUG("Value of len: %lu", len);
    if(!strcmp(Val,"Need Replacement") || !strcmp(Val,"Good"))
    {
        UT_LOG_DEBUG("value of Val is valid");
        UT_PASS("value of Val is valid");
    }
    else
    {
        UT_LOG_DEBUG("value of Val is not valid");
        UT_FAIL("value of Val is not valid");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_BatteryGetLife API when invoked with  NULL pointer for len.
*
* This test case verifies that the function mta_hal_BatteryGetLife returns RETURN_ERR when NULL pointer is provided for len.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 058 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result   | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_BatteryGetLife with NULL pointer len  | Val = valid pointer, len = NULL  | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetLife(void)
{
    gTestID = 58;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR Val[32] = {"\0"};
    ULONG *len = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_BatteryGetLife with val = valid pointer len = NULL pointer");
    result = mta_hal_BatteryGetLife(Val, len);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_BatteryGetLife API when invoked with  NULL pointer for Val.
*
* This test case verifies that the function mta_hal_BatteryGetLife returns the expected error value when NULL pointer is provided for Val.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 059 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result   | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_BatteryGetLife with NULL pointer Val  | Val = NULL pointer, len = valid pointer  | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_BatteryGetLife(void)
{
    gTestID = 59;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR *Val = NULL;
    ULONG len = 32;
    INT result = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_BatteryGetLife with val = NULL pointer len = valid pointer");
    result = mta_hal_BatteryGetLife(Val, &len);
    UT_LOG_DEBUG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_BatteryGetInfo API when invoked with  valid parameter.
*
* This test case checks if the mta_hal_BatteryGetInfo() API returns RETURN_OK when invoked with valid parameter.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 060 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_BatteryGetInfo with valid pointer | pInfo= valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetInfo(void)
{
    gTestID = 60;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT status = 0;
    PMTAMGMT_MTA_BATTERY_INFO pInfo = (PMTAMGMT_MTA_BATTERY_INFO) malloc(sizeof(MTAMGMT_MTA_BATTERY_INFO));
    if(pInfo != NULL)
    {
        UT_LOG_DEBUG("Invoking the  mta_hal_BatteryGetInfo with pInfo");
        status = mta_hal_BatteryGetInfo(pInfo);
        UT_LOG_DEBUG("Result : %d ", status);
        free(pInfo);
        UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    else
    {
        UT_LOG_DEBUG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case verifies the behavior of the mta_hal_BatteryGetInfo function when a null pointer is passed as the parameter.
*
* The purpose of this test is to ensure that the mta_hal_BatteryGetInfo function returns RETURN_ERR when a null pointer is passed as the
* parameter.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 061 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetInfo API with NULL | pInfo = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetInfo(void)
{
    gTestID = 61;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PMTAMGMT_MTA_BATTERY_INFO pInfo = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking the mta_hal_BatteryGetInfo with NULL");
    status = mta_hal_BatteryGetInfo(pInfo);
    UT_LOG_DEBUG("Result Status : %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_BatteryGetPowerSavingModeStatus API when invoked with  valid parameter.
*
* The objective of this test is to verify the correctness of the mta_hal_BatteryGetPowerSavingModeStatus function when power saving mode
* is enabled. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 062 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetPowerSavingModeStatus with valid pointer | pValue = Valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus(void)
{
    gTestID = 62;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG pValue = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_BatteryGetPowerSavingModeStatus with pValue=%p", &pValue);
    result = mta_hal_BatteryGetPowerSavingModeStatus(&pValue);
    UT_LOG_DEBUG("Result : %d ", result);
    UT_LOG_DEBUG("pValue : %lu", pValue);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_BatteryGetPowerSavingModeStatus function when a null pointer is passed
* as the pValue argument.
*
* The objective of this test is to check if the function properly handles the null pointer and returns the correct error code, RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 063 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetPowerSavingModeStatus with NULL | pValue=NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus(void)
{
    gTestID = 63;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *pValue = NULL;
    INT result = 0;

    UT_LOG_DEBUG("Invoking test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus with pValue=NULL");
    result = mta_hal_BatteryGetPowerSavingModeStatus(pValue);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_Get_MTAResetCount API when invoked with  valid parameter.
*
* The purpose of this test is to ensure that the mta_hal_Get_MTAResetCount function returns RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 064 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_Get_MTAResetCount with valid pointer for resetcnt | resetcnt = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_Get_MTAResetCount(void)
{
    gTestID = 64;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    INT status = 0;

    UT_LOG_DEBUG("Invoking mta_hal_Get_MTAResetCount with valid memory location for resetcnt. 0");
    status = mta_hal_Get_MTAResetCount(&resetcnt);
    UT_LOG_DEBUG("Output value resetcnt: %lu", resetcnt);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test case verifies the behavior of mta_hal_Get_MTAResetCount function when it is called with a NULL pointer for resetcnt.
*
* The purpose of this test is to ensure that the function correctly handles the case when a NULL pointer is passed as an argument to the
* function. The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 065 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_Get_MTAResetCount with NULL pointer for resetcnt | resetcnt = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_Get_MTAResetCount(void)
{
    gTestID = 65;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT status = 0;
    UT_LOG_DEBUG("Invoking mta_hal_Get_MTAResetCount with NULL pointer for resetcnt...");
    status = mta_hal_Get_MTAResetCount(NULL);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_Get_LineResetCount API when invoked with  valid parameter.
*
* This test case checks the functionality of the mta_hal_Get_LineResetCount API by verifying the return status The API should return RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 066 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_Get_LineResetCount API  with Valid pointer | resetcnt = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_Get_LineResetCount(void)
{
    gTestID = 66;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    INT status = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_Get_LineResetCount with resetcnt 0");
    status = mta_hal_Get_LineResetCount(&resetcnt);
    UT_LOG_DEBUG("Result : %d resetCnt : %lu ", status, resetcnt);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of the mta_hal_Get_LineResetCount API when called with a null pointer.
*
* This test case is to verify the behavior of the mta_hal_Get_LineResetCount API when called with a null pointer as an argument.
* The function should return  RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 067 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_Get_LineResetCount with null pointer | resetcnt = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_Get_LineResetCount(void)
{
    gTestID = 67;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG *resetcnt = NULL;
    INT status = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_Get_LineResetCount with resetcnt 0");
    status = mta_hal_Get_LineResetCount(resetcnt);
    UT_LOG_DEBUG("Result : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the functionality of the mta_hal_ClearCalls function when called with InstanceNumber set to 0.
*
* This test verifies if the mta_hal_ClearCalls function correctly clears calls for the given instance number. The function should return
* RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 068 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Set InstanceNumber to 0 and call mta_hal_ClearCalls function | InstanceNumber = 0 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_ClearCalls(void)
{
    gTestID = 68;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNumber = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG_DEBUG("result :%d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of mta_hal_ClearCalls function when InstanceNumber is set to (2^32)-1.
*
* This test verifies that mta_hal_ClearCalls function completes successfully when InstanceNumber is set to the maximum value of unsigned
* integer. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 069 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_ClearCalls with Maximum InstanceNumber| InstanceNumber = (4294967296-1) | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive2_ClearCalls(void)
{
    gTestID = 69;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNumber = (4294967296-1);
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG_DEBUG("result :%d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test the functionality of the mta_hal_ClearCalls function.
*
* This test function verifies the functionality of the mta_hal_ClearCalls function by calling it with a specific InstanceNumber and verifying
* the return value. The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 070 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_ClearCalls function with a specific InstanceNumber | InstanceNumber = 1000 | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive3_ClearCalls(void)
{
    gTestID = 70;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNumber = 1000;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG_DEBUG("result :%d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_getDhcpStatus API when invoked with  valid parameter.
*
* This test case verifies the correct retrieval of DHCP status for IPv4 connection using the mta_hal_getDhcpStatus API. The function should
* return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 071 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_getDhcpStatus with Valid data | ipv4Status, ipv6Status = valid parameters |  RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_getDhcpStatus(void)
{
    gTestID = 71;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    MTAMGMT_MTA_STATUS ipv4Status;
    MTAMGMT_MTA_STATUS ipv6Status;
    INT returnValue = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_getDhcpStatus ");
    returnValue = mta_hal_getDhcpStatus(&ipv4Status, &ipv6Status);
    UT_LOG_DEBUG("Return value : %d", returnValue);
    UT_LOG_DEBUG("ipv4Status = %d, ipv6Status = %d",ipv4Status,ipv6Status);

    if(ipv4Status>= MTA_INIT && ipv4Status <= MTA_REJECTED)
    {
        UT_LOG_DEBUG("valid ipv4Status");
        UT_PASS("valid ipv4Status");
    }
    else
    {
        UT_LOG_DEBUG("invalid ipv4Status");
        UT_FAIL("invalid ipv4Status");
    }

    if(ipv6Status>= MTA_INIT && ipv6Status <= MTA_REJECTED)
    {
        UT_LOG_DEBUG("valid ipv6Status");
        UT_PASS("valid ipv6Status");
    }
    else
    {
        UT_LOG_DEBUG("invalid ipv6Status");
        UT_FAIL("invalid ipv6Status");
    }
    UT_ASSERT_EQUAL(returnValue, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the negative scenario of the mta_hal_getDhcpStatus function with NULL pointer for ipv4Status.
*
* This test case checks if the mta_hal_getDhcpStatus function returns RETURN_ERR when trying to get the DHCP status for both IPv4 and IPv6.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 072 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_getDhcpStatus with NULL pointer ipv4Status | ipv4Status = NULL pointer, ipv6Status = valid pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_getDhcpStatus(void)
{
    gTestID = 72;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    MTAMGMT_MTA_STATUS *ipv4Status = NULL;
    MTAMGMT_MTA_STATUS ipv6Status = 0;
    INT returnValue = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_getDhcpStatus ");
    returnValue = mta_hal_getDhcpStatus(ipv4Status, &ipv6Status);
    UT_LOG_DEBUG("Return value : %d", returnValue);
    UT_ASSERT_EQUAL(returnValue, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the negative scenario of the mta_hal_getDhcpStatus function with NULL pointer for ipv6Status.
*
* This test case checks if the mta_hal_getDhcpStatus function returns RETURN_ERR when trying to get the DHCP status for both IPv4 and IPv6.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 073 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_getDhcpStatus with NULL pointer ipv6Status | ipv4Status = valid pointer, ipv6Status = NULL pointer | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative2_getDhcpStatus(void)
{
    gTestID = 73;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    MTAMGMT_MTA_STATUS ipv4Status = 0;
    MTAMGMT_MTA_STATUS *ipv6Status = NULL;
    INT returnValue = 0;

    UT_LOG_DEBUG("Invoking the  mta_hal_getDhcpStatus ");
    returnValue = mta_hal_getDhcpStatus(&ipv4Status, ipv6Status);
    UT_LOG_DEBUG("Return value : %d", returnValue);
    UT_ASSERT_EQUAL(returnValue, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the behavior of the mta_hal_getConfigFileStatus API when invoked with  valid parameter.
*
* This test case is used to verify the functionality of mta_hal_getConfigFileStatus API, which is responsible for getting the status of
* the config file.The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 074 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_getConfigFileStatus with Valid data | poutput_status = Valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_getConfigFileStatus(void)
{
    gTestID = 74;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    MTAMGMT_MTA_STATUS poutput_status = 0;
    INT ret = 0;

    UT_LOG_DEBUG("Invoking mta_hal_getConfigFileStatus with valid memory location for poutput_status...");
    ret = mta_hal_getConfigFileStatus(&poutput_status);
    UT_LOG_DEBUG("Return value: %d", ret);
    UT_LOG_DEBUG("Output status: %d", poutput_status);
    if(poutput_status >= MTA_INIT && poutput_status <= MTA_REJECTED)
    {
        UT_LOG_DEBUG("valid Config File Status");
        UT_PASS("valid Config File Status");
    }
    else
    {
        UT_LOG_DEBUG("invalid Config File Status");
        UT_FAIL("invalid Config File Status");
    }
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to check the behavior of the function mta_hal_getConfigFileStatus when a NULL pointer is passed as an argument.
*
* The objective of this test is to verify that the function handles the NULL pointer correctly and returns RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 075 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data  | Expected Result  | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_getConfigFileStatus with NULL | poutput_status = NULL  | RETURN_ERR  | Should Fail |
*
*/
void test_l1_mta_hal_negative1_getConfigFileStatus(void)
{
    gTestID = 75;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT ret = 0;
    UT_LOG_DEBUG("Invoking mta_hal_getConfigFileStatus with invalid memory location for poutput_status...");
    ret = mta_hal_getConfigFileStatus(NULL);
    UT_LOG_DEBUG("Return value: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the positive scenario of mta_hal_getMtaProvisioningStatus API when invoked with  valid parameter.
*
* This test case verifies the functionality of mta_hal_getMtaProvisioningStatus function when provided with valid input parameters.
* The function should return  RETURN_OK.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 076 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_getMtaProvisioningStatus with &provisionStatus as valid pointer | &provisionStatus = valid pointer | RETURN_OK | Should Pass |
*/
void test_l1_mta_hal_positive1_getMtaProvisioningStatus(void)
{
    gTestID = 76;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    MTAMGMT_MTA_PROVISION_STATUS provisionStatus = 0;
    INT result = 0;

    UT_LOG_DEBUG("Invoking mta_hal_getMtaProvisioningStatus with valid output parameter");
    result = mta_hal_getMtaProvisioningStatus(&provisionStatus);
    UT_LOG_DEBUG("Result : %d", result);
    UT_LOG_DEBUG("MtaProvisioningStatus = %d ",provisionStatus);
    if(provisionStatus == 0 || provisionStatus == 1)
    {
        UT_LOG_DEBUG("VALID MtaProvisioningStatus");
        UT_PASS("VALID MtaProvisioningStatus");
    }
    else
    {
        UT_LOG_DEBUG("invalid MtaProvisioningStatus");
        UT_FAIL("inVALID MtaProvisioningStatus");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test case to verify the negative scenario of mta_hal_getMtaProvisioningStatus  API when invoked with  invalid parameter.
*
* This test case verifies the functionality of mta_hal_getMtaProvisioningStatus function when provided with NULL pointer. The function
* should return RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 077 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_getMtaProvisioningStatus with *provisionStatus = NULL |*provisionStatus = NULL | RETURN_ERR | Should Fail |
*/
void test_l1_mta_hal_negative1_getMtaProvisioningStatus(void)
{
    gTestID = 77;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT result = 0;
    MTAMGMT_MTA_PROVISION_STATUS *provisionStatus = NULL;

    UT_LOG_DEBUG("Invoking mta_hal_getMtaProvisioningStatus with NULL pointer");
    result = mta_hal_getMtaProvisioningStatus(provisionStatus);
    UT_LOG_DEBUG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_mta_hal_l1_register(void)
{
    bool batterySupported;
    // Create the test suite
    pSuite = UT_add_suite("[L1 mta_hal]", init_mta_hal_init, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    batterySupported = UT_KVP_PROFILE_GET_BOOL("mta.batterySupported");
    UT_LOG_DEBUG("batterySupported value from profile : %d \n",batterySupported);

    UT_add_test( pSuite, "l1_mta_hal_positive1_InitDB", test_l1_mta_hal_positive1_InitDB);
    UT_add_test( pSuite, "l1_mta_hal_positive2_InitDB", test_l1_mta_hal_positive2_InitDB);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDHCPInfo", test_l1_mta_hal_positive1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDHCPInfo", test_l1_mta_hal_negative1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDHCPV6Info", test_l1_mta_hal_positive1_GetDHCPV6Info);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDHCPV6Info", test_l1_mta_hal_negative1_GetDHCPV6Info);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetServiceFlow", test_l1_mta_hal_positive1_GetServiceFlow);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetServiceFlow", test_l1_mta_hal_negative1_GetServiceFlow);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetServiceFlow", test_l1_mta_hal_negative2_GetServiceFlow);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetHandsets", test_l1_mta_hal_positive1_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_positive2_GetHandsets", test_l1_mta_hal_positive2_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetHandsets", test_l1_mta_hal_negative1_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetHandsets", test_l1_mta_hal_negative2_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDSXLogs", test_l1_mta_hal_positive1_GetDSXLogs);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDSXLogs", test_l1_mta_hal_negative1_GetDSXLogs);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetDSXLogs", test_l1_mta_hal_negative2_GetDSXLogs);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDSXLogEnable", test_l1_mta_hal_positive1_GetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDSXLogEnable", test_l1_mta_hal_negative1_GetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_SetDSXLogEnable", test_l1_mta_hal_positive1_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_SetDSXLogEnable", test_l1_mta_hal_positive2_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_SetDSXLogEnable", test_l1_mta_hal_negative1_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearDSXLog", test_l1_mta_hal_positive1_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearDSXLog", test_l1_mta_hal_positive2_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_ClearDSXLog", test_l1_mta_hal_negative1_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetCallSignallingLogEnable", test_l1_mta_hal_positive1_GetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetCallSignallingLogEnable", test_l1_mta_hal_negative1_GetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_SetCallSignallingLogEnable", test_l1_mta_hal_positive1_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_SetCallSignallingLogEnable", test_l1_mta_hal_positive2_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_SetCallSignallingLogEnable", test_l1_mta_hal_negative1_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearCallSignallingLog", test_l1_mta_hal_positive1_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearCallSignallingLog", test_l1_mta_hal_positive2_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_ClearCallSignallingLog", test_l1_mta_hal_negative1_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetMtaLog", test_l1_mta_hal_positive1_GetMtaLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetMtaLog", test_l1_mta_hal_negative1_GetMtaLog);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetMtaLog", test_l1_mta_hal_negative2_GetMtaLog);

    if(batterySupported == true)
    {
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetInstalled", test_l1_mta_hal_positive1_BatteryGetInstalled);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetInstalled", test_l1_mta_hal_negative1_BatteryGetInstalled);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetTotalCapacity", test_l1_mta_hal_positive1_BatteryGetTotalCapacity);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetTotalCapacity", test_l1_mta_hal_negative1_BatteryGetTotalCapacity);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetActualCapacity", test_l1_mta_hal_positive1_BatteryGetActualCapacity);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetActualCapacity", test_l1_mta_hal_negative1_BatteryGetActualCapacity);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetRemainingCharge", test_l1_mta_hal_positive1_BatteryGetRemainingCharge);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetRemainingCharge", test_l1_mta_hal_negative1_BatteryGetRemainingCharge);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetRemainingTime", test_l1_mta_hal_positive1_BatteryGetRemainingTime);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetRemainingTime", test_l1_mta_hal_negative1_BatteryGetRemainingTime);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetNumberofCycles", test_l1_mta_hal_positive1_BatteryGetNumberofCycles);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetNumberofCycles", test_l1_mta_hal_negative1_BatteryGetNumberofCycles);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetPowerStatus", test_l1_mta_hal_positive1_BatteryGetPowerStatus);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetPowerStatus", test_l1_mta_hal_negative1_BatteryGetPowerStatus);
        UT_add_test( pSuite, "l1_mta_hal_negative2_BatteryGetPowerStatus", test_l1_mta_hal_negative2_BatteryGetPowerStatus);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetCondition", test_l1_mta_hal_positive1_BatteryGetCondition);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetCondition", test_l1_mta_hal_negative1_BatteryGetCondition);
        UT_add_test( pSuite, "l1_mta_hal_negative2_BatteryGetCondition", test_l1_mta_hal_negative2_BatteryGetCondition);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetStatus", test_l1_mta_hal_positive1_BatteryGetStatus);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetStatus", test_l1_mta_hal_negative1_BatteryGetStatus);
        UT_add_test( pSuite, "l1_mta_hal_negative2_BatteryGetStatus", test_l1_mta_hal_negative2_BatteryGetStatus);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetLife", test_l1_mta_hal_positive1_BatteryGetLife);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetLife", test_l1_mta_hal_negative1_BatteryGetLife);
        UT_add_test( pSuite, "l1_mta_hal_negative2_BatteryGetLife", test_l1_mta_hal_negative2_BatteryGetLife);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetInfo", test_l1_mta_hal_positive1_BatteryGetInfo);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetInfo", test_l1_mta_hal_negative1_BatteryGetInfo);
        UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus", test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus);
        UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus", test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus);
    }
    UT_add_test( pSuite, "l1_mta_hal_positive1_Get_MTAResetCount", test_l1_mta_hal_positive1_Get_MTAResetCount);
    UT_add_test( pSuite, "l1_mta_hal_negative1_Get_MTAResetCount", test_l1_mta_hal_negative1_Get_MTAResetCount);
    UT_add_test( pSuite, "l1_mta_hal_positive1_Get_LineResetCount", test_l1_mta_hal_positive1_Get_LineResetCount);
    UT_add_test( pSuite, "l1_mta_hal_negative1_Get_LineResetCount", test_l1_mta_hal_negative1_Get_LineResetCount);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearCalls", test_l1_mta_hal_positive1_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearCalls", test_l1_mta_hal_positive2_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive3_ClearCalls", test_l1_mta_hal_positive3_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getDhcpStatus", test_l1_mta_hal_positive1_getDhcpStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getDhcpStatus", test_l1_mta_hal_negative1_getDhcpStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative2_getDhcpStatus", test_l1_mta_hal_negative2_getDhcpStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getConfigFileStatus", test_l1_mta_hal_positive1_getConfigFileStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getConfigFileStatus", test_l1_mta_hal_negative1_getConfigFileStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getMtaProvisioningStatus", test_l1_mta_hal_positive1_getMtaProvisioningStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getMtaProvisioningStatus", test_l1_mta_hal_negative1_getMtaProvisioningStatus);
    return 0;
}