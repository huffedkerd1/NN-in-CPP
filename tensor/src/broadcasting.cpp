#include "../base/broadcasting.hpp"

// Are compatible function is to check is give tensors are compatible to broadcasting or not 

bool broadcasting::are_compatible(const Shape &shape_a, const Shape &shape_b)
{

    int a_index = shape_a.size() - 1;
    int b_index = shape_b.size() - 1;

    for (int i = a_index, j = b_index; i >= 0 || j >= 0; --i, --j)
    {

        if (i >= 0 && j >= 0)
        {

            if (shape_a[i] == shape_b[j] || shape_a[i] == 1 || shape_b[j] == 1)
            {
            }

            else
            {
                return false;
            }
        }

        else
        {
        }
    }

    return true;
}

/*
Broadcasting shape:
1. Check compatibility
2. If incompatible, throw exception
3. Calculate new shape
4. Return new shape
*/

Shape broadcasting::broadcast_shape(const Shape &a, const Shape &b)
{

    if (!are_compatible(a, b)){
        throw std::invalid_argument("Not Compatible");
    }

    Shape new_shape;
    new_shape.resize(std::max(a.size(), b.size()));

    for (int i = a.size() - 1, j = b.size() - 1, k = new_shape.size() - 1;
         i >= 0 || j >= 0 || k >= 0;
         --i, --j, --k)
    {

        if (i >= 0 && j >= 0)
        {
            if (a[i] == 1)
            {
                new_shape[k] = b[j];
            }
            else if (b[j] == 1)
            {
                new_shape[k] = a[i];
            }
            else if (a[i] == b[j])
            {
                new_shape[k] = a[i];
            }
        }
        else
        {
            if (i < 0)
            {
                new_shape[k] = b[j];
            }
            else if (j < 0)
            {
                new_shape[k] = a[i];
            }
        }
    }

    return new_shape;
}