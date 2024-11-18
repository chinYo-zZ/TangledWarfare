
#include "menu_scene.h"
#include <sprite_renderer.h>
#include <resource_manager.h>

void MenuScene::on_enter()
{
    MenuRender = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}

void MenuScene::on_update(int delta)
{

}

void MenuScene::on_draw(const Camera& camera)
{
    MenuRender->DrawSprite(ResourceManager::GetTexture("menu_background"),glm::vec2(0, 0), glm::vec2(1920, 1080), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void MenuScene::on_input()
{
}

void MenuScene::on_exit()
{
}
