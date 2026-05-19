#include <iostream>
#include <string>

class Player {
public:
    std::string name;
    int level;
    int score;
    int hp;

    void print_info() {
        std::cout << "name: " << name
                  << ", level: " << level
                  << ", score: " << score
                  << ", hp: " << hp << std::endl;
    }

    void gain_score(int amount) {
        score += amount;
    }

    void level_up() {
        level += 1;
    }
};

void print_player_score(Player player) {
    std::cout << player.name << " score: " << player.score << std::endl;
}

int main() {
    Player alice;
    alice.name = "Alice";
    alice.level = 1;
    alice.score = 10;
    alice.hp = 1;
    alice.level_up();

    Player bob;
    bob.name = "Bob";
    bob.level = 2;
    bob.score = 30;
    bob.hp = 2;
    bob.level_up();

    alice.print_info();
    bob.print_info();

    alice.gain_score(15);

    std::cout << "after Alice gains score:" << std::endl;
    alice.print_info();
    bob.print_info();

    alice.print_info();
    print_player_score(alice);

    return 0;
}


/*
1.Player是一个类，alice是这个类的一个实例
2.不是同一个变量
3.操作的是alice的
4.因为会不好管理，写成相关的好维护并且能体现变量的从属关系
*/
