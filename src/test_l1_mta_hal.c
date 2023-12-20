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
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include "mta_hal.h"
#include <stdlib.h>
#include <ctype.h>

/**
* @brief Test function to verify the initialization of shared DBs using mta_hal_InitDB()
*
* This test verifies if the shared DBs are successfully initialized using the mta_hal_InitDB() function.
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
* | 01 | Invoking the mta_hal_InitDB | NONE | RETURN_OK  | Should be successful |
*/
void test_l1_mta_hal_positive1_InitDB(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_InitDB...");

    UT_LOG("Invoking mta_hal_InitDB...");
    INT ret = mta_hal_InitDB();
    UT_LOG("The Result : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_InitDB...");
}

/**
* @brief Test case to verify the behavior of mta_hal_InitDB when it is called multiple times.
*
* This test case is to verify whether mta_hal_InitDB function can handle multiple initializations correctly.
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
* | 01 | Invoking the mta_hal_InitDB twice | None |  RETURN_OK | should be sucessfull |
*/
void test_l1_mta_hal_positive2_InitDB(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_InitDB...");

    // Step 01: First set of conditions.
    UT_LOG("Invoking mta_hal_InitDB... First time");
    INT ret = mta_hal_InitDB();
    UT_LOG("The Result-1 : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Invoking mta_hal_InitDB again...");
    ret = mta_hal_InitDB();
    UT_LOG("The Result-2 : %d ", ret );
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("mta_hal_InitDB successfully handled multiple initializations.");

    UT_LOG("Exiting test_l1_mta_hal_positive2_InitDB...");
}

/**
 * @brief Tests the positive scenario of the mta_hal_GetDHCPInfo function.
 *
 * This test aims to validate the mta_hal_GetDHCPInfo function when invoked with valid arguments.
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
 * | 01 | Invoke mta_hal_GetDHCPInfo with valid pointer | pInfo = valid Pointer | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_GetDHCPInfo(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDHCPInfo...");

    PMTAMGMT_MTA_DHCP_INFO pInfo = (PMTAMGMT_MTA_DHCP_INFO)malloc(sizeof (MTAMGMT_MTA_DHCP_INFO));
    if(pInfo != NULL)
    {
        UT_LOG("Invoking mta_hal_GetDHCPInfo with valid arguments.");
        INT result = mta_hal_GetDHCPInfo(pInfo);
        UT_LOG(" Result for mta_hal_GetDHCPInfo : %d ",result);
        UT_ASSERT_EQUAL(result, RETURN_OK);
        free(pInfo);
    }
    else
    {
    	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetDHCPInfo...");
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetDHCPInfo function when invoked with a NULL pointer argument.
*
* This test case verifies whether the mta_hal_GetDHCPInfo function returns an error when it is invoked with a NULL pointer argument. The objective is to ensure that the function handles this scenario correctly.
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
* | 01 | Invoking mta_hal_GetDHCPInfo with NULL pointer | pInfo = NULL | RETURN_ERR | Should return an error |
*/
void test_l1_mta_hal_negative1_GetDHCPInfo(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDHCPInfo...");

    PMTAMGMT_MTA_DHCP_INFO pInfo = NULL;
    // Test the function with a null pointer argument
    UT_LOG("Test: Invoking mta_hal_GetDHCPInfo with NULL pointer. ");
    INT result = mta_hal_GetDHCPInfo(pInfo);
    UT_LOG("Return value: %d", result);
    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDHCPInfo...");
}

/**
* @brief This test case verifies the functionality of the mta_hal_GetDHCPV6Info API.
*
* The objective of this test is to validate that the mta_hal_GetDHCPV6Info API returns the DHCPv6 information correctly.
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
* | 01 | Invoke the mta_hal_GetDHCPV6Info API  with valid memory | pInfo = valid memory | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_GetDHCPV6Info(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDHCPV6Info...");

    // Initialize required variables
    PMTAMGMT_MTA_DHCPv6_INFO pInfo = (PMTAMGMT_MTA_DHCPv6_INFO )malloc(sizeof(MTAMGMT_MTA_DHCPv6_INFO));
    if(pInfo != NULL)
    {
        // Invoke the API
        UT_LOG("Invoking the mta_hal_GetDHCPV6Info ()");
        INT status = mta_hal_GetDHCPV6Info(pInfo);
	UT_LOG("Return status : %d ",status);

        // Validate the return status
        UT_ASSERT_EQUAL(status, RETURN_OK);
        free(pInfo);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed")
    }
    UT_LOG("Existing test_l1_mta_hal_positive1_GetDHCPV6Info...");
}

/**
* @brief This test is used to verify the behavior of the mta_hal_GetDHCPV6Info function when a null pointer is passed for the pInfo parameter.
*
* The objective of this test is to ensure that the function returns an error code when a null pointer is passed as input for the pInfo parameter.
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
* | 01 | Invoke mta_hal_GetDHCPV6Info  with NULL | pInfo = NULL | RETURN_ERR | Should return an error code. |
*/
void test_l1_mta_hal_negative1_GetDHCPV6Info(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDHCPV6Info...");
    UT_LOG("Invoking the mta_hal_GetDHCPV6Info with NULL");
    INT result = mta_hal_GetDHCPV6Info(NULL);
    UT_LOG("Result : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDHCPV6Info...");
}

/**
    * @brief Test the functionality of the mta_hal_LineTableGetNumberOfEntries() function.
    *
    * This test case checks if the mta_hal_LineTableGetNumberOfEntries() function returns the correct number of entries in the line table.
    *
    * **Test Group ID:** Basic: 01 @n
    * **Test Case ID:** 007 @n
    * **Priority:** High @n@n
    *
    * **Pre-Conditions:** None @n
    * **Dependencies:** None @n
    * **User Interaction:** If the user chooses to run the test in interactive mode, they should select this test case via the console.@n
    *
    * **Test Procedure:**@n
    * | Variation / Step | Description | Test Data | Expected Result | Notes |
    * | :----: | :---------: | :----------: |:--------------: | :-----: |
    * | 01 | Invoke mta_hal_LineTableGetNumberOfEntries | None | RETURN_OK |  Should be successful |
    */
void test_l1_mta_hal_positive1_LineTableGetNumberOfEntries(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_LineTableGetNumberOfEntries...");

    // Invoke the API
    UT_LOG("Invoking mta_hal_LineTableGetNumberOfEntries with no input parameters...");
    ULONG numEntries = mta_hal_LineTableGetNumberOfEntries();
    UT_LOG("Number of entries: %lu", numEntries);

    // Check the return status
    UT_ASSERT_EQUAL(numEntries >= 0, TRUE);
    UT_LOG("Exiting test_l1_mta_hal_positive1_LineTableGetNumberOfEntries...");
}

/**
 * @brief Test the retrieval of a valid entry from the Line Table
 *
 * This test verifies the functionality of the mta_hal_LineTableGetEntry API by retrieving a valid entry from the Line Table and checking the return status and the values in the returned pEntry structure.
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 008@n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
 *
 * **Test Procedure:** @n
 *  | Variation / Step | Description | Test Data | Expected Result | Notes |
 *  | :----: | :---------: | :----------: |:--------------: | :-----: |
 *  | 01 | Invoking the mta_hal_LineTableGetEntry with index as 4294967295 , entry = Valid pointer | index = 4294967295, entry = Valid pointer | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_LineTableGetEntry...");

    // Provide a valid Index within the expected range
    ULONG index = 4294967295;
    PMTAMGMT_MTA_LINETABLE_INFO entry = (PMTAMGMT_MTA_LINETABLE_INFO) malloc (sizeof(MTAMGMT_MTA_LINETABLE_INFO));    
    if(entry != NULL)
    {
        // Invoking mta_hal_LineTableGetEntry with the Index
        UT_LOG("Invoking the mta_hal_LineTableGetEntry ");
        INT status = mta_hal_LineTableGetEntry(index, entry);
        UT_LOG("Return value : %d ",status);
        // Check the return status to ensure it's RETURN_OK
        UT_ASSERT_EQUAL(status, RETURN_OK);
        free(entry);
    }
    else 
    {
        UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_LineTableGetEntry...");
}

/**
* @brief This test case is used to validate the LineTableGetEntry function with the lowest index value.
*
* This test is used to ensure that the LineTableGetEntry function can handle the lowest possible index value (0) correctly.
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 009 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_LineTableGetEntry with index as 0 , entry = valid Pointer | index = 0, entry = Valid Pointer | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive2_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_LineTableGetEntry...");

    // Provide an Index of 0
    ULONG index = 0;
    PMTAMGMT_MTA_LINETABLE_INFO entry = (PMTAMGMT_MTA_LINETABLE_INFO) malloc (sizeof(MTAMGMT_MTA_LINETABLE_INFO));    
    if(entry != NULL)
    {
        // Invoking mta_hal_LineTableGetEntry with the Index
        UT_LOG("Invoking the mta_hal_LineTableGetEntry");
        INT status = mta_hal_LineTableGetEntry(index, entry);
        UT_LOG("Return status : %d ",status);
        // Check the return status to ensure it's RETURN_OK
        UT_ASSERT_EQUAL(status, RETURN_OK);
    	free(entry);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive2_LineTableGetEntry...");
}

/**
* @brief Test the boundary case where the highest valid index is provided as input to `mta_hal_LineTableGetEntry` function.
*
* This test case checks whether the `mta_hal_LineTableGetEntry` function can successfully retrieve the line table entry when the highest valid index is provided as input. The line table entry is stored in the `entry` structure.
*
* **Test Group ID:** Basic : 01 @n
* **Test Case ID:** 010@n
* **Priority:** High@n@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_LineTableGetEntry with the highest valid index, entry = Valid Pointer | index = 4294967295-1, entry = Valid Pointer | Returns RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive3_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_positive3_LineTableGetEntry...");

    ULONG index = (4294967295-1);
   // EntryType entry;
    PMTAMGMT_MTA_LINETABLE_INFO entry = ( PMTAMGMT_MTA_LINETABLE_INFO )malloc (sizeof(MTAMGMT_MTA_LINETABLE_INFO));
    if(entry != NULL)
    {
        // Invoking mta_hal_LineTableGetEntry with the Index
	UT_LOG("Invoking the mta_hal_LineTableGetEntry with index (4294967295-1) ");
        INT status = mta_hal_LineTableGetEntry(index, entry);
        UT_LOG("Return value status : %d", status);
        // Check the return status to ensure it's RETURN_OK
        UT_ASSERT_EQUAL(status, RETURN_OK);
      	free(entry);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive3_LineTableGetEntry...");
}

/**
* @brief This test is to verify the behavior of the function mta_hal_LineTableGetEntry when an invalid lower index boundary (-1) is provided.
*
* The objective of this test is to check whether the function returns RETURN_ERR when an invalid lower index boundary is provided as input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 011 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_LineTableGetEntry with underflow index | index = -1, entry = Valid Pointer | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_LineTableGetEntry...");

    // Provide an Index of -1 (underflow)
    ULONG index = -1;
    //EntryType entry;

    PMTAMGMT_MTA_LINETABLE_INFO entry = (PMTAMGMT_MTA_LINETABLE_INFO)malloc (sizeof(MTAMGMT_MTA_LINETABLE_INFO));
    if(entry != NULL)
    {
        // Invoking mta_hal_LineTableGetEntry with the Index
	UT_LOG("Invoking mta_hal_LineTableGetEntry with index : %ld ", index);
        INT status = mta_hal_LineTableGetEntry(index, entry);
	UT_LOG("Return value : %d ", status);
        // Check the return status to ensure it's RETURN_ERR
        UT_ASSERT_EQUAL(status, RETURN_ERR);
        free(entry);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_negative1_LineTableGetEntry...");
}

/**
    * @brief This test case tests the behavior of the API when an invalid upper index boundary is provided.
    *
    * This test case verifies the behavior of the mta_hal_LineTableGetEntry API when an invalid upper index boundary is 
    * provided as the input index. It ensures that the API properly handles the overflow condition and returns the 
    * expected error status.
    * 
    * **Test Group ID:** Basic: 01 @n
    * **Test Case ID:** 012 @n
    * **Priority:** High @n@n
    * 
    * **Pre-Conditions:** None@n
    * **Dependencies:** None@n
    * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
    * 
    * **Test Procedure:**@n
    * | Variation / Step | Description | Test Data | Expected Result | Notes |
    * | :----: | :---------: | :----------: |:--------------: | :-----: |
    * | 01 | Invoking the mta_hal_LineTableGetEntry with over flow Value| index = 4294967296, entry = Valid Pointer | Api returns RETURN_ERR | Should be unsuccessful |
    */
void test_l1_mta_hal_negative2_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_negative2_LineTableGetEntry...");

    // Provide an Index of 2^32 (overflow)
    ULONG index = 4294967296;
    //EntryType entry;
    PMTAMGMT_MTA_LINETABLE_INFO entry = (PMTAMGMT_MTA_LINETABLE_INFO) malloc (sizeof(MTAMGMT_MTA_LINETABLE_INFO));
    if(entry != NULL)
    {
        // Invoking mta_hal_LineTableGetEntry with the Index
	UT_LOG("Invoking the mta_hal_LineTableGetEntry with index : %ld ", index);
        INT status = mta_hal_LineTableGetEntry(index, entry);
        UT_LOG("Return value : %d ", status);
        // Check the return status to ensure it's RETURN_ERR
        UT_ASSERT_EQUAL(status, RETURN_ERR);
        free(entry);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_negative2_LineTableGetEntry...");
}

/**
 * @brief Test objective: Verify the behavior of the function when the pEntry parameter is NULL.
 *
 * This test is aimed at checking whether the function mta_hal_LineTableGetEntry handles the NULL pEntry parameter correctly.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 013 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking the mta_hal_LineTableGetEntry with Invalid value index =0, pEntry = NULL | index = 0, pEntry = NULL | Api returns RETURN_ERR | Should be unsuccessful |
 */

void test_l1_mta_hal_negative3_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_negative3_LineTableGetEntry...");

    // Provide a valid Index
    ULONG index = 0;
    PMTAMGMT_MTA_LINETABLE_INFO pEntry = NULL;

    // Invoking mta_hal_LineTableGetEntry with the Index and NULL pEntry
    UT_LOG("Invoking the mta_hal_LineTableGetEntry with Index : %d pEntry = NULL", index);
    INT status = mta_hal_LineTableGetEntry(index, pEntry);
    UT_LOG("Retun value : %d ", status);
    // Check the return status to ensure it's RETURN_ERR
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative3_LineTableGetEntry...");
}

/**
* @brief Test case to verify the behavior of mta_hal_LineTableGetEntry function when provided an index beyond the existing entries
*
* This test case verifies that the mta_hal_LineTableGetEntry function returns the expected error status when provided with an index that is beyond the number of existing entries in the line table.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 014 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_LineTableGetEntry Invalid values | index = 101 , entry | Expected return status is RETURN_ERR | Should return an error status |
*/

void test_l1_mta_hal_negative4_LineTableGetEntry(void) {
    UT_LOG("Entering test_l1_mta_hal_negative4_LineTableGetEntry...");

    // Provide an Index beyond the number of existing entries
    ULONG index = 101;
    PMTAMGMT_MTA_LINETABLE_INFO entry;

    // Invoking mta_hal_LineTableGetEntry with the Index
    UT_LOG("Invoking the mta_hal_LineTableGetEntry () with index value 101 ");
    INT status = mta_hal_LineTableGetEntry(index, entry);
    UT_LOG("Return value : %d ", status);
    // Check the return status to ensure it's RETURN_ERR
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative4_LineTableGetEntry...");
}

/**
* @brief This test is to verify the functionality of the mta_hal_TriggerDiagnostics function.
*
* The purpose of this test is to check if the mta_hal_TriggerDiagnostics function returns the expected value when invoked with a valid line number.
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
* | 01 | Invoke mta_hal_TriggerDiagnostics with a valid line number | index = 2147483648 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_TriggerDiagnostics(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_TriggerDiagnostics...");

    // Provide a valid line number
    ULONG index = 2147483648; 

    // Invoke mta_hal_TriggerDiagnostics
    UT_LOG("Invoking the mta_hal_TriggerDiagnostics with index value 2147483648");
    INT status = mta_hal_TriggerDiagnostics(index);
    UT_LOG("Status: %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_TriggerDiagnostics...");
}

/**
* @brief Test case to verify the functionality of mta_hal_TriggerDiagnostics function.
*
* This test case checks if the mta_hal_TriggerDiagnostics function returns the expected status when invoked with a valid index.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 016@n
* **Priority:** High@n@n
*
* **Pre-Conditions:** None @n 
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_TriggerDiagnostics with a valid index | index = 0 | RETURN_OK | Should be successful |
*/

void test_l1_mta_hal_positive2_TriggerDiagnostics(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive2_TriggerDiagnostics...");

    // Provide the lowest line number
    ULONG index = 0;

    // Invoke mta_hal_TriggerDiagnostics
    UT_LOG("Invoking the mta_hal_TriggerDiagnostics with index value 0");
    INT status = mta_hal_TriggerDiagnostics(index);
    UT_LOG("Status: %lu", status);
    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_TriggerDiagnostics...");
}

/**
* @brief This test case tests the functionality of the mta_hal_TriggerDiagnostics API.
*
* The purpose of this test is to ensure that the mta_hal_TriggerDiagnostics API is working correctly and returning the expected status.
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
* | 01 | Invoke mta_hal_TriggerDiagnostics  with Highest Line Number | index = 4294967295 | RETURN_OK status is expected  | Should be successful |
*/

void test_l1_mta_hal_positive3_TriggerDiagnostics(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive3_TriggerDiagnostics...");
    // Provide the highest line number
    ULONG index = (4294967295-1);

    // Invoke mta_hal_TriggerDiagnostics
    UT_LOG("Invoking the mta_hal_TriggerDiagnostics API with Index : %lu", index);
    INT status = mta_hal_TriggerDiagnostics(index);
    UT_LOG("Status: %lu ", status);
    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive3_TriggerDiagnostics...");
}

/**
* @brief This test case tests the functionality of the mta_hal_TriggerDiagnostics API
*
* The purpose of this test is to ensure that the mta_hal_TriggerDiagnostics API is working correctly and returning the expected status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 018 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_TriggerDiagnostics with Invalid Lower Line Number | index = -1 | RETURN_ERR | Should be equal to RETURN_ERR |
*/
void test_l1_mta_hal_negative1_TriggerDiagnostics(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_TriggerDiagnostics...");

    // Provide an invalid lower line number
    ULONG index = -1;

    // Invoke mta_hal_TriggerDiagnostics
    UT_LOG("Invoking the mta_hal_TriggerDiagnostics with index= -1");
    INT status = mta_hal_TriggerDiagnostics(index);
    UT_LOG("Status: %d", status);
    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_TriggerDiagnostics...");
}

/**
* @brief This test is designed to verify the behavior of the mta_hal_TriggerDiagnostics function when an invalid upper line number is provided.
*
* The test verifies that when an invalid upper line number is provided as the input argument, the function returns the expected error status.
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
* | 01 | Invoking the mta_hal_TriggerDiagnostics with invalid upper line number | index = 4294967296 | status = RETURN_ERR | Should be RETURN_ERR |
*/
void test_l1_mta_hal_negative2_TriggerDiagnostics(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative2_TriggerDiagnostics...");

    // Provide an invalid upper line number
    ULONG index = 4294967296; 

    // Invoke mta_hal_TriggerDiagnostics
    UT_LOG("Invoking the mta_hal_TriggerDiagnostics with index value 4294967296");
    INT status = mta_hal_TriggerDiagnostics(index);
    UT_LOG("status: %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative2_TriggerDiagnostics...");
}

/**
* @brief This test case verifies the functionality of the GetServiceFlow API with valid parameters.
*
* The purpose of this test is to ensure that the GetServiceFlow API returns the expected output when invoked with valid parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 020 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetServiceFlow with valid parameters | Count = 0, ppCfg = Valid pointer | RETURN_OK | The API call should be successful and return the expected status |
*/
void test_l1_mta_hal_positive1_GetServiceFlow(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetServiceFlow...");

    // Initialize test variables
    ULONG Count = 0;
    PMTAMGMT_MTA_SERVICE_FLOW ppCfg = (PMTAMGMT_MTA_SERVICE_FLOW) malloc (sizeof(MTAMGMT_MTA_SERVICE_FLOW));
    if(ppCfg != NULL)
    {
        // Invoke mta_hal_GetServiceFlow
        UT_LOG("Invoking mta_hal_GetServiceFlow with valid parameters.");
        INT status = mta_hal_GetServiceFlow(&Count, &ppCfg);
        UT_LOG("Return value : %d ", status);    
        // Perform assertions
        UT_ASSERT_EQUAL(status, RETURN_OK);
        CU_ASSERT_NOT_EQUAL_FATAL(Count, 0);
        UT_ASSERT_PTR_NOT_NULL(ppCfg);

        // Clean up allocated memory
        free(ppCfg);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetServiceFlow...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetServiceFlow function when NULL pointers are passed as arguments.
*
* This test case is used to verify that the mta_hal_GetServiceFlow function returns an error code when invoked with NULL pointers as arguments.
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
* | 01 | Invoke mta_hal_GetServiceFlow with NULL pointers | serviceFlow = NULL, status = NULL | RETURN_ERR | Should return an error code |
*/

void test_l1_mta_hal_negative1_GetServiceFlow(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetServiceFlow...");
    ULONG *Count = NULL;
    PMTAMGMT_MTA_SERVICE_FLOW ppCfg = NULL;
    // Invoke mta_hal_GetServiceFlow with NULL pointers
    UT_LOG("Invoking mta_hal_GetServiceFlow with NULL pointers.");
    INT status = mta_hal_GetServiceFlow(Count, &ppCfg);
    UT_LOG("Return value : %d ", status); 
    // Perform assertion
    UT_ASSERT_EQUAL(status, RETURN_ERR);
    
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetServiceFlow...");
}

/**
 * @brief Test case to verify the functionality of the mta_hal_DectGetEnable API.
 *
 * This test case verifies the functionality of the mta_hal_DectGetEnable API by checking the return status and enable status.
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
 * | 01   | Invoking mta_hal_DectGetEnable API with enable memory location | enable = TRUE | RETURN_OK |  should be successful 
 */

void test_l1_mta_hal_positive1_DectGetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_DectGetEnable...");

    BOOLEAN enable = TRUE;
    UT_LOG("Invoking mta_hal_DectGetEnable with enable memory location (%p)", &enable);
    INT ret = mta_hal_DectGetEnable(&enable);
    UT_LOG("Returned Status: %d enable: %d", ret, enable);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_EQUAL(enable, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_DectGetEnable...");
}

/**
 * @brief Test for mta_hal_DectGetEnable function
 *
 * This test case is used to verify the behavior of the mta_hal_DectGetEnable function.
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
 * | 01 | Invoke mta_hal_DectGetEnable function witn enable as FALSE | enable = FALSE | RETURN_OK | The enable status should be FALSE |
 */
void test_l1_mta_hal_positive2_DectGetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_DectGetEnable...");

    BOOLEAN enable = FALSE;
    UT_LOG("Invoking mta_hal_DectGetEnable with enable memory location (%p)", &enable);
    INT ret = mta_hal_DectGetEnable(&enable);

    UT_LOG("Returned Status: %d", ret);
    UT_LOG("DECT Enable status: %d", enable);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_EQUAL(enable, FALSE);

    UT_LOG("Exiting test_l1_mta_hal_positive2_DectGetEnable...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_DectGetEnable function when invoked with a NULL enable memory location.
*
* The objective of this test is to ensure that the function returns the expected error code when it is called with a NULL enable memory location.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_DectGetEnable with NULL | enable = NULL | RETURN_ERR | Should be an error |
*/
void test_l1_mta_hal_negative1_DectGetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_DectGetEnable...");

    BOOLEAN *enable = NULL;
    UT_LOG("Invoking mta_hal_DectGetEnable with NULL %p ", enable);
    INT ret = mta_hal_DectGetEnable(enable);

    UT_LOG("Returned Status: %d", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_DectGetEnable...");
}

/**
 * @brief Test to verify the functionality of mta_hal_DectSetEnable function when enabled.
 *
 * This test case is used to verify the functionality of the mta_hal_DectSetEnable function when enabling the DECT feature. It will validate the return status of the function call and ensure that it is equal to RETURN_OK when the DECT feature is successfully enabled.
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
 * | 01 | Invoke mta_hal_DectGetEnable function witn enable as TRUE | bBool = TRUE | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_DectSetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_DectSetEnable...");

    BOOLEAN bBool = TRUE;
    UT_LOG("Invoking mta_hal_DectSetEnable with input parameter bBool = TRUE.");
    INT status = mta_hal_DectSetEnable(bBool);
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_DectSetEnable...");
}

/**
 * @brief This test case is used to test the functionality of mta_hal_DectSetEnable when the input parameter bBool is set to FALSE.
 *
 * In this test case, the mta_hal_DectSetEnable API is invoked with the input parameter bBool = FALSE. The objective of this test is to verify that the API returns the expected status code when the DECT function is disabled.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 026 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking the mta_hal_DectSetEnable with value as FALSE | bBool = FALSE | RETURN_OK | Should return success |
 */
void test_l1_mta_hal_positive2_DectSetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_DectSetEnable...");

    BOOLEAN bBool = FALSE;
    UT_LOG("Invoking mta_hal_DectSetEnable with input parameter bBool = FALSE.");
    INT status = mta_hal_DectSetEnable(bBool);
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_DectSetEnable...");
}

/**
 * @brief Test case to verify the behavior of the mta_hal_DectSetEnable function when an invalid boolean value is provided.
 *
 * This test case checks if the mta_hal_DectSetEnable function returns the correct status code when an invalid boolean value is passed as an input.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 027 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | invoking the mta_hal_DectSetEnable with an invalid boolean value | bBool = 123 (Invalid) | RETURN_ERR | Should return an error status |
 */
void test_l1_mta_hal_negative1_DectSetEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_DectSetEnable...");

    // Invalid boolean value
    BOOLEAN bBool = 123;
    UT_LOG("Invoking mta_hal_DectSetEnable with input parameter bBool = 123 (Invalid).");
    INT status = mta_hal_DectSetEnable(bBool);
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_DectSetEnable...");
}

/**
* @brief This test verifies the functionality of the mta_hal_DectGetRegistrationMode API by checking if it correctly sets the registration mode to enabled.
*
* This test case belongs to the Basic (L1) test group and has a high priority as it is an essential functionality of the API.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 028 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_DectGetRegistrationMode API with pBool value TRUE | pBool = TRUE | SUCCESS | The registration mode should be successfully enabled |
*/
void test_l1_mta_hal_positive1_DectGetRegistrationMode(void) {

    UT_LOG("Entering test_l1_mta_hal_positive1_DectGetRegistrationMode...");
    BOOLEAN pBool = TRUE;

    UT_LOG("Invoking mta_hal_DectGetRegistrationMode with pBool as valid pointer...");
    INT result = mta_hal_DectGetRegistrationMode(&pBool);
    UT_LOG("Returned result: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_DectGetRegistrationMode...");
}

/**
* @brief Test case to verify the behavior of mta_hal_DectGetRegistrationMode function when registration mode is disabled.
*
* This test case validates the mta_hal_DectGetRegistrationMode function when the registration mode is disabled. It checks if the function returns the expected result and updates the output variable correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 029 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_DectGetRegistrationMode with pBool Value with FALSE | pBool = FALSE | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive2_DectGetRegistrationMode(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_DectGetRegistrationMode...");
    BOOLEAN pBool = FALSE; 

    UT_LOG("Invoking mta_hal_DectGetRegistrationMode with pBool as valid pointer...");
    INT result = mta_hal_DectGetRegistrationMode(&pBool);
    UT_LOG("Returned result: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_DectGetRegistrationMode...");
}

/**
 * @brief Test the function mta_hal_DectGetRegistrationMode with a null pointer as input.
 *
 * This test case verifies the behavior of the mta_hal_DectGetRegistrationMode function when a null pointer is passed as an argument.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 030 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_DectGetRegistrationMode with pBool as null pointer | pBool = NULL | RETURN_ERR | Should be unsuccessful |
 */
void test_l1_mta_hal_negative1_DectGetRegistrationMode(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_DectGetRegistrationMode...");
    BOOLEAN* pBool = NULL;

    UT_LOG("Invoking mta_hal_DectGetRegistrationMode with pBool as null pointer...");
    INT result = mta_hal_DectGetRegistrationMode(pBool);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Returned result: %d", result);

    UT_LOG("Exiting test_l1_mta_hal_negative1_DectGetRegistrationMode...");
}

/**
* @brief Test case to verify the functionality of mta_hal_DectSetRegistrationMode function.
*
* This test case verifies the functionality of mta_hal_DectSetRegistrationMode function by setting the DECT registration mode enabled.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 031 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_DectSetRegistrationMode with bBool Value TRUE | bBool = TRUE | The registration mode is set to enabled. | Should return RETURN_OK |
*/
void test_l1_mta_hal_positive1_DectSetRegistrationMode(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_DectSetRegistrationMode...");

    BOOLEAN bBool = TRUE;
    UT_LOG("Invoking mta_hal_DectSetRegistrationMode with bBool = TRUE");
    INT status = mta_hal_DectSetRegistrationMode(bBool);
    UT_LOG("Result : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_DectSetRegistrationMode...");
}

/**
 * @brief Test case to verify the functionality of the `mta_hal_DectSetRegistrationMode` function when the registration mode is disabled.
 *
 * This test case verifies the behavior of the `mta_hal_DectSetRegistrationMode` function when the registration mode is set to disabled (`bBool = FALSE`).
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
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Verify the behavior of `mta_hal_DectSetRegistrationMode bBool value FALSE | bBool = FALSE | RETURN_OK | Should be successful |
 */

void test_l1_mta_hal_positive2_DectSetRegistrationMode(void) {
   UT_LOG("Entering test_l1_mta_hal_positive2_DectSetRegistrationMode...");
   
   BOOLEAN bBool = FALSE;
   UT_LOG("Invoking mta_hal_DectSetRegistrationMode with bBool = FALSE");
   INT status = mta_hal_DectSetRegistrationMode(bBool);
   UT_LOG("Status : %d ", status);
   UT_ASSERT_EQUAL(status, RETURN_OK);
   
   UT_LOG("Exiting test_l1_mta_hal_positive2_DectSetRegistrationMode...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_DectSetRegistrationMode function when an undefined boolean value is passed as an argument.
*
* The objective of this test is to ensure that the mta_hal_DectSetRegistrationMode function handles undefined boolean values correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 033 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_DectSetRegistrationMode with an undefined boolean value | bBool = 2 | RETURN_ERR | Should return an error |
*/

void test_l1_mta_hal_negative1_DectSetRegistrationMode(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_DectSetRegistrationMode...");

    BOOLEAN bBool = 2; 
    UT_LOG("Invoking mta_hal_DectSetRegistrationMode with bBool = 2");
    INT status = mta_hal_DectSetRegistrationMode(bBool);
    UT_LOG("Status : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_DectSetRegistrationMode...");
}

/**
* @brief Test case to verify the functionality of the mta_hal_DectDeregisterDectHandset function.
*
* This test case is used to verify the functionality of the mta_hal_DectDeregisterDectHandset() function when positive input values are provided.
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
* | Variation / Step | Description  | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_DectDeregisterDectHandset() function  with value as 0  | uValue = 0 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_DectDeregisterDectHandset(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_DectDeregisterDectHandset...");

    unsigned long uValue = 0;
    UT_LOG("Invoking mta_hal_DectDeregisterDectHandset with uValue: %lu", uValue);
    INT status = mta_hal_DectDeregisterDectHandset(uValue);
    UT_LOG("Status : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_DectDeregisterDectHandset...");
}

/**
 * @brief Tests the functionality of the mta_hal_DectDeregisterDectHandset() function.
 *
 * This test function verifies the behavior of the mta_hal_DectDeregisterDectHandset() function by passing the maximum possible value to the function and checking if the return value is equal to RETURN_OK.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 035 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoke mta_hal_DectDeregisterDectHandset() function with maximum value | uValue = 4294967295 | status = RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive2_DectDeregisterDectHandset(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_DectDeregisterDectHandset...");

    unsigned long uValue = 4294967295; // maximum value
    UT_LOG("Invoking mta_hal_DectDeregisterDectHandset with uValue: %lu", uValue);
    INT status = mta_hal_DectDeregisterDectHandset(uValue);
    UT_LOG("Status : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_DectDeregisterDectHandset...");
}

/**
* @brief Test the functionality of the mta_hal_DectDeregisterDectHandset() function
*
* This test case checks the functionality of the mta_hal_DectDeregisterDectHandset() function by invoking it with a random value.
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
* | 01 | Invoke mta_hal_DectDeregisterDectHandset() function with random value | uValue = 1234567890 | Function returns RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive3_DectDeregisterDectHandset(void) {
    UT_LOG("Entering test_l1_mta_hal_positive3_DectDeregisterDectHandset...");

    unsigned long uValue = 1234567890; // random value
    UT_LOG("Invoking mta_hal_DectDeregisterDectHandset with uValue: %lu", uValue);
    INT status = mta_hal_DectDeregisterDectHandset(uValue);
    UT_LOG("Status : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive3_DectDeregisterDectHandset...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_DectDeregisterDectHandset when an invalid value is passed as input.
 *
 * This test case verifies the behavior of mta_hal_DectDeregisterDectHandset API when an invalid value is passed as input. The API should return an error status.
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_DectDeregisterDectHandset with an invalid value | uValue = 100 | RETURN_ERR | Should return error status |
 */

void test_l1_mta_hal_negative1_DectDeregisterDectHandset(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_DectDeregisterDectHandset...");

    unsigned long uValue = 100; // assumed invalid value
    UT_LOG("Invoking mta_hal_DectDeregisterDectHandset with uValue: %lu", uValue);
    INT status = mta_hal_DectDeregisterDectHandset(uValue);

    UT_LOG("Status : %d ", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_DectDeregisterDectHandset...");
}

/**
* @brief Unit test for the function mta_hal_GetDect when a valid memory location is provided
*
* This test case verifies the functionality of mta_hal_GetDect when a valid memory location is provided. The objective is to ensure that the function returns successfully and the obtained values in the structure members are correct.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 038 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetDect API with valid memory address | pDectInfo = Valid memory | RETURN_OK | should be successful |
*/
void test_l1_mta_hal_positive1_GetDect(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDect...");

    // Allocate a valid memory location for the structure
    PMTAMGMT_MTA_DECT pDectInfo = (PMTAMGMT_MTA_DECT )malloc(sizeof(MTAMGMT_MTA_DECT));
    if(pDectInfo != NULL)
    {
        // Invoke the API
        UT_LOG("Invoking the mta_hal_GetDect with valid memory");
        INT returnStatus = mta_hal_GetDect(pDectInfo);
        UT_LOG("Return value : %d ", returnStatus);
        // Check the return status
        UT_ASSERT_EQUAL(returnStatus, RETURN_OK);
        // Free the allocated memory
        free(pDectInfo);
    }  
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    } 
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetDect...");
}

/**
* @brief This test case checks the behavior of mta_hal_GetDect when a NULL pointer is passed as input.
*
* This test verifies that the function returns the expected error code when invoked with a NULL pointer as input.
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
* | 01 | Invoke the mta_hal_GetDect API with a NULL pointer | pDectInfo = NULL | RETURN_ERR | Should return an error code |
*/
void test_l1_mta_hal_negative1_GetDect(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDect...");
    PMTAMGMT_MTA_DECT pDectInfo = NULL;
    // Invoke the API with a NULL pointer
    INT returnStatus = mta_hal_GetDect(pDectInfo);
    UT_LOG("Return value : %d ", returnStatus);
    // Check the return status
    UT_ASSERT_EQUAL(returnStatus, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDect...");
}

/**
* @brief Test case for testing the functionality of mta_hal_GetDectPIN API
*
* This test case verifies the functionality of the mta_hal_GetDectPIN API by invoking it with a valid memory location and checking the return status.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_GetDectPIN with valid memory location | pin = Valid Buffer | RETURN_OK | The API should return successfully |
*/

void test_l1_mta_hal_positive1_GetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDectPIN...");

    // Allocate memory for character array
    char pin[128] = {"\0"};
    // Invoke API with valid memory location
    UT_LOG("Invoking mta_hal_GetDectPIN with valid memory location - Passed");
    INT status = mta_hal_GetDectPIN(pin);
    UT_LOG("Return status : %d", status);
    // Check return status
    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetDectPIN...");
}

/**
 * @brief This test case is for testing the mta_hal_GetDectPIN API when invoked with a NULL pointer.
 *
 * This test case verifies the behavior of mta_hal_GetDectPIN API when it is called with a NULL pointer as an argument. The expected outcome is that the API should return RETURN_ERR.
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
 * | 01 | Invoke mta_hal_GetDectPIN API with NULL pointer | pointer = NULL | RETURN_ERR | Should return RETURN_ERR |
 */

void test_l1_mta_hal_negative1_GetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDectPIN...");
    char pin[128] = {"\0"};
    // Invoke API with NULL pointer
    UT_LOG("Invoking mta_hal_GetDectPIN with NULL pointer - Passed");
    INT status = mta_hal_GetDectPIN(pin);
    UT_LOG("Return status : %d", status);
    // Check return status
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDectPIN...");
}

/**
 * @brief This is a positive test case to verify the functionality of mta_hal_SetDectPIN API when a valid PIN string is provided.
 *
 * This test checks whether the mta_hal_SetDectPIN API correctly sets the DECT PIN when a valid PIN string is provided as input.
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
 * | 01 | Invoke mta_hal_SetDectPIN API with a valid PIN string | pinString = "validPIN" | RETURN_OK | Should set the DECT PIN successfully |
 */
void test_l1_mta_hal_positive1_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_SetDectPIN...");

    // Create a valid character array of size 128 bytes filled with a valid PIN
    char pinString[128] = "12345678";  

    // Invoke mta_hal_SetDectPIN using the array's pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with the pin 12345678");
    INT result = mta_hal_SetDectPIN(pinString);
    UT_LOG("Result : %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_SetDectPIN...");
}

/**
* @brief Test for setting an empty string as the DECT PIN.
*
* This test case checks if the mta_hal_SetDectPIN function can successfully set an empty string as the DECT PIN. The objective of this test is to verify the behavior of the function when provided with an empty string as input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 043 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_SetDectPIN with Empty String | pinString = "" | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive2_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive2_SetDectPIN...");

    // Create a character array of size 128 bytes initialized to an empty string
    char pinString[128] = "";

    // Invoke mta_hal_SetDectPIN using the array's pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with empty ");
    INT result = mta_hal_SetDectPIN(pinString);
    UT_LOG("Result : %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_SetDectPIN...");
}

/**
* @brief Test case to verify the behavior of mta_hal_SetDectPIN API when passed a NULL pointer.
*
* This test case verifies the behavior of mta_hal_SetDectPIN when passed a NULL pointer. The objective is to ensure that the API handles the NULL pointer correctly and returns the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 044 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_SetDectPIN with a NULL pointer | pointer = NULL | RETURN_ERR | Should return error |
* 
*/
void test_l1_mta_hal_negative1_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_SetDectPIN...");

    // Invoke mta_hal_SetDectPIN with a NULL pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with NULL");
    INT result = mta_hal_SetDectPIN(NULL);
    UT_LOG("Result : %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_SetDectPIN...");
}

/**
 * @brief Test to verify behavior when a string exceeding the limit is passed to mta_hal_SetDectPIN function.
 *
 * This test aims to verify the behavior of the mta_hal_SetDectPIN function when a string exceeding the limit is passed as input. It checks if the function returns the expected error code when an oversized PIN string is provided.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 045 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 *  | Variation / Step | Description | Test Data | Expected Result | Notes |
 *  | :----: | :---------: | :----------: |:--------------: | :-----: |
 *  | 01 | Invoking the mta_hal_SetDectPIN with a string exceeding the size limit | pinString = "1234567890123456789012345678901234567890123456789012345678901234567890" | RETURN_ERR | Should return an error|
 *
 */

void test_l1_mta_hal_negative2_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative2_SetDectPIN...");

    // Create a valid character array with a size greater than 128 bytes filled with a valid PIN
    char pinString[130] = "1234567890123456789012345678901234567890123456789012345678901234567890";

    // Invoke mta_hal_SetDectPIN using the array's pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with the 128 byte of pin");
    INT result = mta_hal_SetDectPIN(pinString);
    UT_LOG("Result : %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative2_SetDectPIN...");
}

/**
* @brief This test case is designed to verify the behavior of the mta_hal_SetDectPIN function when an array containing invalid characters is provided as input for the dect PIN.
*
* The test verifies if the function returns the expected result when an array filled with invalid characters is passed as the dect PIN parameter.
* 
* **Test Group ID:** Basic :01 @n
* **Test Case ID:** 046 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
*  | Variation / Step | Description | Test Data | Expected Result | Notes |
*  | :----: | :---------: | :----------: |:--------------: | :-----: |
*  | 01 | Invoking the mta_hal_SetDectPIN with invalid characters | pinString = "!@#$%^&*()" |  RETURN_ERR | Should return an error.|
*/
void test_l1_mta_hal_negative3_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative3_SetDectPIN...");

    // Create a character array of size 128 bytes filled with invalid characters
    char pinString[128] = "!@#$%^&*()";
    // Invoke mta_hal_SetDectPIN using the array's pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with Invalid characters");
    INT result = mta_hal_SetDectPIN(pinString);
    UT_LOG("Result : %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative3_SetDectPIN...");
}

/**
* @brief Test the behavior when a partially populated string is passed to mta_hal_SetDectPIN API.
*
* This test case checks the behavior of the mta_hal_SetDectPIN API when a partially populated string is passed as input. The objective is to verify that the API handles the partially populated string correctly and returns the expected result.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_SetDectPIN with Partially populated string | pinString = "validPIN" | RETURN_ERR | The API should return an error code |
*/
void test_l1_mta_hal_negative4_SetDectPIN(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative4_SetDectPIN...");

    // Create a character array of size 128 bytes where only the first 50 bytes are populated with a valid PIN and the rest are uninitialized
    char pinString[128] = "validPIN";

    // Invoke mta_hal_SetDectPIN using the array's pointer
    UT_LOG("Invoking the mta_hal_SetDectPIN with validPIN ");
    INT result = mta_hal_SetDectPIN(pinString);
    UT_LOG("Result : %d", result);

    // Check the return status for the expected result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative4_SetDectPIN...");
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetHandsets API with a valid handset number.
*
* The objective of this test case is to verify that the mta_hal_GetHandsets API returns the expected status and the correct values in ppHandsets when a valid handset number is provided as input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 048 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetHandsets API with valid parameters | pulCount = 1, ppHandsets = valid Memory | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_GetHandsets...");

    unsigned long pulCount = 1;
    PMTAMGMT_MTA_HANDSETS_INFO ppHandsets= (PMTAMGMT_MTA_HANDSETS_INFO )malloc (sizeof (MTAMGMT_MTA_HANDSETS_INFO));
    if(ppHandsets != NULL)
    {
        UT_LOG("Invoking mta_hal_GetHandsets with pulCount : %d  ppHandsets = NULL");
        INT status = mta_hal_GetHandsets(&pulCount, &ppHandsets);
        UT_LOG("Result status : %d", status);
    
        UT_ASSERT_EQUAL(RETURN_OK, status);
        free(ppHandsets);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Existing test_l1_mta_hal_positive1_GetHandsets...");
}

/**
 * @brief Test case to validate the behavior of the mta_hal_GetHandsets function when the minimum number of handsets is returned.
 *
 * This test case checks if the mta_hal_GetHandsets function returns the correct status and updates the pulCount and ppHandsets variables correctly when the minimum number of handsets is returned.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 049 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_GetHandsets with valid memory | pulCount = 0, ppHandsets = NULL | RETURN_OK is returned | Should be successful |
 */

void test_l1_mta_hal_positive2_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive2_GetHandsets...");
    unsigned long* pulCount = malloc(sizeof(unsigned long));
    if (pulCount != NULL)
    {
        *pulCount = 0;
        PMTAMGMT_MTA_HANDSETS_INFO ppHandsets = NULL;
        UT_LOG("Invoking the mta_hal_GetHandsets");
        INT status = mta_hal_GetHandsets(pulCount, &ppHandsets);
        UT_LOG("Status: %d ", status);
        UT_LOG("mta_hal_GetHandsets with pulCount=%lu, ppHandsets=%s", *pulCount, (ppHandsets != NULL) ? "valid" : "NULL");
        UT_ASSERT_EQUAL(RETURN_OK, status);
        free(pulCount);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive2_GetHandsets...");
}

/**
* @brief This test checks the behavior of the mta_hal_GetHandsets function when the 'pulCount' parameter is NULL.
*
* The mta_hal_GetHandsets function is tested in this test case to verify the behavior when the 'pulCount' parameter is NULL. The objective of this test case is to ensure that the function handles the NULL 'pulCount' parameter correctly and returns the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 050 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetHandsets with NULL pulCount parameter | pulCount = NULL, ppHandsets = Valid | RETURN_ERR | Should return error |
*
*/
void test_l1_mta_hal_negative1_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_GetHandsets...");
    ULONG *pulCount = NULL;
    PMTAMGMT_MTA_HANDSETS_INFO ppHandsets;
    UT_LOG("Invoking the mta_hal_GetHandsets ");
    INT status = mta_hal_GetHandsets(pulCount, &ppHandsets);
    UT_LOG("Status: %d ", status);
    UT_LOG("mta_hal_GetHandsets returns ppHandsets=%s", (ppHandsets != NULL) ? "valid" : "NULL");
    UT_ASSERT_EQUAL(RETURN_ERR, status);
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetHandsets...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetHandsets function when the ppHandsets parameter is NULL.
*
* The objective of this test is to ensure that the function correctly handles the case when the ppHandsets parameter is NULL.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify  mta_hal_GetHandsets API behavior when ppHandsets is NULL | pulCount = 1, ppHandsets = NULL | Function returns RETURN_ERR | Should be successful |
*/
void test_l1_mta_hal_negative2_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative2_GetHandsets...");

    unsigned long* pulCount = malloc(sizeof(unsigned long));
    if(pulCount != NULL)
    {
        *pulCount = 1;
        UT_LOG("Invoking the mta_hal_GetHandsets ");
        INT status = mta_hal_GetHandsets(pulCount, NULL);
        UT_LOG("Status: %d ", status);
        UT_LOG("mta_hal_GetHandsets returned pulCount=%lu", *pulCount);
        UT_ASSERT_EQUAL(RETURN_ERR, status);
        free(pulCount);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_negative2_GetHandsets...");
}

/**
* @brief This is a negative test case to verify the behavior of mta_hal_GetHandsets function when pulCount and ppHandsets are NULL.
*
* This test case verifies that when pulCount and ppHandsets are NULL, the mta_hal_GetHandsets function returns RETURN_ERR.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 052 @n
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
* | 01 | Invoking mta_hal_GetHandsets function with pulCount=NULL, ppHandsets=NULL | pulCount = NULL, ppHandsets = NULL | RETURN_ERR | Should return error |
*/
void test_l1_mta_hal_negative3_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative3_GetHandsets...");
    UT_LOG("Invoking mta_hal_GetHandsets with pulCount=NULL, ppHandsets=NULL");
    INT status = mta_hal_GetHandsets(NULL, NULL);
    UT_LOG("Status: %d ", status);
    UT_ASSERT_EQUAL(RETURN_ERR, status);

    UT_LOG("Exiting test_l1_mta_hal_negative3_GetHandsets...");
}

/**
 * @brief This test case is used to verify the behavior of the mta_hal_GetHandsets function when an invalid handset number is passed as input.
 *
 * The objective of this test is to ensure that the mta_hal_GetHandsets function returns an error status when an invalid handset number is provided.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 053 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_GetHandsets with invalid handset number | pulCount = 4294967297, ppHandsets = NULL | RETURN_ERR | This test is expected to fail |
 */
void test_l1_mta_hal_negative4_GetHandsets(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative4_GetHandsets...");

    unsigned long* pulCount = malloc(sizeof(unsigned long));
    if(pulCount != NULL)
    {
        *pulCount = 4294967297; 

        PMTAMGMT_MTA_HANDSETS_INFO ppHandsets = NULL;
        UT_LOG("Invoking the mta_hal_GetHandsets with %lu ", *pulCount);
        INT status = mta_hal_GetHandsets(pulCount, &ppHandsets);
        UT_LOG("Status: %d ", status);

        UT_ASSERT_EQUAL(RETURN_ERR, status);
        free(pulCount);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_negative4_GetHandsets...");
}

/**
* @brief Unit test for the mta_hal_GetCalls function.
*
* This test case is used to verify the functionality of the mta_hal_GetCalls function by invoking it with various input arguments and checking the return status.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetCalls with pCfg as NULL | instanceNumber = 42, count = 0, pCfg = NULL | RETURN_OK is returned | The function should execute successfully |
*/
void test_l1_mta_hal_positive1_GetCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetCalls");
    
    ULONG instanceNumber = 42;
    ULONG count = 0;
    PMTAMGMT_MTA_CALLS pCfg = (PMTAMGMT_MTA_CALLS) malloc (sizeof(MTAMGMT_MTA_CALLS));
    if(pCfg != NULL)
    {
        UT_LOG("Invoking mta_hal_GetCalls with instanceNumber = 42 , count =0   and pCfg = NULL");
	INT result = mta_hal_GetCalls(instanceNumber, &count, &pCfg);
	UT_LOG("Return status: %d count : %lu", result, count);
	UT_ASSERT_EQUAL(result, RETURN_OK);
	free(pCfg);
    }
    else
    {
    	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Existing from the test_l1_mta_hal_positive1_GetCalls() ");
}

/**
* @brief This test case is for testing the boundary conditions of the mta_hal_GetCalls API.
*
* The objective of this test case is to check if the mta_hal_GetCalls API can handle the boundary conditions of the input parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 055 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetCalls with instanceNumber: 0, count: 0, pCfg: NULL | instanceNumber = 0, count = 0, pCfg = NULL | Success (RETURN_OK) | Should be successful |
*/
void test_l1_mta_hal_positive2_GetCalls(void) {
    UT_LOG("Entering into test_l1_mta_hal_positive2_GetCalls ");
    
    ULONG instanceNumber1 = 0;
    ULONG count1 = 0;
    PMTAMGMT_MTA_CALLS pCfg1 = (PMTAMGMT_MTA_CALLS) malloc (sizeof(MTAMGMT_MTA_CALLS));
    if(pCfg1 != NULL)
    {
	UT_LOG("Invoking mta_hal_GetCalls with instanceNumber1 = 0 count : 0 and pCfg = Valid Memory");
	INT result1 = mta_hal_GetCalls(instanceNumber1, &count1, &pCfg1);
	UT_LOG("Return status: %d", result1);
	UT_ASSERT_EQUAL(result1, RETURN_OK);
	free(pCfg1);
    }
    else
    {
    	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    
    UT_LOG(" Existing from test_l1_mta_hal_positive2_GetCalls");
    
}

/**
 * @brief Test case to verify mta_hal_GetCalls API with null ppCfg parameter.
 *
 * The objective of this test is to verify the behavior of mta_hal_GetCalls API when the ppCfg parameter is NULL.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 056 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * Test Procedure: @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * |01| Invoking mta_hal_GetCalls with pCfg as NULL | instanceNumber = 42, count = 0, pCfg = NULL | RETURN_ERR | Should be equal to RETURN_ERR
 */
void test_l1_mta_hal_negative1_GetCalls(void) {
    UT_LOG(" Entering into test_l1_mta_hal_negative1_GetCalls");
    
    ULONG instanceNumber = 42; 
    ULONG count = 0;
    PMTAMGMT_MTA_CALLS pCfg = NULL;
    UT_LOG("Invoking mta_hal_GetCalls with instanceNumber = 42 , count =0   and pCfg = NULL");
    INT result = mta_hal_GetCalls(instanceNumber, &count, NULL);
    UT_LOG("Return status: %d Count : %lu", result, count);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Existing from test_l1_mta_hal_negative1_GetCalls");
}

/**
 * @brief Test the mta_hal_GetCalls function with NULL count and pCfg pointers.
 * 
 * This test case verifies the behavior of the mta_hal_GetCalls function when the count and pCfg pointers are NULL.
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_GetCalls with NULL count and pCfg pointers | instanceNumber = 42 | RETURN_ERR | Should return an error |
 */

void test_l1_mta_hal_negative2_GetCalls(void) {
    UT_LOG(" Entering into test_l1_mta_hal_negative2_GetCalls ");
    
    ULONG instanceNumber = 42;
    UT_LOG("Invoking mta_hal_GetCalls with instanceNumber: %lu, count: %p, pCfg: %p", instanceNumber, NULL, NULL);
    INT result = mta_hal_GetCalls(instanceNumber, NULL, NULL);
    UT_LOG("Return status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Existing from test_l1_mta_hal_negative2_GetCalls");
}

/**
* @brief This test is to verify the behavior of mta_hal_GetCalls function when the instance number is out of range.
*
* The purpose of this test is to check whether the function correctly handles out of range instance numbers and returns the expected result.
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify the behavior of mta_hal_GetCalls function with an out of range instance number | instanceNumber = 4294967296, count = 0, pCfg = NULL | RETURN_ERR | Function should return an error status |
*/

void test_l1_mta_hal_negative3_GetCalls(void) {
    UT_LOG("Entering into test_l1_mta_hal_negative3_GetCalls() ");
    
    ULONG instanceNumber = 4294967296; 
    ULONG count = 0;
    PMTAMGMT_MTA_CALLS pCfg = NULL;
    UT_LOG("Invoking mta_hal_GetCalls with count: %lu", count);
    INT result = mta_hal_GetCalls(instanceNumber, &count, &pCfg);
    UT_LOG("Return status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Existing from test_l1_mta_hal_negative3_GetCalls() ");
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetCALLP API
*
* This test case checks the functionality of the mta_hal_GetCALLP API, which is used to retrieve the call progress information for a given line number.
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
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetCALLP with valid LineNumber | LineNumber = 1 | RETURN_OK | should be successful |
*/
void test_l1_mta_hal_positive1_GetCALLP(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_GetCALLP...");

    UINT LineNumber = 1;  /* Set valid line number */
    PMTAMGMT_MTA_CALLP callp = (PMTAMGMT_MTA_CALLP) malloc (sizeof (MTAMGMT_MTA_CALLP));
    if(callp != NULL)
    {
        UT_LOG("Invoking mta_hal_GetCALLP with LineNumber = %u", LineNumber);
	INT result = mta_hal_GetCALLP(LineNumber, callp);
	UT_LOG("Result : %d ", result );
	UT_LOG("callp.LCState %s ", callp->LCState);
	/* Verify return value */
	UT_ASSERT_EQUAL(result, RETURN_OK);
	free(callp);
    }
    else
    {
	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetCALLP...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_GetCALLP function when an invalid line number is provided as input.
*
* The objective of this test is to ensure that the mta_hal_GetCALLP function returns the correct error code when an invalid line number is provided.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 060 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify mta_hal_GetCALLP API with an invalid line number | LineNumber = 0 | RETURN_ERR | The function should return an error |
*/
void test_l1_mta_hal_negative1_GetCALLP(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_GetCALLP...");

    UINT LineNumber = 0;  /* Set invalid line number */
    PMTAMGMT_MTA_CALLP callp = (PMTAMGMT_MTA_CALLP) malloc (sizeof (MTAMGMT_MTA_CALLP));
    if(callp != NULL)
    {
	UT_LOG("Invoking mta_hal_GetCALLP with LineNumber = %u", LineNumber);
	INT result = mta_hal_GetCALLP(LineNumber, callp);
	UT_LOG("Result : %d", result);
	/* Verify return value */
	UT_ASSERT_EQUAL(result, RETURN_ERR);
	free(callp);
    }
    else
    {
	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetCALLP...");
}

/**
 * @brief This test case is used to verify the behavior of the mta_hal_GetCALLP function when provided with invalid inputs.
 *
 * This test is part of the Basic (for L1) tests and has a high priority as it verifies the correctness of the function under negative scenarios.
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
 * | 01 | Invoke mta_hal_GetCALLP with LineNumber set to 1 and pCallp set to NULL | LineNumber = 1, pCallp = NULL | RETURN_ERR | Should return an error |
 */
void test_l1_mta_hal_negative2_GetCALLP(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative2_GetCALLP...");

    /* Set valid line number */
    UINT LineNumber = 1;
    /* Set pCallp as NULL */
    MTAMGMT_MTA_CALLP* pCallp = NULL;
    /* Invoking mta_hal_GetCALLP with LineNumber = 1, pCallp = NULL */
    UT_LOG("Invoking mta_hal_GetCALLP with LineNumber = %u, pCallp = NULL", LineNumber);
    INT result = mta_hal_GetCALLP(LineNumber, pCallp);
    UT_LOG("Result: %d ", result);
    /* Verify return value */
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative2_GetCALLP...");
}

/**
 * @brief This function tests the mta_hal_GetDSXLogs API.
 *
 * This test function verifies the functionality of the mta_hal_GetDSXLogs API by invoking it with valid input parameters. It checks if the API returns the expected result and if the log entries are not NULL.
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
 * | 01 | Invoking mta_hal_GetDSXLogs with valid input parameters | count = 0, pDSXLog = Valid Memory | result = RETURN_OK, count > 0, pDSXLog is not NULL | Should be successful |
*/

void test_l1_mta_hal_positive1_GetDSXLogs(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDSXLogs...");

    ULONG count;
    PMTAMGMT_MTA_DSXLOG pDSXLog;
    UT_LOG("Invoking mta_hal_GetDSXLogs with valid input parameters...");
    INT result = mta_hal_GetDSXLogs(&count, &pDSXLog);
   
    UT_LOG("Returned value: %d", result);
    UT_LOG("Number of Log Entries: %lu", count);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_GetDSXLogs...");
}

/**
 * @brief Test case to verify the behavior of the mta_hal_GetDSXLogs function when called with invalid input parameters (NULL). 
 * 
 * This test case checks if the mta_hal_GetDSXLogs function returns an expected error code when called with invalid input parameters. 
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
 * | 01 | Invoking mta_hal_GetDSXLogs with invalid input parameters (NULL) | count = NULL, pDSXLog = NULL | RETURN_ERR | Should return error |
 */
void test_l1_mta_hal_negative1_GetDSXLogs(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDSXLogs...");
    ULONG *count = NULL;
    PMTAMGMT_MTA_DSXLOG pDSXLog = NULL;
    UT_LOG("Invoking mta_hal_GetDSXLogs with invalid input parameters (NULL)...");
    INT result = mta_hal_GetDSXLogs(count, &pDSXLog);
    UT_LOG("Returned value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDSXLogs...");
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetDSXLogEnable function
*
* This test case is used to verify the functionality of the mta_hal_GetDSXLogEnable function by checking the return value and the value pointed to by pBool.
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
* | 01 | Provide a valid memory location for pBool and call mta_hal_GetDSXLogEnable function | pBool = valid memory address | RETURN_OK | The return value should be RETURN_OK |
*/
void test_l1_mta_hal_positive1_GetDSXLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetDSXLogEnable...");
    BOOLEAN bool_value;
    UT_LOG("Invoking mta_hal_GetDSXLogEnable with valid memory location for pBool");
    INT ret = mta_hal_GetDSXLogEnable(&bool_value);
    UT_LOG("Return Value: %d", ret);
    UT_LOG("Output Value: %d", bool_value);
    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_GetDSXLogEnable...");
}

/**
* @brief This function is used to test the behavior of the mta_hal_GetDSXLogEnable function.
*
* This test case verifies whether the mta_hal_GetDSXLogEnable function returns the expected value and modifies the boolean value correctly.
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
* | Variation / Step | Description | Test Data |Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Provide valid memory location for pBool and call the mta_hal_GetDSXLogEnable function | pBool = valid memory location | RETURN_OK | The return value should be RETURN_OK |
*/
void test_l1_mta_hal_positive2_GetDSXLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_GetDSXLogEnable...");
    BOOLEAN bool_value;
    UT_LOG("Invoking mta_hal_GetDSXLogEnable with valid memory location for pBool");
    INT ret = mta_hal_GetDSXLogEnable(&bool_value);
    UT_LOG("Return Value: %d", ret);
    UT_LOG("Output Value: %d", bool_value);
    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    // Verify the value pointed to by pBool is FALSE
    UT_ASSERT_EQUAL(bool_value, FALSE);
    UT_LOG("Exiting test_l1_mta_hal_positive2_GetDSXLogEnable...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_GetDSXLogEnable when a NULL pointer is provided for pBool.
 *
 * This test case checks whether the mta_hal_GetDSXLogEnable function returns RETURN_ERR when a NULL pointer is provided for pBool.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 066 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, they need to select this test case via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description  | Test Data     | Expected Result |Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_GetDSXLogEnable with NULL | pBool = NULL  | RETURN_ERR | Should be successful |
 */
void test_l1_mta_hal_negative1_GetDSXLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetDSXLogEnable...");
    UT_LOG("Invoking mta_hal_GetDSXLogEnable with NULL pointer for pBool");
    INT ret = mta_hal_GetDSXLogEnable(NULL);
    UT_LOG("Return Value: %d", ret);
    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_GetDSXLogEnable...");
}

/**
 * @brief Test case for enabling DSX log in the SetDSXLogEnable API.
 *
 * This test case verifies the functionality of the SetDSXLogEnable API when enabling the DSX log.
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
 * | 01 | Invoking mta_hal_SetDSXLogEnable with Bool Value TRUE | Bool = TRUE | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_SetDSXLogEnable(void) {
    /* Logging */
    UT_LOG("Entering test_l1_mta_hal_positive1_SetDSXLogEnable...\n");

    /* Test Setup */
    BOOLEAN Bool = TRUE;

    /* Test Execution */
    UT_LOG("Invoking mta_hal_SetDSXLogEnable with Bool = TRUE\n");
    INT result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG("Result : %d", result);
    /* Test Verification */

    UT_ASSERT_EQUAL(result, RETURN_OK);

    /* Logging */
    UT_LOG("Exiting test_l1_mta_hal_positive1_SetDSXLogEnable...\n");
}

/**
 * @brief Test case to verify the functionality of the function test_l1_mta_hal_positive2_SetDSXLogEnable.
 *
 * This test case is used to verify that the function correctly disables the DSX log when the input boolean value is set to FALSE.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 068 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 * | Variation/Step | Description | Test Data | Expected Result  | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * |  01  | Invoking the mta_hal_SetDSXLogEnable API with Bool Value = FALSE | Bool = FALSE | The API call should return RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive2_SetDSXLogEnable(void) {
    /* Logging */
    UT_LOG("Entering test_l1_mta_hal_positive2_SetDSXLogEnable...\n");
    /* Test Setup */
    BOOLEAN Bool = FALSE;
    /* Test Execution */
    UT_LOG("Invoking mta_hal_SetDSXLogEnable with Bool = FALSE\n");
    INT result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG("Result : %d", result);
    /* Test Verification */
    UT_ASSERT_EQUAL(result, RETURN_OK);
    /* Logging */
    UT_LOG("Exiting test_l1_mta_hal_positive2_SetDSXLogEnable...\n");
}

/**
* @brief This test verifies the behavior of the mta_hal_SetDSXLogEnable function when an invalid boolean value is passed as an argument.
*
* The objective of this test is to ensure that the mta_hal_SetDSXLogEnable function properly handles an invalid boolean value and returns an error code.
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
* | 01 | Invoking mta_hal_SetDSXLogEnable with invalid boolean value | Bool = 2 | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_SetDSXLogEnable(void) {
    /* Logging */
    UT_LOG("Entering test_l1_mta_hal_negative1_SetDSXLogEnable...\n");

    /* Test Setup */
    BOOLEAN Bool = 2; // Invalid value (not TRUE or FALSE)

    /* Test Execution */
    UT_LOG("Invoking mta_hal_SetDSXLogEnable with invalid value: Bool = 2\n");
    INT result = mta_hal_SetDSXLogEnable(Bool);
    UT_LOG("Result : %d", result);
    /* Test Verification */

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    /* Logging */
    UT_LOG("Exiting test_l1_mta_hal_negative1_SetDSXLogEnable...\n");
}

/**
* @brief Test function to verify the functionality of mta_hal_ClearDSXLog API when the Bool parameter is set to TRUE.
*
* This test function verifies the functionality of mta_hal_ClearDSXLog API by setting the Bool parameter to TRUE and calling the API. It checks if the return value is RETURN_OK or not.
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
* |  01    | Invoking the mta_hal_ClearDSXLog with TRUE clearLog | clearLog = TRUE | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_ClearDSXLog(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_ClearDSXLog...");

    // Set the Bool parameter to TRUE
    BOOLEAN clearLog = TRUE;

    // Call the mta_hal_ClearDSXLog function
    UT_LOG("Invoking mta_hal_ClearDSXLog with Bool parameter set to TRUE");
    INT result = mta_hal_ClearDSXLog(clearLog);
    UT_LOG("Result : %d", result);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_ClearDSXLog...");
}

/**
* @brief Test the function mta_hal_ClearDSXLog with Bool parameter set to FALSE
*
* This test case verifies the behavior of the mta_hal_ClearDSXLog function when the Bool parameter is set to FALSE.
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
* | 01 | Invoke mta_hal_ClearDSXLog with Bool parameter set to FALSE | clearLog = FALSE | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive2_ClearDSXLog(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_ClearDSXLog...");

    // Set the Bool parameter to FALSE
    BOOLEAN clearLog = FALSE;

    // Call the mta_hal_ClearDSXLog function
    UT_LOG("Invoking mta_hal_ClearDSXLog with Bool parameter set to FALSE");
    INT result = mta_hal_ClearDSXLog(clearLog);
    UT_LOG("Result : %d", result);
    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive2_ClearDSXLog...");
}

/**
* @brief This test case is to verify the behavior of the mta_hal_ClearDSXLog() function when an invalid boolean value is passed as a parameter.
*
* The objective of this test is to check if the function handles the case of an invalid boolean value correctly by returning the error code.
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
* | Variation / Step | Description  | Test Data | Expected Result   | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01  | Invoking mta_hal_ClearDSXLog  with Invalid value | clearLog = 2 | RETURN_ERR  | Should be error   |
*/

void test_l1_mta_hal_negative1_ClearDSXLog(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_ClearDSXLog...");

    // Set the Bool parameter to an invalid value (e.g., 2)
    BOOLEAN clearLog = 2;
    // Call the mta_hal_ClearDSXLog function
    UT_LOG("Invoking mta_hal_ClearDSXLog with invalid Bool parameter value (2)");
    INT result = mta_hal_ClearDSXLog(clearLog);
    UT_LOG("Return Status: %d", result);
    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_ClearDSXLog...");
}

/**
* @brief Test case to verify the functionality of the mta_hal_GetCallSignallingLogEnable API.
*
* This test case verifies the functionality of the mta_hal_GetCallSignallingLogEnable API. The objective of this test is to ensure that the API returns the correct result and value at the memory location.
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
* | 01 | Invoking the mta_hal_GetCallSignallingLogEnable with value as TRUE | pBool = TRUE | RETURN_OK | should be successful |
*/
void test_l1_mta_hal_positive1_GetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetCallSignallingLogEnable...");

    BOOLEAN pBool = TRUE;
    // Call the API function
    UT_LOG("Invoking the mta_hal_GetCallSignallingLogEnable API with TRUE");
    INT result = mta_hal_GetCallSignallingLogEnable(&pBool);
    UT_LOG("Result : %d ",result);
    UT_LOG("Boolean pBool value  : %d", pBool);
    // Verify the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Verify the value at the memory location
    UT_ASSERT_EQUAL(pBool, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_GetCallSignallingLogEnable...");
}

/**
* @brief This test is to verify the functionality of the GetCallSignallingLogEnable API
*
* The purpose of this test is to verify that the GetCallSignallingLogEnable API returns the correct value and that the memory location pointed to by the pBool parameter is updated with the correct value.
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
* | 01 | Call the GetCallSignallingLogEnable API with value as FALSE | pBool = FALSE | result is RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive2_GetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_GetCallSignallingLogEnable...");

    BOOLEAN pBool = FALSE;
    // Call the API function
    UT_LOG("Invoking the mta_hal_GetCallSignallingLogEnable API with False ");
    INT result = mta_hal_GetCallSignallingLogEnable(&pBool);
    UT_LOG("Result : %d ",result);
    // Verify the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Verify the value at the memory location
    UT_ASSERT_EQUAL(pBool, FALSE);

    UT_LOG("Exiting test_l1_mta_hal_positive2_GetCallSignallingLogEnable...");
}

/**
* @brief Test case to verify the behavior of the mta_hal_GetCallSignallingLogEnable function when the pBool parameter is set to NULL
*
* This test case checks if the mta_hal_GetCallSignallingLogEnable function returns the expected error code when the pBool parameter is set to NULL.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 075 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_GetCallSignallingLogEnable with Invaid pBool Value | pBool = NULL | RETURN_ERR | Should return an error status |
*/
void test_l1_mta_hal_negative1_GetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetCallSignallingLogEnable...");

    BOOLEAN *pBool = NULL; 
    // Call the API function
    UT_LOG("Invoking the mta_hal_GetCallSignallingLogEnable API with NULL");
    INT result = mta_hal_GetCallSignallingLogEnable(pBool);
    UT_LOG("Result : %d ",result);
    // Verify the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_GetCallSignallingLogEnable...");
}

/**
* @brief Test case to verify the functionality of mta_hal_SetCallSignallingLogEnable API.
*
* This test case verifies whether mta_hal_SetCallSignallingLogEnable API is able to enable the call signalling log successfully and whether it returns the expected result.
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
* | 01 | Invoke the mta_hal_SetCallSignallingLogEnable API with enable value TRUE | enable = TRUE | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_SetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_SetCallSignallingLogEnable...");

    // Enable the CallSignalling Log
    BOOLEAN enable = TRUE;
    UT_LOG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    INT result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG("Return value: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_SetCallSignallingLogEnable...");
}

/**
 * @brief Test case to verify the functionality of the "mta_hal_SetCallSignallingLogEnable" function
 *
 * This test case verifies the functionality of the "mta_hal_SetCallSignallingLogEnable" API by setting the Call Signalling Log Enable to FALSE and checking if the result is RETURN_OK.
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
 * |  01    | Invoking the mta_hal_SetCallSignallingLogEnable API with FALSE | enable = FALSE | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive2_SetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_SetCallSignallingLogEnable...");

    // Disable the CallSignalling Log
    BOOLEAN enable = FALSE;
    UT_LOG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    INT result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG("Return value: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive2_SetCallSignallingLogEnable...");
}

/**
* @brief Testing the function `mta_hal_SetCallSignallingLogEnable` with invalid boolean value.
*
* This test case is designed to verify the behavior of `mta_hal_SetCallSignallingLogEnable` function when an invalid boolean value is passed as input.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 078 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_SetCallSignallingLogEnable with invalid boolean value as input | enable = 2 | RETURN_ERR | Should return `RETURN_ERR` |
*/
void test_l1_mta_hal_negative1_SetCallSignallingLogEnable(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_SetCallSignallingLogEnable...");

    // Invalid Boolean Value
    BOOLEAN enable = 2;  // Assuming BOOLEAN accepts only 0 or 1
    UT_LOG("Invoking mta_hal_SetCallSignallingLogEnable with enable = %d", enable);
    INT result = mta_hal_SetCallSignallingLogEnable(enable);
    UT_LOG("Return value: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_SetCallSignallingLogEnable...");
}

/**
 * @brief Test case to verify the functionality of the mta_hal_ClearCallSignallingLog() function.
 *
 * The purpose of this test is to ensure that the mta_hal_ClearCallSignallingLog() function is able to clear the call signalling log when the Bool parameter is set to TRUE.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 079 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Call the mta_hal_ClearCallSignallingLog() function with Bool parameter set to TRUE. | Bool parameter = TRUE | RETURN_OK | The call signalling log should be cleared successfully.
 */
void test_l1_mta_hal_positive1_ClearCallSignallingLog(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_ClearCallSignallingLog...");
    BOOLEAN value = TRUE;
    // Call the function with Bool parameter set to TRUE
    UT_LOG("Invoking the mta_hal_ClearCallSignallingLog TRUE");
    INT ret = mta_hal_ClearCallSignallingLog(value);
    UT_LOG("Result : %d", ret);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_ClearCallSignallingLog...");
}

/**
 * @brief Test case to verify the behavior of mta_hal_ClearCallSignallingLog function when the parameter is set to FALSE.
 *
 * This test case verifies that the mta_hal_ClearCallSignallingLog function returns RETURN_OK when the parameter is set to FALSE.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 080 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Call mta_hal_ClearCallSignallingLog function with parameter set to FALSE | isClear = FALSE | RETURN_OK | Should return RETURN_OK |
 */
void test_l1_mta_hal_positive2_ClearCallSignallingLog(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_ClearCallSignallingLog...");

    BOOLEAN value = FALSE;
    // Call the function with Bool parameter set to FALSE
    UT_LOG("Invoking the mta_hal_ClearCallSignallingLog FALSE ");
    INT ret = mta_hal_ClearCallSignallingLog(value);
    UT_LOG("Result : %d", ret);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive2_ClearCallSignallingLog...");
}

/**
* @brief Test case to validate the behavior of the mta_hal_ClearCallSignallingLog function when provided with an invalid BOOLEAN value.
*
* This test case verifies that the mta_hal_ClearCallSignallingLog function returns RETURN_ERR when an invalid BOOLEAN value is provided.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 081 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_ClearCallSignallingLog with an invalid BOOLEAN value | invalidValue = 0 | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_ClearCallSignallingLog(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_ClearCallSignallingLog...");

    BOOLEAN invalidValue = 2; 
    UT_LOG("Invoking the mta_hal_ClearCallSignallingLog invalidValue ");
    INT ret = mta_hal_ClearCallSignallingLog(invalidValue);
    UT_LOG("Result : %d", ret);

    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_ClearCallSignallingLog...");
}

/**
* @brief This is a positive test for the function mta_hal_GetMtaLog.
*
* This test verifies that the function mta_hal_GetMtaLog retrieves the MTA log correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 082 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetMtaLog with valid inputs | count = 0, pLog = NULL |  RETURN_OK | The function should succeed and return an empty log |
*/

void test_l1_mta_hal_positive1_GetMtaLog(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_GetMtaLog...");

    // Test variables
    ULONG count = 0;
    PMTAMGMT_MTA_MTALOG_FULL pLog = NULL;
    // Invoke the API
    UT_LOG("Invoking the mta_hal_GetMtaLog");
    INT result = mta_hal_GetMtaLog(&count, &pLog);
    UT_LOG("Result : %d ", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_GetMtaLog...");
}

/**
* @brief Test case to check the behaviour of mta_hal_GetMtaLog when NULL pointers are passed as arguments
*
* This test case checks whether the function mta_hal_GetMtaLog handles NULL pointers correctly and returns the expected error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 083 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_GetMtaLog function with NULL pointers | count = NULL, pLog = NULL | RETURN_ERR | Should return error |
*/

void test_l1_mta_hal_negative1_GetMtaLog(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_GetMtaLog...");

    // Test variables
    ULONG* count = NULL; 
    PMTAMGMT_MTA_MTALOG_FULL pLog = NULL; 

    // Invoke the API
    UT_LOG("Invoking the mta_hal_GetMtaLog");
    INT result = mta_hal_GetMtaLog(count, &pLog);
    UT_LOG("Result : %d ", result);
    // Perform assertions
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_GetMtaLog...");
}

/**
* @brief Test to verify the functionality of mta_hal_BatteryGetInstalled API.
*
* This test case is used to verify the functionality of the mta_hal_BatteryGetInstalled API. The API is responsible for retrieving the installed status of the battery. The objective of this test is to ensure that the API returns the expected result and does not produce any errors or crashes.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 084 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetInstalled API | Val = 0 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_BatteryGetInstalled(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetInstalled...");

    BOOLEAN Val = 0;
    UT_LOG("Invoking mta_hal_BatteryGetInstalled with Val=%d", Val);
    INT ret = mta_hal_BatteryGetInstalled(&Val);
    UT_LOG("Result : %d", ret);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_TRUE(Val == TRUE || Val == FALSE);

    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetInstalled...");
}

/**
* @brief This test validates the behavior of the mta_hal_BatteryGetInstalled function when invoked with NULL pointers.
*
* The mta_hal_BatteryGetInstalled function is tested in this test case to verify its behavior when NULL pointers are passed as arguments. The objective of this test is to ensure that the function handles NULL pointers correctly and returns the expected error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 085 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetInstalled with NULL | val = NULL | RETURN_ERR | Should be error |
*/
void test_l1_mta_hal_negative1_BatteryGetInstalled(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetInstalled...");

    BOOLEAN *Val = NULL; 
    UT_LOG("Invoking mta_hal_BatteryGetInstalled with Val= %d", Val);
    INT ret = mta_hal_BatteryGetInstalled(Val);
    UT_LOG("Result : %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetInstalled...");
}

/**
* @brief Test to check the functionality of mta_hal_BatteryGetTotalCapacity function
*
* The objective of this test is to check the functionality of the mta_hal_BatteryGetTotalCapacity function by invoking it with valid input parameters and verifying the return value and the value of Val.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 086 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetTotalCapacity with valid input parameters | val = 0 | RETURN_OK | The function should return success and Val should be updated |
*/

void test_l1_mta_hal_positive1_BatteryGetTotalCapacity(void) {
    /* Log entering the test function */
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetTotalCapacity...");

    /* Provide a valid memory location for Val */
    ULONG val =0 ;

    /* Invoke the API with valid input parameters */
    UT_LOG("Invoking mta_hal_BatteryGetTotalCapacity with Val=%p", &val);
    INT result = mta_hal_BatteryGetTotalCapacity(&val);
    UT_LOG("Return value: %d", result);
    /* Log the test description, output values, and return status */
       
    UT_LOG("Val: %lu", val);

    /* Check the return value */
    UT_ASSERT_EQUAL(result, RETURN_OK);

    /* Log exiting the test function */
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetTotalCapacity...");
}

/**
    * @brief This test case is used to verify the functionality of the mta_hal_BatteryGetTotalCapacity function when NULL is provided for the 'val' parameter.
    *
    * The objective of this test is to ensure that the function handles the invalid input parameter correctly and returns the expected result.
    *
    * **Test Group ID:** Basic: 01 @n
    * **Test Case ID:** 087 @n
    * **Priority:** High @n@n
    *
    * **Pre-Conditions:** None @n
    * **Dependencies:** None @n
    * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
    *
    * **Test Procedure:** @n
    * | Variation / Step | Description | Test Data | Expected Result | Notes |
    * | :----: | :---------: | :----------: |:--------------: | :-----: |
    * | 01 | Invoking the mta_hal_BatteryGetTotalCapacity with NULL | val = NULL | RETURN_ERR | Should return ERROR |
    */

void test_l1_mta_hal_negative1_BatteryGetTotalCapacity(void) {
    /* Log entering the test function */
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetTotalCapacity...");

    /* Provide NULL for Val */
    ULONG* val = NULL;

    /* Invoke the API with invalid input parameters */
    UT_LOG("Invoking mta_hal_BatteryGetTotalCapacity with Val=NULL");
    INT result = mta_hal_BatteryGetTotalCapacity(val);

    /* Log the test description, output values, and return status */
    UT_LOG("Return value: %d", result);

    /* Check the return value */
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    /* Log exiting the test function */
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetTotalCapacity...");
}

/**
 * @brief Test to verify the functionality of mta_hal_BatteryGetTotalCapacity with valid capacity.
 *
 * This test verifies if the mta_hal_BatteryGetTotalCapacity function returns a valid battery capacity by invoking mta_hal_BatteryGetActualCapacity and checking the return status and actual capacity against the expected range.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 088 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n 
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description  | Test Data  | Expected Result  | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * |  01  | Invoking mta_hal_BatteryGetTotalCapacity with valid memory location | capacity = 0 | RETURN_OK | should be successful |                                          *
 */
void test_l1_mta_hal_positive1_BatteryGetActualCapacity(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetActualCapacity...");

    ULONG capacity = 0;
    UT_LOG("Invoking mta_hal_BatteryGetTotalCapacity with valid memory location...");
    INT status = mta_hal_BatteryGetActualCapacity(&capacity);
    UT_LOG("Expected Output: Capacity within the range 0 to (2^32)-1");
    UT_LOG("Actual Output: capacity = %lu", capacity);
    UT_LOG("Return Status: %s", (status == RETURN_OK) ? "RETURN_OK" : "RETURN_ERR");

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_ASSERT_TRUE(capacity >= 0 && capacity <= (UINT32_MAX));

    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetActualCapacity...");
}

/**
 * @brief Tests the mta_hal_BatteryGetTotalCapacity function when passed a NULL pointer
 *
 * This test case is designed to verify the behavior of the mta_hal_BatteryGetTotalCapacity function when a NULL pointer is passed as an argument. The expected behavior is that the function should return RETURN_ERR.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 089 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_BatteryGetActualCapacity with NULL pointer | Val = NULL | RETURN_ERR | Should return RETURN_ERR |
 */
void test_l1_mta_hal_negative1_BatteryGetActualCapacity(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetActualCapacity...");
    ULONG *capacity = NULL;
    UT_LOG("Invoking mta_hal_BatteryGetTotalCapacity with NULL pointer for Val...");
    INT status = mta_hal_BatteryGetActualCapacity(capacity);
    UT_LOG("Expected Output: %d", status);
    UT_LOG("Return Status: %s", (status == RETURN_ERR) ? "RETURN_ERR" : "RETURN_OK");

    UT_ASSERT_EQUAL(status, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetActualCapacity...");
}

/**
* @brief Test to verify the functionality of the mta_hal_BatteryGetRemainingCharge API when a valid memory location is passed as an argument.
*
* This test verifies that the mta_hal_BatteryGetRemainingCharge API returns the expected result and updates the value at the provided memory location.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 090 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetRemainingCharge API with a valid memory location for Val | val = 0 |  RETURN_OK  | Should be successful |
*/
void test_l1_mta_hal_positive1_BatteryGetRemainingCharge(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetRemainingCharge...");

    ULONG val = 0;
    UT_LOG("Invoking mta_hal_BatteryGetRemainingCharge with valid memory location for Val = %d", val);
    INT result = mta_hal_BatteryGetRemainingCharge(&val);
    UT_LOG("Returned Value: %d, Val: %lu", result, val);
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetRemainingCharge...");
}

/**
* @brief Test for negative scenario of BatteryGetRemainingCharge function.
*
* This test case is used to verify the behavior of BatteryGetRemainingCharge function when a NULL pointer is passed as an argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 091 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Verify behavior of mta_hal_BatteryGetRemainingCharge API when a NULL pointer is passed | val=NULL | RETURN_ERR | Should return error |
*/
void test_l1_mta_hal_negative1_BatteryGetRemainingCharge(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetRemainingCharge...");
    ULONG* val = NULL;
    UT_LOG("Invoking mta_hal_BatteryGetRemainingCharge with NULL pointer for Val");
    INT result = mta_hal_BatteryGetRemainingCharge(val);
    UT_LOG("Returned Value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetRemainingCharge...");
}

/**
* @brief Test the functionality of the mta_hal_BatteryGetRemainingTime function
*
*  This test case is used to verify the behavior of mta_hal_BatteryGetRemainingTime function with valid value as argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 092 @n 
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetRemainingTime function  with valid value | Val=0 | RETURN_OK | Result should be return with success |
*/
void test_l1_mta_hal_positive1_BatteryGetRemainingTime(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetRemainingTime...");

    ULONG val = 0;
    UT_LOG("Invoking mta_hal_BatteryGetRemainingTime with input parameters (Val=%p)", &val);
    INT ret = mta_hal_BatteryGetRemainingTime(&val);
    UT_LOG("Returned value: %d, Val: %lu", ret, val);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetRemainingTime...");
}

/**
* @brief Test for verifying the behavior of mta_hal_BatteryGetRemainingTime function when NULL pointer is passed as the argument
*
* This test is aimed at verifying the functionality of mta_hal_BatteryGetRemainingTime function when a NULL pointer is passed as the argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 093 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetRemainingTime with NULL pointer | val = NULL | RETURN_ERR | The function should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_BatteryGetRemainingTime(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetRemainingTime...");

    ULONG* val = NULL;
    UT_LOG("Invoking mta_hal_BatteryGetRemainingTime with input parameters (Val=%p)", val);
    INT ret = mta_hal_BatteryGetRemainingTime(val);
    UT_LOG("Returned value: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetRemainingTime...");
}

/**
* @brief Test function to validate the mta_hal_BatteryGetNumberofCycles API
*
* This test case validates the functionality of the mta_hal_BatteryGetNumberofCycles API. The objective is to verify if the API returns the number of cycles for the battery correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 094 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetNumberofCycles with valid input | val = 0 | RETURN_OK | Should be successful |
*/

void test_l1_mta_hal_positive1_BatteryGetNumberofCycles(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetNumberofCycles...");

    // Prepare the test data
    ULONG val = 0;

    // Invoke the API
    UT_LOG("Invoking the mta_hal_BatteryGetNumberofCycles ");
    INT result = mta_hal_BatteryGetNumberofCycles(&val);
    UT_LOG("result : %d", result);

    // Check the return value and assert
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_ASSERT_TRUE(val >= 0 && val <= (1000)); 

    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetNumberofCycles...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_BatteryGetNumberofCycles when passed a null pointer.
 *
 * This test case checks if the mta_hal_BatteryGetNumberofCycles function returns the expected error code when a null pointer is passed as the parameter.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 095 @n
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
 * | 01 | Invoking the mta_hal_BatteryGetNumberofCycles when a null pointer is passed. | val = NULL | RETURN_ERR | Should be unsuccessful |
 */

void test_l1_mta_hal_negative1_BatteryGetNumberofCycles(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetNumberofCycles...");

    // Prepare the test data
    ULONG* val = NULL;

    // Invoke the API
    UT_LOG("Invoking the mta_hal_BatteryGetNumberofCycles ");
    INT result = mta_hal_BatteryGetNumberofCycles(val);
    UT_LOG("result : %d", result);
    
    // Check the return value and assert
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetNumberofCycles...");
}

/**
 * @brief This function tests the functionality of the mta_hal_BatteryGetPowerStatus API.
 *
 * This test case verifies the behavior of the mta_hal_BatteryGetPowerStatus API by calling it with valid memory locations for Val and len. The return value, as well as the values of Val and len, are checked to ensure the correct operation of the API.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 096 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 *  | Variation / Step | Description  | Test Data   | Expected Result   | Notes  |
 *  | :----: | :---------: | :----------: |:--------------: | :-----: |
 *  |  01  | Invoking the mta_hal_BatteryGetPowerStatus with valid memory locations for Val | Val = valid memory , len = valid memory  |  RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_BatteryGetPowerStatus(void) {
    CHAR Val[8] = {"\0"};
    ULONG len =0;
    INT ret =0;

    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetPowerStatus...");
    // Invoke the API with valid memory locations for Val and len
    UT_LOG("Invoking the mta_hal_BatteryGetPowerStatus ");
    ret = mta_hal_BatteryGetPowerStatus(Val, &len);
    UT_LOG("Result : %d", ret);
    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetPowerStatus...");
}

/**
 * @brief This function tests the functionality of the mta_hal_BatteryGetPowerStatus API
 * 
 * This test case verifies the behavior of the mta_hal_BatteryGetPowerStatus when we pass NULL as arguments.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 097 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 * 
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoke the mta_hal_BatteryGetPowerStatus API with NULL pointers for Val and len | Val = NULL, len = NULL | RETURN_ERR | Should be unsuccessful |
*/
void test_l1_mta_hal_negative1_BatteryGetPowerStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetPowerStatus...");
    INT ret =0;
    CHAR *Val = NULL;
    ULONG *len = NULL;
    // Invoke the API with NULL pointers for Val and len
    UT_LOG("Invoking the mta_hal_BatteryGetPowerStatus Val = NULL Len = NULL");

    ret = mta_hal_BatteryGetPowerStatus(Val, len);
    UT_LOG("Result : %d ",ret );
    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetPowerStatus...");
}

/**
* @brief This test verifies the behavior of the mta_hal_BatteryGetCondition function when the AC power status is reported as "Good".
*
* This test case checks the functionality of the mta_hal_BatteryGetCondition function by invoking it and verifying the output values and return status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 98 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
*  | Variation / Step | Description | Test Data | Expected Result | Notes |
*  | :----: | :---------: | :----------: |:--------------: | :-----: |
*  | 01 | Invoke the mta_hal_BatteryGetCondition API with valid memory locations | Val =Valid buffer, len = valid buffer | RETURN_OK | The function should return successfully 
*/
void test_l1_mta_hal_positive1_BatteryGetCondition(void) {
    // Logging entering test function
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetCondition...");

    CHAR Val[5] = {"\0"};
    ULONG len = 0;
    INT result = 0;

    // Invoke the API with valid memory locations
    UT_LOG("Invoking mta_hal_BatteryGetCondition with Val = %s, len = %lu", Val, len);
    result = mta_hal_BatteryGetCondition(Val, &len);
    UT_LOG("Result : %d Val : %s len : %lu", result, Val, len);
    // Log the test description, output values, and the return status

    // Assertion to check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Assertion to check the value of Val
    //UT_ASSERT_STRING_EQUAL(Val, "Good");
    if(!strcmp(Val, "Good") || !strcmp(Val, "Bad"))
    {
	UT_LOG("Status: %s ", Val);
	UT_PASS("The Battery COndtion is Good || Bad ");
    }
    else
    {
	UT_LOG("Status: %s ", Val);
	UT_PASS("The Battery Condtion is Invalid State");
    } 

    // Assertion to check the value of len
    UT_ASSERT_EQUAL(len, 4);

    // Logging exiting test function
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetCondition...");
}

/**
* @brief This test case checks the functionality of the mta_hal_BatteryGetCondition API when invoked with NULL pointers.
*
* The objective of this test is to verify if the API can handle NULL pointers correctly and return the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 99 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data   | Expected Result    | Notes  |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01   | Invoking mta_hal_BatteryGetCondition with NULL values  | Val = {"\0"}, *len = NULL   | RETURN_ERR | Should be unsuccessful |
*/

void test_l1_mta_hal_negative1_BatteryGetCondition(void) {
    CHAR Val[5] = {"\0"};
    ULONG *len = NULL;
    // Logging entering test function
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetCondition...");

    // Invoke the API with NULL pointers
    UT_LOG("Invoking mta_hal_BatteryGetCondition with Val = NULL, len = NULL. Return status:");
    INT result = mta_hal_BatteryGetCondition(Val, len);
    UT_LOG("Result : %d", result);

    // Assertion to check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    // Logging exiting test function
    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetCondition...");
}

/**
* @brief This test case is used to verify the mta_hal_BatteryGetStatus() function when retrieving the battery status is in good condition.
*
* The objective of this test case is to ensure that the mta_hal_BatteryGetStatus() function returns the correct battery status when the battery is in good condition.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 100 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetStatus with valid memory | Val = Valid Memory, len = Valid Memory | Result: RETURN_OK | Should pass |
*/
void test_l1_mta_hal_positive1_BatteryGetStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetStatus...");

    CHAR Val[8] ={"\0"};
    ULONG len = 0;
    UT_LOG("Invoking mta_hal_BatteryGetStatus with valid memory locations for Val and len...");
    INT result = mta_hal_BatteryGetStatus(Val, &len);
    UT_LOG("Result : %d", result );

    UT_LOG("Value of Val is %s", Val);
    UT_LOG("Value of len is %lu", len);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    if(!strcmp(Val, "Missing") || !strcmp(Val, "Idle") || !strcmp(Val, "Charging") || !strcmp(Val, "Discharging") || !strcmp(Val, "Unknown"))
    {
	UT_LOG("Batery status : %s ", Val); 
    }
    else
    {
	UT_LOG("Battery Status is different : %s", Val);
    }
    
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetStatus...");
}

/**
* @brief Test to validate the behavior of the mta_hal_BatteryGetStatus function when passed NULL pointers for Val and len.
*
* This test case is intended to verify the behavior of the mta_hal_BatteryGetStatus function when it is invoked with NULL pointers for Val and len. It is expected that the function returns an error code to indicate the failure.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 101 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetStatus with NULL pointers | Val = NULL, len = NULL | RETURN_ERR | Should return an error code |
*/
void test_l1_mta_hal_negative1_BatteryGetStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetStatus...");

    CHAR* Val = NULL;
    ULONG* len = NULL;
    UT_LOG("Invoking mta_hal_BatteryGetStatus with NULL pointers for Val and len...");
    INT result = mta_hal_BatteryGetStatus(Val, len);
    UT_LOG("Result : %d", result );
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetStatus...");
}

/**
* @brief Test case for the mta_hal_BatteryGetLife function from L1 Module
*
* This test case is used to verify the functionality of the mta_hal_BatteryGetLife function from the L1 module. It checks if the function returns the correct values for Val and len variables.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 102 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke mta_hal_BatteryGetLife with valid memory locations for Val and len | Val = {"\0"} , len = 0 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_BatteryGetLife(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetLife...");
    
    /* Provide valid memory locations for Val and len */
    CHAR Val[20] = {"\0"};
    ULONG len = 0;
    
    /* Invoke the API with valid memory locations for Val and len */
    UT_LOG("Invoking mta_hal_BatteryGetLife with valid memory locations for Val and len...");
    INT result = mta_hal_BatteryGetLife(Val, &len);
    
    /* Check the return value */
    UT_LOG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);
    
    /* Check the value of Val */
    UT_LOG("Value of Val: %s", Val);
     
    /* Check the value of len */
    UT_LOG("Value of len: %lu", len);
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetLife...");
}

/**
 * @brief Test the function mta_hal_BatteryGetLife for negative scenario
 * 
 * This test case verifies that the function mta_hal_BatteryGetLife returns the expected error value when NULL pointers are provided for Val and len.
 * 
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 103 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description  | Test Data  | Expected Result   | Notes  |
 * | :----: | :---------: | :----------: |:--------------: | :-----: | 
 * | 01 | Invoking the  mta_hal_BatteryGetLife with NULL pointers Val and len  | Val = NULL, len = NULL  | RETURN_ERR | Should be unsuccessful |
 *
 */
void test_l1_mta_hal_negative1_BatteryGetLife(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetLife...");
    CHAR* Val = NULL;
    ULONG *len = NULL;
    UT_LOG("Invoking the  mta_hal_BatteryGetLife with val %p len : %p",Val,len);
    /* Provide NULL pointers for Val and len */
    INT result = mta_hal_BatteryGetLife(Val, len);

    /* Check the return value */
    UT_LOG("Return value: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetLife...");
}

/**
 * @brief Test case to verify the functionality of the mta_hal_BatteryGetInfo() API.
 *
 * This test case checks if the mta_hal_BatteryGetInfo() API correctly retrieves the battery information and assigns it to the provided PMTAMGMT_MTA_BATTERY_INFO structure.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 104 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking the  mta_hal_BatteryGetInfo with valid pointer | pInfo= valid pointer | RETURN_OK | Should successfully retrieve battery information |
 */
void test_l1_mta_hal_positive1_BatteryGetInfo(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetInfo...");

    // Prepare test data
    PMTAMGMT_MTA_BATTERY_INFO pInfo = (PMTAMGMT_MTA_BATTERY_INFO) malloc(sizeof(MTAMGMT_MTA_BATTERY_INFO));
    if(pInfo != NULL)
    {
        // Call the API
        UT_LOG("Invoking the  mta_hal_BatteryGetInfo with pInfo");
        INT status = mta_hal_BatteryGetInfo(pInfo);
        UT_LOG("Result : %d ", status);
        // Check the return status
        UT_ASSERT_EQUAL(status, RETURN_OK);
        // Clean up
        free(pInfo);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetInfo...");
}

/**
* @brief This test case verifies the behavior of the mta_hal_BatteryGetInfo function when a null pointer is passed as the parameter.
*
* The purpose of this test is to ensure that the mta_hal_BatteryGetInfo function returns RETURN_ERR when a null pointer is passed as the parameter.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 105 @n 
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_BatteryGetInfo API with NULL | pInfo = NULL | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_BatteryGetInfo(void) {
    UT_LOG("Entering test_l1_mta_hal_negative3_BatteryGetInfo...");

    // Prepare test data
    PMTAMGMT_MTA_BATTERY_INFO pInfo = NULL;
    // Call the API
    UT_LOG("Invoking the mta_hal_BatteryGetInfo with NULL");
    INT status = mta_hal_BatteryGetInfo(pInfo);
    UT_LOG("Result Status : %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative3_BatteryGetInfo...");
}

/** 
 * @brief This test case is used to check the retrieval of power saving mode status when enabled.
 *
 * The objective of this test is to verify the correctness of the mta_hal_BatteryGetPowerSavingModeStatus function when power saving mode is enabled.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 106 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking the mta_hal_BatteryGetPowerSavingModeStatus with valid buffer | pValue = Valid Value | Success | Should be successful |
 *
 */
void test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus...");

    ULONG value = 0;
    UT_LOG("Invoking mta_hal_BatteryGetPowerSavingModeStatus with pValue=%p", &value);
    INT result = mta_hal_BatteryGetPowerSavingModeStatus(&value);
    UT_LOG("Result : %d ", result);
    UT_LOG("Value : %lu", value);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus...");
}

/**
* @brief This test case is used to verify the behavior of the mta_hal_BatteryGetPowerSavingModeStatus function when a null pointer is passed as the pValue argument.
*
* The objective of this test is to check if the function properly handles the null pointer and returns the correct error code, RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 107 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_BatteryGetPowerSavingModeStatus with NULL | pValue=NULL | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus...");
    ULONG *pValue = NULL;
    UT_LOG("Invoking test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus with pValue=NULL");
    INT result = mta_hal_BatteryGetPowerSavingModeStatus(pValue);
    UT_LOG("Result : %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus...");
}

/**
 * @brief This test verifies the functionality of the mta_hal_Get_MTAResetCount function.
 *
 * The purpose of this test is to ensure that the mta_hal_Get_MTAResetCount function returns the correct reset count value.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 108 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_Get_MTAResetCount with valid memory location for resetcnt | resetcnt = 0 | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_Get_MTAResetCount(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_Get_MTAResetCount...");

    ULONG resetcnt = 0;
    UT_LOG("Invoking mta_hal_Get_MTAResetCount with valid memory location for resetcnt. 0");
    INT status = mta_hal_Get_MTAResetCount(&resetcnt);
    UT_LOG("Output value resetcnt: %lu", resetcnt);
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_Get_MTAResetCount...");
}

/**
* @brief This test case verifies the behavior of mta_hal_Get_MTAResetCount function when it is called with a NULL pointer for resetcnt.
*
* The purpose of this test is to ensure that the function correctly handles the case when a NULL pointer is passed as an argument to the function.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 109 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_Get_MTAResetCount with NULL pointer for resetcnt | resetcnt = NULL | status = RETURN_ERR | The function should return RETURN_ERR when called with a NULL pointer. |
*/
void test_l1_mta_hal_negative1_Get_MTAResetCount(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_Get_MTAResetCount...");
    UT_LOG("Invoking mta_hal_Get_MTAResetCount with NULL pointer for resetcnt...");
    INT status = mta_hal_Get_MTAResetCount(NULL);
    UT_LOG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_Get_MTAResetCount...");
}

/**
 * @brief Test case to verify the correctness of the function mta_hal_Get_LineResetCount
 *
 * This test case checks the functionality of the mta_hal_Get_LineResetCount API by verifying the return status and the reset count value.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 110 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Call mta_hal_Get_LineResetCount API  with Valid Memory | resetcnt = 0 | RETURN_OK | Reset count is within range |
 */
void test_l1_mta_hal_positive1_Get_LineResetCount(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_Get_LineResetCount...");

    // Initialize variables
    ULONG resetcnt = 0;
    // Call the API function
    UT_LOG("Invoking the  mta_hal_Get_LineResetCount with resetcnt 0");
    INT status = mta_hal_Get_LineResetCount(&resetcnt);
    UT_LOG("Result : %d resetCnt : %lu ", status, resetcnt);
    // Check the return value
    UT_ASSERT_EQUAL(status, RETURN_OK);

    // Check the reset count value
    UT_ASSERT_TRUE(resetcnt >= 0 && resetcnt <= UINT32_MAX);

    // Log the test result
    UT_LOG("Exiting test_l1_mta_hal_positive1_Get_LineResetCount...");
}

/**
 * @brief Test to verify the functionality of the mta_hal_Get_LineResetCount API when called with a null pointer.
 * 
 * This test case is to verify the behavior of the mta_hal_Get_LineResetCount API when called with a null pointer as an argument. The test aims to ensure that the correct error code is returned by the API in this scenario.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 111 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Call mta_hal_Get_LineResetCount with null pointer | resetcnt = NULL | RETURN_ERR | Should return an error |
 */ 
void test_l1_mta_hal_negative1_Get_LineResetCount(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_Get_LineResetCount...");

    // Call the API function with null pointer
    ULONG *resetcnt = NULL;
    UT_LOG("Invoking the  mta_hal_Get_LineResetCount with resetcnt 0");
    INT status = mta_hal_Get_LineResetCount(resetcnt);
    UT_LOG("Result : %d ", status);

    // Check the return value
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    // Log the test result
    UT_LOG("Exiting test_l1_mta_hal_negative1_Get_LineResetCount...");
}

/**
* @brief Test case to verify the functionality of the mta_hal_ClearCalls function when called with InstanceNumber set to 0.
*
* This test verifies if the mta_hal_ClearCalls function correctly clears calls for the given instance number.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 112 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Set InstanceNumber to 0 and call mta_hal_ClearCalls function | InstanceNumber = 0 | Return value should be RETURN_OK | Should be successful |
*/ 
void test_l1_mta_hal_positive1_ClearCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_ClearCalls...");

    // Set InstanceNumber to 0
    UINT InstanceNumber = 0;

    // Call mta_hal_ClearCalls function
    UT_LOG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    INT result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG("result :%d", result);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive1_ClearCalls...");
}

/**
 * @brief Test to verify the functionality of mta_hal_ClearCalls function when InstanceNumber is set to (2^32)-1.
 *
 * This test verifies that mta_hal_ClearCalls function completes successfully when InstanceNumber is set to the maximum value of unsigned integer.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 113 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_ClearCalls with Maximum InstanceNumber | InstanceNumber = (4294967296-1) | RETURN_OK | should be successful |
 *
 */
void test_l1_mta_hal_positive2_ClearCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_ClearCalls...");

    // Set InstanceNumber to (2^32)-1
    UINT InstanceNumber = (4294967296-1);

    // Call mta_hal_ClearCalls function
    UT_LOG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    INT result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG("result :%d", result);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive2_ClearCalls...");
}

/**
* @brief Test the functionality of the mta_hal_ClearCalls function.
*
* This test function verifies the functionality of the mta_hal_ClearCalls function by calling it with a specific InstanceNumber and verifying the return value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 114 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_ClearCalls function with a specific InstanceNumber | InstanceNumber = 1000 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive3_ClearCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_positive3_ClearCalls...");

    // Set InstanceNumber to an intermediate value
    UINT InstanceNumber = 1000;

    // Call mta_hal_ClearCalls function
    UT_LOG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    INT result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG("result :%d", result);

    // Verify the return value is RETURN_OK
    UT_ASSERT_EQUAL(result, RETURN_OK);
 
    UT_LOG("Exiting test_l1_mta_hal_positive3_ClearCalls...");
}

/**
* @brief This test function is used to verify the behavior of the mta_hal_ClearCalls function when an out-of-range value is passed as the InstanceNumber parameter.
*
* This test aims to check if the mta_hal_ClearCalls function returns RETURN_ERR when an out-of-range value is provided as the InstanceNumber parameter. It also validates the logging behavior of the function.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 115 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Set InstanceNumber to an out-of-range value and call mta_hal_ClearCalls API | InstanceNumber = 999999999 | RETURN_ERR | Should be unsuccessful |
*/
void test_l1_mta_hal_negative1_ClearCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_ClearCalls...");

    // Set InstanceNumber to an out-of-range value
    UINT InstanceNumber = 999999999;

    // Call mta_hal_ClearCalls function
    UT_LOG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    INT result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG("result :%d", result);

    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_ClearCalls...");
}

/**
* @brief This test case verifies the behavior of the mta_hal_ClearCalls function when the InstanceNumber is an unallocated value.
*
* The test is performed by setting the InstanceNumber to an unallocated value and then calling the mta_hal_ClearCalls function. The return value is then verified to be RETURN_ERR.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 116 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:**
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_ClearCalls with InstanceNumber as 123456 | InstanceNumber = 123456 | RETURN_ERR  | Should return an error status |
*/
void test_l1_mta_hal_negative2_ClearCalls(void) {
    UT_LOG("Entering test_l1_mta_hal_negative2_ClearCalls...");

    // Set InstanceNumber to an unallocated value
    UINT InstanceNumber = 123456;

    // Call mta_hal_ClearCalls function
    UT_LOG("Invoking mta_hal_ClearCalls with InstanceNumber = %u ", InstanceNumber);
    INT result = mta_hal_ClearCalls(InstanceNumber);
    UT_LOG("result :%d", result);

    // Verify the return value is RETURN_ERR
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative2_ClearCalls...");
}

/**
* @brief Test the functionality of the mta_hal_getDhcpStatus API for IPv4
*
* This test case verifies the correct retrieval of DHCP status for IPv4 connection using the mta_hal_getDhcpStatus API.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 117 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_getDhcpStatus with Valid data | ipv4Status, ipv6Status = uninitialized |  RETURN_OK | IPv4 status should be within the range MTA_INIT - MTA_REJECTED |
*/

void test_l1_mta_hal_positive1_getDhcpStatus(void)
{
    UT_LOG("Entering test_l1_mta_hal_positive1_getDhcpStatus...");

    MTAMGMT_MTA_STATUS ipv4Status;
    MTAMGMT_MTA_STATUS ipv6Status;
    UT_LOG("Invoking the  mta_hal_getDhcpStatus ");
    INT returnValue = mta_hal_getDhcpStatus(&ipv4Status, &ipv6Status);
    UT_LOG("Return value : %d", returnValue);
    // Verify return value
    UT_ASSERT_EQUAL(returnValue, RETURN_OK);
    UT_ASSERT_TRUE(ipv4Status>= MTA_INIT && ipv4Status <= MTA_REJECTED);
    UT_LOG("Exiting test_l1_mta_hal_positive1_getDhcpStatus...");
}

/**
* @brief Test case to verify the negative scenario of the mta_hal_getDhcpStatus function for both IPv4 and IPv6.
*
* This test case checks if the mta_hal_getDhcpStatus function returns the expected error code when trying to get the DHCP status for both IPv4 and IPv6.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 118 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the  mta_hal_getDhcpStatus with NULL | ipv4Status = NULL, ipv6Status = NULL | RETURN_ERR | Should return an error |
*/
void test_l1_mta_hal_negative1_getDhcpStatus(void)
{
    UT_LOG("Entering test_l1_mta_hal_negative1_getDhcpStatus...");

    MTAMGMT_MTA_STATUS *ipv4Status = NULL;
    MTAMGMT_MTA_STATUS *ipv6Status = NULL;
    UT_LOG("Invoking the  mta_hal_getDhcpStatus ");
    INT returnValue = mta_hal_getDhcpStatus(ipv4Status, ipv6Status);
    UT_LOG("Return value : %d", returnValue);
    // Verify return value
    UT_ASSERT_EQUAL(returnValue, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_getDhcpStatus...");
}

/**
* @brief Test case to verify the functionality of mta_hal_getConfigFileStatus API.
*
* This test case is used to verify the functionality of mta_hal_getConfigFileStatus API, which is responsible for getting the status of the config file.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 119 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_getConfigFileStatus with Valid data | output_status = Valid Memory | RETURN_OK | should be successful |
*/

void test_l1_mta_hal_positive1_getConfigFileStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_getConfigFileStatus...");

    MTAMGMT_MTA_STATUS output_status;
    UT_LOG("Invoking mta_hal_getConfigFileStatus with valid memory location for poutput_status...");
    INT ret = mta_hal_getConfigFileStatus(&output_status);
    UT_LOG("Return value: %d", ret);
    UT_LOG("Output status: %d", output_status);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_TRUE(output_status >= MTA_INIT && output_status <= MTA_REJECTED);

    UT_LOG("Exiting test_l1_mta_hal_positive1_getConfigFileStatus...");
}

/**
* @brief Test case to check the behavior of the function mta_hal_getConfigFileStatus when an invalid memory location for poutput_status is passed as an argument.
*
* The objective of this test is to verify that the function handles the invalid memory location correctly and returns the expected error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 120 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data  | Expected Result  | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_getConfigFileStatus with NULL | poutput_status = NULL  | Return_ERR  | Should be unsuccessful |
*
*/
void test_l1_mta_hal_negative1_getConfigFileStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_getConfigFileStatus...");
    UT_LOG("Invoking mta_hal_getConfigFileStatus with invalid memory location for poutput_status...");
    INT ret = mta_hal_getConfigFileStatus(NULL);
    UT_LOG("Return value: %d", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_getConfigFileStatus...");
}

/**
* @brief Test the functionality of mta_hal_getLineRegisterStatus when given a valid memory location and expected array size.
*
* This test case verifies that the mta_hal_getLineRegisterStatus function returns the expected result and that the output_status_array values are within the expected range.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 121 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_getLineRegisterStatus with valid memory location and expected array size | output_status_array = valid memory location, array_size = 5 | RETURN_OK | All values in output_status_array should be within the range MTA_INIT to MTA_REJECTED |
*/
void test_l1_mta_hal_positive1_getLineRegisterStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_getLineRegisterStatus...");

    // Setup
    MTAMGMT_MTA_STATUS output_status_array[5]; // Assuming array size is 5
    int array_size = 5;

    // Test
    UT_LOG("Invoking mta_hal_getLineRegisterStatus with output_status_array (valid) and array_size %d", array_size);
    INT result = mta_hal_getLineRegisterStatus(output_status_array, array_size);
    UT_LOG("Result : %d ", result);
    // Verification
    UT_ASSERT_EQUAL(result, RETURN_OK);
    // Additional verification for output_status_array values
    for (int i = 0; i < array_size; i++) {
        UT_ASSERT_TRUE(output_status_array[i] >= MTA_INIT && output_status_array[i] <= MTA_REJECTED);
    }

    UT_LOG("Exiting test_l1_mta_hal_positive1_getLineRegisterStatus...");
}

/**
 * @brief Test case to verify the behavior when the array size is zero.
 *
 * This test case verifies the behavior of the function 'mta_hal_getLineRegisterStatus' when the array size is zero. The objective of this test is to ensure that the function handles this scenario correctly and returns the expected result.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 122 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * |01| Invoking the mta_hal_getLineRegisterStatus with Valid date | output_status_array = 5, array_size = 0 | RETURN_OK | The function should return RETURN_OK without writing any values to the output_status_array.
 */
void test_l1_mta_hal_positive2_getLineRegisterStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_getLineRegisterStatus...");

    // Setup
    MTAMGMT_MTA_STATUS output_status_array[5]; // Assuming array size is 5
    int array_size = 0;

    UT_LOG("Invoking the mta_hal_getLineRegisterStatus with array size 0");
    INT result = mta_hal_getLineRegisterStatus(output_status_array, array_size);
    UT_LOG("Result: %d ", result);
    // Verification
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_mta_hal_positive2_getLineRegisterStatus...");
}

/**
 * @brief This test case is used to verify the behavior of the mta_hal_getLineRegisterStatus function when an invalid memory location is provided for the output status array.
 *
 * This test case is used to verify the behavior of the mta_hal_getLineRegisterStatus function when an invalid memory location is provided for the output status array. The objective of this test is to ensure that the function handles this scenario correctly and returns the expected error code.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 123 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * |  01    | Invoke the mta_hal_getLineRegisterStatus with Invalid values | output_status_array = NULL, array_size = 5 | RETURN_ERR | Should be unsuccessful |
 */
void test_l1_mta_hal_negative1_getLineRegisterStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_getLineRegisterStatus...");

    // Setup
    MTAMGMT_MTA_STATUS *output_status_array = NULL; // Invalid memory location
    int array_size = 5;

    // Test
    UT_LOG("Invoking mta_hal_getLineRegisterStatus with output_status_array (NULL) and array_size %d", array_size);
    INT result = mta_hal_getLineRegisterStatus(output_status_array, array_size);
    UT_LOG("Result : %d", result);

    // Verification
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_getLineRegisterStatus...");
}

/**
* @brief Unit test to verify the behavior of mta_hal_getLineRegisterStatus when passed a negative array size.
*
* This test case aims to verify the behavior of the mta_hal_getLineRegisterStatus API when it is called with a negative array size. The objective of this test is to ensure that the API handles the negative array size gracefully and returns an error.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 124 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the mta_hal_getLineRegisterStatus with negative Array size | output_status_array = valid, array_size = -1 | Error should be returned | -
*/
void test_l1_mta_hal_negative2_getLineRegisterStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative2_getLineRegisterStatus...");

    // Setup
    MTAMGMT_MTA_STATUS output_status_array[5]; // Assuming array size is 5
    int array_size = -1; // Negative array size

    // Test
    UT_LOG("Invoking mta_hal_getLineRegisterStatus with output_status_array (valid) and array_size %d", array_size);
    INT result = mta_hal_getLineRegisterStatus(output_status_array, array_size);
    UT_LOG("Result : %d", result);

    // Verification
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative2_getLineRegisterStatus...");
}

/**
* @brief Test case to verify the behavior when the size of the array is greater than the actual allocation size.
*
* This test case checks if the function handles the scenario where the size of the array provided is greater than the actual allocation size of the array.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 125 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description   | Test Data  | Expected Result  | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* |   01   | Verify mta_hal_getLineRegisterStatus API behavior when array size is greater than actual allocation | output_status_array = valid, array_size = 10 | RETURN_ERR | Should be failed.   |
*/

void test_l1_mta_hal_negative3_getLineRegisterStatus(void) {
    UT_LOG("Entering test_l1_mta_hal_negative3_getLineRegisterStatus...");

    // Setup
    MTAMGMT_MTA_STATUS output_status_array[5]; // Assuming array size is 5
    int array_size = 10; // Greater than actual allocation

    // Test
    UT_LOG("Invoking mta_hal_getLineRegisterStatus with output_status_array (valid) and array_size %d", array_size);
    INT result = mta_hal_getLineRegisterStatus(output_status_array, array_size);
    UT_LOG("Result : %d", result);
    // Verification

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative3_getLineRegisterStatus...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_devResetNow() API when the reset value is set to TRUE.
 *
 * This test case checks if the mta_hal_devResetNow() API returns the expected status when the reset value is set to TRUE.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 126 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 *  | Variation / Step | Description | Test Data | Expected Result | Notes |
 *  | :----: | :---------: | :----------: |:--------------: | :-----: |
 *  | 01 | Invoking mta_hal_devResetNow with bResetValue = TRUE | bResetValue = TRUE | Return status: RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive1_devResetNow(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_devResetNow...");

    BOOLEAN bResetValue = TRUE;
    UT_LOG("Invoking mta_hal_devResetNow with bResetValue = TRUE...");
    INT status = mta_hal_devResetNow(bResetValue);
    UT_LOG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive1_devResetNow...");
}

/**
 * @brief Test to verify the behavior of the mta_hal_devResetNow function when the reset value is set to FALSE.
 *
 * This test verifies whether the mta_hal_devResetNow function returns the expected status when the reset value is set to FALSE.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 127 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Invoking mta_hal_devResetNow with bResetValue = FALSE | bResetValue = FALSE | RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive2_devResetNow(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_devResetNow...");

    BOOLEAN bResetValue = FALSE;
    UT_LOG("Invoking mta_hal_devResetNow with bResetValue = FALSE...");
    INT status = mta_hal_devResetNow(bResetValue);
   
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_mta_hal_positive2_devResetNow...");
}

/**
 * @brief Test for checking the behavior of the mta_hal_devResetNow function when an invalid boolean value is passed.
 * 
 * This test verifies the behavior of the mta_hal_devResetNow function when an invalid boolean value is passed as an argument. The objective of this test is to ensure that the function returns the expected error status when an invalid boolean value is provided.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 128 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Test with invalid boolean value | bResetValue = 2 | return status = RETURN_ERR | Should return an error status |
 */
void test_l1_mta_hal_negative1_devResetNow(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_devResetNow...");

    BOOLEAN bResetValue = 2;
    UT_LOG("Invoking mta_hal_devResetNow with invalid bResetValue = 2...");
    INT status = mta_hal_devResetNow(bResetValue);
   
    UT_LOG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_mta_hal_negative1_devResetNow...");
}

/**
 * @brief This test case is used to verify the behavior of the mta_hal_devResetNow function when it is called multiple times consecutively.
 *
 * The purpose of this test is to check how the mta_hal_devResetNow function responds to multiple consecutive reset calls. It tests whether the function returns the expected status code and if it can handle this scenario correctly.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 129 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description  | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01  | Invoking mta_hal_devResetNow with bResetValue = TRUE twice  | bResetValue = TRUE  | RETURN_ERR | Should be Unsuccessful  |
 */
void test_l1_mta_hal_negative2_devResetNow(void) {
    UT_LOG("Entering test_l1_mta_hal_negative2_devResetNow...");

    BOOLEAN bResetValue = TRUE;
    UT_LOG("Invoking mta_hal_devResetNow with bResetValue = TRUE");
    INT status1 = mta_hal_devResetNow(bResetValue);
    UT_LOG("Return status - First reset: %d", status1);
    UT_LOG("Invoking mta_hal_devResetNow with bResetValue = TRUE again...");
    INT status2 = mta_hal_devResetNow(bResetValue);
    UT_LOG("Return status - Second reset: %d", status2);

    // Expected return value depends on the system behavior for multiple consecutive resets.
    UT_ASSERT_TRUE((status1 == RETURN_OK) || (status1 == RETURN_ERR));
    UT_ASSERT_TRUE((status2 == RETURN_OK) || (status2 == RETURN_ERR));

    UT_LOG("Exiting test_l1_mta_hal_negative2_devResetNow...");
}

/**
* @brief Test case to check the behavior of mta_hal_devResetNow function when the reset value is toggled rapidly.
*
* This test case is designed to verify the functionality of the mta_hal_devResetNow function when the reset value is toggled rapidly. It tests if the function can handle multiple invocations within a short period of time.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 130 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | mta_hal_devResetNow Toggle reset value rapidly | bResetValue = TRUE | RETURN_OK or RETURN_ERR | The return value can be either RETURN_OK or RETURN_ERR depending on the system behavior |
*/
void test_l1_mta_hal_negative3_devResetNow(void) {
    UT_LOG("Entering test_l1_mta_hal_negative3_devResetNow...");

    INT numToggles = 100;
    INT i;

    for (i = 0; i < numToggles; i++) {
        BOOLEAN bResetValue = (i % 2 == 0) ? TRUE : FALSE;
        UT_LOG("Invoking the mta_hal_devResetNow ");
        INT status = mta_hal_devResetNow(bResetValue);

        UT_LOG("Invoking mta_hal_devResetNow with bResetValue = %s...", bResetValue ? "TRUE" : "FALSE");
        UT_LOG("Return status: %d", status);

        // Expected return value depends on the system behavior when receiving alternating signals.
        UT_ASSERT_TRUE((status == RETURN_OK) || (status == RETURN_ERR));
    }
     UT_LOG("Existing test_l1_mta_hal_negative3_devResetNow...");
}

/**
* @brief This test function is used to verify the functionality of the mta_hal_getMtaOperationalStatus API.
*
* The purpose of this test is to check if the API mta_hal_getMtaOperationalStatus returns the expected result and if the operationalStatus value is one of the valid enum values.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 131 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Call mta_hal_getMtaOperationalStatus function with Valid memory | operationalStatus = Valid memory | Return value is RETURN_OK | operationalStatus is one of the valid enum values |
*/
void test_l1_mta_hal_positive1_getMtaOperationalStatus(void) {
   UT_LOG("Entering test_l1_mta_hal_positive1_getMtaOperationalStatus...");

   // Allocate memory for operationalStatus
   MTAMGMT_MTA_STATUS operationalStatus;

   // Call the mta_hal_getMtaOperationalStatus function
   UT_LOG("Invoking mta_hal_getMtaOperationalStatus  for operationalStatus: SUCCESS ");
   INT result = mta_hal_getMtaOperationalStatus(&operationalStatus);
   UT_LOG("Result : %d ", result);
   // Verify the return value is RETURN_OK
   UT_ASSERT_EQUAL(result, RETURN_OK);

   // Check if the operationalStatus is one of the valid enum values
   CU_ASSERT(operationalStatus == MTA_INIT || operationalStatus == MTA_START || operationalStatus == MTA_COMPLETE ||
             operationalStatus == MTA_ERROR || operationalStatus == MTA_REJECTED);

   // Log the test description and the return status
   UT_LOG("Invoking mta_hal_getMtaOperationalStatus with valid memory location for operationalStatus: SUCCESS");
   UT_LOG("Exiting test_l1_mta_hal_positive1_getMtaOperationalStatus...");
}

/**
 * @brief Test case to verify the behavior of mta_hal_getMtaOperationalStatus when invoked with a NULL operationalStatus pointer.
 *
 * This test case verifies the behavior of the mta_hal_getMtaOperationalStatus function when called with a NULL operationalStatus pointer. The function is expected to return RETURN_ERR in this case.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 132 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Call the mta_hal_getMtaOperationalStatus API with NULL operationalStatus pointer | operationalStatus = NULL | RETURN_ERR | should be Fail|
 */
void test_l1_mta_hal_negative1_getMtaOperationalStatus(void) {
   UT_LOG("Entering test_l1_mta_hal_negative1_getMtaOperationalStatus...");

   // Set operationalStatus to NULL
   MTAMGMT_MTA_STATUS *operationalStatus = NULL;
   // Call the mta_hal_getMtaOperationalStatus function
   UT_LOG("Invoking mta_hal_getMtaOperationalStatus with NULL pointer for operationalStatus: FAILURE");
   INT result = mta_hal_getMtaOperationalStatus(operationalStatus);
   UT_LOG("Result : %d", result);
   // Verify the return value is RETURN_ERR
   UT_ASSERT_EQUAL(result, RETURN_ERR);

   // Log the test description and the return status
   UT_LOG("Exiting test_l1_mta_hal_negative1_getMtaOperationalStatus...");
}

/**
* @brief Test case to verify the positive scenario of mta_hal_start_provisioning function
*
* This test case verifies the functionality of mta_hal_start_provisioning function when provided with valid input parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 133 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking the mta_hal_start_provisioning with MtaIPMode as MTA_IPV4 | pParameters -> MtaIPMode = MTA_IPV4 | RETURN_OK | Should be successful |
*/
void test_l1_mta_hal_positive1_start_provisioning(void) {
    UT_LOG("Entering test_l1_mta_hal_positive1_start_provisioning...");

    // Test case specific setup
    PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters = (PMTAMGMT_MTA_PROVISIONING_PARAMS) malloc(sizeof(MTAMGMT_PROVISIONING_PARAMS));
    if(pParameters != NULL)
    {
        pParameters->MtaIPMode = MTA_IPV4;
        // Test invocation
        UT_LOG("Invoking the mta_hal_start_provisioning with MTA_IPV4");
        INT result = mta_hal_start_provisioning(pParameters);
        UT_LOG("Result : %d", result);

        // Test verification
        UT_ASSERT_EQUAL(result, RETURN_OK);
        // Test case specific cleanup
        free(pParameters);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive1_start_provisioning...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_start_provisioning API.
 *
 * This test case verifies the behavior of mta_hal_start_provisioning API by checking if it returns the expected result when valid input is provided.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 134 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Verify start provisioning with valid parameters | pParameters->MtaIPMode = MTA_IPV6 | RETURN_OK | Test should pass |
 */
void test_l1_mta_hal_positive2_start_provisioning(void) {
    UT_LOG("Entering test_l1_mta_hal_positive2_start_provisioning...");

    // Test case specific setup
    PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters = (PMTAMGMT_MTA_PROVISIONING_PARAMS) malloc(sizeof(PMTAMGMT_MTA_PROVISIONING_PARAMS));
    if(pParameters != NULL)
    {
        pParameters->MtaIPMode = MTA_IPV6;
        // Set other valid values for pParameters structure members

        // Test invocation
        UT_LOG("Invoking the mta_hal_start_provisioning with MTA_IPV6");
        INT result = mta_hal_start_provisioning(pParameters);
        UT_LOG("Result : %d", result);

        // Test verification
        UT_ASSERT_EQUAL(result, RETURN_OK);
        // Add other assertions if needed

        // Test case specific cleanup
        free(pParameters);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive2_start_provisioning...");
}

/**
 * @brief Test case to verify the functionality of mta_hal_start_provisioning function in positive scenario.
 *
 * This test case checks whether the mta_hal_start_provisioning function is working correctly in the positive scenario.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 135 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: |:--------------: | :-----: |
 * | 01 | Verifying mta_hal_start_provisioning function with Valid parameter | pParameters->MtaIPMode = MTA_DUAL_STACK | The function should return RETURN_OK | Should be successful |
 */
void test_l1_mta_hal_positive3_start_provisioning(void) {
    UT_LOG("Entering test_l1_mta_hal_positive3_start_provisioning...");

    // Test case specific setup
    PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters = (PMTAMGMT_MTA_PROVISIONING_PARAMS) malloc(sizeof(PMTAMGMT_MTA_PROVISIONING_PARAMS));
    if( pParameters != NULL )
    {
        pParameters->MtaIPMode = MTA_DUAL_STACK;
        // Set other valid values for pParameters structure members

        // Test invocation
        UT_LOG("Invoking the mta_hal_start_provisioning with MTA_DUAL_STACK");
        INT result = mta_hal_start_provisioning(pParameters);
        UT_LOG("Result : %d", result);

        // Test verification
        UT_ASSERT_EQUAL(result, RETURN_OK);
        // Add other assertions if needed

        // Test case specific cleanup
        free(pParameters);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_mta_hal_positive3_start_provisioning...");
}

/**
* @brief Test case for negative scenario of mta_hal_start_provisioning function
*
* This test case checks the behavior of mta_hal_start_provisioning function when invoked with NULL input parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 136 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_start_provisioning with NULL input parameters | pParameters = NULL | RETURN_ERR | Should return error |
*/
void test_l1_mta_hal_negative1_start_provisioning(void) {
    UT_LOG("Entering test_l1_mta_hal_negative1_start_provisioning...");

    // Test case specific setup
    PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters = NULL;

    // Test invocation
    UT_LOG("Invoking the mta_hal_start_provisioning with NULL");
    INT result = mta_hal_start_provisioning(pParameters);
    UT_LOG("Result : %d", result);

    // Test verification
    UT_ASSERT_EQUAL(result, RETURN_ERR);
    UT_LOG("Exiting test_l1_mta_hal_negative1_start_provisioning...");
}

/**
* @brief This test case is for testing the boundary conditions of the mta_hal_GetCalls API.
*
* The objective of this test case is to check if the mta_hal_GetCalls API can handle the boundary conditions of the input parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 137 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoking mta_hal_GetCalls with instanceNumber: UINT32_MAX, count: 0, pCfg: NULL | instanceNumber = UINT32_MAX, count = 0, pCfg = NULL | Success (RETURN_OK) | Should be successful |
*/
void test_l1_mta_hal_positive3_GetCalls(void) {
    UT_LOG(" Entering from test_l1_mta_hal_positive3_GetCalls");
    ULONG instanceNumber2 = 4294967295;
    ULONG count2 = 0;
    PMTAMGMT_MTA_CALLS pCfg2 = (PMTAMGMT_MTA_CALLS) malloc (sizeof(MTAMGMT_MTA_CALLS));
    if(pCfg2 != NULL)
    {
        UT_LOG("Invoking mta_hal_GetCalls with instanceNumber1 = MAX count : 0 and pCfg = NULL");
	INT result2 = mta_hal_GetCalls(instanceNumber2, &count2, &pCfg2);
	UT_LOG("mta_hal_GetCalls with instanceNumber: %lu, count: %lu, pCfg: %p", instanceNumber2, count2, pCfg2);
	UT_LOG("Return status: %d", result2);
	UT_ASSERT_EQUAL(result2, RETURN_OK);
	free(pCfg2);
    }
    else
    {
	UT_LOG("Malloc operation failed");
	UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG(" Existing from test_l1_mta_hal_positive3_GetCalls");
}


static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_mta_hal_l1_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 mta_hal]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }
    
    UT_add_test( pSuite, "l1_mta_hal_positive1_InitDB", test_l1_mta_hal_positive1_InitDB);
    UT_add_test( pSuite, "l1_mta_hal_positive2_InitDB", test_l1_mta_hal_positive2_InitDB);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDHCPInfo", test_l1_mta_hal_positive1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDHCPInfo", test_l1_mta_hal_negative1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDHCPV6Info", test_l1_mta_hal_positive1_GetDHCPV6Info);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDHCPV6Info", test_l1_mta_hal_negative1_GetDHCPV6Info);
    UT_add_test( pSuite, "l1_mta_hal_positive1_LineTableGetNumberOfEntries", test_l1_mta_hal_positive1_LineTableGetNumberOfEntries);
    UT_add_test( pSuite, "l1_mta_hal_positive1_LineTableGetEntry", test_l1_mta_hal_positive1_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_positive2_LineTableGetEntry", test_l1_mta_hal_positive2_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_positive3_LineTableGetEntry", test_l1_mta_hal_positive3_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_negative1_LineTableGetEntry", test_l1_mta_hal_negative1_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_negative2_LineTableGetEntry", test_l1_mta_hal_negative2_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_negative3_LineTableGetEntry", test_l1_mta_hal_negative3_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_negative4_LineTableGetEntry", test_l1_mta_hal_negative4_LineTableGetEntry);
    UT_add_test( pSuite, "l1_mta_hal_positive1_TriggerDiagnostics", test_l1_mta_hal_positive1_TriggerDiagnostics);
    UT_add_test( pSuite, "l1_mta_hal_positive2_TriggerDiagnostics", test_l1_mta_hal_positive2_TriggerDiagnostics);
    UT_add_test( pSuite, "l1_mta_hal_positive3_TriggerDiagnostics", test_l1_mta_hal_positive3_TriggerDiagnostics);
    UT_add_test( pSuite, "l1_mta_hal_negative1_TriggerDiagnostics", test_l1_mta_hal_negative1_TriggerDiagnostics);
    UT_add_test( pSuite, "l1_mta_hal_negative2_TriggerDiagnostics", test_l1_mta_hal_negative2_TriggerDiagnostics);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetServiceFlow", test_l1_mta_hal_positive1_GetServiceFlow);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetServiceFlow", test_l1_mta_hal_negative1_GetServiceFlow);
    UT_add_test( pSuite, "l1_mta_hal_positive1_DectGetEnable", test_l1_mta_hal_positive1_DectGetEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_DectGetEnable", test_l1_mta_hal_positive2_DectGetEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_DectGetEnable", test_l1_mta_hal_negative1_DectGetEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_DectSetEnable", test_l1_mta_hal_positive1_DectSetEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_DectSetEnable", test_l1_mta_hal_positive2_DectSetEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_DectSetEnable", test_l1_mta_hal_negative1_DectSetEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_DectGetRegistrationMode", test_l1_mta_hal_positive1_DectGetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_positive2_DectGetRegistrationMode", test_l1_mta_hal_positive2_DectGetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_negative1_DectGetRegistrationMode", test_l1_mta_hal_negative1_DectGetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_positive1_DectSetRegistrationMode", test_l1_mta_hal_positive1_DectSetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_positive2_DectSetRegistrationMode", test_l1_mta_hal_positive2_DectSetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_negative1_DectSetRegistrationMode", test_l1_mta_hal_negative1_DectSetRegistrationMode);
    UT_add_test( pSuite, "l1_mta_hal_positive1_DectDeregisterDectHandset", test_l1_mta_hal_positive1_DectDeregisterDectHandset);
    UT_add_test( pSuite, "l1_mta_hal_positive2_DectDeregisterDectHandset", test_l1_mta_hal_positive2_DectDeregisterDectHandset);
    UT_add_test( pSuite, "l1_mta_hal_positive3_DectDeregisterDectHandset", test_l1_mta_hal_positive3_DectDeregisterDectHandset);
    UT_add_test( pSuite, "l1_mta_hal_negative1_DectDeregisterDectHandset", test_l1_mta_hal_negative1_DectDeregisterDectHandset);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDect", test_l1_mta_hal_positive1_GetDect);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDect", test_l1_mta_hal_negative1_GetDect);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDectPIN", test_l1_mta_hal_positive1_GetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDectPIN", test_l1_mta_hal_negative1_GetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_positive1_SetDectPIN", test_l1_mta_hal_positive1_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_positive2_SetDectPIN", test_l1_mta_hal_positive2_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_negative1_SetDectPIN", test_l1_mta_hal_negative1_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_negative2_SetDectPIN", test_l1_mta_hal_negative2_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_negative3_SetDectPIN", test_l1_mta_hal_negative3_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_negative4_SetDectPIN", test_l1_mta_hal_negative4_SetDectPIN);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetHandsets", test_l1_mta_hal_positive1_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_positive2_GetHandsets", test_l1_mta_hal_positive2_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetHandsets", test_l1_mta_hal_negative1_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetHandsets", test_l1_mta_hal_negative2_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative3_GetHandsets", test_l1_mta_hal_negative3_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_negative4_GetHandsets", test_l1_mta_hal_negative4_GetHandsets);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetCalls", test_l1_mta_hal_positive1_GetCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive2_GetCalls", test_l1_mta_hal_positive2_GetCalls);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetCalls", test_l1_mta_hal_negative1_GetCalls);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetCalls", test_l1_mta_hal_negative2_GetCalls);
    UT_add_test( pSuite, "l1_mta_hal_negative3_GetCalls", test_l1_mta_hal_negative3_GetCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetCALLP", test_l1_mta_hal_positive1_GetCALLP);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetCALLP", test_l1_mta_hal_negative1_GetCALLP);
    UT_add_test( pSuite, "l1_mta_hal_negative2_GetCALLP", test_l1_mta_hal_negative2_GetCALLP);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDSXLogs", test_l1_mta_hal_positive1_GetDSXLogs);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDSXLogs", test_l1_mta_hal_negative1_GetDSXLogs);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetDSXLogEnable", test_l1_mta_hal_positive1_GetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_GetDSXLogEnable", test_l1_mta_hal_positive2_GetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetDSXLogEnable", test_l1_mta_hal_negative1_GetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_SetDSXLogEnable", test_l1_mta_hal_positive1_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_SetDSXLogEnable", test_l1_mta_hal_positive2_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_SetDSXLogEnable", test_l1_mta_hal_negative1_SetDSXLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearDSXLog", test_l1_mta_hal_positive1_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearDSXLog", test_l1_mta_hal_positive2_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_ClearDSXLog", test_l1_mta_hal_negative1_ClearDSXLog);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetCallSignallingLogEnable", test_l1_mta_hal_positive1_GetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_GetCallSignallingLogEnable", test_l1_mta_hal_positive2_GetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetCallSignallingLogEnable", test_l1_mta_hal_negative1_GetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_SetCallSignallingLogEnable", test_l1_mta_hal_positive1_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive2_SetCallSignallingLogEnable", test_l1_mta_hal_positive2_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_negative1_SetCallSignallingLogEnable", test_l1_mta_hal_negative1_SetCallSignallingLogEnable);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearCallSignallingLog", test_l1_mta_hal_positive1_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearCallSignallingLog", test_l1_mta_hal_positive2_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_ClearCallSignallingLog", test_l1_mta_hal_negative1_ClearCallSignallingLog);
    UT_add_test( pSuite, "l1_mta_hal_positive1_GetMtaLog", test_l1_mta_hal_positive1_GetMtaLog);
    UT_add_test( pSuite, "l1_mta_hal_negative1_GetMtaLog", test_l1_mta_hal_negative1_GetMtaLog);
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
    UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetCondition", test_l1_mta_hal_positive1_BatteryGetCondition);
    UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetCondition", test_l1_mta_hal_negative1_BatteryGetCondition);
    UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetStatus", test_l1_mta_hal_positive1_BatteryGetStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetStatus", test_l1_mta_hal_negative1_BatteryGetStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetLife", test_l1_mta_hal_positive1_BatteryGetLife);
    UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetLife", test_l1_mta_hal_negative1_BatteryGetLife);
    UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetInfo", test_l1_mta_hal_positive1_BatteryGetInfo);
    UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetInfo", test_l1_mta_hal_negative1_BatteryGetInfo);
    UT_add_test( pSuite, "l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus", test_l1_mta_hal_positive1_BatteryGetPowerSavingModeStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus", test_l1_mta_hal_negative1_BatteryGetPowerSavingModeStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_Get_MTAResetCount", test_l1_mta_hal_positive1_Get_MTAResetCount);
    UT_add_test( pSuite, "l1_mta_hal_negative1_Get_MTAResetCount", test_l1_mta_hal_negative1_Get_MTAResetCount);
    UT_add_test( pSuite, "l1_mta_hal_positive1_Get_LineResetCount", test_l1_mta_hal_positive1_Get_LineResetCount);
    UT_add_test( pSuite, "l1_mta_hal_negative1_Get_LineResetCount", test_l1_mta_hal_negative1_Get_LineResetCount);
    UT_add_test( pSuite, "l1_mta_hal_positive1_ClearCalls", test_l1_mta_hal_positive1_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive2_ClearCalls", test_l1_mta_hal_positive2_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive3_ClearCalls", test_l1_mta_hal_positive3_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_negative1_ClearCalls", test_l1_mta_hal_negative1_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_negative2_ClearCalls", test_l1_mta_hal_negative2_ClearCalls);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getDhcpStatus", test_l1_mta_hal_positive1_getDhcpStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getDhcpStatus", test_l1_mta_hal_negative1_getDhcpStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getConfigFileStatus", test_l1_mta_hal_positive1_getConfigFileStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getConfigFileStatus", test_l1_mta_hal_negative1_getConfigFileStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getLineRegisterStatus", test_l1_mta_hal_positive1_getLineRegisterStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive2_getLineRegisterStatus", test_l1_mta_hal_positive2_getLineRegisterStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getLineRegisterStatus", test_l1_mta_hal_negative1_getLineRegisterStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative2_getLineRegisterStatus", test_l1_mta_hal_negative2_getLineRegisterStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative3_getLineRegisterStatus", test_l1_mta_hal_negative3_getLineRegisterStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_devResetNow", test_l1_mta_hal_positive1_devResetNow);
    UT_add_test( pSuite, "l1_mta_hal_positive2_devResetNow", test_l1_mta_hal_positive2_devResetNow);
    UT_add_test( pSuite, "l1_mta_hal_negative1_devResetNow", test_l1_mta_hal_negative1_devResetNow);
    UT_add_test( pSuite, "l1_mta_hal_negative2_devResetNow", test_l1_mta_hal_negative2_devResetNow);
    UT_add_test( pSuite, "l1_mta_hal_negative3_devResetNow", test_l1_mta_hal_negative3_devResetNow);
    UT_add_test( pSuite, "l1_mta_hal_positive1_getMtaOperationalStatus", test_l1_mta_hal_positive1_getMtaOperationalStatus);
    UT_add_test( pSuite, "l1_mta_hal_negative1_getMtaOperationalStatus", test_l1_mta_hal_negative1_getMtaOperationalStatus);
    UT_add_test( pSuite, "l1_mta_hal_positive1_start_provisioning", test_l1_mta_hal_positive1_start_provisioning);
    UT_add_test( pSuite, "l1_mta_hal_positive2_start_provisioning", test_l1_mta_hal_positive2_start_provisioning);
    UT_add_test( pSuite, "l1_mta_hal_positive3_start_provisioning", test_l1_mta_hal_positive3_start_provisioning);
    UT_add_test( pSuite, "l1_mta_hal_negative1_start_provisioning", test_l1_mta_hal_negative1_start_provisioning);
    UT_add_test( pSuite, "l1_mta_hal_positive3_GetCalls", test_l1_mta_hal_positive3_GetCalls);


    return 0;
}

