#include "controlCommands.h"

void UpCommand::execute(void *object)
{
    std::cout << "Up" << std::endl;
};

void UpCommand::check(Event inputEvent){

};

void DownCommand::execute(void *object)
{
    std::cout << "Down" << std::endl;
}

void DownCommand::check(Event inputEvent){

};

void RightCommand::execute(void *object)
{
    std::cout << "Right" << std::endl;
}

void RightCommand::check(Event inputEvent){

};

void LeftCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

void LeftCommand::check(Event inputEvent){

};

void JumpCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

void JumpCommand::check(Event inputEvent){

};