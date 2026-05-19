#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print_scores(const std::vector<int>& scores) {
    std::cout << "scores:";

    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;
}

void print_names(const std::vector<std::string>& names) {
    std::cout << "names:";

    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> scores = {88, 75, 100, 75, 92};

    std::cout << "before sort" << std::endl;
    print_scores(scores);

    std::sort(scores.begin(), scores.end());

    std::cout << "after sort" << std::endl;
    print_scores(scores);

    auto found_score = std::find(scores.begin(), scores.end(), 66);
    if (found_score != scores.end()) {
        std::cout << "found score: " << *found_score << std::endl;
    } else {
        std::cout << "score not found" << std::endl;
    }

    int seventy_five_count = std::count(scores.begin(), scores.end(), 75);
    std::cout << "75 count: " << seventy_five_count << std::endl;

    std::vector<std::string> names = {"Charlie", "Alice", "Bob", "Alice"};
    names.push_back("Diana");
    names.push_back("Bob");

    std::cout << "before name sort" << std::endl;
    print_names(names);

    std::sort(names.begin(), names.end());

    std::cout << "after name sort" << std::endl;
    print_names(names);

    auto alice_it = std::find(names.begin(), names.end(), "Alice");
    if (alice_it != names.end()) {
        std::cout << "found name: " << *alice_it << std::endl;
    }

    int alice_count = std::count(names.begin(), names.end(), "Alice");
    std::cout << "Alice count: " << alice_count << std::endl;

    return 0;
}

/*
练习答案写在这里：
练习1:
发生了变化
std::sort 修改了原来的 vector，因为元素顺序发生在 scores 自己身上

练习2:
排序默认从小到大
重复的75不会丢失

练习3:
找到时能解引用
没找到时，find 返回 scores.end()，不能解引用

练习4:
返回2
返回0

练习5:
按自然排序的顺序
找到的是第一个匹配的项
能统计重复的名字

练习6:
因为 begin/end 可以表示任意一段范围，也让算法不依赖某一种具体容器
std::find 找不到时返回传入的结束迭代器，也就是 end()
因为 end() 不指向有效元素，直接解引用会产生未定义行为
std::sort 会修改原容器；std::find 和 std::count 不会修改原容器
标准算法比手写循环更直观，能表达意图，也能减少重复代码和边界错误
*/
