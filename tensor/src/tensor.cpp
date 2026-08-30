#include "../base/tensor.hpp"

#include <stdexcept>
#include <iostream>


Tensor::Tensor(
    const FloatVec& input_data, 
    const Shape& shape) 
    :   shape_(shape), 
        numel_(1), 
        data_(nullptr)
    {

    for (Size i = 0; i < shape.size(); ++i){
        numel_ *= shape[i];
    }

    if (input_data.size() != numel_){
        throw std::invalid_argument("Shape mismatch");
    }

    data_ = new float[numel_];
    for (Size i = 0; i < numel_; ++i){
        data_[i] = input_data[i];
    }

    if (shape_.empty()){
        return;
    }

    stride_.resize(shape.size());

    int n = shape.size();

    stride_[n-1] = 1;

    for (Size i = n-1; i > 0; --i){
        stride_[i] = stride_[i+1] * shape[i+1];
    }
}

Tensor::~Tensor(){
    delete[] data_;
}

Size Tensor::numel() const{
    return numel_;
}

void Tensor::print() const{
    std::cout << "Tensor([";
    for (int i = 0; i < numel_; i++){
        if (i == numel_-1){
            std::cout << data_[i];
        }
        else{
            std::cout << data_[i] << ",";
        }
    }
    std::cout << "])";
}