#include <iostream>
#include "base/broadcasting.hpp"
#include "base/tensor.hpp"

using namespace std;
int main()
{
    Shape a = {2, 3};
    Shape b = {2, 3};

    cout << broadcasting::are_compatible(a, b);

    return 0;
}