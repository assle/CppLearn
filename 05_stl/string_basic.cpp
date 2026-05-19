#include <iostream>
#include <string>

void print_string_state(const std::string& text) {
    std::cout << "value: [" << text << "]"
              << ", size: " << text.size()
              << ", empty: " << std::boolalpha << text.empty()
              << std::endl;
}

int main() {
    std::string name = "luzhendong";
    std::string title = "computer science";

    std::cout << "After create strings" << std::endl;
    print_string_state(name);
    print_string_state(title);

    std::string profile = name + " - " + title;
    std::cout << "After concatenate" << std::endl;
    print_string_state(profile);

    profile += " C++";
    profile += " STL";
    std::cout << "After append" << std::endl;
    print_string_state(profile);

    std::cout << "First char: " << profile[0] << std::endl;
    std::cout << "Last char: " << profile[profile.size() - 1] << std::endl;

    std::size_t dash_pos = profile.find("-");
    if (dash_pos != std::string::npos) {
        std::cout << "Dash found at index: " << dash_pos << std::endl;
        std::string left = profile.substr(0, dash_pos - 1);
        std::string right = profile.substr(dash_pos + 2);
        std::cout << "Left part: " << left << std::endl;
        std::cout << "Right part: " << right << std::endl;
    }

    std::size_t cpp_pos = profile.find("C++");
    if (cpp_pos != std::string::npos) {
        std::cout << "C++ found at index: " << cpp_pos << std::endl;
    }

    if (profile == "luzhendong - computer science C++ STL") {
        std::cout << "Profile matches expected text" << std::endl;
    }

    std::string sub_str = profile.substr(0, 5);
    std::cout << sub_str << std::endl;

    return 0;
}

/*
练习1：
拼接后的profile发生了变化，size也变化了
练习3:
std::string::npos表示一个没找到的一个状态，如果比较以后不相等，说明找到了
如果没找到返回的是std::string::npos，不能把返回值当下标使用。npos 是 std::size_t 类型的特殊最大值，不是一个有效下标
练习5:
1.工程上std::string能自动管理内存的创建和释放，不需要手动去维护长度
2.因为std::string内部维护字符存储、字符串长度和结尾细节，使用者通常不用手动管理 '\0'
*/
