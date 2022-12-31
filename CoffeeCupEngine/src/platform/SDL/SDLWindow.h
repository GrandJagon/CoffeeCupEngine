#pragma once

#include "../../utils/utilities.h"
#include "../../rendering/window/window.h"

class SDLWindow : public Window
{ 
    private:
        SDL_Window *_window;

    public:
        void init(std::string title, int width, int height, bool fullScreen) override;
        void endFrame() override;
        void resize(int width, int height) override;
        void destroy() override;
};

