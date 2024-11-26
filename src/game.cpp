#include "resource_manager.h"
#include "sprite_renderer.h"

#include "scene.h"
#include "game.h"
#include "menu_scene.h"
#include "game_scene.h"
#include "selector_scene.h"
#include "scene_manager.h"
#include "camera.h"

// Game-related State data
SpriteRenderer  *Renderer;

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;
Scene *selector_scene = nullptr;

Camera MainCamera;  

SceneManager scene_manager;

Atlas atlas_peashooter_idle_right;
Atlas atlas_sunflower_idle_right;

Game::Game(GLuint width, GLuint height) 
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height) 
{ 

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // Load shaders
    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.frag", nullptr, "sprite");
    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // Load textures
    ResourceManager::LoadTexture("../resources/avatar_sunflower.png", GL_TRUE, "avatar_sunflower");
    ResourceManager::LoadTexture("../resources/menu_background.png",GL_TRUE,"menu_background");

    // 使用 ResourceManager 加载纹理
    ResourceManager::LoadTexture("../resources/VS.png", GL_TRUE, "img_VS");
    ResourceManager::LoadTexture("../resources/1P.png", GL_TRUE, "img_1P");
    ResourceManager::LoadTexture("../resources/2P.png", GL_TRUE, "img_2P");
    ResourceManager::LoadTexture("../resources/1P_desc.png", GL_TRUE, "img_1P_desc");
    ResourceManager::LoadTexture("../resources/2P_desc.png", GL_TRUE, "img_2P_desc");
    ResourceManager::LoadTexture("../resources/gravestone_left.png", GL_TRUE, "img_gravestone_left");
    ResourceManager::LoadTexture("../resources/gravestone_right.png", GL_TRUE, "img_gravestone_right");
    ResourceManager::LoadTexture("../resources/selector_tip.png", GL_TRUE, "img_selector_tip");
    ResourceManager::LoadTexture("../resources/selector_background.png", GL_TRUE, "img_selector_background");
    ResourceManager::LoadTexture("../resources/1P_selector_btn_idle_left.png", GL_TRUE, "img_1P_selector_btn_idle_left");
    ResourceManager::LoadTexture("../resources/1P_selector_btn_idle_right.png", GL_TRUE, "img_1P_selector_btn_idle_right");
    ResourceManager::LoadTexture("../resources/1P_selector_btn_down_left.png", GL_TRUE, "img_1P_selector_btn_down_left");
    ResourceManager::LoadTexture("../resources/1P_selector_btn_down_right.png", GL_TRUE, "img_1P_selector_btn_down_right");
    ResourceManager::LoadTexture("../resources/2P_selector_btn_idle_left.png", GL_TRUE, "img_2P_selector_btn_idle_left");
    ResourceManager::LoadTexture("../resources/2P_selector_btn_idle_right.png", GL_TRUE, "img_2P_selector_btn_idle_right");
    ResourceManager::LoadTexture("../resources/2P_selector_btn_down_left.png", GL_TRUE, "img_2P_selector_btn_down_left");
    ResourceManager::LoadTexture("../resources/2P_selector_btn_down_right.png", GL_TRUE, "img_2P_selector_btn_down_right");
    ResourceManager::LoadTexture("../resources/peashooter_selector_background_left.png", GL_TRUE, "img_peashooter_selector_background_left");
    ResourceManager::LoadTexture("../resources/peashooter_selector_background_right.png", GL_TRUE, "img_peashooter_selector_background_right");
    ResourceManager::LoadTexture("../resources/sunflower_selector_background_left.png", GL_TRUE, "img_sunflower_selector_background_left");
    ResourceManager::LoadTexture("../resources/sunflower_selector_background_right.png", GL_TRUE, "img_sunflower_selector_background_right");

    atlas_peashooter_idle_right.LoadFromFile("peashooter_idle",9);
    atlas_sunflower_idle_right.LoadFromFile("sunflower_idle",8);
    // Set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    menu_scene = new MenuScene(glm::vec2(1920,1080),ResourceManager::GetTexture("menu_background"));
	game_scene = new GameScene();
	selector_scene = new SelectorScene();

	scene_manager.SetCurrentScene(menu_scene);
}

void Game::Update(GLuint dt)
{
    scene_manager.on_update(dt);
}

void Game::ProcessInput(GLuint dt)
{
    scene_manager.on_input(Keys);
}

void Game::Render()
{
    scene_manager.on_draw(*Renderer);
    //Renderer->DrawSprite(ResourceManager::GetTexture("menu_background"), glm::vec2(0, 0), glm::vec2(1920, 1080), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    //Renderer->DrawSprite(ResourceManager::GetTexture("avatar_sunflower"), glm::vec2(0, 0), glm::vec2(100, 100), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

}