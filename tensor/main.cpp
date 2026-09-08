#include <iostream>
#include "base/tensor.hpp"

using namespace std;
int main()
{
    Tensor t1({1, 2, 3}, {1, 3});
    Tensor t2({4, 0, 6}, {1, 3});

    Tensor t3 = t1 / t2;
    t3.print();

    cout << t3.shape();

    return 0;
}