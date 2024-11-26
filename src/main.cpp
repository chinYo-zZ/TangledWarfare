
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "scene.h"
#include "game.h"
#include "menu_scene.h"
#include "game_scene.h"
#include "selector_scene.h"
#include "scene_manager.h"
#include "camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

Game GameInstance(SCR_WIDTH,SCR_HEIGHT);

int main()
{
	const int FPS = 60;
    // -----------------------------------------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "TangledWarfare", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    
    glfwSetKeyCallback(window, key_callback);

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // -----------------------------------------------------------------------
    

    GameInstance.Init();

    while (!glfwWindowShouldClose(window))
    {
        auto frame_start_time = std::chrono::high_resolution_clock::now();
        glfwPollEvents();

		static auto last_tick_time = std::chrono::high_resolution_clock::now();
		auto current_tick_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> delta_tick = current_tick_time - last_tick_time;
		auto delta_tick_ms = std::chrono::duration_cast<std::chrono::milliseconds>(delta_tick).count();
        
		GameInstance.ProcessInput(delta_tick_ms);

        GameInstance.Update(delta_tick_ms);
		last_tick_time = current_tick_time;
        

		
        // render
        // ------
        glClearColor(0.f, 0.f, 0.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        GameInstance.Render();
        //scene_manager.on_draw(MainCamera);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);

        auto frame_end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> frame_delta_time = frame_end_time - frame_start_time;
		auto frame_delta_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(frame_delta_time).count();
		// 目标时间：1 / FPS（单位：毫秒）
		int target_frame_time_ms = 1000 / FPS;
		// 如果帧时间小于目标帧时间，进行睡眠
		if (frame_delta_time_ms < target_frame_time_ms)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(target_frame_time_ms - frame_delta_time_ms));
		}
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            GameInstance.Keys[key] = GL_TRUE;
        else if (action == GLFW_RELEASE)
            GameInstance.Keys[key] = GL_FALSE;
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}