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

#ifndef _WRAPPER_FACTORY_H_
#define _WRAPPER_FACTORY_H_

#include <memory>
#include <OCApi.h>
#include "IClientWrapper.h"
#include "IServerWrapper.h"
#include <OutOfProcClientWrapper.h>
#include <InProcClientWrapper.h>
#include <OutOfProcServerWrapper.h>
#include <InProcServerWrapper.h>

namespace OC
{
    // Interface to permit easier mocking/unit testing later
    class IWrapperFactory
    {
    public:
        typedef std::shared_ptr<IWrapperFactory> Ptr;

        virtual IClientWrapper::Ptr CreateClientWrapper(PlatformConfig cfg) =0;
        virtual IServerWrapper::Ptr CreateServerWrapper(PlatformConfig cfg) =0;
        virtual ~IWrapperFactory(){}
    };

    // Class to create the client/server object!
    class WrapperFactory : public IWrapperFactory
    {
    public:
        WrapperFactory(){}

        virtual IClientWrapper::Ptr CreateClientWrapper(PlatformConfig cfg)
        {
            switch(cfg.serviceType)
            {
            case ServiceType::InProc:
                return std::make_shared<InProcClientWrapper>(cfg);
                break;
            case ServiceType::OutOfProc:
                return std::make_shared<OutOfProcClientWrapper>(cfg);
                break;
            }
			return nullptr;
        }

        virtual IServerWrapper::Ptr CreateServerWrapper(PlatformConfig cfg)
        {
            switch(cfg.serviceType)
            {
            case ServiceType::InProc:
                return std::make_shared<InProcServerWrapper>(cfg);
                break;
            case ServiceType::OutOfProc:
              //  return std::make_shared<OutOfProcServerWrapper>(cfg);
                break;
            }
			return nullptr;
        }

        virtual ~WrapperFactory(){}
    };
}

#endif
