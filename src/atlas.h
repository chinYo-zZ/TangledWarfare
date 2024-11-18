#pragma once

#include <texture.h>
#include <vector>
#include <string> 

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void LoadFromFile(std::string path_template, int num);

	void Clear();
	int GetSize();
	Texture2D *GetImage(int idx);
	void AddImage(const Texture2D &img);

private:
	std::vector<Texture2D> ImgList;
};