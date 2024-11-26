#pragma once

#include "scene.h"
#include <camera.h>
class SceneManager
{
public:
	enum class SceneType
	{
		Menu,
		Game,
		Selector
	};

public:
	SceneManager() = default;
	~SceneManager() = default;

	void SetCurrentScene(Scene *scene);

	void SwitchTo(SceneType type);

	void on_update(int delta);
	void on_draw(SpriteRenderer &renderer);
	void on_input(GLboolean (&Keys)[1024]);

private:
	Scene *CurrentScene = nullptr;
};