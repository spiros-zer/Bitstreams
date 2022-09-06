// Spyridon Zervos (c)


#include "Bitstream.h"

void Bitstream::PrintBinary()
{
    short unsigned BitCounter{ 0 };
    std::cout << "Bit0\tBit1\tBit2\tBit3\tBit4\tBit5\tBit6\tBit7\n";
    for (uint8_t Byte : _bitstream)
    {
        std::cout << std::hex << static_cast<int>(Byte) << "\t";
        if (!(BitCounter >= 7 ? BitCounter = 0 : ++BitCounter))
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}