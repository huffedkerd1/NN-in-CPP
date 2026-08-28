#pragma once
#include <vector>

using namespace std;

using FloatVec = vector<float>;
using IntVec = vector<int>;


class Tensor{
    private:
        IntVec shape;
        int total_size = 1;
        float* data;
    public:
        Tensor(FloatVec input_data, IntVec shape);
        ~Tensor();

        int numel();
        void print();

        Tensor(const Tensor&) = delete;
        Tensor& operator = (const Tensor&) = delete;
};