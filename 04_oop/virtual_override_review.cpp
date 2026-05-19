#include <iostream>
#include <string>

class Character {
private:
    int id;

protected:
    std::string name;

public:
    Character(int id, std::string name) : id(id), name(name) {
    }

    virtual ~Character() {
    }

    virtual void act() const {
        std::cout << name << " waits." << std::endl;
    }

    void act(int times) const {
        std::cout << name << " acts " << times << " times." << std::endl;
    }

    void print_id() const {
        std::cout << "id: " << id << std::endl;
    }
};

class Warrior : public Character {
public:
    Warrior(int id, std::string name) : Character(id, name) {
    }

    void act() const override {
        std::cout << name << " attacks with a sword." << std::endl;

        // id is private in Character, so Warrior cannot access it directly.
        // std::cout << id << std::endl;
    }
};

void run_turn(const Character& character) {
    character.act();
}

int main() {
    Character npc(1, "NPC");
    Warrior warrior(2, "Arthur");

    std::cout << "direct calls:" << std::endl;
    npc.act();
    npc.act(3);
    warrior.act();

    std::cout << std::endl;
    std::cout << "polymorphic calls:" << std::endl;
    run_turn(npc);
    run_turn(warrior);

    std::cout << std::endl;
    std::cout << "private member is exposed through public function:" << std::endl;
    npc.print_id();
    warrior.print_id();

    return 0;
}

/*
练习1:
act(int times)是重载，act()是重写

练习2:
参数类型是Character的引用
因为是通过引用调用，根据真实对象类型决定调用哪个版本

练习3:
因为参数变了，而对于重写，参数类型是不变的，是实现细节变了

练习4:
因为派生类继承了基类的属性，但是name和id的变量权限不同
因为print_id是基类自己的方法，能够访问到id,相当于开放出来的一个接口，让使用者不能直接拿到id内容但是能够进行打印。
*/