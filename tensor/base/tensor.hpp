/*
This file contain the complete blueprint of our tensor class.
In this file you can clearly see that how to maintain and develop professional code.
This framework Architecture is very easy to understand that how actually tensors are work.
*/

#pragma once
#include <vector>
#include <iostream>
#include <memory>

#include "storage.hpp"

// Making Type allises for better and professional way to code.
using Size = std::size_t;
using Scalar = float;
using Bool = bool;

using FloatVec = std::vector<Scalar>;
using IntVec = std::vector<int>;
using Shape = std::vector<Size>;

using Storage_ptr = std::shared_ptr<Storage>;

std::ostream &operator<<(std::ostream &os, const Shape &shape);

// Our tensor class start from here.
class Tensor
{
    /*
    Private Access Specifiers:
    shape, numel(total size), data(Owned memory by Tensors), stride
    */
private:
    Shape shape_;
    Size numel_ = 1;
    Storage_ptr storage_;
    Shape stride_;
    Size offset_ = 0;
    Bool is_view_ = false;
    Bool contiguous_ = true;

    /*
    Public Access Specifiers:
    */
public:
    Tensor(const FloatVec &input_data, const Shape &shape);
    Tensor(Storage_ptr storage, Shape shape, Size offset);
    ~Tensor();

    // Signatures.
    Size numel() const;
    void print() const;
    const Shape &shape() const;
    const Shape &stride() const;
    Scalar at(const Shape &indicies) const;
    Bool is_contiguous() const;

    Tensor slice(Size start, Size end) const;

    // Copy Constructor.
    Tensor(const Tensor &other);

    // Copy Assignment.
    Tensor &operator=(const Tensor &other);

    // Move Constructor.
    Tensor(Tensor &&other);

    // Move Assignment.
    Tensor &operator=(Tensor &&other);
};