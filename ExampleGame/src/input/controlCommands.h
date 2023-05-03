#pragma once

#include "CCEngine.h"


class UpCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
        virtual void check(InputEvent inputEvent) override;
};

class DownCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
        virtual void check(InputEvent inputEvent) override;
};

class RightCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
        virtual void check(InputEvent inputEvent) override;
};

class LeftCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
        virtual void check(InputEvent inputEvent) override;
};

class JumpCommand : public Command
{
    public:
        virtual void execute(void *object = nullptr) override;
        virtual void check(InputEvent inputEvent) override;
};