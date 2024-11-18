#include "animation.h"

void Animation::Reset()
{
	timer = 0;
	idx_frame = 0;
}

void Animation::SetAtlas(Atlas *NewAtlas)
{
	Reset();
	atlas = NewAtlas;
}

void Animation::SetLoop(bool Flag)
{
	is_loop = Flag;
}

void Animation::SetInterval(int ms)
{
	interval = ms;
}

int Animation::GetidxFrame()
{
	return idx_frame;
}

Texture2D *Animation::GetFrame()
{
	return atlas->GetImage(idx_frame);
}

bool Animation::CheckFinished()
{
	if (is_loop)
	{
		return false;
	}
	return (idx_frame == atlas->GetSize() - 1);
}

void Animation::OnUpdate(int delta)
{
	timer += delta;
	if (timer >= interval)
	{
		timer = 0;
		idx_frame++;
		if (idx_frame >= atlas->GetSize())
		{
			idx_frame = is_loop ? 0 : atlas->GetSize() - 1;
			if (!is_loop && callback)
			{
				callback();
			}
		}
	}
}

void Animation::SetCallBack(std::function<void()> callback)
{
	this->callback = callback;
}