#include <iostream>


void reset_by_value(int value){
    value = 0;
    std::cout << "inside reset_by_value: " << value << std::endl;
}
void reset_by_pointer(int* value_ptr) {
    *value_ptr = 0;
    std::cout << "inside reset_by_pointer: " << *value_ptr << std::endl;
}
void reset_by_reference(int& value_ref) {
    value_ref = 0;
    std::cout << "inside reset_by_reference: " << value_ref << std::endl;
}
void add_by_value(int value) {
    value = value + 10;
    std::cout << "inside add_by_value: " << value << std::endl;
}

void add_by_pointer(int* value_ptr) {
    *value_ptr = *value_ptr + 10;
    std::cout << "inside add_by_pointer: " << *value_ptr << std::endl;
}

void add_by_reference(int& value_ref) {
    value_ref = value_ref + 10;
    std::cout << "inside add_by_reference: " << value_ref << std::endl;
}

void swap_by_reference(int& left, int& right){
    int temp = left;
    left = right;
    right = temp;
}

int main() {
    int score = 80;
    int level = 5;
    int a = 10;
    int b = 20;

    std::cout << "before swap_by_reference: a = " << a << ", b = " << b << std::endl;
    swap_by_reference(a, b);
    std::cout << "after swap_by_reference: a = " << a << ", b = " << b << std::endl;

    std::cout << "before add_by_value: " << score << std::endl;
    add_by_value(score);
    std::cout << "after add_by_value: " << score << std::endl;

    std::cout << "before add_by_pointer: " << score << std::endl;
    add_by_pointer(&score);
    std::cout << "after add_by_pointer: " << score << std::endl;

    std::cout << "before add_by_reference: " << score << std::endl;
    add_by_reference(score);
    std::cout << "after add_by_reference: " << score << std::endl;

    std::cout << "before reset_by_value: " << level << std::endl;
    reset_by_value(level);
    std::cout << "after reset_by_value: " << level << std::endl;

    level = 5; // reset level to 5
    std::cout << "before reset_by_pointer: " << level << std::endl;
    reset_by_pointer(&level);
    std::cout << "after reset_by_pointer: " << level << std::endl;

    level = 5; // reset level to 5
    std::cout << "before reset_by_reference: " << level << std::endl;
    reset_by_reference(level);
    std::cout << "after reset_by_reference: " << level << std::endl;

    return 0;
}
