#include <iostream>
#include <vector>
#include "base/tensor.hpp"

using namespace std;

int main()
{
    FloatVec data = {1, 2, 3, 4, 5, 6};
    Shape shape = {2, 3};

    Tensor t(data, shape);

    int total = t.numel();
    cout << total << endl;
    t.print();

    Shape t_shape = t.shape();
    cout << t_shape << endl;

    Shape t_stride = t.stride();
    cout << t_stride << endl;
    return 0;
}