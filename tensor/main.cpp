#include <iostream>
#include "base/tensor.hpp"

using namespace std;
int main()
{
    Tensor t1({1,2,3,4,5, 6,7,8,9,10, 11,12,13,14,15, 16,17,18,19,20}, {4,5});
    Tensor sliced = t1.slice({1, 1}, {3, 4});

    sliced.print();

    return 0;
}