#include <iostream>

#include "math_utils.h"

int main()
{
    int sum = add(10, 20);
    int product = multiply(10, 20);
    int difference = subtract(20, 10);

    std::cout << "difference: " << difference << std::endl;
    std::cout << "sum: " << sum << std::endl;
    std::cout << "product: " << product << std::endl;

    return 0;
}
