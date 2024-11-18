#include "camera.h"

Camera::Camera()
{
    TimerShake.SetOneShot(true);
    TimerShake.SetCallBack([&](){
        IsShaking = false;
        Reset();
    });
}

const glm::vec2 Camera::GetPosition() const
{
    return glm::vec2();
}

void Camera::Reset()
{
    Position.x = 0.0;
    Position.y = 0.0;
}

void Camera::OnUpate(int delta)
{
    TimerShake.OnUpdate(delta);

    if(IsShaking){
        Position.x = (-50 + rand() % 100) / 50.0f * ShakingStrength;
        Position.y = (-50 + rand() % 100) / 50.0f * ShakingStrength;
    }
}

void Camera::Shake(float strength, int duration)
{
    IsShaking = true;
    ShakingStrength = strength;
    TimerShake.SetWaitTime(duration);
    TimerShake.Restart();
}
