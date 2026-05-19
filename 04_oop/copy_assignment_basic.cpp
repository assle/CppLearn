#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int hp;

public:
    Player(std::string name, int hp) : name(name), hp(hp) {
        std::cout << "construct: " << this->name
                  << ", this: " << this << std::endl;
    }

    Player(const Player& other) : name(other.name), hp(other.hp) {
        std::cout << "copy construct from " << other.name
                  << ", new object this: " << this
                  << ", source object: " << &other << std::endl;
    }

    Player& operator=(const Player& other) {
        std::cout << "assign from " << other.name
                  << " to " << name << std::endl;

        if (this == &other) {
            std::cout << "self assignment, do nothing" << std::endl;
            return *this;
        }

        name = other.name;
        hp = other.hp;

        return *this;
    }

    ~Player() {
        std::cout << "destruct: " << name
                  << ", this: " << this << std::endl;
    }

    void rename(std::string new_name) {
        name = new_name;
    }

    void take_damage(int amount) {
        if (amount <= 0) {
            return;
        }

        hp -= amount;
        if (hp < 0) {
            hp = 0;
        }
    }

    void print_info() const {
        std::cout << "name: " << name
                  << ", hp: " << hp
                  << ", this: " << this << std::endl;
    }
};

void print_by_value(Player player) {
    std::cout << "inside print_by_value" << std::endl;
    player.print_info();
}
void print_by_const_reference(const Player& player) {
    std::cout << "inside print_by_const_reference" << std::endl;
    player.print_info();
}

int main() {
    std::cout << "create alice" << std::endl;
    Player alice("Alice", 100);
    alice.print_info();

    std::cout << "copy construct bob from alice" << std::endl;
    Player bob = alice;
    bob.rename("Bob");
    bob.take_damage(30);

    alice.print_info();
    bob.print_info();

    std::cout << "assign bob to charlie" << std::endl;
    Player charlie("Charlie", 50);
    charlie = bob;
    charlie.print_info();

    std::cout << "self assign charlie" << std::endl;
    charlie = charlie;
    charlie.print_info();

    std::cout << "pass alice by value" << std::endl;
    print_by_value(alice);

    std::cout << "main end" << std::endl;
    print_by_const_reference(alice);

    return 0;
}

/*
练习1:这一行在创建新对象，地址是不同的，修改了bob，alice没有变化
练习2:
在赋值前就已经存在
是调用了赋值
赋值后状态变成了bob的状态
练习3:
因为传参的时候进行了拷贝
函数结束时，会析构
练习4:
调用这个函数以后不会出发拷贝构造
因为传进去的是引用
*/

/*
思考题：
1.拷贝构造在创建新对象的时候会调用
2.赋值运算在对象已经创建了以后用=调用的就是赋值
3.最大区别是前者还没有创建，后者已经创建了
4.这个不知道
5.这个也不知道
*/