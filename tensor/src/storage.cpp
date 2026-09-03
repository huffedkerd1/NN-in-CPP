#include "../base/storage.hpp"

#include <vector>

Storage::Storage(
    const FloatVec &input_data)
    : data_(nullptr),
      numel_(0)
{
    numel_ = input_data.size();

    data_ = new Scalar[numel_];
    for (Size i = 0; i < numel_; ++i)
    {
        data_[i] = input_data[i];
    }
}

Storage::~Storage()
{
    delete[] data_;
}

const Scalar *Storage::data() const
{
    return data_;
}

Storage::Storage(const Storage &other)
    : numel_(other.numel_)
{
    data_ = new Scalar[numel_];

    for (Size i = 0; i < numel_; ++i)
    {
        data_[i] = other.data_[i];
    }
}

Storage &Storage::operator=(const Storage &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] data_;

    this->numel_ = other.numel_;

    data_ = new Scalar[numel_];

    for (Size i = 0; i < numel_; ++i)
    {
        data_[i] = other.data_[i];
    }

    return *this;
}

Storage::Storage(Storage &&other)
    : numel_(other.numel_),
      data_(other.data_)
{
    other.data_ = nullptr;
    other.numel_ = 0;
}

Storage &Storage::operator=(Storage &&other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] data_;

    this->numel_ = other.numel_;
    this->data_ = other.data_;

    other.data_ = nullptr;
    other.numel_ = 0;

    return *this;
}