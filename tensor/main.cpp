#include <iostream>
#include "base/tensor.hpp"

using namespace std;
int main() {
    FloatVec data = {1, 2, 3, 4, 5, 6};
    Shape shape = {2, 3};

    Tensor t1(data, shape);
    t1.print();

    // Tensor t2 = t1.slice(3, 6);y
    // t2.print();

    // Tensor t3 = t2.slice(1, 3);
    // t3.print();

    return 0;
}