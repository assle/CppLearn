#include <iostream>

int* create_score(int value) {
    int* score_ptr = new int(value);
    return score_ptr;
}

int* create_level(int value) {
    int* level_ptr = new int(value);
    return level_ptr;
}

int main() {
    int* score_ptr = new int(80);
    int* level_ptr = new int(5);
    int* levels = new int[4]{1, 2, 3, 4};

    std::cout << "levels value:" << levels[0] << ", " << levels[1] << ", " << levels[2] << ", " << levels[3] << std::endl;
    delete[] levels;
    levels = nullptr;
    std::cout << "score_ptr stores address: " << score_ptr << std::endl;
    std::cout << "value on heap: " << *score_ptr << std::endl;
    std::cout << "level_ptr stores address: " << level_ptr << std::endl;
    std::cout << "value on heap: " << *level_ptr << std::endl;
    
    *level_ptr = 8;
    std::cout << "level value after change: " << *level_ptr << std::endl;
    *score_ptr = 95;
    std::cout << "value after change: " << *score_ptr << std::endl;

    delete level_ptr;
    level_ptr = nullptr;
    delete score_ptr;
    score_ptr = nullptr;

    std::cout << "score_ptr after delete: " << score_ptr << std::endl;

    int* created_score_ptr = create_score(100);

    std::cout << "created_score_ptr stores address: " << created_score_ptr << std::endl;
    std::cout << "created score value: " << *created_score_ptr << std::endl;

    delete created_score_ptr;
    created_score_ptr = nullptr;

    int* numbers = new int[3];
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    std::cout << "numbers[0]: " << numbers[0] << std::endl;
    std::cout << "numbers[1]: " << numbers[1] << std::endl;
    std::cout << "numbers[2]: " << numbers[2] << std::endl;

    delete[] numbers;
    numbers = nullptr;

    int* empty_ptr = nullptr;
    delete empty_ptr;

    int* created_level_ptr = create_level(3);
    std::cout << "created_level_ptr stores address: " << created_level_ptr << std::endl;
    std::cout << "created level value: " << *created_level_ptr << std::endl;

    delete created_level_ptr;
    created_level_ptr = nullptr;

    return 0;
}


// Dangerous examples. Do not run:
//
// int* p = new int(80);
// delete p;
// delete p; // double delete
//
// int* p = new int(80);
// // missing delete p; causes a memory leak
//
// int* arr = new int[3];
// delete arr; // should use delete[] arr
