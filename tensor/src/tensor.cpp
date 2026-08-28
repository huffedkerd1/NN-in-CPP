#include "../base/tensor.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

Tensor::Tensor(FloatVec input_data, IntVec shape){
    this->shape = shape;
    for (int i = 0; i < shape.size(); i++){
        total_size *= shape[i];
    }

    if (input_data.size() != total_size){
        throw invalid_argument("Shape mismatch");
    }

    data = new float[total_size];
    for (int i = 0; i < total_size; i++){
        data[i] = input_data[i];
    }
}

Tensor::~Tensor(){
    delete[] data;
}

int Tensor::numel(){
    return total_size;
}

void Tensor::print(){
    cout << "Tensor([";
    for (int i = 0; i < total_size; i++){
        if (i == total_size-1){
            cout << data[i];
        }
        else{
            cout << data[i] << ",";
        }
    }
    cout << "])";
}