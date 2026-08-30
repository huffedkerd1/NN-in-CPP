#pragma once
#include <vector>

using Size = std::size_t;
using Scalar = float;

using FloatVec = std::vector<Scalar>;
using Shape = std::vector<Size>;


class Tensor{
    private:
        Shape shape_;
        Size numel_ = 1;
        Scalar* data_ = nullptr;
        Shape stride_;
    public:
        Tensor(const FloatVec& input_data, const Shape& shape);
        ~Tensor();

        Size numel() const;
        void print() const;

        Tensor(const Tensor&) = delete;
        Tensor& operator = (const Tensor&) = delete;
};