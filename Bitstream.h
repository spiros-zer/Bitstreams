// Spyridon Zervos (c)


#pragma once

#include <vector>
#include <iostream>

class Bitstream
{
public:

    /** @brief Construct a new Bitstream object by converting the given Array to Binary
     * Data in the form of unit8_t. */
    template<std::size_t N>
    Bitstream(const double (&Obj2Data)[N]);

    Bitstream() = default;
    
    template<typename T>
    void AddData(T InData);
    
    /**
     * @brief Converts and Emplaces the Binary Data of the Bitstream to a std::vector 
     * of type T.
     * 
     * @tparam T The type to convert the Binary Data to.
     * @param OutVectorOfObjs Is populated by the converted Binary Data.
     */
    template<typename T>
    void Data2Obj(std::vector<T>& OutVectorOfObjs);

    void AddByte(const unsigned char& InBit);
    
    /******** GETTERS ********/

    std::vector<uint8_t> GetBitstream() const {return bitstream_;}

    /******** COSMETIC ********/
    
    void PrintBinary() const;

private:
    
    /** @brief Contains the Binary Data. */
    std::vector<uint8_t> bitstream_;
};

template<std::size_t N>
Bitstream::Bitstream(const double (&Obj2Data)[N])
{
    for (const double Num : Obj2Data)
    {
        const uint8_t* Data = (uint8_t *)&Num; // Conversion of double to uint8_t
        for (size_t Datum = 0; Datum < sizeof(Num); ++Datum) // Since the converted data is an array we iterate through it
        {
            bitstream_.emplace_back(Data[Datum]);
        }
    }
}

template<typename T>
void Bitstream::Data2Obj(std::vector<T>& OutVectorOfObjs)
{
    uint8_t *Data = bitstream_.data();
    for (size_t Offset = 0; Offset < bitstream_.size(); Offset += sizeof(T))
    {
        T Obj;
        memcpy(&Obj, Data + Offset, sizeof(T));
        OutVectorOfObjs.emplace_back(Obj);
    }
}

template<typename T>
void Bitstream::AddData(T InData)
{
    const uint8_t* Data = (uint8_t*)&InData; // Conversion of double to uint8_t
    for (size_t Datum = 0; Datum < sizeof(InData); ++Datum) // Since the converted data is an array we iterate through it
    {
        bitstream_.emplace_back(Data[Datum]);
    }
}
