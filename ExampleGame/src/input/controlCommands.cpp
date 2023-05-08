#include "controlCommands.h"

void UpCommand::execute(void *object)
{
    std::cout << "Up" << std::endl;
};

void UpCommand::check(InputEvent inputEvent)
{

};

void DownCommand::execute(void *object)
{
    std::cout << "Down" << std::endl;
}

void DownCommand::check(InputEvent inputEvent)
{

};

void RightCommand::execute(void *object)
{
    std::cout << "Right" << std::endl;
}

void RightCommand::check(InputEvent inputEvent)
{

};

void LeftCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

void LeftCommand::check(InputEvent inputEvent)
{

};

void JumpCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

void JumpCommand::check(InputEvent inputEvent)
{

};