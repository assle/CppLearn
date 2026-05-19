#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

void print_tags(const std::set<std::string>& tags) {
    std::cout << "std::set tags:" << std::endl;

    for (const auto& tag : tags) {
        std::cout << "  " << tag << std::endl;
    }
}

void print_online_users(const std::unordered_set<std::string>& users) {
    std::cout << "std::unordered_set online users:" << std::endl;

    for (const auto& user : users) {
        std::cout << "  " << user << std::endl;
    }
}

int main() {
    std::set<std::string> tags;

    tags.insert("cpp");
    tags.insert("stl");
    tags.insert("memory");
    tags.insert("cpp");

    tags.insert("debug");
    tags.insert("compile");
    tags.insert("cpp");

    std::cout << "After insert tags" << std::endl;
    print_tags(tags);
    std::cout << "tags size: " << tags.size() << std::endl;

    auto cpp_it = tags.find("cpp");
    if (cpp_it != tags.end()) {
        std::cout << "cpp tag exists" << std::endl;
    }

    if (tags.find("network") == tags.end()) {
        std::cout << "network tag not found" << std::endl;
    }

    std::size_t removed_count = tags.erase("memory");
    std::cout << "removed memory count: " << removed_count << std::endl;
    print_tags(tags);

    std::unordered_set<std::string> online_users;
    online_users.insert("Alice");
    online_users.insert("Bob");
    online_users.insert("Charlie");
    online_users.insert("Alice");

    std::cout << "After insert online users" << std::endl;
    print_online_users(online_users);
    std::cout << "online user size: " << online_users.size() << std::endl;

    if (online_users.find("Bob") != online_users.end()) {
        std::cout << "Bob is online" << std::endl;
    }

    if (tags.find("stl") != tags.end()) {
        std::cout << "stl tag exists" << std::endl;
    }

    std::size_t removed_network_count = tags.erase("network");
    std::cout << "removed network count: " << removed_network_count << std::endl;

    online_users.insert("Diana");
    std::cout << "After insert Diana" << std::endl;
    print_online_users(online_users);
    std::cout << "online user size after Diana: " << online_users.size() << std::endl;

    return 0;
}

/*
练习1:
发生了变化
标签顺序按照自然排序

练习2:
没有变化
因为set是去重集合

练习4:
删除不存在的元素返回0
删除存在的元素返回删除的数量

练习5:
没有算两次
不一定等于插入顺序

练习6:
表示元素的类型
set是单元素集合，map是键值对集合
因为set底层约束了插入元素是去重的，而vector需要手动维护
*/
