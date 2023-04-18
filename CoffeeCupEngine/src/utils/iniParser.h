#pragma once

#include <iostream>
#include <fstream>
#include <string>
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
            std::cout << "Cannot open file at " << filePath << " : " << strerror(errno) << std::endl;
            return -1;
        };

        std::cout << "File at " << filePath << " successfully opened" << std::endl;

        std::string line;

        Section section;

        while(std::getline(fileStream, line))
        {

            std::cout << line << std::endl;
            if(line[0] == '#' || line.empty()) // comment
            {
                continue;
            };

            if(line[0] == '[') // section start
            {
                section.title = line.substr(1, (line.length() - 2));
                file.sections.push_back(section);
                Section newSection;
                section = newSection;
                continue;
            }; 

            


        };

        return 0;
    };

    int saveFile(INIFile& file, std::string filePath)
    {
        return 0;

    }

}