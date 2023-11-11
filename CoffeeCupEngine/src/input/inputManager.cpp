#include "CCEnginePrecompiled.h"
#include "inputManager.h"

#include "utils/iniParser.h"

void InputManager::init(const std::string inputMappingFile)
{
    loadInputMapping(inputMappingFile);
}

const void InputManager::loadInputMapping(const std::string filePath)
{
    INIParser::INIFile iniFile;
    INIParser::parseFile(iniFile, filePath); // loads file content to file

    CommandFactory factory; // STATIC ?

    for (unsigned int i = 0; i < iniFile.sections.size(); i++)
    {
        auto newContext = std::make_shared<InputContext>();
        newContext->setName(iniFile.sections[i].title);

        for (unsigned int j = 0; j < iniFile.sections[i].entries.size(); j++)
        {
            auto command = factory.createCommand(iniFile.sections[i].entries[j].value);
            // & -> NOT SAFE, TO CHANGE LATER BY IMPLEMENTING POLYMORPHISM (INPUT CAN BE OF SEVERAK TYPES BUT RIGHT NOW JUST LOADING COMMAND NAME FROM INI FILE IS FINE)
            command->setInput(&iniFile.sections[i].entries[j].key);

            newContext->addCommand(command);
        };
        _contextChain.addContext(newContext, newContext->getName());
    }
}

void InputManager::onEvent(const std::shared_ptr<Event> event)
{
}
