#pragma once

#include <functional>


class Timer
{
public:
    Timer() = default;
    ~Timer() = default;

    void Restart();
    void SetWaitTime(int val);
    void SetOneShot(bool flag);
    void SetCallBack(std::function<void()>callback);
    void Pause();
    void Resume();
    void OnUpdate(int delta);
private:
    int pass_time = 0;// 已过时间
    int wait_time = 0;// 等待时间
    bool paused = false;// 是否暂停
    bool shotted = false;// 是否触发
    bool one_shot = false;// 单次触发
    std::function<void()> CallBack; // 触发回调
};