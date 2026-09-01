/*
This file contain the complete blueprint of our tensor class.
In this file you can clearly see that how to maintain and develop professional code.
This framework Architecture is very easy to understand that how actually tensors are work.
*/

#pragma once
#include <vector>
#include <iostream>

// Making Type allises for better and professional way to code.
using Size = std::size_t;
using Scalar = float;

using FloatVec = std::vector<Scalar>;
using IntVec = std::vector<int>;
using Shape = std::vector<Size>;

std::ostream& operator<<(std::ostream& os, const Shape& shape);

// Our tensor class start from here.
class Tensor{
    /*
    Private Access Specifiers:
    shape, numel(total size), data(Owned memory by Tensors), stride
    */
    private:
        Shape shape_;
        Size numel_ = 1;
        Scalar* data_ = nullptr;
        Shape stride_;

    /*
    Public Access Specifiers:
    */
    public:
        
        Tensor(const FloatVec& input_data, const Shape& shape);
        ~Tensor();

        // Signatures.
        Size numel() const;
        void print() const;
        const Shape& shape() const;
        const Shape& stride() const;
        Scalar at(const Shape& indicies) const;

        // Copy Constructor.
        Tensor(const Tensor& other);

        // Copy Assignment.
        Tensor& operator= (const Tensor& other);
};