#include "../base/tensor.hpp"

#include <stdexcept>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Shape &shape)
{
    os << "(";

    for (Size i = 0; i < shape.size(); ++i)
    {
        os << shape[i];

        if (i + 1 < shape.size())
        {
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
      storage_(std::make_shared<Storage>(input_data))
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
    for (Size i = 0; i < numel_; i++)
    {
        if (i == numel_ - 1)
        {
            std::cout << storage_->data()[i];
        }
        else
        {
            std::cout << storage_->data()[i] << ",";
        }
    }
    std::cout << "])" << std::endl;
}

// Getter: return shape
const Shape &Tensor::shape() const
{
    return shape_;
}
// Getter: return stride
const Shape &Tensor::stride() const
{
    return stride_;
}

// Getter: To access value by index
Scalar Tensor::at(const Shape &indices) const
{
    if (indices.size() != shape_.size())
    {
        throw std::invalid_argument("Shape mismatch");
    }

    for (Size i = 0; i < shape_.size(); ++i)
    {
        if (indices[i] >= shape_[i])
        {
            throw std::out_of_range("List index out of range");
        }
    }

    Size flat_index = 0;
    for (Size i = 0; i < stride_.size(); ++i)
    {
        flat_index += indices[i] * stride_[i];
    }

    Scalar target_value = storage_->data()[flat_index];

    return target_value;
}

// Copy Constructor.
Tensor::Tensor(const Tensor &other)
    : shape_(other.shape_),
      numel_(other.numel_),
      stride_(other.stride_),
      storage_(other.storage_)
{

}

// Copy Assignment.
Tensor &Tensor::operator=(const Tensor &other)
{

    if (this == &other)
    {
        return *this;
    }

    this->shape_ = other.shape_;
    this->numel_ = other.numel_;
    this->stride_ = other.stride_;
    this->storage_ = other.storage_;

    return *this;
}

// Move Constructor.
Tensor::Tensor(Tensor &&other)
    : shape_(other.shape_),
      numel_(other.numel_),
      stride_(other.stride_),
      storage_(std::move(other.storage_))
{
    other.numel_ = 0;
}

// Move Assignment.
Tensor &Tensor::operator=(Tensor &&other)
{
    if (this == &other)
    {
        return *this;
    }


    this->shape_ = other.shape_;
    this->numel_ = other.numel_;
    this->stride_ = other.stride_;
    this->storage_ = std::move(other.storage_);

    other.numel_ = 0;

    return *this;
}