#include "CCEnginePrecompiled.h"
#include "keyboardInputContext.h"
#include <SDL2/SDL.h>


void KeyboardInputContext::addCommand(std::shared_ptr<Command> command)
{
    if(_lastCommandIndex >= _maxCommands)
    {
        std::cout << "Maximum command quantity reached" << std::endl;
        return;
    }

    _lastCommandIndex++;
    _inputToIndex.insert({(SDL_Scancode*) command->getInput(), _lastCommandIndex});
    _commands[_lastCommandIndex] = command;
}

void KeyboardInputContext::addCommands(std::vector<std::shared_ptr<Command>> commands)
{
    for(int i = 0; i < commands.size(); i++)
    {
        addCommand(commands[i]);
    }
}

void KeyboardInputContext::removeCommand(SDL_Scancode input)
{
    if(_inputToIndex.find(input) == _inputToIndex.end())
    {
        std::cout << input << " cannot be removed as not corresponding to any savec command " << std::endl;
        return;
    }
    
    // Deleting command corresponding to input
    unsigned int index = _inputToIndex.at(input);
    _inputToIndex.erase(input);
    
    // Replacing it with last command in the array
    std::shared_ptr<Command> lastCommand = _commands[_lastCommandIndex];
    _commands[index] = lastCommand;
    _inputToIndex[(SDL_Scancode*) lastCommand->getInput()] = index;
   
   
    _lastCommandIndex--;
}

void KeyboardInputContext::pollEvents()
{
    _keysLastFrame = _keysCurrentFrame;
    _keysCurrentFrame.clear();
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        auto inputIndex = _inputToIndex.find(event.key.keysim.sym);
        if(inputIndex != _input.toIndex.end() && event.type = SDL_KEYDOWN) {       
            _keysCurrentFrame.setBit(inputIndex, true);
        }
    }
}

void KeyboardInputContext::update()
{
    for(int i = 0; i <= _lastCommandIndex; i++)
    {
        if(_keysCurrentFrame.getBit(i))
        {
            _commands[i]->execute();
        }
    }
}