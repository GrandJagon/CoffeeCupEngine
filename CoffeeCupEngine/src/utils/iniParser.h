#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

namespace INIParser
{
    struct Entry
    {
        std::string key;
        std::string value;
    };
    
    struct Section
    {
        std::string title;
        std::vector<Entry> entries;
    };

    struct INIFile
    {       
        std::vector<Section> sections; 
    };

    int parseFile(INIFile &file, std::string filePath)
    {   
        std::fstream fileStream;

        fileStream.open(filePath);

        if(!fileStream)
        {
            std::cout << "Cannot open file at " << filePath << " : " << std::strerror(errno) << std::endl;
            return -1;
        };

        std::string line;


        while(std::getline(fileStream, line))
        {
            if(line[0] == '#' || line.empty()) // comment
            {
                continue;
            };

            if(line[0] == '[') // section start
            {
                Section section;

                section.title = line.substr(1, (line.length() - 2));
                file.sections.push_back(section);
            ;
             
                continue;
            };

            int delimiter = line.find('=');

            if(delimiter == std::string::npos)
            {
                std::cout << "INI file malformed" << std::endl;
                return -1;
            };

            Section *currentSection = &file.sections[file.sections.size() - 1];
            
            Entry entry;
            entry.key = line.substr(0, delimiter);
            entry.value = line.substr(delimiter + 1, line.length() - 1);

            currentSection->entries.push_back(entry);
        };

        return 0;
    };

    int saveFile(INIFile& file, std::string filePath)
    {
        return 0;

    }

}