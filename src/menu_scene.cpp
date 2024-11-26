
#include "menu_scene.h"
#include <sprite_renderer.h>
#include <resource_manager.h>
#include <scene_manager.h>
#include <GLFW/glfw3.h>

extern SceneManager scene_manager;

MenuScene::MenuScene(glm::vec2 size, Texture2D sprite)
{
    Size = size;
    Sprite = sprite;
}

void MenuScene::on_enter()
{
    
}

void MenuScene::on_update(int delta)
{

}

void MenuScene::on_draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(ResourceManager::GetTexture("menu_background"),glm::vec2(0, 0), glm::vec2(1920, 1080), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void MenuScene::on_input(GLboolean (&Keys)[1024])
{
    if(Keys[GLFW_KEY_ENTER]){
        scene_manager.SwitchTo(SceneManager::SceneType::Selector);
    }
}

void MenuScene::on_exit()
{
}
