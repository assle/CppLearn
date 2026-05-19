#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int hp;

public:
    Player(std::string name, int hp) : name(name), hp(hp) {
        std::cout << "construct: " << this->name << std::endl;
    }

    Player(const Player& other) : name(other.name), hp(other.hp) {
        std::cout << "copy construct from: " << other.name << std::endl;
    }

    void print_info() const {
        std::cout << "name: " << name << ", hp: " << hp << std::endl;
    }
};

class ScoreBuffer {
private:
    int* score;

public:
    ScoreBuffer(int value) : score(new int(value)) {
        std::cout << "construct ScoreBuffer, score address: " << score
                  << ", value: " << *score << std::endl;
    }

    ScoreBuffer(const ScoreBuffer& other) : score(new int(*other.score)) {
        std::cout << "copy construct ScoreBuffer, new address: " << score
                  << ", copied from: " << other.score << std::endl;
    }

    ScoreBuffer& operator=(const ScoreBuffer& other) {
        std::cout << "assign ScoreBuffer from " << other.score
                  << " to " << score << std::endl;

        if (this == &other) {
            std::cout << "self assignment detected, keep current resource"
                      << std::endl;
            return *this;
        }

        delete score;
        score = new int(*other.score);

        return *this;
    }

    ~ScoreBuffer() {
        std::cout << "destruct ScoreBuffer, score address: " << score
                  << std::endl;
        delete score;
    }

    void print() const {
        std::cout << "score address: " << score
                  << ", value: " << *score << std::endl;
    }
};

void print_player_by_const_reference(const Player& player) {
    std::cout << "print by const reference" << std::endl;
    player.print_info();
}

int main() {
    std::cout << "part 1: const reference avoids extra copy" << std::endl;

    Player alice("Alice", 100);
    Player bob = alice;
    print_player_by_const_reference(alice);

    std::cout << std::endl;
    std::cout << "part 2: self assignment check protects resource"
              << std::endl;

    ScoreBuffer first(10);
    ScoreBuffer second(20);

    second = first;
    second.print();

    second = second;
    second.print();

    return 0;
}

/*
练习1:
因为会造成重复的拷贝构造
避免了传入了参数要进行拷贝，这回重复的调用拷贝构造
表示了不会修改传入参数的内容

练习2:
因为有可能会自赋值
没有检查可能中间会释放delete某一个变量地址，但是如果要创建堆内存进行管理，会调用旧地址不成立的对象

练习3:
拥有的
因为构造函数中已经拥有了指向堆内存的指针

*/