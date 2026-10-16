#include <iostream>
#include "base/broadcasting.hpp"
#include "base/tensor.hpp"
#include "base/broadcasting.hpp"

using namespace std;
int main()
{
    Tensor A({1, 2, 3}, {3});
    A.expand({2, 3});

    return 0;
}