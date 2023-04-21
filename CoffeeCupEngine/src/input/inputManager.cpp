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

    for(int i = 0; i < iniFile.sections.size(); i++)
    {
        std::cout << "Section : " << iniFile.sections[i].title << std::endl;

        for(int j = 0; j < iniFile.sections[i].entries.size(); j++)
        {
            std::cout << "Key : " << iniFile.sections[i].entries[j].key << std::endl;
            std::cout << "Value : " << iniFile.sections[i].entries[j].value << std::endl;
        }
    }


}

void InputManager::addContext(std::string contextName, std::shared_ptr<InputContext> context)
{
    
}

void InputManager::onEvent(const std::shared_ptr<Event> event)
{

}

