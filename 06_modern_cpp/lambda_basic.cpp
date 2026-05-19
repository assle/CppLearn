#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string name;
    int score;
    int hp;
};

void print_players(const std::vector<Player>& players) {
    for (const auto& player : players) {
        std::cout << player.name
                  << " score: " << player.score
                  << " hp: " << player.hp
                  << std::endl;
    }
}

int main() {
    std::vector<Player> players = {
        {"Alice", 90, 70},
        {"Bob", 75, 95},
        {"Charlie", 88, 60},
        {"Diana", 95, 85},
    };

    std::cout << "original players:" << std::endl;
    print_players(players);

    std::sort(players.begin(), players.end(),
              [](const Player& left, const Player& right) {
                  return left.hp < right.hp;
              });

    std::cout << "sorted by hp ascending:" << std::endl;
    print_players(players);

    int pass_score = 85;
    auto first_passed = std::find_if(players.begin(), players.end(),
                                     [pass_score](const Player& player) {
                                         return player.score >= pass_score;
                                     });

    if (first_passed != players.end()) {
        std::cout << "first passed player: " << first_passed->name << std::endl;
    }

    int hp_line = 70;
    auto hp_is_enough = [hp_line](const Player& player) {
        return player.hp >= hp_line;
    };

    hp_line = 90;
    int enough_hp_count = std::count_if(players.begin(), players.end(), hp_is_enough);
    std::cout << "hp >= captured line count: " << enough_hp_count << std::endl;

    int total_score = 0;
    std::for_each(players.begin(), players.end(),
                  [&total_score](const Player& player) {
                      total_score += player.score;
                  });

    std::cout << "total score: " << total_score << std::endl;

    std::for_each(players.begin(), players.end(),
                  [](Player& player) {
                      player.hp += 5;
                  });

    std::cout << "after healing:" << std::endl;
    print_players(players);

    return 0;
}

/*
练习答案写在这里：
练习1:
1.因为比较是两个数比较，所有Left表示前面的对象，right表示后面的对象
2.按照从大到小排序
3.因为只是比较大小并排序，不涉及修改对象
练习2:
1.表达式写成<
2.不用修改Player对象本身
练习3:
1.捕获的是70
2.因为是值捕获，是外部变量的拷贝
练习4:
1.因为总分数是要累计的
2.不能
3.要注意lambda要在被引用变量的生命周期结束之前结束
练习5:
1.适合细小的，定制化的，偏对象的
2.普通函数
3。第一个会进行拷贝，第二个能修改，第三个不拷贝也不修改
*/
