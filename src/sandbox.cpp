#include <iostream>
#include <cstring>

#include "vendors/imgui/imgui.h"
#include "vendors/imgui/imgui_impl_glfw_gl3.h"
#include "utils/utilities.h"

#include "game/game.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

Game testGame = Game("GAME TEST");

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void)
{   
    
    testGame.getWindow().setKeyCallBack(&key_callback);
    
    // GAME LOOP 
    

    
    return 0;
}

// Input callbacks to be passed to the game
// Will be abstracted within Event object that will tie an event to a function to be called in game loop by processEvents()
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{   
    // KEY INPUT PROCESSING LOGIC
}