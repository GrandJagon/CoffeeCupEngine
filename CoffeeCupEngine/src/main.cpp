#include <iostream>
#include <cstring>

#include "utils/utilities.h"

#include "game/game.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;


int main(void)
{   

    Game::instance()->init("Game test", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    
    bool running = true;
    while (running)
    {   

        // SDL input handling
        SDL_Event e;

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                std::cout << "Application temrinated by user" << std::endl;
                running = false;
            }
        
         if(e.type == SDL_MOUSEMOTION){
                std::cout << "mouse has been moved\n";
            }

            
 
            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout << "right arrow key is pressed\n";
            }
        }

        

        
    }
    
    return 0;
}

