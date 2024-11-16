#include "resource_manager.h"
#include "sprite_renderer.h"
#include "game.h"


// Game-related State data
SpriteRenderer  *Renderer;


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
    // Set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}

void Game::Update(GLfloat dt)
{

}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("avatar_sunflower"), glm::vec2(0, 0), glm::vec2(300, 300), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}