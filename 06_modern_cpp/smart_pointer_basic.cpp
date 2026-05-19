#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Player {
    std::string name;
    int hp;

    Player(std::string player_name, int player_hp)
        : name(player_name), hp(player_hp) {
        std::cout << "construct Player: " << name << std::endl;
    }

    ~Player() {
        std::cout << "destroy Player: " << name << std::endl;
    }
};

void print_player(const Player& player) {
    std::cout << player.name << " hp: " << player.hp << std::endl;
}

void heal_player(Player& player, int amount) {
    player.hp += amount;
}

std::unique_ptr<Player> create_unique_player(const std::string& name, int hp) {
    return std::make_unique<Player>(name, hp);
}

void print_shared_player_count(const std::shared_ptr<Player>& player) {
    if (player == nullptr) {
        std::cout << "shared player is null" << std::endl;
        return;
    }

    std::cout << player->name << " shared count: " << player.use_count() << std::endl;
}

void damage_player(Player& player, int amount) {
    player.hp -= amount;
}

int main() {
    std::cout << "unique_ptr demo" << std::endl;

    std::unique_ptr<Player> alice = std::make_unique<Player>("Alice", 80);
    print_player(*alice);
    heal_player(*alice, 15);
    print_player(*alice);

    std::unique_ptr<Player> owner = std::move(alice);
    if (alice == nullptr) {
        std::cout << "alice unique_ptr is empty after move" << std::endl;
    }

    damage_player(*owner, 10);

    print_player(*owner);

    std::unique_ptr<Player> created = create_unique_player("Bob", 60);
    print_player(*created);

    std::cout << "shared_ptr demo" << std::endl;

    std::shared_ptr<Player> shared_alice = std::make_shared<Player>("SharedAlice", 100);
    print_shared_player_count(shared_alice);

    {
        std::shared_ptr<Player> another_owner = shared_alice;
        print_shared_player_count(shared_alice);
        print_shared_player_count(another_owner);
    }

    print_shared_player_count(shared_alice);

    std::vector<std::shared_ptr<Player>> team;
    team.push_back(shared_alice);
    print_shared_player_count(shared_alice);

    team.clear();
    print_shared_player_count(shared_alice);

    std::cout << "end of main" << std::endl;
    return 0;
}

/*
练习答案写在这里：
练习1:
没有手写delete
因为智能指针在变量销毁的时候自己释放了内存

练习2:
表示把 alice 拥有的堆对象所有权转移给 owner；std::move 本身不释放对象
因为移动后 alice 不再拥有对象，检查 alice == nullptr 可以避免继续解引用空的 unique_ptr
因为 unique_ptr 表达独占所有权；如果允许普通复制，两个 unique_ptr 可能同时释放同一个堆对象

练习3:
因为 damage_player 只是临时借用对象并修改 hp，不需要接管 unique_ptr 的所有权
*owner 表示解引用 unique_ptr，得到它管理的 Player 对象

练习4:
use_count()返回的数量变多了
减一
当use_count返回的数量变为0的时候就自动释放

练习5:
因为滥用共享指针会导致编码困难，弄不清楚是谁主要负责
当确实需要多个所有者共同延长同一个对象的生命周期时，才应该考虑 shared_ptr
更适合 const Player&，因为函数只是临时读取对象，不需要拥有或延长对象生命周期
*/
