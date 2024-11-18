#include "timer.h"

void Timer::Restart()
{
    pass_time = 0;
    shotted = false;
}

void Timer::SetWaitTime(int val)
{
    wait_time = val;
}

void Timer::SetOneShot(bool flag)
{
    one_shot = flag;
}

void Timer::SetCallBack(std::function<void()> callback)
{
    this->CallBack = callback;
}

void Timer::Pause()
{
    paused = true;
}

void Timer::Resume()
{
    paused = false;
}

void Timer::OnUpdate(int delta)
{
    if (paused)
        return;
    pass_time += delta;
    if (pass_time >= wait_time){
        if ((!one_shot || (one_shot && !shotted)) && CallBack)
            CallBack();
        shotted = true;
        pass_time = 0;
    }
}
