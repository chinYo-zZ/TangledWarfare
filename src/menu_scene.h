#pragma once

#include "scene.h"

class SpriteRenderer;

class MenuScene : public Scene
{
public:
	MenuScene();
	MenuScene(glm::vec2 size, Texture2D sprite);
	~MenuScene() = default;

	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(SpriteRenderer& renderer) override;
	void on_input(GLboolean (&Keys)[1024]) override;
	void on_exit() override;

private:
};