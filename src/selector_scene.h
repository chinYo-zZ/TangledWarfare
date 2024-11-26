#pragma once

#include "scene.h"
#include <animation.h>

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(SpriteRenderer &render) override;
	void on_input(GLboolean (&Keys)[1024]) override;
	void on_exit();

private:
	glm::vec2 pos_img_VS = glm::vec2(0,0);// Vs 艺术字图片位置
	glm::vec2 pos_img_tip = glm::vec2(0,0);//提示信息文本图片位置
	glm::vec2 pos_img_1P = glm::vec2(0,0);//1P文本图片位置
	glm::vec2 pos_img_2P = glm::vec2(0,0);// 2P 文本图片位置
	glm::vec2 pos_img_1P_desc = glm::vec2(0,0);// 1P 键位描述图片位置
	glm::vec2 pos_img_2P_desc = glm::vec2(0,0);// 2P 键位描述图片位置
	glm::vec2 pos_img_1P_name = glm::vec2(0,0);// 1P 角色姓名文本位置
	glm::vec2 pos_img_2P_name = glm::vec2(0,0);// 2P 角色姓名文本位置
	glm::vec2 pos_animation_1P = glm::vec2(0,0);// 1P 角色动画位置
	glm::vec2 pos_animation_2P = glm::vec2(0,0);// 2P 角色动画位置
	glm::vec2 pos_img_1P_gravestone = glm::vec2(0,0);// 1P墓碑图片位置
	glm::vec2 pos_img_2P_gravestone = glm::vec2(0,0);// 2P 墓碑图片位置
	glm::vec2 pos_1P_selector_btn_left = glm::vec2(0,0);// 1P 向左切换按钮位置
	glm::vec2 pos_1P_selector_btn_right = glm::vec2(0,0);// 1P 向右切换按钮位置
	glm::vec2 pos_2P_selector_btn_left = glm::vec2(0,0);// 2P 向左切换按钮位置
	glm::vec2 pos_2P_selector_btn_right = glm::vec2(0,0);// 2P 向右切换按钮位置

	Animation animation_peashooter;
	Animation animation_sunflower;
};