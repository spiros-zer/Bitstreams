#include "BitstreamsLibrary.h"

int main(int argc, char** argv)
{
    double DoubleArray[] = {-1, 0, 0.5, 1, 2, 3, 4, 5, 6, 7, 10, 1024};
    Bitstream Bits{DoubleArray};
    std::vector<double> Nums;

    std::cout << "Binary data contained in Bits:\n";
    Bits.PrintBinary();

    Bits.Data2Obj(Nums);
    std::cout << "Conversion of binary data to double yields the following:\n";
    for (const double& Num : Nums)
    {
        std::cout << Num << " ";
    }
    std::cout << std::endl;

    return 0;
}
