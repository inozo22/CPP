#include <iostream>
#include <cstdint>

class Data {
public:
    // Non-empty Data structure with data members
    int value;

    Data(int val) : value(val) {}
};

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer() {}

public:
    // Serialize a pointer to uintptr_t
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    // Deserialize uintptr_t to a pointer
    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

int main() {
    // Create an instance of Data
    Data myData(42);

    // Use serialize on the address of the Data object
    uintptr_t serializedPtr = Serializer::serialize(&myData);

    // Use deserialize on the serialized pointer
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Ensure the return value of deserialize() compares equal to the original pointer
    if (deserializedPtr == &myData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
