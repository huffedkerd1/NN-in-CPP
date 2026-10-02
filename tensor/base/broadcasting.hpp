#ifndef BROADCASTING_HPP
#define BROADCASTING_HPP

#include "tensor.hpp"

namespace broadcasting{
    bool are_compatible(const Shape& shape_a, const Shape& shape_b);
}

#endif