#include "../../base/tensor.hpp"

Tensor Tensor::operator+(const Tensor &other) const
{
    if (this->shape_ != other.shape_)
    {
        throw std::invalid_argument("Shape mismatch");
    }

    FloatVec Added_values;
    Added_values.resize(this->numel_);

    for (Size i = 0; i < this->numel_; ++i)
    {
        Added_values[i] = this->storage_->data()[i] + other.storage_->data()[i];
    }

    Tensor Final_values(Added_values, this->shape_);
    return Final_values;
}

Tensor Tensor::operator-(const Tensor &other) const
{
    if (this->shape_ != other.shape_)
    {
        throw std::invalid_argument("Shape mismatch");
    }

    FloatVec Subtracted_values;
    Subtracted_values.resize(this->numel_);

    for (Size i = 0; i < this->numel_; ++i)
    {
        Subtracted_values[i] = this->storage_->data()[i] - other.storage_->data()[i];
    }

    Tensor Final_values(Subtracted_values, this->shape_);
    return Final_values;
}

Tensor Tensor::operator*(const Tensor &other) const
{
    if (this->shape_ != other.shape_)
    {
        throw std::invalid_argument("Shape mismatch");
    }

    FloatVec Mul_values;
    Mul_values.resize(this->numel_);
    
    for (Size i = 0; i < this->numel_; ++i)
    {
        Mul_values[i] = this->storage_->data()[i] * other.storage_->data()[i];
    }

    Tensor Final_values(Mul_values, this->shape_);
    return Final_values;
}

Tensor Tensor::operator/(const Tensor &other) const
{
    if (this->shape_ != other.shape_)
    {
        throw std::invalid_argument("Shape mismatch");
    }

    FloatVec Div_values;
    Div_values.resize(this->numel_);

    for (Size i = 0; i < this->numel_; ++i)
    {
        if (other.storage_->data()[i] == 0)
        {
            Div_values[i] = INF;
            continue;
        }

        Div_values[i] = this->storage_->data()[i] / other.storage_->data()[i];
    }

    Tensor Final_values(Div_values, this->shape_);
    return Final_values;
}