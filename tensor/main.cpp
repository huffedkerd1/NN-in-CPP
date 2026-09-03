#include <iostream>
#include "base/tensor.hpp"

using namespace std;
int main() {
    Tensor t1({1, 2, 3, 4, 5, 6}, {2, 3});
    t1.print();
    cout << t1.numel() << endl;

    Tensor t2 = t1;
    t2.print();
    cout << t2.numel() << endl;

    Tensor t3 = move(t1);
    t3.print();
    cout << t3.numel() << endl;

    cout << t1.numel() << endl;

    return 0;
}