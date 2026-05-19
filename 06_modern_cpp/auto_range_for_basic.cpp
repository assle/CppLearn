#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Player {
    std::string name;
    int score;
    int level;
};

void print_scores_with_iterator(const std::vector<int>& scores) {
    std::cout << "iterator:";

    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;
}

void print_scores_with_range_for(const std::vector<int>& scores) {
    std::cout << "range for:";

    for (int score : scores) {
        std::cout << " " << score;
    }

    std::cout << std::endl;
}

void print_players(const std::vector<Player>& players) {
    for (const auto& player : players) {
        std::cout << player.name << ": " << player.score << "," << player.level << std::endl;
    }
}

int main() {
    std::vector<int> scores = {80, 90, 75};

    print_scores_with_iterator(scores);
    print_scores_with_range_for(scores);

    for (auto score : scores) {
        score += 10;
    }

    std::cout << "after auto value loop:";
    for (auto score : scores) {
        std::cout << " " << score;
    }
    std::cout << std::endl;

    for (auto& score : scores) {
        score += 10;
    }

    std::cout << "after auto reference loop:";
    for (const auto& score : scores) {
        std::cout << " " << score;
    }
    std::cout << std::endl;

    std::vector<Player> players = {
        {"Alice", 100, 3},
        {"Bob", 85, 2},
        {"Charlie", 92, 5},
    };

    std::cout << "players:" << std::endl;
    print_players(players);

    for (auto& player : players) {
        player.score += 5;
    }

    std::cout << "players after bonus:" << std::endl;
    print_players(players);

    std::map<std::string, int> name_to_score = {
        {"Alice", 105},
        {"Bob", 90},
        {"Charlie", 97},
    };

    std::cout << "map:" << std::endl;
    for (const auto& item : name_to_score) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

    for (auto& player : players) {
        player.level += 1;
    }

    std::cout << "players after level up:" << std::endl;
    print_players(players);

    return 0;
}

/*
练习答案写在这里：
练习1:
不是
表示当前位置的迭代器对象

练习2:
没有变化
因为是拷贝

练习3:
有变化
auto& 是引用，绑定到容器里的原元素；auto 让编译器推导被引用元素的具体类型

练习4:
已给 Player 增加 level，并在初始化和 print_players 中输出等级

练习5:
已使用 for (auto& player : players) 让所有玩家的 level 加 1
因为 player 是容器中原元素的引用，所以原来的 players 会被修改

练习6:
item.first是键，item.second是值
因为这里只读遍历 map，不需要修改键值对；const 防止误修改，引用避免复制键值对

练习7:
1.因为只读遍历时不应该修改元素，const 可以保护原对象；引用可以避免复制 Player 对象
2.因为需要修改容器中的原元素，auto& 会绑定到原元素，而不是创建副本
3.增加拷贝，影响内存和效率
*/
