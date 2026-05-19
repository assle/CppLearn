#include <iostream>

int main() {
    int score = 85;

    if (score >= 90) {
        std::cout << "grade: A" << std::endl;
    } else if (score >= 80) {
        std::cout << "grade: B" << std::endl;
    } else if (score >= 60) {
        std::cout << "grade: C" << std::endl;
    } else {
        std::cout << "grade: F" << std::endl;
    }

    return 0;
}
