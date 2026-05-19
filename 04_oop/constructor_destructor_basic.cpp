#include <iostream>
#include <string>

class Player {
public:
    std::string name;
    int level;
    int score;
    int hp;

    Player(std::string player_name, int player_level, int player_score, int player_hp)
        : name(player_name), level(player_level), score(player_score), hp(player_hp) {
        std::cout << "construct Player: " << name << std::endl;
    }

    ~Player() {
        std::cout << "destruct Player: " << name << std::endl;
    }

    void print_info() {
        std::cout << "name: " << name
                  << ", level: " << level
                  << ", score: " << score
                  << ", hp: " << hp << std::endl;
    }
};

void create_two_players() {
    Player first("First", 1, 10, 100);
    Player second("Second", 2, 20, 200);
}

void create_temporary_player() {
    std::cout << "enter create_temporary_player" << std::endl;

    Player temp("Temp", 1, 0, 1);
    temp.print_info();

    std::cout << "leave create_temporary_player" << std::endl;
}

int main() {
    std::cout << "main begin" << std::endl;

    Player alice("Alice", 1, 10, 2);
    alice.print_info();

    {
        std::cout << "enter inner block" << std::endl;

        Player bob("Bob", 2, 30, 3);
        bob.print_info();

        std::cout << "leave inner block" << std::endl;
    }

    std::cout << "after inner block" << std::endl;

    Player* heap_player = new Player("HeapPlayer", 3, 50, 4);
    heap_player->print_info();
    delete heap_player;
    heap_player = nullptr;

    create_temporary_player();

    std::cout << "main end" << std::endl;

    std::cout << "----------------" << std::endl;
    create_two_players();

    return 0;
}

/*
1.因为构造函数相当于对属性进行初始化（为什么没有返回值为不了解）
2.这个我也不清楚
3.生命周期的最后阶段，对于作用域来说，在出作用域之前会调用析构函数销毁，还有就是delete的时候会销毁
4.会触发构造函数和析构函数
5.可能造成内存泄漏
*/
