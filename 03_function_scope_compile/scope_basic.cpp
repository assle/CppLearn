#include <iostream>

int global_count = 200;

void print_global_count()
{
    std::cout << "global_count in function: " << global_count << std::endl;
}

int main()
{
    int user_score = 88;
    int local_count = 10;

    std::cout << "user_score in main: " << user_score << std::endl;
    std::cout << "local_count in main: " << local_count << std::endl;
    std::cout << "global_count in main: " << global_count << std::endl;

    {
        int block_count = 20;
        std::cout << "block_count in block: " << block_count << std::endl;
        std::cout << "local_count in block: " << local_count << std::endl;
    }

    // std::cout << "block_count outside block: " << block_count << std::endl;

    print_global_count();

    return 0;
}


// local_count的作用域大于内部代码块，所以能在内部代码块中被访问；全局变量会遍及多个文件，如果在不同的文件中都使用到了这个同名的变量，可能会造成变量误用，甚至改变了某些重要的变量的值，造成不可逆的影响