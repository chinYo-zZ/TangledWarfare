#include "scene_manager.h"

extern Scene *menu_scene;
extern Scene *game_scene;
extern Scene *selector_scene;

void SceneManager::SetCurrentScene(Scene *scene)
{
	CurrentScene = scene;
	CurrentScene->on_enter();
}

void SceneManager::SwitchTo(SceneType type)
{
	CurrentScene->on_exit();
	switch (type)
	{
	case SceneManager::SceneType::Menu:
		CurrentScene = menu_scene;
		break;
	case SceneManager::SceneType::Game:
		CurrentScene = game_scene;
		break;
	case SceneManager::SceneType::Selector:
		CurrentScene = selector_scene;
		break;
	default:
		break;
	}
	CurrentScene->on_enter();
}

void SceneManager::on_update(int delta)
{
	CurrentScene->on_update(delta);
}

void SceneManager::on_draw(const Camera& camera)
{
	CurrentScene->on_draw(camera);
}

void SceneManager::on_input()
{
	CurrentScene->on_input();
}