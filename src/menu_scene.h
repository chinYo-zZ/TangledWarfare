#pragma once

#include "scene.h"

class SpriteRenderer;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	void on_input() override;
	void on_exit() override;

private:
	SpriteRenderer* MenuRender;
};