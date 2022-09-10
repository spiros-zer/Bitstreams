// Spyridon Zervos (c)


#pragma once

#include <vector>
#include <iostream>

/**
 * @brief Converts data to binary data in the form of uint8_t.
 * 
 */
class Bitstream
{
private:

    /**
     * @brief Contains the Binary Data.
     * 
     */
    std::vector<uint8_t> _bitstream;

    /**
     * @brief The size of the Bitstream object. Equal to data() function of 
     * std::vector.
     * 
     */
    int _sizeOfBitstream = 0;

public:

    /**
     * @brief Construct a new Bitstream object by converting the given Array to Binary
     * Data in the form of unit8_t.
     * 
     * @tparam N the size of the input Array.
     */
    template<std::size_t N>
    Bitstream(const double (&Obj2Data)[N]);

    Bitstream();

    /**
     * @brief Get the Bitstream object.
     * 
     * @return std::vector<uint8_t> 
     */
    inline std::vector<uint8_t> GetBitstream()
    {
        return _bitstream;
    }

    /**
     * @brief Converts and Emplaces the Binary Data of the Bitstream to a std::vector 
     * of type T.
     * 
     * @tparam T The type to convert the Binary Data to.
     * @param OutVectorOfObjs Is populated by the converted Binary Data.
     */
    template<typename T>
    void Data2Obj(std::vector<T>& OutVectorOfObjs);

    /**
     * @brief Gets the SizeofBitstream object.
     * 
     * @return The number of bytes in the bitstream.
     */
    int GetSizeOfBitstream();

    /**
     * @brief Prints the contents of _bitstream field in hex.
     * 
     */
    void PrintBinary();

    template<typename T>
    void AddData(T Data);
};

template<std::size_t N>
Bitstream::Bitstream(const double (&Obj2Data)[N])
{
    for (const double Num : Obj2Data)
    {
        const uint8_t* Data = (uint8_t *)&Num; // Conversion of double to uint8_t
        for (size_t Datum = 0; Datum < sizeof(Num); ++Datum) // Since the converted data is an array we iterate through it
        {
            _bitstream.emplace_back(Data[Datum]);
            ++_sizeOfBitstream;
        }
    }
}

template<typename T>
void Bitstream::Data2Obj(std::vector<T>& OutVectorOfObjs)
{
    uint8_t *Data = _bitstream.data();
    for (size_t Offset = 0; Offset < _sizeOfBitstream; Offset += sizeof(T))
    {
        T Obj;
        memcpy(&Obj, Data + Offset, sizeof(T));
        OutVectorOfObjs.emplace_back(Obj);
    }
}

template<typename T>
inline void Bitstream::AddData(T Object)
{
    const uint8_t* Data = (uint8_t*)&Object; // Conversion of double to uint8_t
    for (size_t Datum = 0; Datum < sizeof(Object); ++Datum) // Since the converted data is an array we iterate through it
    {
        _bitstream.emplace_back(Data[Datum]);
        ++_sizeOfBitstream;
    }
}
