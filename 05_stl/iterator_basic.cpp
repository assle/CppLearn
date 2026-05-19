#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

void print_vector_with_iterator(const std::vector<int>& scores) {
    std::cout << "vector by iterator:";

    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;
}

void add_bonus(std::vector<int>& scores, int bonus) {
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        *it += bonus;
    }
}

void print_set_with_iterator(const std::set<std::string>& tags) {
    std::cout << "set by iterator:";

    for (auto it = tags.begin(); it != tags.end(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;
}

void print_map_with_iterator(const std::map<std::string, int>& scores) {
    std::cout << "map by iterator:" << std::endl;

    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << "  " << it->first << " => " << it->second << std::endl;
    }
}

int main() {
    std::vector<int> scores = {90, 80, 70};
    scores.push_back(60);
    scores.push_back(100);

    print_vector_with_iterator(scores);
    add_bonus(scores, 10);
    print_vector_with_iterator(scores);

    auto first_score = scores.begin();
    if (first_score != scores.end()) {
        std::cout << "first score: " << *first_score << std::endl;
    }

    ++first_score;
    if (first_score != scores.end()) {
        std::cout << "second score: " << *first_score << std::endl;
    }

    std::set<std::string> tags = {"stl", "cpp", "iterator"};
    tags.insert("algorithm");
    print_set_with_iterator(tags);

    auto tag_it = tags.find("cpp");
    if (tag_it != tags.end()) {
        std::cout << "found tag: " << *tag_it << std::endl;
    }

    std::map<std::string, int> named_scores;
    named_scores["Alice"] = 95;
    named_scores["Bob"] = 88;
    named_scores["Charlie"] = 91;
    named_scores["Diana"] = 77;

    print_map_with_iterator(named_scores);

    auto bob_it = named_scores.find("Bob");
    if (bob_it != named_scores.end()) {
        std::cout << "Bob score before: " << bob_it->second << std::endl;
        bob_it->second += 2;
        std::cout << "Bob score after: " << bob_it->second << std::endl;
    }

    return 0;
}

/*
练习1:
可以输出新增元素
不需要知道有几个元素，直接用++it进行遍历即可

练习2:
是每个元素都增加了10
因为使用了迭代器啊，*it就是取对应位置上的元素

练习3:
表示将迭代器位置往下移一位
因为end表示集合最后位置的下一个位置，不能解引用

练习4:
输出顺序按照自然排序
因为set不是动态数组啊，是一个参照元素内容自然排序的集合，只能用迭代器

练习5:
会输出新的键值对
前者表示键，后者表示值

练习6:
begin表示集合开头位置的迭代器，end表示末尾的后一位
*it表示访问迭代器当前指向的元素，++it表示把迭代器移动到下一个位置
因为是末尾的后一位
因为在set和map中不能使用索引，所以用迭代器
*/
