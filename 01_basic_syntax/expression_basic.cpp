#include <iostream>

int main() {
    int a = 10;
    int b = 3;

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    bool is_greater = a > b;
    bool is_equal = a == b;

    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << difference << std::endl;
    std::cout << "a * b = " << product << std::endl;
    std::cout << "a / b = " << quotient << std::endl;
    std::cout << "a % b = " << remainder << std::endl;
    std::cout << "a > b: " << is_greater << std::endl;
    std::cout << "a == b: " << is_equal << std::endl;

    return 0;
}
