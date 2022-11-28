#pragma once
#include "../../utils/utilities.h"


class Texture
{
    private:
        unsigned int _id;

        // index assigned byt textureManager, -1 if not bound
        int _index = -1;
        std::string _filePath;
        int _width, _height, _bitsPerPixel;

    public:
        // File init
        Texture(unsigned int &id, std::string filePath,  int width, int height, int bitsPerPixel)
            : _id(id), _filePath(filePath), _width(width), _height(height), _bitsPerPixel(bitsPerPixel) {};

        // Color init  
        Texture(unsigned int id, int width, int height, int bitsPerPixel)
            : _id(id), _width(width), _height(height), _bitsPerPixel(bitsPerPixel) {};


        ~Texture();

        inline const int getWidth() {return _width;}
        inline const int getHeight() {return _height;}
        inline const unsigned int getId() {return _id;}

        inline const int getIndex() {return _index;}
        inline void setIndex(const int index) {_index = index;};

};