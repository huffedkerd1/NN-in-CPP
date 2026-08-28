#include <iostream>
#include <vector>
#include "base/tensor.hpp"

int main(){
    vector<float> data = {1, 2, 3, 4, 5, 6};
    vector<int> shape = {2, 3};
    Tensor t(data, shape);

    int total = t.numel();
    cout<<total<<endl;
    t.print();
    return 0;
}