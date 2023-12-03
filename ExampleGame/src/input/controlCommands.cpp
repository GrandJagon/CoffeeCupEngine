#include "controlCommands.h"

void UpCommand::execute(void *object)
{
    printf("ControlCommandUp called");
};

void UpCommand::check(Event inputEvent){

};

void DownCommand::execute(void *object)
{
    printf("ControlCommandDown called");
}

void DownCommand::check(Event inputEvent){

};

void RightCommand::execute(void *object)
{
    printf("ControlCommandRight called");
}

void RightCommand::check(Event inputEvent){

};

void LeftCommand::execute(void *object)
{
    printf("ControlCommandLeft called");
};

void LeftCommand::check(Event inputEvent){

};

void JumpCommand::execute(void *object)
{
    printf("ControlCommandJump called");
};

void JumpCommand::check(Event inputEvent){

};