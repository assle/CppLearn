#include <iostream>

void print_borrowed_score(const int* score_ptr) {
    if (score_ptr == nullptr) {
        std::cout << "score_ptr is nullptr\n";
        return;
    }

    std::cout << "borrowed score address: " << score_ptr << "\n";
    std::cout << "borrowed score value: " << *score_ptr << "\n";
}

void increase_borrowed_score(int* score_ptr) {
    if (score_ptr == nullptr) {
        return;
    }

    *score_ptr += 10;
}

void reset_borrowed_score(int& score_ref) {
    score_ref = 0;
}

int* create_owned_score(int value) {
    int* score_ptr = new int(value);
    return score_ptr;
}

void destroy_owned_score(int*& score_ptr) {
    delete score_ptr;
    score_ptr = nullptr;
}

int main() {
    int stack_score = 80;

    std::cout << "stack_score before borrow: " << stack_score << "\n";
    print_borrowed_score(&stack_score);

    reset_borrowed_score(stack_score);
    std::cout << "stack_score after reset: " << stack_score << "\n";

    int* heap_score = create_owned_score(80);
    std::cout << "heap_score address: " << heap_score << "\n";
    std::cout << "heap_score value: " << *heap_score << "\n";

    print_borrowed_score(heap_score);

    increase_borrowed_score(&stack_score);
    std::cout << "stack_score after increase: " << stack_score << "\n";

    increase_borrowed_score(heap_score);
    std::cout << "heap_score after increase: " << *heap_score << "\n";

    destroy_owned_score(heap_score);

    if (heap_score == nullptr) {
        std::cout << "heap_score has been destroyed\n";
    }

    print_borrowed_score(heap_score);
    increase_borrowed_score(heap_score);
    std::cout << "heap_score after nullptr increase: " << heap_score << "\n";

    return 0;
}
