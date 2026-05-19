#include <iostream>

int add(int left, int right);
int multiply(int left, int right);
void print_result(int value);

int main()
{
    int result = add(10, 20);
    print_result(result);
    result = multiply(10, 20);
    print_result(result);

    return 0;
}

int add(int left, int right)
{
    return left + right;
}

void print_result(int value)
{
    std::cout << "result: " << value << std::endl;
}

int multiply(int left, int right)
{
    return left * right;
}

// 因为函数声明和定义的顺序，编译器在编译 main 函数时已经知道了 add 和 print_result 的存在，所以能够正确地调用它们。而 multiply 函数虽然在 main 函数之后定义，但由于它在 main 函数之前被声明了，所以编译器也能够正确地调用它。
// 因为会导致文件内容的耦合，比如想要引入一些接口文件，但是这些接口函数在一个大文件中，我们引入他会引入全部的的函数，导致编译时间增加，甚至可能引入一些不必要的函数，增加了代码的复杂度和维护难度。通过函数声明，我们可以只引入需要的函数接口，减少了文件之间的耦合，提高了代码的可维护性和可读性。