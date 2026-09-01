#include <iostream>
#include <vector>
#include "base/tensor.hpp"

using namespace std;

int main()
{
    FloatVec data = {1, 2, 3, 4, 5, 6};
    Shape shape = {2, 3};

    Tensor t1(data, shape);
    t1.print();

    Tensor t2 = move(t1);
    t2.print();

    t1.print();

    return 0;
}