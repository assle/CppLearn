#include <iostream>
#include <string>

struct Player {
    std::string name;
    int hp;
};

void print_player(const Player* player) {
    if (player == nullptr) {
        std::cout << "no player" << std::endl;
        return;
    }

    std::cout << player->name << " hp: " << player->hp << std::endl;
}

void heal_player(Player* player, int amount) {
    if (player == nullptr) {
        std::cout << "cannot heal null player" << std::endl;
        return;
    }

    player->hp += amount;
}

void choose_target(int target_id) {
    std::cout << "choose target by id: " << target_id << std::endl;
}

void choose_target(Player* player) {
    if (player == nullptr) {
        std::cout << "choose no target" << std::endl;
        return;
    }

    std::cout << "choose target player: " << player->name << std::endl;
}

void damage_player(Player* player, int amount) {
    if (player == nullptr) {
        std::cout << "cannot damage null player" << std::endl;
        return;
    }
    player->hp -= amount;
}

int main() {
    Player alice = {"Alice", 80};
    Player* current_player = &alice;

    print_player(current_player);
    heal_player(current_player, 15);
    print_player(current_player);

    damage_player(current_player, 10);

    current_player = nullptr;
    print_player(current_player);
    heal_player(current_player, 10);

    damage_player(current_player, 10);

    choose_target(0);
    choose_target(nullptr);

    Player* heap_player = new Player{"Bob", 60};
    print_player(heap_player);

    delete heap_player;
    heap_player = nullptr;
    print_player(heap_player);

    return 0;
}

/*
练习答案写在这里：
练习1:
表示当前指针指向为空，避免悬空指针
因为并不知道传入的对象指针指向的地址上的对象是否被释放，如果不判断，可能会重复使用导致悬空指针问题，调用了未成型的对象

练习3:
调用了重载前的版本
调用了重载后的版本
因为能跟更安全的使用重载，能根据不同的传入类型执行对应的逻辑

练习4:
释放了heap_player指向的地址上的对象
改变的是指针变量本身
悬空指针，导致重复调用，调用未成型的对象

练习5:
1.因为适合重载执行对应的逻辑，如果用0，可能NULL也表示0，在进行一些判断条件的时候不够灵活
2.要对这个传入的对象进行操作之前必须进行检查
3.如果函数确定必须接收一个真实存在的对象，用 Player& 更合适
因为引用表达“必须有对象”，调用方不能传 nullptr
如果函数允许“没有对象”，才更适合用 Player* 并在函数内检查 nullptr
*/
