#include "selector_scene.h"
#include <animation.h>
#include <resource_manager.h>
#include <game.h>

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern Game GameInstance;

void SelectorScene::on_enter()
{
    animation_peashooter.SetAtlas(&atlas_peashooter_idle_right);
    animation_sunflower.SetAtlas(&atlas_sunflower_idle_right);
    animation_peashooter.SetInterval(100);
    animation_sunflower.SetInterval(100);

    GLuint SCR_WIDTH = GameInstance.Width;
    GLuint SCR_HEIGHT = GameInstance.Height;

    static const int OFFSET_X = 50;
    // 使用 ResourceManager::GetTexture("img_VS").Width 来代替 img_VS.getwidth()
    pos_img_VS.x = (SCR_WIDTH - ResourceManager::GetTexture("img_VS").Width) / 2;
    pos_img_VS.y = (SCR_HEIGHT - ResourceManager::GetTexture("img_VS").Height) / 2;

    // 依照相同逻辑修改其它图像的位置
    pos_img_tip.x = (SCR_WIDTH - ResourceManager::GetTexture("img_selector_tip").Width) / 2;
    pos_img_tip.y = SCR_HEIGHT - 125;

    pos_img_1P.x = (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_1P").Width) / 2 - OFFSET_X;
    pos_img_1P.y = 35;

    pos_img_2P.x = SCR_WIDTH / 2 + (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_2P").Width) / 2 + OFFSET_X;
    pos_img_2P.y = pos_img_1P.y;

    pos_img_1P_desc.x = (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_1P_desc").Width) / 2 - OFFSET_X;
    pos_img_1P_desc.y = SCR_HEIGHT - 150;

    pos_img_2P_desc.x = SCR_WIDTH / 2 + (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_2P_desc").Width) / 2 + OFFSET_X;
    pos_img_2P_desc.y = pos_img_1P_desc.y;

    pos_img_1P_gravestone.x = (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_gravestone_right").Width) / 2 - OFFSET_X;
    pos_img_1P_gravestone.y = pos_img_1P.y + ResourceManager::GetTexture("img_1P").Height + 35;

    pos_img_2P_gravestone.x = SCR_WIDTH / 2 + (SCR_WIDTH / 2 - ResourceManager::GetTexture("img_gravestone_left").Width) / 2 + OFFSET_X;
    pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;

    pos_animation_1P.x = (SCR_WIDTH / 2 - ResourceManager::GetTexture("atlas_peashooter_idle_right").Width) / 2 - OFFSET_X;
    pos_animation_1P.y = pos_img_1P_gravestone.y + 80;

    pos_animation_2P.x = SCR_WIDTH / 2 + (SCR_WIDTH / 2 - ResourceManager::GetTexture("atlas_peashooter_idle_right").Width) / 2 + OFFSET_X;
    pos_animation_2P.y = pos_animation_1P.y;

    pos_img_1P_name.y = pos_animation_1P.y + 155;
    pos_img_2P_name.y = pos_img_1P_name.y;

    pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - ResourceManager::GetTexture("img_1P_selector_btn_idle_left").Width;
    pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (ResourceManager::GetTexture("img_gravestone_right").Height - ResourceManager::GetTexture("img_1P_selector_btn_idle_left").Height) / 2;

    pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + ResourceManager::GetTexture("img_gravestone_right").Width;
    pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;

    pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - ResourceManager::GetTexture("img_2P_selector_btn_idle_left").Width;
    pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;

    pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + ResourceManager::GetTexture("img_gravestone_left").Width;
    pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
}

void SelectorScene::on_update(int delta)
{
}

void SelectorScene::on_draw(SpriteRenderer &render)
{
}

void SelectorScene::on_input(GLboolean (&Keys)[1024])
{
}

void SelectorScene::on_exit()
{
}
