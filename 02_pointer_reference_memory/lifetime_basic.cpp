#include <iostream>

void print_stack_variable() {
    int local_score = 80;

    std::cout << "inside function local_score value: " << local_score << std::endl;
    std::cout << "inside function local_score address: " << &local_score << std::endl;
}

int create_score_by_value() {
    int local_score = 90;
    return local_score;
}

int* create_score_on_heap() {
    int* heap_score = new int(100);
    return heap_score;
}

int create_level_by_value() {
    int local_level = 6;
    return local_level;
}

int* create_level_on_heap() {
    int* heap_level = new int(7);
    return heap_level;
}

int main() {
    int main_score = 70;
    int level = 5;


    std::cout << "main_score value: " << main_score << std::endl;
    std::cout << "main_score address: " << &main_score << std::endl;
    std::cout << "level value: " << level << std::endl;
    std::cout << "level address: " << &level << std::endl;

    print_stack_variable();

    int returned_score = create_score_by_value();
    std::cout << "returned_score value: " << returned_score << std::endl;
    std::cout << "returned_score address: " << &returned_score << std::endl;

    int returned_level = create_level_by_value();
    std::cout << "returned_level value: " << returned_level << std::endl;
    std::cout << "returned_level address: " << &returned_level << std::endl;

    int* heap_score_ptr = create_score_on_heap();
    std::cout << "heap_score_ptr stores address: " << heap_score_ptr << std::endl;
    std::cout << "value on heap: " << *heap_score_ptr << std::endl;

    delete heap_score_ptr;
    heap_score_ptr = nullptr;

    std::cout << "heap_score_ptr after delete: " << heap_score_ptr << std::endl;

    int* heap_level_ptr = create_level_on_heap();
    std::cout << "heap_level_ptr stores address: " << heap_level_ptr << std::endl;
    std::cout << "value on heap: " << *heap_level_ptr << std::endl;

    delete heap_level_ptr;
    heap_level_ptr = nullptr;

    std::cout << "heap_level_ptr after delete: " << heap_level_ptr << std::endl;

    return 0;
}

// Dangerous example. Do not write it as runnable code:
//
// int* bad_create_level() {
//     int local_level = 6;
//     return &local_level;
// }
//
// local_level is a stack local variable. It is destroyed when the function
// returns, so the returned address no longer points to a valid int object.
// Dereferencing that address would be undefined behavior.
