#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int hp;
    int max_hp;

public:
    Player(std::string name, int max_hp)
        : name(name), hp(max_hp), max_hp(max_hp) {
        std::cout << "construct Player, this: " << this << std::endl;
    }

    void rename(std::string name) {
        this->name = name;
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

    void heal(int amount) {
        if (amount <= 0) {
            return;
        }

        hp += amount;
        if (hp > max_hp) {
            hp = max_hp;
        }
    }

    void print_info() {
        std::cout << "this in print_info: " << this << std::endl;
        std::cout << "name: " << name
                  << ", hp: " << hp
                  << ", max_hp: " << max_hp << std::endl;
    }

    void set_max_hp(int value) {
        if (value <= 0) {
            return;
        }

        max_hp = value;
        if (hp > max_hp) {
            hp = max_hp;
        }
    }
};

int main() {
    Player alice("Alice", 100);
    Player bob("Bob", 80);

    std::cout << "&alice: " << &alice << std::endl;
    alice.print_info();

    std::cout << "&bob: " << &bob << std::endl;
    bob.print_info();

    alice.take_damage(30);
    alice.heal(200);
    alice.rename("AliceLv2");
    alice.set_max_hp(60);

    std::cout << "after operations:" << std::endl;
    alice.print_info();
    bob.print_info();

    // These lines cannot compile because name, hp, and max_hp are private.
    // alice.hp = -999;
    // alice.name = "BrokenAlice";

    return 0;
}

/*
练习1:相同，说明this指向当前对象所在的地址

练习2:饮食两个属性是是由的，不运行使用这种方式改变；如果允许外部随便写，可能会被修改属性，导致对象原本的内容出现更改，而这种更改在程序中是不允许的

*/

/*
思考题：
1.this表示当前对象所在的地址
2.左边的name表示当前对象地址中的name变量存储的地址，而右边的name表示要传给左边的属性值
3.因为有些敏感的成员变量比如密码不应该暴露出来
4.并不是，可以通过暴露的接口比如set进行调整，这是为了规范行为，防止随便修改的事情，泄漏信息的事情发生
5.承担当前对象的一些可以使用的方法和行为
*/
