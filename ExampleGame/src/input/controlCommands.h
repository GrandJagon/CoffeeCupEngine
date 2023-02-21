#pragma once

#include "CCEngine.h"

// CONNTROL THROUGH PARAMETER TO BE IMPLEMENTED AFTER ECS
// RIGHT NOW DIRECTLY ACCESS PLAYER OBJECT FOR TESTING PURPOSE

class UpCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
};

class DownCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
};

class RightCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
};

class LeftCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
};

class JumpCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
};