#include "controlCommands.h"

UpCommand::execute(void *object)
{
    std::cout << "Up" << std::endl;
};

UpCommand::check(InputEvent inputEvent)
{

};

DownCommand::execute(void *object)
{
    std::cout << "Down" << std::endl;
}

DownCommand::check(InputEvent inputEvent)
{

};

RightCommand::execute(void *object)
{
    std::cout << "Right" << std::endl;
}

RightCommand::check(InputEvent inputEvent)
{

};

LeftCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

LeftCommand::check(InputEvent inputEvent)
{

};

JumpCommand::execute(void *object)
{
    std::cout << "Left" << std::endl;
};

JumpCommand::check(InputEvent inputEvent)
{

};