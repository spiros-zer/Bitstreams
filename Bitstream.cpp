// Spyridon Zervos (c)


#include "Bitstream.h"

void Bitstream::AddByte(const unsigned char& InBit)
{
    bitstream_.emplace_back(InBit);
}

void Bitstream::PrintBinary() const
{
    short unsigned BitCounter{ 0 };
    std::cout << "Byte0\tByte1\tByte2\tByte3\tByte4\tByte5\tByte6\tByte7\n";
    for (const uint8_t Byte : bitstream_)
    {
        std::cout << std::hex << static_cast<int>(Byte) << "\t\t";
        if (!(BitCounter >= 7 ? BitCounter = 0 : ++BitCounter))
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}
