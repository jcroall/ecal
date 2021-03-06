/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2020 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include "command.h"

namespace eCAL
{
  namespace sys
  {
    namespace command
    {
      eCAL::sys::Error Command::GetRemoteSysStatus(const std::string& hostname, const std::shared_ptr<eCAL::protobuf::CServiceClient<eCAL::pb::sys::Service>>& remote_ecalsys_service, eCAL::pb::sys::State& state_output) const
      {
        SServiceResponse service_response;
        bool success = remote_ecalsys_service->Call(hostname, "GetStatus", eCAL::pb::sys::GenericRequest(), service_response, state_output);

        if (!success)
        {
          return eCAL::sys::Error(eCAL::sys::Error::ErrorCode::REMOTE_HOST_UNAVAILABLE, hostname);
        }
        else
        {
          return eCAL::sys::Error::OK;
        }
      }
    }
  }
}