#pragma once

#include <ArduinoOTA.h>

namespace ota
{

inline void initialize(const char * name)
{
    ArduinoOTA.setHostname(name);

    ArduinoOTA.begin();
}

inline void handle()
{
    ArduinoOTA.handle();
}
}  // namespace ota
