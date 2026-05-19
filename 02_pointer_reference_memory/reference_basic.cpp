#include <iostream>

int main() {
    int score = 80;
    int level = 3;
    int backup_level = 1;

    int* score_ptr = &score;
    int& score_ref = score;
    int* level_ptr = &level;
    int& level_ref = level;

    std::cout << "score value: " << score << std::endl;
    std::cout << "score address: " << &score << std::endl;
    std::cout << "level value: " << level << std::endl;
    std::cout << "level_ref value: " << level_ref << std::endl;
    std::cout << "level address: " << &level << std::endl;
    std::cout << "level_ref address: " << &level_ref << std::endl;

    level_ref = 10;
    std::cout << "level after level_ref = 10: " << level << std::endl;

    std::cout << "score_ptr stores address: " << score_ptr << std::endl;
    std::cout << "value through score_ptr: " << *score_ptr << std::endl;

    std::cout << "score_ref value: " << score_ref << std::endl;
    std::cout << "score_ref address: " << &score_ref << std::endl;

    *score_ptr = 90;
    std::cout << "score after *score_ptr = 90: " << score << std::endl;

    score_ref = 95;
    std::cout << "score after score_ref = 95: " << score << std::endl;

    int another_score = 60;

    score_ptr = &another_score;
    std::cout << "score_ptr now points to another_score: " << *score_ptr << std::endl;

    score_ref = another_score;
    std::cout << "score after score_ref = another_score: " << score << std::endl;
    std::cout << "another_score after assignment: " << another_score << std::endl;

    level_ptr = &backup_level;
    level_ref = backup_level;

    std::cout << "value through level_ptr after pointing to backup_level: " << *level_ptr << std::endl;
    std::cout << "level after level_ref = backup_level: " << level << std::endl;
    std::cout << "backup_level after assignment: " << backup_level << std::endl;

    return 0;
}

/*
c1思考题：
指针变量保存了地址
p表示地址，*p表示地址指向的值
p指向了level的地址，修改这个地址的值会改变level的值
指针变量可以改为指向另一个变量

c2思考题：
已有变量的别名
因为相当于原有变量的别名，所以修改引用的值会改变原有变量的值
指针可以改
引用绑定以后不能改，只能修改值
是把值赋给原变量，而不是改变引用的绑定关系
*/
