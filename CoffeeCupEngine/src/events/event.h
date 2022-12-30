#pragma once

class Event 
{
    public:
        virtual ~Event() = default;
    
    protected:
        int type;
}