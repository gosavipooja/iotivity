//******************************************************************
//
// Copyright 2014 Intel Corporation All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


//=============================================================================
// Includes
//=============================================================================
/*extern "C" {
    #include "occoap.h"
    #include "logger.h"
}*/

#include "gtest/gtest.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <stdint.h>
using namespace std;

//=============================================================================
// Private Variables
//=============================================================================
static const char TAG[] = "TestHarness";

//=============================================================================
// Callback function
//=============================================================================
/*void discoverServicesAsync(const char *Url) {
    OC_LOG_V(INFO, TAG, "Entering discoverServicesAsync.  URL = %s", Url);
}*/

//=============================================================================
// Tests
//=============================================================================
TEST(OCCoapTest, General) {
    EXPECT_EQ(0, 0);
}

/*TEST(OCCoapTest, ServiceDiscovery) {
    OC_LOG(INFO, TAG, "Running ServiceDiscovery");

    EXPECT_EQ(0, OCInitCoAP("127.0.0.1", 0, OC_CLIENT));

    OCCoAPClientCallbackFunction asyncReturnFunc = discoverServicesAsync;
    EXPECT_EQ(0, OCDoCoAPResource(OC_REST_GET, "oc/core/d", asyncReturnFunc));

    EXPECT_EQ(0, OCProcessCoAP());

    EXPECT_EQ(0, OCStopCoAP());
}*/
