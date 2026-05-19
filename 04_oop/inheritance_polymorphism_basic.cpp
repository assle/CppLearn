#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int hp;

public:
    Character(std::string name, int hp) : name(name), hp(hp) {
        std::cout << "construct Character: " << name << std::endl;
    }

    virtual ~Character() {
        std::cout << "destruct Character: " << name << std::endl;
    }

    virtual void act() const {
        std::cout << name << " waits." << std::endl;
    }

    void print_status() const {
        std::cout << "name: " << name << ", hp: " << hp << std::endl;
    }
};

class Warrior : public Character {
private:
    int rage;

public:
    Warrior(std::string name, int hp, int rage)
        : Character(name, hp), rage(rage) {
        std::cout << "construct Warrior: " << name << std::endl;
    }

    ~Warrior() override {
        std::cout << "destruct Warrior: " << name << std::endl;
    }

    void act() const override {
        std::cout << name << " swings a sword, rage: " << rage << std::endl;
    }
};

class Mage : public Character {
private:
    int mana;

public:
    Mage(std::string name, int hp, int mana)
        : Character(name, hp), mana(mana) {
        std::cout << "construct Mage: " << name << std::endl;
    }

    ~Mage() override {
        std::cout << "destruct Mage: " << name << std::endl;
    }

    void act() const override {
        std::cout << name << " casts a spell, mana: " << mana << std::endl;
    }
};

class Archer : public Character {
private:
    int arrows;

public:
    Archer(std::string name, int hp, int arrows)
        : Character(name, hp), arrows(arrows) {
    }

    ~Archer() override {
        std::cout << "destruct Archer: " << name << std::endl;
    }

    void act() const override {
        std::cout << name << " shoots an arrow, arrows: "
                  << arrows << std::endl;
    }
};

void run_turn(const Character& character) {
    std::cout << "run_turn: ";
    character.act();
}

int main() {
    Character npc("NPC", 50);
    Warrior warrior("Arthur", 120, 30);
    Mage mage("Merlin", 80, 100);

    std::cout << std::endl;

    npc.print_status();
    warrior.print_status();
    mage.print_status();

    std::cout << std::endl;

    npc.act();
    warrior.act();
    mage.act();

    std::cout << std::endl;

    run_turn(npc);
    run_turn(warrior);
    run_turn(mage);

    std::cout << std::endl;

    Archer archer("Robin", 90, 12);
    archer.print_status();
    archer.act();
    run_turn(archer);

    std::cout << std::endl;
    std::cout << "main end" << std::endl;

    return 0;
}


/*
练习1:
会先创建Character部分
因为继承了基类的对应方法
因为同样继承了基类的对应方法

练习2:
参数类型是Character类型的引用
因为是调用的act行为是重写了基类的虚函数
同上

*/

/*
思考题
1.Character是基类，其余两个是派生类
2.这两个作用域修饰符表示变量或者函数的能不能被其他作用域看到
3.表明这个函数能被重载
4.重载一个虚函数
5.多态就是传入参数定义是一个基类，但是传入派生类对象的时候，能够根据派生类的实际定义调用派生类的实现逻辑。
*/
