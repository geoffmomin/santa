/// Copyright 2014 Google Inc. All rights reserved.
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///    http://www.apache.org/licenses/LICENSE-2.0
///
///    Unless required by applicable law or agreed to in writing, software
///    distributed under the License is distributed on an "AS IS" BASIS,
///    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///    See the License for the specific language governing permissions and
///    limitations under the License.

#include "SantaDriver.h"

#define super IOService
#define SantaDriver com_google_SantaDriver

// The defines above can'be used in this function, we must use the full names.
OSDefineMetaClassAndStructors(com_google_SantaDriver, IOService);

bool SantaDriver::start(IOService *provider) {
  if (!super::start(provider)) return false;

  registerService();

  LOGI("Loaded, version %s.", OSKextGetCurrentVersionString());

  return true;
}

void SantaDriver::stop(IOService *provider) {
  LOGI("Unloaded.");
}

#undef super
