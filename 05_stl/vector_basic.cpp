#include <iostream>
#include <vector>

void print_vector_state(const std::vector<int>& scores) {
    std::cout << "size: " << scores.size()
              << ", capacity: " << scores.capacity()
              << ", values:";

    for (int score : scores) {
        std::cout << " " << score;
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> scores;

    std::cout << "After create vector" << std::endl;
    print_vector_state(scores);

    scores.push_back(90);
    std::cout << "After push 90" << std::endl;
    print_vector_state(scores);

    scores.push_back(80);
    std::cout << "After push 80" << std::endl;
    print_vector_state(scores);

    scores.push_back(70);
    std::cout << "After push 70" << std::endl;
    print_vector_state(scores);

    std::cout << "First score: " << scores[0] << std::endl;
    std::cout << "Last score: " << scores[scores.size() - 1] << std::endl;

    scores[1] = 85;
    std::cout << "After change second score" << std::endl;
    print_vector_state(scores);

    scores.push_back(88);
    scores.push_back(76);
    print_vector_state(scores);

    scores[0] = 100;
    std::cout << "After change first score" << std::endl;
    print_vector_state(scores);

    return 0;
}

/*
练习2:
因为vector就是一个可变数组，支持随机存取
会出现索引越界
练习3:
size和capacity不会总是相等。在刚创建的时候可能相等，但是进行扩容以后会按一定的规则增加容量。一个表示当前的数据量，一个表示当前的容量。
说明vector内部做了扩容
练习4:
使用new的时候，由创建者自己负责释放内存
因为vector内部自动管理了内存的创建和释放，所以不需要手动delete，这也是为什么现代C++规范推荐用vector的方式创建动态数组。
*/
