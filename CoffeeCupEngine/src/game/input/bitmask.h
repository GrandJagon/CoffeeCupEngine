#pragma once

#include <stdint.h>

// Class that represents the state of all pressed inputs, one bit represent one input
class Bitmask
{
    private:
        uint32_t _mask = 0;
    
    public:

        Bitmask() = default;

        // Returns the whole mask as 32 bits integer
        uint32_t getMask() const;

        inline void setMask(const Bitmask mask) {_mask = mask.getMask();};

        // Returns single bit at position
        bool getBit(unsigned int position);

        // Sets a single bite at position to state
        void setBit(unsigned int position, bool state);

        // Sets the whole mask to 0
        void clear();
};