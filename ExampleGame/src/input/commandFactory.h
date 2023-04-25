#pragma once

#include "CCEngine.h"

class Command;

namespace CommandFactory
{
    std::shared_ptr<Command> createCommand(std::string commandName);
}