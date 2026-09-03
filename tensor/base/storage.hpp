#pragma once
#include <vector>

using Scalar = float;
using Size = size_t;

using FloatVec = std::vector<Scalar>;
using IntVec = std::vector<int>;

class Storage
{
private:
    Scalar *data_ = nullptr;
    Size numel_ = 0;

public:
    Storage(const FloatVec &input_data);
    ~Storage();

    const Scalar *data() const;

    Storage(const Storage &other);
    Storage &operator=(const Storage &other);

    Storage(Storage &&other);
    Storage &operator=(Storage &&other);
};