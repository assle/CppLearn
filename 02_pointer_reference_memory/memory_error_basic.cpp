#include <iostream>

int* create_heap_score(int value) {
    int* score_ptr = new int(value);
    return score_ptr;
}

void safe_delete(int*& ptr) {
    delete ptr;
    ptr = nullptr;
}

int main() {
    int* score_ptr = create_heap_score(80);
    int* level_ptr = create_heap_score(60);

    std::cout << "level_value:" << *level_ptr << std::endl;
    std::cout << "level_address:" << level_ptr << std::endl;

    safe_delete(level_ptr);
    if(level_ptr == nullptr){
        std::cout << "level_ptr is nullptr after delete" << std::endl;
    }

    std::cout << "score_ptr stores address: " << score_ptr << std::endl;
    std::cout << "score value: " << *score_ptr << std::endl;

    safe_delete(score_ptr);

    if (score_ptr == nullptr) {
        std::cout << "score_ptr is nullptr after delete" << std::endl;
    }

    int stack_score = 90;
    int* stack_score_ptr = &stack_score;

    std::cout << "stack_score value through pointer: " << *stack_score_ptr << std::endl;

    stack_score_ptr = nullptr;

    if (stack_score_ptr == nullptr) {
        std::cout << "stack_score_ptr no longer points to stack_score" << std::endl;
    }

    return 0;
}

// Dangerous examples. Do not run:
//
// 1. Wild pointer:
// int* p;
// *p = 10;
//
// p is uninitialized. It does not reliably point to a valid int object.
// Dereferencing it may crash the program, corrupt data, or appear to work
// while still being undefined behavior.
//
// 2. Dangling pointer after delete:
// int* p = new int(80);
// delete p;
// *p = 90;
//
// The heap object is already destroyed. p may still store the old address,
// but that address no longer represents a valid int object.
//
// 3. Dangling pointer to a local variable:
// int* bad_create_score() {
//     int local_score = 80;
//     return &local_score;
// }
//
// local_score is destroyed when the function returns, so the returned address
// no longer points to a valid object.
//
// 4. Memory leak:
// int* p = new int(80);
// p = new int(90);
//
// The address of the first heap object is lost before delete.
