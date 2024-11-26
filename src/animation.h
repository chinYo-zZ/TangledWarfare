#pragma once

#include "util.h"
#include <sprite_renderer.h>
#include <functional>
#include <gameobject.h>

class Animation : public GameObject
{
public:
	Animation() = default;
	~Animation() = default;

	void Reset();
	void SetAtlas(Atlas *NewAtlas);
	void SetLoop(bool Flag);
	void SetInterval(int ms);
	int GetidxFrame();
	Texture2D *GetFrame();
	bool CheckFinished();

	void OnUpdate(int delta);

	void SetCallBack(std::function<void()> callback);

	void Draw(SpriteRenderer &renderer) override;
private:
	int timer = 0;		   
	int interval = 0;	 
	int idx_frame = 0;	 
	bool is_loop = true; 
	Atlas *atlas = nullptr;
	
	std::function<void()> callback;
};