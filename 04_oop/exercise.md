# D1 练习：类、对象、成员变量、成员函数

示例文件：

```text
04_oop/class_object_basic.cpp
```

编译运行：

```bash
g++ 04_oop/class_object_basic.cpp -o /private/tmp/cpplearn_oop_d1
/private/tmp/cpplearn_oop_d1
```

## 练习 1：新增成员变量

给 `Player` 增加一个成员变量：

```cpp
int hp;
```

然后分别给 `alice` 和 `bob` 设置不同的 `hp`，并在 `print_info()` 中输出。

观察：

- 修改 `alice.hp` 会不会影响 `bob.hp`？
- 为什么？

## 练习 2：新增成员函数

给 `Player` 增加成员函数：

```cpp
void level_up() {
    level += 1;
}
```

在 `main()` 中调用：

```cpp
alice.level_up();
```

观察：

- 调用 `alice.level_up()` 后，谁的等级发生变化？
- `bob.level` 会不会变化？

## 练习 3：对比普通函数和成员函数

在类外新增普通函数：

```cpp
void print_player_score(Player player) {
    std::cout << player.name << " score: " << player.score << std::endl;
}
```

然后对比：

```cpp
alice.print_info();
print_player_score(alice);
```

思考：

- 成员函数调用时，为什么不需要把 `alice` 作为参数传进去？
- 普通函数为什么需要通过参数接收 `Player`？

## 思考题

1. `Player` 和 `alice` 分别是什么？
2. `alice.score` 和 `bob.score` 是同一个变量吗？
3. `alice.gain_score(15)` 中，`gain_score` 操作的是谁的 `score`？
4. 为什么工程里不喜欢把 `name`、`level`、`score` 都写成一堆互不相关的变量？

# D2 练习：构造函数、析构函数

示例文件：

```text
04_oop/constructor_destructor_basic.cpp
```

编译运行：

```bash
g++ 04_oop/constructor_destructor_basic.cpp -o /private/tmp/cpplearn_oop_d2
/private/tmp/cpplearn_oop_d2
```

## 练习 1：新增构造参数

给 `Player` 增加成员变量：

```cpp
int hp;
```

然后修改构造函数，让创建对象时必须传入 `hp`：

```cpp
Player(std::string player_name, int player_level, int player_score, int player_hp)
```

要求：

- 在成员初始化列表中初始化 `hp`。
- 在 `print_info()` 中输出 `hp`。
- 修改 `alice`、`bob`、`temp`、`heap_player` 的创建代码，让程序能编译运行。

## 练习 2：观察析构顺序

运行程序，观察输出顺序。

重点观察：

- `bob` 是什么时候析构的？
- `temp` 是什么时候析构的？
- `heap_player` 是什么时候析构的？
- `alice` 是什么时候析构的？

## 练习 3：新增函数观察作用域

新增一个函数：

```cpp
void create_two_players() {
    Player first("First", 1, 10, 100);
    Player second("Second", 2, 20, 200);
}
```

在 `main()` 中调用它。

观察：

- `first` 和 `second` 的析构顺序是什么？
- 为什么它们会在函数结束时析构？

## 思考题

1. 构造函数为什么没有返回值类型？
2. 为什么 `Player alice("Alice", 1, 10);` 比先创建对象再逐个赋值更稳妥？
3. 析构函数什么时候自动调用？
4. `new Player(...)` 和 `delete heap_player` 分别会触发什么？
5. 如果堆对象忘记 `delete`，可能带来什么问题？

# D2 补充练习：对象创建即初始化

示例文件：

```text
04_oop/constructor_init_review.cpp
```

编译运行：

```bash
g++ 04_oop/constructor_init_review.cpp -o /private/tmp/cpplearn_oop_d2_review
/private/tmp/cpplearn_oop_d2_review
```

## 练习 1：观察半初始化对象

运行示例，观察这两行之间的区别：

```cpp
LoosePlayer loose;
loose.print_info();
```

思考：

- 为什么 `LoosePlayer` 创建后还不能直接当作完整玩家使用？
- 如果工程里很多函数都可能拿到 `LoosePlayer`，会有什么维护风险？

## 练习 2：观察构造函数初始化

观察：

```cpp
Player alice("Alice", 1, 100);
alice.print_info();
```

思考：

- `alice` 创建完成后，是否已经有完整的 `name`、`level`、`hp`？
- 为什么这比 `LoosePlayer loose;` 再 `setup(...)` 更稳？

## 练习 3：区分构造函数和普通函数返回对象

观察：

```cpp
Player create_player() {
    Player player("CreatedByFunction", 3, 300);
    return player;
}
```

思考：

- 哪个是普通函数？
- 哪个是构造函数？
- 谁有返回值类型？
- 谁没有返回值类型？

# D3 练习：`this`、`public/private`

示例文件：

```text
04_oop/this_private_basic.cpp
```

编译运行：

```bash
g++ 04_oop/this_private_basic.cpp -o /private/tmp/cpplearn_oop_d3
/private/tmp/cpplearn_oop_d3
```

## 练习 1：观察 `this`

运行程序，比较：

```cpp
std::cout << "&alice: " << &alice << std::endl;
alice.print_info();
```

观察：

- `&alice` 和 `alice.print_info()` 里打印的 `this` 是否相同？
- `&bob` 和 `bob.print_info()` 里打印的 `this` 是否相同？
- 这说明成员函数里的 `this` 指向谁？

## 练习 2：观察 `private` 编译错误

取消下面两行注释：

```cpp
// alice.hp = -999;
// alice.name = "BrokenAlice";
```

尝试编译，观察错误。

然后恢复注释。

思考：

- 编译器为什么不允许这样写？
- 如果允许外部随便写 `alice.hp = -999`，对象可能出现什么问题？

## 练习 3：新增受控接口

给 `Player` 增加一个 `public` 成员函数：

```cpp
void set_max_hp(int value)
```

要求：

- 如果 `value <= 0`，直接 `return`。
- 如果 `value` 合法，更新 `max_hp`。
- 如果当前 `hp > max_hp`，把 `hp` 调整为 `max_hp`。

在 `main()` 中调用它，并打印对象状态。

## 思考题

1. `this` 在成员函数里代表什么？
2. `this->name = name;` 左边和右边的 `name` 分别是什么？
3. 为什么成员变量通常不应该全部写成 `public`？
4. `private` 是否意味着外部完全不能使用对象？为什么？
5. `public` 成员函数在工程里承担什么角色？

# D4 练习：拷贝构造、赋值运算符

示例文件：

```text
04_oop/copy_assignment_basic.cpp
```

编译运行：

```bash
g++ 04_oop/copy_assignment_basic.cpp -o /private/tmp/cpplearn_oop_d4
/private/tmp/cpplearn_oop_d4
```

## 练习 1：观察拷贝构造

运行程序，重点观察：

```cpp
Player bob = alice;
```

思考：

- 这一行是在创建新对象，还是修改已有对象？
- 输出里的 `new object this` 和 `source object` 是否是两个不同地址？
- 修改 `bob` 后，`alice` 是否变化？

## 练习 2：观察赋值运算符

运行程序，重点观察：

```cpp
Player charlie("Charlie", 50);
charlie = bob;
```

思考：

- `charlie` 在赋值前是否已经存在？
- `charlie = bob;` 是调用拷贝构造函数，还是赋值运算符？
- 赋值后 `charlie` 的状态变成了谁的状态？

## 练习 3：观察按值传参

运行程序，重点观察：

```cpp
print_by_value(alice);
```

思考：

- 为什么调用这个函数时也会出现拷贝构造输出？
- 函数结束时，参数对象会不会析构？

## 练习 4：改成引用传参

新增函数：

```cpp
void print_by_const_reference(const Player& player) {
    std::cout << "inside print_by_const_reference" << std::endl;
    player.print_info();
}
```

在 `main()` 中调用：

```cpp
print_by_const_reference(alice);
```

观察：

- 调用这个函数时还会不会触发拷贝构造？
- 为什么 `const Player&` 可以避免拷贝？

## 思考题

1. 拷贝构造函数什么时候调用？
2. 赋值运算符什么时候调用？
3. `Player bob = alice;` 和 `charlie = bob;` 最大区别是什么？
4. 为什么拷贝构造函数参数通常写成 `const Player& other`？
5. 为什么赋值运算符里常见 `if (this == &other)`？

# D4 补充练习：拷贝参数和自赋值检查

示例文件：

```text
04_oop/copy_assignment_review.cpp
```

编译运行：

```bash
g++ 04_oop/copy_assignment_review.cpp -o /private/tmp/cpplearn_oop_d4_review
/private/tmp/cpplearn_oop_d4_review
```

## 练习 1：解释 `const Player& other`

阅读：

```cpp
Player(const Player& other)
```

回答：

- 为什么不能写成 `Player(Player other)`？
- `&` 避免了什么问题？
- `const` 表示什么承诺？

## 练习 2：观察自赋值

运行程序，重点观察：

```cpp
second = second;
```

回答：

- `this == &other` 为什么成立？
- 如果没有这个检查，资源管理类可能会先做什么危险操作？

## 练习 3：连接所有权

观察 `ScoreBuffer`：

```cpp
int* score;
```

回答：

- `ScoreBuffer` 是否拥有 `score` 指向的堆内存？
- 析构函数为什么要 `delete score`？
- 赋值运算符里为什么要重新 `new int(*other.score)`，而不是只写 `score = other.score`？

# D5 练习：继承、多态、虚函数

示例文件：

```text
04_oop/inheritance_polymorphism_basic.cpp
```

编译运行：

```bash
g++ 04_oop/inheritance_polymorphism_basic.cpp -o /private/tmp/cpplearn_oop_d5
/private/tmp/cpplearn_oop_d5
```

## 练习 1：观察继承

运行程序，观察：

```cpp
Warrior warrior("Arthur", 120, 30);
Mage mage("Merlin", 80, 100);
```

思考：

- 创建 `Warrior` 时，是否先构造了 `Character` 部分？
- `Warrior` 为什么可以调用 `print_status()`？
- `Mage` 为什么也可以调用 `print_status()`？

## 练习 2：观察多态

运行程序，重点观察：

```cpp
run_turn(npc);
run_turn(warrior);
run_turn(mage);
```

思考：

- `run_turn` 的参数类型是什么？
- 为什么传入 `warrior` 时调用的是 `Warrior::act()`？
- 为什么传入 `mage` 时调用的是 `Mage::act()`？

## 练习 3：新增派生类

新增一个派生类：

```cpp
class Archer : public Character {
private:
    int arrows;

public:
    Archer(std::string name, int hp, int arrows)
        : Character(name, hp), arrows(arrows) {
    }

    void act() const override {
        std::cout << name << " shoots an arrow, arrows: "
                  << arrows << std::endl;
    }
};
```

在 `main()` 中创建：

```cpp
Archer archer("Robin", 90, 12);
```

并调用：

```cpp
archer.print_status();
archer.act();
run_turn(archer);
```

## 练习 4：观察去掉 `virtual`

临时把基类中的：

```cpp
virtual void act() const
```

改成：

```cpp
void act() const
```

同时去掉派生类 `act()` 后面的 `override`。

重新编译运行，观察 `run_turn(warrior)` 和 `run_turn(mage)` 的输出变化。

然后恢复 `virtual` 和 `override`。

## 思考题

1. `Character`、`Warrior`、`Mage` 分别是什么关系？
2. `protected` 和 `private` 有什么区别？
3. `virtual` 的作用是什么？
4. `override` 的作用是什么？
5. 什么是多态？用 `run_turn` 的例子说明。

# D5 补充练习：`virtual/override`、重载/重写、访问控制

示例文件：

```text
04_oop/virtual_override_review.cpp
```

编译运行：

```bash
g++ 04_oop/virtual_override_review.cpp -o /private/tmp/cpplearn_oop_d5_review
/private/tmp/cpplearn_oop_d5_review
```

## 练习 1：区分重载和重写

观察：

```cpp
virtual void act() const;
void act(int times) const;
```

以及：

```cpp
void act() const override;
```

回答：

- 哪两个函数构成重载？
- 哪个函数是在重写基类虚函数？

## 练习 2：观察动态绑定

运行程序，观察：

```cpp
run_turn(npc);
run_turn(warrior);
```

回答：

- `run_turn` 的参数类型是什么？
- 为什么 `run_turn(warrior)` 调用的是 `Warrior::act()`？

## 练习 3：观察 `override` 检查

临时把 `Warrior` 中的：

```cpp
void act() const override
```

改成：

```cpp
void act(int value) const override
```

尝试编译，观察错误。

然后恢复。

回答：

- 编译器为什么报错？
- `override` 帮你发现了什么问题？

## 练习 4：观察 `protected/private`

阅读：

```cpp
private:
    int id;

protected:
    std::string name;
```

回答：

- 为什么 `Warrior::act()` 可以直接使用 `name`？
- 为什么 `Warrior::act()` 不能直接使用 `id`？
- 类外为什么应该通过 `print_id()` 使用 `id`？

# D6 练习：RAII 基础

示例文件：

```text
04_oop/raii_basic.cpp
```

编译运行：

```bash
g++ 04_oop/raii_basic.cpp -o /private/tmp/cpplearn_oop_d6
/private/tmp/cpplearn_oop_d6
```

## 练习 1：观察自动析构

运行程序，观察：

```cpp
raii_resource_example(true);
```

回答：

- 函数中途 `return` 时，`ScoreArray` 的析构函数有没有执行？
- 这说明局部对象离开作用域时会发生什么？

## 练习 2：理解构造和析构职责

阅读：

```cpp
ScoreArray(int array_size) : data(new int[array_size]), size(array_size) {
}

~ScoreArray() {
    delete[] data;
}
```

回答：

- 构造函数里获取了什么资源？
- 析构函数里释放了什么资源？
- 为什么 `new[]` 要对应 `delete[]`？

## 练习 3：观察禁用拷贝

在 `main()` 中临时加入：

```cpp
ScoreArray a(3);
ScoreArray b = a;
```

尝试编译，观察错误。

然后恢复。

回答：

- 编译器为什么不允许拷贝？
- 如果允许默认拷贝，两个对象可能会保存什么相同内容？
- 两个对象析构时可能出现什么问题？

## 练习 4：新增函数

新增函数：

```cpp
void nested_scope_example() {
    std::cout << "enter nested scope" << std::endl;
    {
        ScoreArray scores(2);
        scores.set(0, 7);
        scores.set(1, 8);
        scores.print();
    }
    std::cout << "leave nested scope" << std::endl;
}
```

在 `main()` 中调用它。

观察：

- `ScoreArray` 是在什么时候构造的？
- `ScoreArray` 是在什么时候析构的？

## 思考题

1. RAII 的核心思想是什么？
2. 为什么 RAII 比手动到处写 `delete` 更稳？
3. 构造函数和析构函数在 RAII 中分别承担什么职责？
4. 为什么拥有堆内存的 RAII 类不能随便默认拷贝？
5. 你见过哪些资源也适合用 RAII 管理？

# D6 补充练习：默认拷贝和资源类型

示例文件：

```text
04_oop/raii_copy_review.cpp
```

编译运行：

```bash
g++ 04_oop/raii_copy_review.cpp -o /private/tmp/cpplearn_oop_d6_review
/private/tmp/cpplearn_oop_d6_review
```

## 练习 1：观察浅拷贝

运行程序，观察：

```cpp
BrokenArray first(3);
BrokenArray second = first;
```

回答：

- `first` 和 `second` 打印出的 `data address` 是否相同？
- 这说明默认拷贝指针时复制的是堆数组内容，还是堆地址？
- 如果两个对象都执行 `delete[] data`，会发生什么风险？

## 练习 2：理解为什么示例里用了 `owner`

阅读：

```cpp
bool owner;
```

回答：

- 为什么 `second` 的 `owner` 被设置为 `false`？
- 如果 `first` 和 `second` 的 `owner` 都是 `true`，析构时可能发生什么？

## 练习 3：观察文件型 RAII

运行程序，观察：

```cpp
FakeFile file("report.txt");
file.write_line("hello RAII");
```

回答：

- `FakeFile` 构造函数模拟了什么动作？
- `FakeFile` 析构函数模拟了什么动作？
- 为什么文件也适合用 RAII 管理？

## 练习 4：列举资源

列出至少 3 种适合 RAII 管理的资源，并说明它们分别对应什么“获取动作”和“释放动作”。

# 04_oop 阶段复盘练习

示例文件：

```text
04_oop/oop_stage_review.cpp
```

编译运行：

```bash
g++ 04_oop/oop_stage_review.cpp -o /private/tmp/cpplearn_oop_stage_review
/private/tmp/cpplearn_oop_stage_review
```

## 练习 1：观察深拷贝

运行程序，重点观察：

```cpp
Player bob = alice;
```

回答：

- 这行代码调用的是拷贝构造函数，还是赋值运算符？
- `alice` 和 `bob` 打印出的 `ScoreLog` 数据地址是否相同？
- 修改 `bob` 的分数后，`alice` 的分数是否变化？
- 这说明深拷贝解决了什么问题？

## 练习 2：观察赋值运算符

运行程序，重点观察：

```cpp
charlie = alice;
```

回答：

- 为什么这行代码不是拷贝构造？
- `charlie` 赋值前是否已经是一个存在的对象？
- 赋值运算符里为什么要处理旧资源？
- `this == &other` 这个检查是在防什么情况？

## 练习 3：观察析构顺序

观察 `copy_example()`、`assignment_example()`、`polymorphism_example()` 结束时的输出。

回答：

- `Player` 的析构函数和 `ScoreLog` 的析构函数分别什么时候调用？
- 为什么局部对象离开函数作用域会自动析构？
- 如果 `ScoreLog` 析构函数里没有 `delete[] scores`，会发生什么资源问题？

## 练习 4：观察多态

阅读：

```cpp
void run_turn(const Character& character) {
    character.take_turn();
}
```

回答：

- `run_turn` 的参数类型是 `Character&`，为什么传入 `Player` 也可以？
- 为什么实际调用的是 `Player::take_turn()`？
- 如果去掉基类函数前面的 `virtual`，调用行为会有什么变化？

## 练习 5：修改代码加深理解

给 `Player` 增加一个成员函数：

```cpp
void heal(int value)
```

要求：

- 如果 `value <= 0`，直接返回。
- 否则让 `hp` 增加 `value`。
- 在 `polymorphism_example()` 中调用一次 `heal`。

思考：

- 为什么 `hp` 是 `private` 后，外部不能直接写 `alice.hp += 10`？
- 通过 `heal` 这种 `public` 接口修改对象状态有什么工程好处？

## 阶段复盘思考题

1. 类和对象解决的核心组织问题是什么？
2. 构造函数和析构函数分别对应对象生命周期里的哪个时刻？
3. 如果一个类拥有堆内存，默认拷贝为什么可能危险？
4. 拷贝构造和赋值运算符的触发时机有什么区别？
5. RAII 为什么能减少资源泄漏？
6. 多态为什么能让调用方少依赖具体类型？
7. 学完本轮后，你觉得 `04_oop` 里最需要继续加固的是哪一块？
