/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2023 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <ut.h>
#include <ut_log.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mta_hal.h"

extern int register_hal_l1_tests( void );

int init_mta_hal_init(void)
{
    int ret = 0;
    ret = mta_hal_InitDB();
    if (ret == 0)
    {
        UT_LOG_DEBUG("mta_hal_InitDB returned success");
        return 0;
    }
    else
    {
        UT_LOG_DEBUG("mta_hal_InitDB returned failure");
        UT_FAIL("mta_hal_InitDB initialization failed");
        return -1;
    }
}

int main(int argc, char** argv)
{
    printf("In main");
    int registerReturn = 0;

    /* Register tests as required, then call the UT-main to support switches and triggering */
    UT_init( argc, argv );
    /* Check if tests are registered successfully */
    registerReturn = register_hal_l1_tests();
    if (registerReturn == 0)
    {
        printf("register_hal_l1_tests() returned success");
    }
    else
    {
        printf("register_hal_l1_tests() returned failure");
        return 1;
    }

    /* Begin test executions */
    UT_run_tests();
    printf("END main");
    return 0;
}