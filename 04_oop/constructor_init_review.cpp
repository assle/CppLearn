#include <iostream>
#include <string>

class LoosePlayer {
public:
    std::string name;
    int level;
    int hp;
    bool initialized;

    LoosePlayer() : name(""), level(0), hp(0), initialized(false) {
        std::cout << "LoosePlayer created, but not ready" << std::endl;
    }

    void setup(std::string player_name, int player_level, int player_hp) {
        name = player_name;
        level = player_level;
        hp = player_hp;
        initialized = true;
    }

    void print_info() {
        if (!initialized) {
            std::cout << "LoosePlayer is not fully initialized" << std::endl;
            return;
        }

        std::cout << "LoosePlayer name: " << name
                  << ", level: " << level
                  << ", hp: " << hp << std::endl;
    }
};

class Player {
public:
    std::string name;
    int level;
    int hp;

    Player(std::string player_name, int player_level, int player_hp)
        : name(player_name), level(player_level), hp(player_hp) {
        std::cout << "Player created and ready: " << name << std::endl;
    }

    void print_info() {
        std::cout << "Player name: " << name
                  << ", level: " << level
                  << ", hp: " << hp << std::endl;
    }
};

Player create_player() {
    Player player("CreatedByFunction", 3, 300);
    return player;
}

int main() {
    LoosePlayer loose;
    loose.print_info();

    loose.setup("LooseAlice", 1, 100);
    loose.print_info();

    Player alice("Alice", 1, 100);
    alice.print_info();

    Player from_function = create_player();
    from_function.print_info();

    return 0;
}

/*
练习1:
因为创建后没有初始化
如果拿到没初始化的对象，很多函数调用的话可能会多次赋值，从而导致其中的一些属性改变
练习2:
已经有完整的属性了
因为可能会忘记set，并且代码较多，不方便维护
练习3:
create_player()是普通函数
Player player是构造函数
普通函数有返回类型
构造函数没有返回类型
*/