#include "../base/tensor.hpp"

#include <stdexcept>
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Shape& shape){
    os << "(";

    for (Size i = 0; i < shape.size(); ++i){
        os << shape[i];

        if (i + 1 < shape.size()){
            os << ", ";
        }
    }

    os << ")";

    return os;
}

/*
Constructor:
    In constructor we do following things:
    1. Input.
        a. Input data.
        b. Shape.

    2. Calculating.
        a. Calculate total size.
        b. Checking is total size match with the size of input data.
        c. Taking memory to store data init(Emty for now).
        d. Checking is shape empty or not.
        e. Calculating Stride.
*/
Tensor::Tensor(
    const FloatVec &input_data,
    const Shape &shape)
    : shape_(shape),
      numel_(1),
      data_(nullptr)
{
    // A. Calculating Total size (Numel).
    for (Size i = 0; i < shape_.size(); ++i)
    {
        numel_ *= shape_[i];
    }

    // B. Exception handling for shape.
    if (input_data.size() != numel_)
    {
        throw std::invalid_argument("Shape mismatch");
    }

    // C. Reserve memory for data, and store data in memory.
    data_ = new Scalar[numel_];
    for (Size i = 0; i < numel_; ++i)
    {
        data_[i] = input_data[i];
    }

    // D. No stride is required for empty shape.
    if (shape_.empty())
    {
        return;
    }

    // Save the shape of stride.
    stride_.resize(shape_.size());

    Size n = shape_.size();

    // E. Stride algorithm
    /*
    Stride[n] = 1
    Stride[i-1] = Stride[i] * Shape[i]
    */
    stride_[n - 1] = 1;

    for (Size i = n - 1; i > 0; --i)
    {
        stride_[i - 1] = stride_[i] * shape_[i];
    }
}
// Destructor: Free memory that we use for data when we close our object.
Tensor::~Tensor()
{
    delete[] data_;
}
// Numel: Getter for Total Size.
Size Tensor::numel() const
{
    return numel_;
}
// Print: Display tensor data in readable form.
void Tensor::print() const
{
    std::cout << "Tensor([";
    for (int i = 0; i < numel_; i++)
    {
        if (i == numel_ - 1)
        {
            std::cout << data_[i];
        }
        else
        {
            std::cout << data_[i] << ",";
        }
    }
    std::cout << "])" << std::endl;
}

const Shape &Tensor::shape() const
{
    return shape_;
}

const Shape& Tensor::stride() const {
    return stride_;
}