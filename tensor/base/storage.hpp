/*
This file handle the memory for storing and delete data.

Storage class is the owner of whole storage that store data in memory.
This file is directly connected to Tensor Class file for different operations.
*/

#pragma once
#include <vector>

using Scalar = float;
using Size = size_t;

using FloatVec = std::vector<Scalar>;
using IntVec = std::vector<int>;

class Storage
{
private:
    Scalar *data_ = nullptr; // set default data as null
    Size numel_ = 0; // set default numel to 0

public:
    // Storage class taking data as input to store it in the memory
    Storage(const FloatVec &input_data);
    ~Storage();

    const Scalar *data() const;

    Storage(const Storage &other);
    Storage &operator=(const Storage &other);

    Storage(Storage &&other);
    Storage &operator=(Storage &&other);
};