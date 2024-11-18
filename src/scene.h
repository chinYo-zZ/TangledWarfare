#pragma once

#include <camera.h>

class Scene
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter(){};
	virtual void on_update(int delta){};
	virtual void on_draw(const Camera& camera){};
	virtual void on_input(){};
	virtual void on_exit(){};

private:
};