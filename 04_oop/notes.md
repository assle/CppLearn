# D1 类、对象、成员变量、成员函数

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解为什么需要类。
- 理解对象是什么。
- 理解成员变量属于具体对象。
- 理解成员函数用于操作具体对象的数据。

## 为什么需要类

如果程序里只有少量变量，可以直接这样写：

```cpp
std::string player_name = "Alice";
int player_level = 1;
int player_score = 10;
```

但工程里经常会有多个同类对象，例如多个玩家：

```cpp
std::string alice_name = "Alice";
int alice_level = 1;
int alice_score = 10;

std::string bob_name = "Bob";
int bob_level = 2;
int bob_score = 30;
```

这样写的问题是：数据是分散的。名字、等级、分数本来属于同一个玩家，但代码层面没有把它们绑定在一起。

类的作用，就是定义一种新的数据类型，把一组相关数据和操作这些数据的函数组织到一起。

## 类和对象

`class Player` 定义的是一种类型，类似于自己创建了一个新的“变量类型”。

```cpp
class Player {
public:
    std::string name;
    int level;
    int score;
};
```

`Player alice;` 才是真正创建了一个对象。

```cpp
Player alice;
```

可以这样理解：

- `Player` 是类型。
- `alice` 是这个类型创建出来的一个对象。
- `bob` 是另一个独立对象。

## 成员变量

类里面定义的变量叫成员变量。

```cpp
class Player {
public:
    std::string name;
    int level;
    int score;
};
```

每个对象都有自己的一份成员变量：

```cpp
Player alice;
Player bob;

alice.score = 10;
bob.score = 30;
```

修改 `alice.score` 不会修改 `bob.score`，因为它们是两个不同对象里的成员变量。

## 成员函数

类里面定义的函数叫成员函数。

```cpp
void gain_score(int amount) {
    score += amount;
}
```

调用方式：

```cpp
alice.gain_score(15);
```

这表示：对 `alice` 这个对象执行 `gain_score`，所以函数里面的 `score` 指的是 `alice.score`。

如果写：

```cpp
bob.gain_score(15);
```

函数里面的 `score` 就指的是 `bob.score`。

## 工程原因

类把“数据”和“操作数据的函数”放在一起，主要是为了：

- 让代码表达真实概念，例如玩家、订单、文件、连接、配置。
- 减少散落变量，降低传错参数的风险。
- 让相关逻辑集中，方便维护。
- 为后续访问控制、构造函数、析构函数和 RAII 打基础。

现在我们先使用 `public`，让外部代码可以直接访问成员。后面会学习 `private`，让对象保护自己的内部状态。

# D2 构造函数、析构函数

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解为什么需要构造函数。
- 理解为什么需要析构函数。
- 观察对象在作用域结束时自动析构。
- 观察 `new` 创建的对象在 `delete` 时析构。

## 为什么需要构造函数

D1 里创建对象后，需要手动给每个成员变量赋值：

```cpp
Player alice;
alice.name = "Alice";
alice.level = 1;
alice.score = 10;
```

工程里的问题是：对象刚创建出来时，可能处于“不完整状态”。例如忘记设置 `score`，后面代码却直接使用它。

构造函数的作用是：对象创建时自动执行，把对象初始化成一个可用状态。

```cpp
Player(std::string player_name, int player_level, int player_score)
    : name(player_name), level(player_level), score(player_score) {
    std::cout << "construct Player: " << name << std::endl;
}
```

使用时直接传入初始化数据：

```cpp
Player alice("Alice", 1, 10);
```

这样 `alice` 创建完成后，`name`、`level`、`score` 已经有明确值。

## 构造函数的写法

构造函数的特点：

- 名字和类名相同。
- 没有返回值类型。
- 创建对象时自动调用。

```cpp
class Player {
public:
    Player(std::string player_name, int player_level, int player_score)
        : name(player_name), level(player_level), score(player_score) {
    }
};
```

冒号后面的部分叫成员初始化列表：

```cpp
: name(player_name), level(player_level), score(player_score)
```

它表示在对象创建过程中初始化成员变量。后面学习 `const` 成员、引用成员和复杂对象时，成员初始化列表会变得更重要。

## 为什么需要析构函数

对象不只会“出生”，也会“离开”。

栈上的局部对象离开作用域时会自动销毁：

```cpp
{
    Player bob("Bob", 2, 30);
}
```

离开 `{}` 后，`bob` 的生命周期结束。

析构函数的作用是：对象销毁时自动执行，用于做收尾工作。

```cpp
~Player() {
    std::cout << "destruct Player: " << name << std::endl;
}
```

析构函数的特点：

- 名字是 `~类名`。
- 没有返回值类型。
- 通常没有参数。
- 对象生命周期结束时自动调用。

## 栈对象和堆对象的析构时机

栈对象：

```cpp
Player alice("Alice", 1, 10);
```

`alice` 会在所在作用域结束时自动析构。

堆对象：

```cpp
Player* heap_player = new Player("HeapPlayer", 3, 50);
delete heap_player;
```

`new` 会创建对象并调用构造函数。  
`delete` 会调用析构函数，然后释放堆内存。

如果忘记 `delete`，堆对象的析构函数不会在正确时机执行，堆内存也不会被释放。

## 工程原因

构造函数解决的是“对象一创建就应该可用”的问题。

析构函数解决的是“对象离开时应该自动收尾”的问题。

这两个机制是后续 RAII 的基础。RAII 的核心思想是：把资源的获取放进构造函数，把资源的释放放进析构函数，让对象生命周期管理资源生命周期。

## D2 补充：构造函数为什么没有返回值类型

构造函数不是普通函数。普通函数是“已经有程序在运行，然后调用函数，函数算出一个结果并返回”。

构造函数发生在对象创建过程中：

```cpp
Player alice("Alice", 1, 100);
```

这行代码的含义不是“调用一个函数返回一个 `Player`”，而是：

- 为 `alice` 这个对象准备存储空间。
- 调用 `Player` 的构造函数初始化这块存储空间里的成员。
- 初始化完成后，`alice` 这个对象开始可用。

所以构造函数没有返回值类型。它的职责不是返回东西，而是把“正在创建的这个对象”初始化好。

如果确实需要“函数返回一个对象”，那是普通函数的工作：

```cpp
Player create_player() {
    Player player("Alice", 1, 100);
    return player;
}
```

这里 `create_player()` 有返回值类型 `Player`，但 `Player(...)` 构造函数本身仍然没有返回值类型。

## D2 补充：为什么创建时初始化更稳妥

先创建对象再逐个赋值的问题是：对象会有一段时间处于“不完整状态”。

```cpp
LoosePlayer loose;
loose.print_info();  // 此时还没有 setup
loose.setup("Alice", 1, 100);
```

如果某个函数在 `setup` 之前使用了对象，就可能读到不完整状态。

构造函数把必要数据放在创建对象时一次性传入：

```cpp
Player alice("Alice", 1, 100);
alice.print_info();
```

这样 `alice` 一创建出来就有 `name`、`level`、`hp`，后面的代码不需要猜它是否已经准备好。

工程里这很重要，因为对象经常会被传给其他函数、放进容器、作为成员变量保存。如果对象允许“半初始化”状态，维护者就必须到处检查它到底准备好了没有，错误会变得隐蔽。

# D3 `this`、访问控制：`public/private`

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解成员函数里的 `this` 指向谁。
- 理解为什么需要 `private`。
- 理解 `public` 是对象对外提供的接口。
- 理解类如何保护自己的内部状态。

## 为什么需要 `this`

D1 里我们说过：

```cpp
alice.print_info();
bob.print_info();
```

同一个成员函数，为什么调用 `alice.print_info()` 时打印的是 `alice` 的数据，调用 `bob.print_info()` 时打印的是 `bob` 的数据？

原因是：成员函数被调用时，C++ 会隐式传入“当前对象”的地址，这个地址可以通过 `this` 访问。

```cpp
void print_info() {
    std::cout << this << std::endl;
}
```

如果：

```cpp
alice.print_info();
```

那么 `this` 指向 `alice`。

如果：

```cpp
bob.print_info();
```

那么 `this` 指向 `bob`。

所以成员函数里的成员变量访问，本质上是在访问当前对象的成员。

## `this->` 的常见用途

当参数名和成员变量名相同时，`this->` 可以明确表示访问的是成员变量。

```cpp
class Player {
private:
    std::string name;

public:
    void rename(std::string name) {
        this->name = name;
    }
};
```

这里：

- 左边的 `this->name` 是当前对象的成员变量。
- 右边的 `name` 是函数参数。

## 为什么需要 `private`

如果所有成员变量都是 `public`，外部代码可以随便改对象内部状态：

```cpp
alice.hp = -999;
```

这会让对象进入不合理状态。工程里这种问题很危险，因为坏状态可能不是立刻崩溃，而是在后面某个功能里变成难查的错误。

`private` 的作用是：不允许类外代码直接访问内部数据。

```cpp
class Player {
private:
    int hp;
    int max_hp;
};
```

类外不能直接写：

```cpp
alice.hp = -999;
```

## `public` 是对外接口

虽然成员变量是 `private`，但类可以提供 `public` 成员函数，让外部以受控方式操作对象：

```cpp
void take_damage(int amount) {
    if (amount <= 0) {
        return;
    }

    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
}
```

这样外部不能随便把 `hp` 改成负数，只能通过类提供的规则修改。

## 工程原因

`private` 和 `public` 的核心不是“藏起来”，而是建立边界：

- 内部数据由类自己维护。
- 外部代码只通过稳定接口使用对象。
- 类可以保证自己的状态不容易被改坏。
- 后续修改内部实现时，外部调用代码可以少受影响。

这就是封装的基础。

# D4 拷贝构造、赋值运算符

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解什么是拷贝构造函数。
- 理解什么是赋值运算符。
- 区分“创建新对象时拷贝”和“已有对象被赋值”。
- 观察按值传参也会触发拷贝。

## 为什么需要学习拷贝

对象不只会被创建和销毁，还会被复制。

例如：

```cpp
Player alice("Alice", 100);
Player bob = alice;
```

这表示创建一个新对象 `bob`，并用 `alice` 初始化它。

如果对象里只有 `int`、`std::string` 这类成员，默认拷贝通常能工作。但后面一旦对象拥有堆内存、文件句柄、网络连接等资源，拷贝就会变得危险。

D4 先学习拷贝发生在哪里，后续 RAII 再学习如何管理资源拷贝。

## 拷贝构造函数

拷贝构造函数用于“创建新对象时，用另一个同类型对象初始化它”。

```cpp
Player(const Player& other)
    : name(other.name), hp(other.hp) {
}
```

常见触发方式：

```cpp
Player bob = alice;
Player bob(alice);
```

参数通常写成 `const Player& other`：

- 用引用避免为了传参再拷贝一次。
- 用 `const` 表示不会修改来源对象。

## 赋值运算符

赋值运算符用于“已有对象被另一个对象覆盖状态”。

```cpp
Player& operator=(const Player& other) {
    name = other.name;
    hp = other.hp;
    return *this;
}
```

触发方式：

```cpp
Player charlie("Charlie", 50);
charlie = alice;
```

这里 `charlie` 已经存在，所以不是构造新对象，而是把 `alice` 的状态赋给已有的 `charlie`。

## 为什么返回 `Player&`

赋值运算符通常返回当前对象的引用：

```cpp
return *this;
```

这是为了支持连续赋值：

```cpp
a = b = c;
```

这里 `*this` 表示当前对象本身，返回引用可以避免不必要的拷贝。

## 自赋值检查

赋值时可能出现：

```cpp
charlie = charlie;
```

这叫自赋值。

对于现在这种只有 `std::string` 和 `int` 的类，自赋值通常问题不大。但当类管理堆内存时，如果没有自赋值检查，可能先释放自己的资源，再从已经被释放的自己那里拷贝，导致严重错误。

所以常见写法会先判断：

```cpp
if (this == &other) {
    return *this;
}
```

## 按值传参也会拷贝

如果函数这样写：

```cpp
void print_by_value(Player player)
```

调用：

```cpp
print_by_value(alice);
```

会创建一个参数对象 `player`，用 `alice` 拷贝构造出来。

工程里如果对象很大，按值传参会带来额外拷贝成本。后续会更常用 `const Player&` 来避免拷贝。

## 工程原因

拷贝构造和赋值运算符让我们能控制对象复制时发生什么。

这对工程很重要，因为对象可能拥有资源：

- 堆内存。
- 文件。
- 锁。
- 网络连接。
- 图形资源。

如果只是简单复制地址，两个对象可能以为自己都拥有同一份资源，最后重复释放或互相影响。D4 是后续 RAII、智能指针和资源管理的基础。

## D4 补充：为什么拷贝构造参数写成 `const Player& other`

拷贝构造函数通常这样写：

```cpp
Player(const Player& other)
```

这里有两个关键点：引用 `&` 和 `const`。

### 为什么必须用引用

如果拷贝构造函数参数不用引用，而是写成类似：

```cpp
Player(Player other)
```

就会出现逻辑循环：

1. 为了拷贝构造一个新 `Player`，需要调用拷贝构造函数。
2. 但调用 `Player(Player other)` 时，参数 `other` 是按值传入。
3. 按值传入本身又需要先拷贝出一个 `other`。
4. 为了拷贝出 `other`，又需要调用拷贝构造函数。
5. 于是无限递归。

所以拷贝构造函数参数必须是引用：

```cpp
Player(Player& other)
```

这样传进来的不是一个新副本，而是已有对象的别名。

### 为什么通常加 `const`

拷贝来源对象只是被读取，不应该被修改。

```cpp
Player(const Player& other)
```

`const` 表示：我只是从 `other` 读数据来初始化当前对象，不会改坏来源对象。

这也让函数可以接受临时对象或只读对象，接口更稳。

## D4 补充：为什么赋值运算符要检查自赋值

赋值运算符通常有这段：

```cpp
if (this == &other) {
    return *this;
}
```

它处理的是：

```cpp
player = player;
```

现在 `Player` 只有 `std::string` 和 `int`，自赋值通常没大问题。

但如果类自己管理堆内存，问题就来了：

```cpp
delete score;
score = new int(*other.score);
```

如果 `other` 就是自己，那么 `other.score` 和 `score` 是同一个地址。  
第一行 `delete score` 已经释放了这块内存。  
第二行再读 `*other.score`，就是从已经释放的内存里读值，属于危险行为。

因此资源管理类里，赋值运算符常常先判断是不是自己赋值给自己。

## 这两个点和工程的关系

`const Player& other` 解决的是“拷贝来源如何安全传进来”的问题。

自赋值检查解决的是“已有对象覆盖自己状态时，不能破坏自己的资源”的问题。

现在只是基础类，后续学 RAII、智能指针、文件对象、容器对象时，这些规则会变得非常重要。

# D5 继承、多态、虚函数

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解为什么需要继承。
- 理解派生类和基类的关系。
- 理解为什么需要虚函数。
- 理解多态：同一个接口，根据真实对象类型执行不同逻辑。

## 为什么需要继承

如果程序里有多种角色：

```cpp
Warrior
Mage
```

它们都有共同信息：

```cpp
name
hp
print_status()
```

如果每个类都重复写一份，代码会越来越难维护。

继承的作用是：把共同部分放到基类里，让具体类型复用它。

```cpp
class Character {
protected:
    std::string name;
    int hp;
};

class Warrior : public Character {
};

class Mage : public Character {
};
```

这里：

- `Character` 是基类。
- `Warrior` 和 `Mage` 是派生类。
- `public Character` 表示公开继承。

## `protected`

D3 学过 `private` 和 `public`。

继承里还会遇到 `protected`：

```cpp
protected:
    std::string name;
    int hp;
```

`protected` 的意思是：

- 类外不能直接访问。
- 派生类可以访问。

所以 `Warrior` 可以在自己的成员函数里使用 `name`，但 `main()` 不能直接写：

```cpp
warrior.name = "Bad";
```

## 为什么需要虚函数

基类可以定义一个通用行为：

```cpp
virtual void act() const {
    std::cout << name << " waits." << std::endl;
}
```

派生类可以覆盖它：

```cpp
void act() const override {
    std::cout << name << " swings a sword." << std::endl;
}
```

`virtual` 表示：这个函数支持运行时多态。

`override` 表示：我明确要覆盖基类的虚函数。如果函数签名写错，编译器会提醒。

## 什么是多态

看这个函数：

```cpp
void run_turn(const Character& character) {
    character.act();
}
```

参数类型是 `const Character&`，但传入的真实对象可以是：

```cpp
run_turn(npc);
run_turn(warrior);
run_turn(mage);
```

如果 `act()` 是虚函数，那么运行时会根据真实对象类型调用不同版本：

- `Character` 调用 `Character::act()`。
- `Warrior` 调用 `Warrior::act()`。
- `Mage` 调用 `Mage::act()`。

这就是多态。

## 工程原因

继承解决的是“共同代码复用”和“类型层次表达”的问题。

虚函数和多态解决的是“统一接口，不同实现”的问题。

例如游戏里可以用统一的 `Character&` 处理所有角色；UI 里可以用统一的 `Widget&` 处理按钮、输入框、列表；文件系统里可以用统一的 `FileSystemEntry&` 处理文件和目录。

后续会继续学习什么时候该用继承，什么时候组合更合适。

## D5 补充：重载、重写、虚函数

这三个词很容易混在一起。

重载 overload：同一个作用域里，函数名相同，但参数列表不同。

```cpp
void act() const;
void act(int times) const;
```

这两个函数都叫 `act`，但参数不同，所以是重载。

重写 override：派生类重新实现基类的虚函数。

```cpp
class Character {
public:
    virtual void act() const;
};

class Warrior : public Character {
public:
    void act() const override;
};
```

这里 `Warrior::act()` 是重写 `Character::act()`。

`virtual` 的作用是启用动态绑定。也就是通过基类引用或指针调用函数时，C++ 会看真实对象类型：

```cpp
void run_turn(const Character& character) {
    character.act();
}
```

如果传入的是 `Warrior`，并且 `act()` 是虚函数，就会调用 `Warrior::act()`。

`override` 的作用是让编译器检查：这个函数是否真的重写了基类虚函数。如果参数、`const`、函数名写错，编译器会报错。

## D5 补充：`protected` 和 `private`

`private`：

- 类外不能直接访问。
- 派生类也不能直接访问。
- 只能由本类自己的成员函数直接访问。

`protected`：

- 类外不能直接访问。
- 派生类可以直接访问。

例如：

```cpp
class Character {
private:
    int id;

protected:
    std::string name;
};
```

`Warrior` 可以直接使用 `name`，但不能直接使用 `id`。

如果外部需要读取 `id`，应该由基类提供 `public` 函数：

```cpp
void print_id() const;
```

这保持了 D3 学过的封装边界。

# D6 RAII 基础

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 理解 RAII 为什么解决资源释放问题。
- 理解资源获取放进构造函数。
- 理解资源释放放进析构函数。
- 理解对象离开作用域时会自动释放资源。
- 理解为什么拥有资源的类要认真处理拷贝。

## 为什么需要 RAII

前面学习 `new/delete` 时，我们手动管理堆内存：

```cpp
int* scores = new int[3];
delete[] scores;
```

问题是：工程代码里经常有多个出口。

```cpp
int* scores = new int[3];

if (early_return) {
    return;  // 如果忘记 delete[]，就泄漏
}

delete[] scores;
```

只要某条路径忘记释放，就会内存泄漏。

RAII 的思路是：不要让调用方到处记得释放，而是让对象自己负责资源。

## RAII 是什么

RAII 是 Resource Acquisition Is Initialization。

可以先不背英文，记住这句话：

> 资源获取放进构造函数，资源释放放进析构函数。

例如：

```cpp
class ScoreArray {
private:
    int* data;

public:
    ScoreArray(int size) : data(new int[size]) {
    }

    ~ScoreArray() {
        delete[] data;
    }
};
```

创建对象时自动申请资源：

```cpp
ScoreArray scores(3);
```

对象离开作用域时自动调用析构函数释放资源。

## RAII 和作用域

```cpp
void example() {
    ScoreArray scores(3);

    if (some_condition) {
        return;
    }
}
```

即使中途 `return`，`scores` 是局部对象，离开函数作用域时仍然会析构。

这就是 RAII 的工程价值：释放动作绑定到对象生命周期，而不是依赖程序员记住每条路径都写 `delete`。

## 为什么禁用拷贝

`ScoreArray` 里有一个指针：

```cpp
int* data;
```

它拥有一块堆内存。

如果直接允许默认拷贝，两个 `ScoreArray` 对象可能保存同一个 `data` 地址。两个对象析构时都会 `delete[] data`，造成重复释放。

所以基础 RAII 类可以先禁止拷贝：

```cpp
ScoreArray(const ScoreArray& other) = delete;
ScoreArray& operator=(const ScoreArray& other) = delete;
```

这表示：

- 不能拷贝构造。
- 不能赋值。

后续现代 C++ 会学习更好的资源所有权表达，例如 `std::unique_ptr`。

## 工程原因

RAII 把资源生命周期和对象生命周期绑定起来。

这能管理很多资源：

- 堆内存。
- 文件。
- 网络连接。
- 锁。
- 图形资源。

RAII 是 C++ 工程能力里非常核心的思想。后续 STL、智能指针、文件流、锁对象，本质上都大量依赖 RAII。

## D6 补充：默认拷贝为什么危险

如果一个类里有裸指针：

```cpp
int* data;
```

默认拷贝不会自动申请一块新的堆内存。它只会把成员变量逐个复制。

也就是说：

```cpp
ScoreArray a(3);
ScoreArray b = a;
```

如果允许默认拷贝，可能得到：

```text
a.data == 0x1000
b.data == 0x1000
```

两个对象保存同一个堆地址。

这叫浅拷贝。危险在于：

- `a` 觉得自己拥有这块内存。
- `b` 也觉得自己拥有这块内存。
- `a` 析构时 `delete[] data`。
- `b` 析构时又 `delete[] data`。

同一块堆内存被释放两次，就是重复释放。

所以拥有资源的 RAII 类不能随便默认拷贝。基础阶段可以先禁用拷贝：

```cpp
ScoreArray(const ScoreArray& other) = delete;
ScoreArray& operator=(const ScoreArray& other) = delete;
```

## D6 补充：RAII 可以管理哪些资源

RAII 不只是管理堆内存。

只要某个东西需要“获取”和“释放”，就适合用 RAII 管理。

常见例子：

- 堆内存：`new` / `delete`。
- 文件：打开文件 / 关闭文件。
- 锁：加锁 / 解锁。
- 网络连接：连接 / 断开。
- 数据库连接：打开连接 / 关闭连接。
- 图形资源：创建纹理 / 销毁纹理。

工程里最常见的 RAII 类型之一是文件流：

```cpp
std::ofstream file("a.txt");
file << "hello";
```

当 `file` 离开作用域时，文件流对象会自动关闭文件。

后续学习 STL、文件 IO、智能指针和并发锁时，会不断看到 RAII。

# 04_oop 阶段复盘：对象生命周期和资源管理

## 当前阶段

本知识点属于 `04_oop` 阶段。

本轮目标：

- 把类、对象、构造函数、析构函数、拷贝构造、赋值运算符、多态和 RAII 串起来。
- 理解为什么“拥有资源的对象”需要特别关心拷贝。
- 理解为什么 C++ 工程里经常把资源交给对象管理。

示例文件：

```text
04_oop/oop_stage_review.cpp
```

## 为什么需要阶段复盘

前面 D1-D6 分别学的是独立概念：

- 类把相关数据和函数组织在一起。
- 构造函数让对象创建完成后处于可用状态。
- 析构函数让对象离开作用域时自动收尾。
- `private` 让对象保护自己的内部状态。
- 拷贝构造和赋值运算符决定对象被复制时发生什么。
- `virtual` 让基类引用可以根据真实对象类型调用函数。
- RAII 把资源获取和释放绑定到对象生命周期。

工程里这些概念通常不是分开出现的。一个真正有用的类，往往既有内部状态，又有生命周期，还可能拥有资源。

## 复盘示例的核心结构

`ScoreLog` 管理一块堆数组：

```cpp
class ScoreLog {
private:
    int* scores;
    int size;
};
```

这里的 `scores` 是一个裸指针，但它不是随便借用别人的地址，而是通过 `new int[...]` 申请来的堆资源。

所以 `ScoreLog` 要负责三件事：

- 构造时申请资源。
- 析构时释放资源。
- 拷贝时不能只复制地址。

## 为什么拷贝时不能只复制地址

如果默认拷贝一个拥有裸指针资源的对象，可能出现：

```text
first.scores  -> 0x1000
second.scores -> 0x1000
```

两个对象保存同一个堆数组地址。它们析构时都会执行 `delete[] scores`，这会导致重复释放。

所以复盘示例里的 `ScoreLog` 使用深拷贝：

```cpp
ScoreLog(const ScoreLog& other)
    : scores(new int[other.size]), size(other.size) {
    for (int i = 0; i < size; ++i) {
        scores[i] = other.scores[i];
    }
}
```

深拷贝的含义是：新对象申请自己的堆数组，再把内容复制过去。

这样两个对象的数据地址不同，生命周期也互不干扰。

## 赋值运算符为什么更复杂

拷贝构造发生在创建新对象时：

```cpp
Player bob = alice;
```

赋值运算符发生在已有对象被另一个对象覆盖时：

```cpp
charlie = alice;
```

已有对象原本可能已经拥有资源。因此赋值时要考虑：

- 是否是自赋值。
- 新资源是否申请成功。
- 旧资源什么时候释放。
- 成员变量如何更新。

示例里先申请新数组，再释放旧数组：

```cpp
int* new_scores = new int[other.size];
delete[] scores;
scores = new_scores;
```

这样比先删除旧资源再申请新资源更稳，因为对象不会在中途失去原来的有效资源。

## 多态在复盘中的作用

`Character` 是基类，`Player` 是派生类：

```cpp
class Player : public Character {
};
```

`run_turn` 接收基类引用：

```cpp
void run_turn(const Character& character) {
    character.take_turn();
}
```

因为 `take_turn` 是虚函数：

```cpp
virtual void take_turn() const;
```

所以传入 `Player` 对象时，会调用 `Player::take_turn()`。

这就是多态的工程价值：调用方可以面向更通用的类型写代码，具体行为由真实对象决定。

## 为什么基类析构函数要是 virtual

复盘示例里 `Character` 的析构函数写成：

```cpp
virtual ~Character()
```

原因是：如果将来通过基类指针管理派生类对象，例如：

```cpp
Character* character = new Player("Alice", 100);
delete character;
```

只有基类析构函数是 `virtual`，才能确保先调用 `Player` 的析构函数，再调用 `Character` 的析构函数。

这能避免派生类拥有的资源没有被正确释放。

## 本阶段复盘结论

面向对象不是只为了把函数放进类里。

从工程角度看，类更重要的作用是：

- 定义稳定的对象状态。
- 控制外部如何修改对象。
- 把初始化和清理放进生命周期。
- 明确对象被拷贝和赋值时的行为。
- 通过多态降低调用方对具体类型的依赖。
- 用 RAII 管理资源，减少手动释放遗漏。

完成本轮后，可以准备进入 `05_stl`。学习 STL 时要带着这个视角：很多 STL 类型本质上也是对象，它们在内部管理资源，并通过构造、析构、拷贝和赋值提供稳定行为。
