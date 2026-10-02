#include "../base/broadcasting.hpp"

bool broadcasting::are_compatible(const Shape& shape_a, const Shape& shape_b){

    int a_index = shape_a.size() - 1;
    int b_index = shape_b.size() - 1;

    for (int i = a_index, j = b_index; i >= 0 || j >= 0; --i, --j){

        if (i >= 0 && j >= 0){

            if (shape_a[i] == shape_b[j] || shape_a[i] == 1 || shape_b[j] == 1){}

            else {
                return false;
            }
        }

        else{

        }

    }

    return true;

}