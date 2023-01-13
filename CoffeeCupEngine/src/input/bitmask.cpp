#include "bitmask.h"

uint32_t Bitmask::getMask() const
{
    return _mask;
}

bool Bitmask::getBit(unsigned int position)
{   
    // 1 is shifted by position
    // result is ANDed with mask so the wanted bit is 1 if one in our mask and 0 if 0
    return (_mask & (1 << position) != 0);
}

void Bitmask::setBit(unsigned int position, bool state)
{
    if(state = 1)
    {
        // 1 is shifted by position
        // result is ORed with mask, the corresponding bit is then in any case flipped to 1
        _mask | (1 << position);
    } else if (state = 0) {

        // 1 is shifted by position
        // result is inverted so all bits but position are flipped to 1
        // result is ANDed with mask so only the wanted bit is flipped to 0
        _mask & ~(1 << position);
    }
}

void Bitmask::clear()
{
    _mask = 0;
}
