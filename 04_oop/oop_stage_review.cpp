#include <iostream>
#include <string>

class ScoreLog {
private:
    int* scores;
    int size;

public:
    ScoreLog(int log_size) : scores(new int[log_size]), size(log_size) {
        for (int i = 0; i < size; ++i) {
            scores[i] = 0;
        }

        std::cout << "ScoreLog construct, data: " << scores << std::endl;
    }

    ScoreLog(const ScoreLog& other)
        : scores(new int[other.size]), size(other.size) {
        for (int i = 0; i < size; ++i) {
            scores[i] = other.scores[i];
        }

        std::cout << "ScoreLog copy construct, new data: " << scores
                  << ", source data: " << other.scores << std::endl;
    }

    ScoreLog& operator=(const ScoreLog& other) {
        std::cout << "ScoreLog operator=, current data: " << scores
                  << ", source data: " << other.scores << std::endl;

        if (this == &other) {
            return *this;
        }

        int* new_scores = new int[other.size];
        for (int i = 0; i < other.size; ++i) {
            new_scores[i] = other.scores[i];
        }

        delete[] scores;
        scores = new_scores;
        size = other.size;

        return *this;
    }

    ~ScoreLog() {
        std::cout << "ScoreLog destruct, data: " << scores << std::endl;
        delete[] scores;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            return;
        }

        scores[index] = value;
    }

    void print() const {
        std::cout << "scores:";
        for (int i = 0; i < size; ++i) {
            std::cout << " " << scores[i];
        }
        std::cout << std::endl;
    }
};

class Character {
private:
    std::string name;

public:
    Character(const std::string& character_name) : name(character_name) {
        std::cout << "Character construct: " << name << std::endl;
    }

    Character& operator=(const Character& other) {
        if (this == &other) {
            return *this;
        }

        name = other.name;
        return *this;
    }

    virtual ~Character() {
        std::cout << "Character destruct: " << name << std::endl;
    }

    const std::string& get_name() const {
        return name;
    }

    virtual void take_turn() const {
        std::cout << name << " takes a normal turn." << std::endl;
    }
};

class Player : public Character {
private:
    int hp;
    ScoreLog score_log;

public:
    Player(const std::string& player_name, int player_hp)
        : Character(player_name), hp(player_hp), score_log(3) {
        std::cout << "Player construct: " << get_name() << std::endl;
    }

    Player(const Player& other)
        : Character(other.get_name()), hp(other.hp), score_log(other.score_log) {
        std::cout << "Player copy construct: " << get_name() << std::endl;
    }

    Player& operator=(const Player& other) {
        std::cout << "Player operator=: " << get_name() << " <- "
                  << other.get_name() << std::endl;

        if (this == &other) {
            return *this;
        }

        Character::operator=(other);
        hp = other.hp;
        score_log = other.score_log;

        return *this;
    }

    ~Player() override {
        std::cout << "Player destruct: " << get_name() << std::endl;
    }

    void heal(int value) {
        if (value <= 0) {
            return;
        }
        hp += value;
    }

    void add_score(int index, int value) {
        score_log.set(index, value);
    }

    void print_scores() const {
        std::cout << get_name() << " ";
        score_log.print();
    }

    void take_turn() const override {
        std::cout << get_name() << " attacks with hp " << hp << "."
                  << std::endl;
    }
};

void run_turn(const Character& character) {
    character.take_turn();
}

void copy_example() {
    std::cout << "\ncopy_example begin" << std::endl;

    Player alice("Alice", 100);
    alice.add_score(0, 10);
    alice.add_score(1, 20);

    Player bob = alice;
    bob.add_score(0, 99);

    alice.print_scores();
    bob.print_scores();

    std::cout << "copy_example end" << std::endl;
}

void assignment_example() {
    std::cout << "\nassignment_example begin" << std::endl;

    Player alice("Alice", 100);
    alice.add_score(0, 10);

    Player charlie("Charlie", 80);
    charlie.add_score(0, 1);

    charlie = alice;
    charlie.add_score(1, 77);

    alice.print_scores();
    charlie.print_scores();

    std::cout << "assignment_example end" << std::endl;
}

void polymorphism_example() {
    std::cout << "\npolymorphism_example begin" << std::endl;

    Player alice("Alice", 100);
    run_turn(alice);
    alice.heal(10);

    std::cout << "polymorphism_example end" << std::endl;
}

int main() {
    copy_example();
    assignment_example();
    polymorphism_example();

    std::cout << "\nmain end" << std::endl;

    return 0;
}


/*
练习1:
调用的是拷贝构造函数
地址不相同
不发生变化
解决了地址被多个指针指向的问题

练习2:
因为charlie和alice都是已经创建好的对象，所以是赋值拷贝
是一个已经存在的对象
赋值运算符里为什么要处理旧资源（没看懂什么意思）
防止赋值号作用两边是同一个地址上的内容，在赋值拷贝的时候会销毁对应的变量，如果是同一个地址上的内容会发生被销毁的变量重新使用

练习3:
在离开作用域的时候调用，先调用派生类的析构函数再调用基类的析构函数
因为离开作用域就销毁了，销毁调用的就是析构函数
会发生内存泄漏的问题

练习4:
因为Player是Character的派生类，这符合多态的思想
因为是多态的机制，函数调用的是实际传入对象的具体行为
会调用基类的对应方法

练习5:
因为private限制了这个变量的可见性
可以有限制的开放端口，防止外部直接获取到内部的敏感数据
*/

/*
思考题：
1.是一些有专属行为和特性的东西分门别类，更好管理，杜绝繁杂的变量干扰代码可读性和维护困难
2.创建和销毁
3.是浅拷贝，会将地址一起拷贝，后期可能会出现一系列重复删除，重复调用的问题
4.拷贝构造触发时机是左值还没有被创建的时候，而赋值运算符触发时机是两边的对象都已经创建好了
5.因为在构造函数和析构函数中自动处理了，不需要手动释放，创建，减少了维护成本。
6.因为能根据传入的具体对象调用对应的行为
7.我觉得没有了
*/