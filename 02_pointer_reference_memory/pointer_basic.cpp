#include <iostream>

int main() {
    int score = 80;
    int level = 3;

    std::cout << "score value: " << score << std::endl;
    std::cout << "level value: " << level << std::endl;
    std::cout << "score address: " << &score << std::endl;
    std::cout << "level address: " << &level << std::endl;

    int* score_ptr = &score;
    int* level_ptr = &level;

    std::cout << "score_ptr stores address: " << score_ptr << std::endl;
    std::cout << "value through score_ptr: " << *score_ptr << std::endl;
    std::cout << "level_ptr stores address: " << level_ptr << std::endl;
    std::cout << "value through level_ptr: " << *level_ptr << std::endl;

    *score_ptr = 95;
    *level_ptr = 10;

    std::cout << "score after *score_ptr = 95: " << score << std::endl;
    std::cout << "level after *level_ptr = 10: " << level << std::endl;

    int another_score = 60;
    int backup_level = 1;
    score_ptr = &another_score;
    level_ptr = &backup_level;

    std::cout << "score_ptr now stores another_score address: " << score_ptr << std::endl;
    std::cout << "value through score_ptr now: " << *score_ptr << std::endl;
    std::cout << "level_ptr now stores backup_level address: " << level_ptr << std::endl;
    std::cout << "value through level_ptr now: " << *level_ptr << std::endl;

    return 0;
}
