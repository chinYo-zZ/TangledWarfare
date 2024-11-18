#include "atlas.h"
#include "resource_manager.h"
#include <stdio.h>
#include <Format.h>

void Atlas::LoadFromFile(std::string path_template, int num)
{
	ImgList.clear();
	ImgList.resize(num);

	for (int i = 0; i < num; i++)
	{
		std::string Path = "../resources/" + path_template + util::Format("_{0}", i + 1);
		ImgList[i] = ResourceManager::LoadTexture(Path.c_str(), true, Path);
	}
}

void Atlas::Clear()
{
	ImgList.clear();
}

int Atlas::GetSize()
{
	return (int)ImgList.size();
}

Texture2D *Atlas::GetImage(int idx)
{
	if (idx < 0 || idx >= ImgList.size())
	{
		return nullptr;
	}
	return &ImgList[idx];
}

void Atlas::AddImage(const Texture2D &img)
{
	ImgList.push_back(img);
}