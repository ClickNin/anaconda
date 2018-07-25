#include "platform.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <mmsystem.h>
#endif

#include "fpslimit.h"

FPSLimiter::FPSLimiter()
: framerate(-1)
{
    old_time = platform_get_time();
}

void FPSLimiter::set(int value)
{
    framerate = value;
}

double FPSLimiter::normalize(double delta)
{
    if (delta > 1.0)
        return 1.0 / framerate;
    return delta;
}

void FPSLimiter::start()
{
    double current_time = platform_get_time();
    next_update = current_time + 1.0 / framerate;
    dt = normalize(current_time - old_time);
    old_time = current_time;
    if (dt < 0.0)
        dt = 0.001;
    current_framerate = 1.0 / dt;
}

void FPSLimiter::finish()
{
#ifdef CHOWDREN_IS_DESKTOP
    if (framerate >= 100)
        return;
    double t = normalize(next_update - platform_get_time());
    platform_sleep(t);
#endif
}
