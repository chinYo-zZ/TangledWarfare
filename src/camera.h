#pragma once

#include <glm/glm.hpp>
#include "timer.h"
class Camera
{
public:
    Camera();
    ~Camera() = default;

    const glm::vec2 GetPosition() const;
    void Reset();
    void OnUpate(int delta);
    void Shake(float strength,int duration);
private:
    glm::vec2 Position;

    Timer TimerShake;
    bool IsShaking = false;
    float ShakingStrength = 0;
};