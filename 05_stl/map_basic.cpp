#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

void print_scores(const std::map<std::string, int>& scores) {
    std::cout << "std::map scores:" << std::endl;

    for (const auto& item : scores) {
        std::cout << "  " << item.first << " => " << item.second << std::endl;
    }
}

void print_config(const std::unordered_map<std::string, std::string>& config) {
    std::cout << "std::unordered_map config:" << std::endl;

    for (const auto& item : config) {
        std::cout << "  " << item.first << " => " << item.second << std::endl;
    }
}

int main() {
    std::map<std::string, int> scores;

    scores["Alice"] = 90;
    scores["Bob"] = 82;
    scores["Charlie"] = 95;
    scores["Diana"] = 91;
    

    std::cout << "After insert scores" << std::endl;
    print_scores(scores);

    scores["Bob"] = 88;
    std::cout << "After update Bob" << std::endl;
    print_scores(scores);

    scores["Charlie"] = 99;
    std::cout << "After update Charlie" << std::endl;
    print_scores(scores);

    std::string target_name = "Alice";
    auto alice_it = scores.find(target_name);
    if (alice_it != scores.end()) {
        std::cout << target_name << "'s score is " << alice_it->second << std::endl;
    }

    std::string missing_name = "David";
    auto david_it = scores.find(missing_name);
    if (david_it == scores.end()) {
        std::cout << missing_name << " not found" << std::endl;
    }

    std::string second_missing_name = "Eve";
    auto eve_it = scores.find(second_missing_name);
    if (eve_it == scores.end()) {
        std::cout << second_missing_name << " not found" << std::endl;
    }

    std::unordered_map<std::string, std::string> config;
    config["host"] = "127.0.0.1";
    config["port"] = "8080";
    config["mode"] = "debug";
    config["log_level"] = "info";

    std::cout << "After create config" << std::endl;
    print_config(config);

    if (config.find("mode") != config.end()) {
        std::cout << "mode: " << config["mode"] << std::endl;
    }

    std::cout << "scores size: " << scores.size() << std::endl;
    std::cout << "config size: " << config.size() << std::endl;

    std::cout << scores["Unknown"] << std::endl;
    std::cout << "scores size after Unknown: " << scores.size() << std::endl;

    return 0;
}

/*
练习1:：
出现了变化
名字顺序是根据键进行自然排序的

练习2:
不发生变化
因为不是新增元素，而是修改

练习4:
出现了变化
因为这相当于默认执行了插入的功能，但是我们的目标其实只有查找

练习5:
unordered_map的遍历顺序不保证等于插入顺序，本次输出只是当前实现和数据下的结果
选map

练习6:
前者表示键，后者表示值
表示没有找到键
因为operator[]在没有元素的时候会默认创建新元素
*/
