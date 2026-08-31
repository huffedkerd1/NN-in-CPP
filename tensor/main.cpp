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

    Shape index = {1, 2};
    Scalar value = t.at(index);
    cout << value << endl;

    Tensor t2 = t;
    t2.print();

    Shape t2_shape = t2.shape();
    cout << t2_shape << endl;

    return 0;
}