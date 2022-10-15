# BitstreamsLibrary
### BitstreamsLibrary Converts data to binary data in the form of uint8_t. ###
The library is templated, but currently only array of doubles is supported.

### Methods ###
```
+ Construct a new Bitstream object by converting the given Array to Binary Data in the form of unit8_t.
+ Get the Bitstream object.
+ Converts and Emplaces the Binary Data of the Bitstream to a std::vector of type T.
+ Prints the contents of _bitstream field in hex.
```
### Conclusions ###
**(Templates)** When templating a class the compiler needs ALL of the definitions inside the .h file **and based on what editor you use, it may be necessary to include the non templated ones as well**. During compilation the template constructor is instantiated, but since no implementation of the instance is present in the BitstreamsLibrary.h or BitstreamsLibraryTest.cpp (containing the main{} function) the linker can't link the implementation contained in BitstreamsLibrary.cpp and thus producing Undefined Reference error. More info can be found [here](https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor).

**(Data type conversion)** The quickest and most reliable way to convert an object to binary data is using the classic c-style cast (see l72 in BitstreamLibrary.h). For binary data to object the memcpy seems to be the best one yet.
