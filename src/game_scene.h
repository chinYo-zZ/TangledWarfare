#pragma once

#include "scene.h"

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
private:
};