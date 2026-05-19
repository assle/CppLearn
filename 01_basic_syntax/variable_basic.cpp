#include <iostream>
#include <string>

int main() {
    int age = 20;
    double height = 1.75;
    char grade = 'A';
    bool is_student = true;
    std::string name = "Cpp learner";
    int year = 2026;

    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "grade: " << grade << std::endl;
    std::cout << "year: " << year << std::endl;
    std::cout << "is_student: " << is_student << std::endl;

    age = 21;
    std::cout << "new age: " << age << std::endl;

    return 0;
}
