#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) {
        std::cout << "for i = " << i << std::endl;
    }

    int count = 1;
    while (count <= 3) {
        std::cout << "while count = " << count << std::endl;
        count++;
    }

    return 0;
}
