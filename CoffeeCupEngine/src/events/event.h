#pragma once

class Event 
{
    public:
        virtual ~Event() = default;
        int type;
};