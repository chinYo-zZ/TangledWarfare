#pragma once

#include <camera.h>
#include "gameobject.h"

class Scene : public GameObject
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter(){};
	virtual void on_update(int delta){};
	virtual void on_draw(SpriteRenderer &renderer){};
	virtual void on_input(GLboolean (&Keys)[1024]){};
	virtual void on_exit(){};

private:
};