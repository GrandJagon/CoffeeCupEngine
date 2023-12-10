#include "CCEnginePrecompiled.h"
#include "inputManager.h"

#include "utils/iniParser.h"

std::shared_ptr<InputManager> InputManager::_instance = nullptr;

void InputManager::init(const std::string inputMappingFile)
{
    loadInputMapping(inputMappingFile);
}

const void InputManager::loadInputMapping(const std::string filePath)
{
    INIParser::INIFile iniFile;
    INIParser::parseFile(iniFile, filePath); // loads file content to file

    for (unsigned int i = 0; i < iniFile.sections.size(); i++)
    {
        auto newContext = std::make_shared<InputContext>();
        printf("INI section name is %s\n", iniFile.sections[i].title.c_str());
        newContext->setName(iniFile.sections[i].title);

        printf("New inputContext created with name : %s\n", newContext->getName().c_str());

        for (unsigned int j = 0; j < iniFile.sections[i].entries.size(); j++)
        {
            auto command = _commandFactory.createCommand(iniFile.sections[i].entries[j].value);
            // & -> NOT SAFE, TO CHANGE LATER BY IMPLEMENTING POLYMORPHISM (INPUT CAN BE OF SEVERAL TYPES BUT RIGHT NOW JUST LOADING COMMAND NAME FROM INI FILE IS FINE)
            command->setInput(&iniFile.sections[i].entries[j].key);

            newContext->addCommand(command);
        };
        _contextChain.addContext(newContext, newContext->getName());
    }
}

void InputManager::onEvent(const std::shared_ptr<Event> event)
{
    _contextChain.processInput(event);
}

void InputManager::setContextStatus(std::string contextName, bool status)
{
    std::shared_ptr<InputContext> context = _contextChain.getContext(contextName);
    context->setStatus(status);
}
