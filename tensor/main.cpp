#include <iostream>
#include "base/broadcasting.hpp"
#include "base/tensor.hpp"
#include "base/broadcasting.hpp"

using namespace std;
int main()
{
    Shape a = {1, 2, 3};
    Shape b = {4,};

    Shape result = broadcasting::broadcast_shape(a, b);

    for (int dim : result){
        cout << dim << " ";
    }

    return 0;
}