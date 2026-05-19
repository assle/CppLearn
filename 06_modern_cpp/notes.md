# F1 auto 和范围 for

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `auto_range_for_basic.cpp`

## 为什么需要 auto

在 C++ 中，每个变量都有明确类型。`auto` 不是“没有类型”，而是让编译器根据右边的初始化表达式推导出类型。

工程代码里经常会遇到很长的类型，例如：

```cpp
std::vector<int>::const_iterator it = scores.begin();
```

写成：

```cpp
auto it = scores.begin();
```

含义不是放弃类型，而是让编译器推导 `it` 的真实类型。这样可以减少重复、降低写错复杂类型的概率，也能让代码更关注业务意图。

## 为什么需要范围 for

很多遍历代码本质都在做三件事：

1. 从 `begin()` 开始；
2. 没到 `end()` 就继续；
3. 每次 `++it` 移动到下一个元素。

传统迭代器遍历：

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    std::cout << *it << std::endl;
}
```

范围 `for` 把这个模式简化成：

```cpp
for (auto score : scores) {
    std::cout << score << std::endl;
}
```

背后仍然依赖容器的 `begin()` 和 `end()`。所以它能遍历 `vector`、`set`、`map` 等标准容器。

## auto、auto&、const auto&

### auto

```cpp
for (auto score : scores) {
    score += 10;
}
```

这里的 `score` 是容器元素的副本。修改 `score` 不会修改 `scores` 中的原元素。

适合：

- 元素很小；
- 只需要读；
- 不在乎复制成本。

### auto&

```cpp
for (auto& score : scores) {
    score += 10;
}
```

这里的 `score` 是原元素的引用。修改 `score` 会修改容器里的元素。

适合：

- 需要修改原元素；
- 希望避免复制。

### const auto&

```cpp
for (const auto& player : players) {
    std::cout << player.name << std::endl;
}
```

这里的 `player` 是原元素的只读引用。不会复制元素，也不能修改元素。

适合：

- 只读遍历；
- 元素较大，例如 `std::string`、结构体、类对象；
- 希望避免不必要的拷贝。

## map 的范围 for

`std::map<std::string, int>` 的每个元素可以理解成一个键值对。

```cpp
for (const auto& item : name_to_score) {
    std::cout << item.first << ": " << item.second << std::endl;
}
```

其中：

- `item.first` 是键；
- `item.second` 是值；
- `const auto&` 避免复制键值对，也避免误修改。

## 工程习惯

常见选择：

- 只读小类型：`auto`
- 需要修改原元素：`auto&`
- 只读大对象：`const auto&`

看到范围 `for` 时，要先判断：这次遍历是读取、修改，还是需要避免拷贝。

# F2 nullptr

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `nullptr_basic.cpp`

## 为什么需要 nullptr

指针变量保存的是对象地址。但工程代码中经常需要表达“现在没有指向任何对象”。

早期 C/C++ 代码里常见写法是：

```cpp
Player* player = 0;
```

或者：

```cpp
Player* player = NULL;
```

问题是：`0` 本身也是整数。`NULL` 在很多环境中也可能只是 `0` 的宏定义。这样在函数重载、类型判断和阅读代码时容易产生歧义。

现代 C++ 使用：

```cpp
Player* player = nullptr;
```

`nullptr` 的意思很明确：这是一个空指针值。它不是整数 `0`，而是专门用于指针的空值。

## 空指针为什么需要检查

指针可能指向有效对象：

```cpp
Player alice = {"Alice", 80};
Player* player = &alice;
```

也可能不指向任何对象：

```cpp
Player* player = nullptr;
```

如果对空指针解引用：

```cpp
std::cout << player->name << std::endl;
```

程序会访问一个不存在的对象，属于未定义行为，常见结果是崩溃。

所以使用指针参数时，常见写法是先检查：

```cpp
void print_player(const Player* player) {
    if (player == nullptr) {
        return;
    }

    std::cout << player->name << std::endl;
}
```

## nullptr 和函数重载

如果有两个函数：

```cpp
void choose_target(int target_id);
void choose_target(Player* player);
```

调用：

```cpp
choose_target(0);
```

`0` 更像整数，所以会调用 `int` 版本。

调用：

```cpp
choose_target(nullptr);
```

`nullptr` 是空指针值，所以会调用指针版本。

这就是 `nullptr` 的工程价值：表达更准确，减少歧义。

## delete 后为什么常把指针设为 nullptr

```cpp
Player* player = new Player{"Bob", 60};
delete player;
player = nullptr;
```

`delete player` 释放的是指针指向的堆对象。指针变量 `player` 自己还存在。

如果不置空，它可能还保存旧地址，变成悬空指针。后续代码如果误用它，风险很高。

置为 `nullptr` 后，至少可以通过空指针检查挡住误用：

```cpp
if (player == nullptr) {
    std::cout << "no player" << std::endl;
}
```

## 工程习惯

- 表示空指针时，用 `nullptr`。
- 检查指针是否为空时，优先写清楚：`ptr == nullptr` 或 `ptr != nullptr`。
- 指针参数如果允许为空，函数内部要先检查。
- `delete` 后如果这个指针变量还可能被后续代码看到，可以把它设为 `nullptr`。
- 不要用 `0` 或 `NULL` 表达现代 C++ 里的空指针。

# F3 智能指针：unique_ptr 和 shared_ptr

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `smart_pointer_basic.cpp`

## 为什么需要智能指针

前面学过裸指针和 `new/delete`：

```cpp
Player* player = new Player{"Alice", 80};
delete player;
player = nullptr;
```

这种写法的问题是：释放责任完全靠人记住。工程代码一复杂，就容易出现：

- 忘记 `delete`，造成内存泄漏；
- 提前 `return` 或异常路径漏掉释放；
- 同一块堆对象被多个指针误以为自己负责释放，造成重复释放；
- `delete` 后还继续使用旧指针，造成悬空指针。

智能指针的核心价值是：把“谁负责释放资源”写进类型里，让对象生命周期自动管理资源。这是标准库版本的 RAII。

## unique_ptr：独占所有权

```cpp
std::unique_ptr<Player> player = std::make_unique<Player>("Alice", 80);
```

`unique_ptr` 表示：这块堆对象当前只有一个所有者。

当 `unique_ptr` 离开作用域时，它会自动 `delete` 自己拥有的对象。

所以通常不用手写：

```cpp
delete player;
```

## 为什么 unique_ptr 不能复制

如果两个 `unique_ptr` 同时拥有同一个堆对象，它们离开作用域时都会释放同一块内存，这会造成重复释放。

所以 `unique_ptr` 禁止复制：

```cpp
// std::unique_ptr<Player> other = player; // 编译错误
```

如果确实要转移所有权，要显式写：

```cpp
std::unique_ptr<Player> owner = std::move(player);
```

转移后，原来的 `player` 通常变为空。

## 借用对象时不要拿走所有权

如果函数只是临时读取或修改对象，不应该接收 `unique_ptr` 本身。

只读借用：

```cpp
void print_player(const Player& player);
```

可修改借用：

```cpp
void heal_player(Player& player, int amount);
```

调用时：

```cpp
print_player(*player);
heal_player(*player, 10);
```

这里的 `*player` 是解引用智能指针，得到它拥有的 `Player` 对象。

## shared_ptr：共享所有权

```cpp
std::shared_ptr<Player> player = std::make_shared<Player>("Alice", 80);
```

`shared_ptr` 表示：这块堆对象可以有多个所有者。

每复制一个 `shared_ptr`，引用计数会增加。每销毁一个 `shared_ptr`，引用计数会减少。当最后一个 `shared_ptr` 销毁时，堆对象才会被释放。

```cpp
std::shared_ptr<Player> a = std::make_shared<Player>("Alice", 80);
std::shared_ptr<Player> b = a;
```

此时 `a` 和 `b` 共同拥有同一个对象。

## 工程习惯

- 默认优先考虑 `unique_ptr`，因为独占所有权更清楚。
- 只有确实需要多个地方共同延长对象生命时，才使用 `shared_ptr`。
- 临时使用对象时，优先传引用：`Player&` 或 `const Player&`。
- 不要为了“方便”到处传 `shared_ptr`，否则对象到底由谁负责会变得不清楚。
- 优先用 `std::make_unique` 和 `std::make_shared` 创建智能指针。

# F4 移动语义：右值引用和 std::move

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `move_semantics_basic.cpp`

## 为什么需要移动语义

有些对象内部管理资源，例如堆内存、文件句柄、网络连接、线程、锁等。

如果复制这类对象，通常有两种风险：

- 浅拷贝：两个对象保存同一个资源地址，容易重复释放；
- 深拷贝：为新对象重新申请资源并复制内容，安全但可能很贵。

移动语义解决的是第三种情况：如果源对象马上就不用了，可以把它内部资源“转交”给新对象，而不是重新复制一份。

这就是移动的工程意义：**避免不必要的深拷贝，同时保持资源所有权清楚。**

## 拷贝和移动的区别

拷贝构造：

```cpp
ScoreBuffer copied = first;
```

含义是：`first` 还要继续保持可用，所以 `copied` 需要拥有一份独立资源。

移动构造：

```cpp
ScoreBuffer moved = std::move(first);
```

含义是：允许从 `first` 取走资源，让 `moved` 接管资源。移动后，`first` 仍然是一个合法对象，但内容通常已经被清空或变成“被移动后”的状态。

## std::move 到底做了什么

`std::move(first)` 这个名字容易误导。

它本身不会移动内存，也不会释放对象。它只是告诉编译器：

```text
这个表达式可以被当成“即将不用的对象”来处理。
```

真正转移资源的是移动构造函数或移动赋值运算符。

```cpp
ScoreBuffer(ScoreBuffer&& other) noexcept;
ScoreBuffer& operator=(ScoreBuffer&& other) noexcept;
```

其中 `ScoreBuffer&&` 是右值引用。它通常用于接收可以被移动的对象。

## 移动构造函数做什么

移动构造通常做三件事：

1. 偷走源对象的资源指针；
2. 把源对象指针置空；
3. 让源对象析构时不会释放已经转走的资源。

示意：

```cpp
ScoreBuffer(ScoreBuffer&& other) noexcept
    : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}
```

这样 `data_` 不需要重新申请和复制，资源所有权从 `other` 转移到了新对象。

## 移动后的对象还能不能用

能，但只能依赖它仍然“合法可析构、可重新赋值”。

不要假设移动后的对象还保留原来的业务内容。

比如：

```cpp
ScoreBuffer moved = std::move(first);
```

之后 `first` 仍然会正常析构，但它的内部资源可能已经被置空。

## 为什么 noexcept 常见于移动构造

标准库容器例如 `std::vector` 在扩容时可能需要搬迁元素。

如果元素的移动构造标记为 `noexcept`，容器更愿意使用移动而不是拷贝，因为移动失败风险更低。

所以资源管理类的移动构造和移动赋值通常写：

```cpp
ScoreBuffer(ScoreBuffer&& other) noexcept;
ScoreBuffer& operator=(ScoreBuffer&& other) noexcept;
```

## 工程习惯

- 需要保留源对象内容时，用拷贝。
- 源对象以后不再需要原内容时，可以考虑移动。
- `std::move` 不移动任何东西，它只是允许后续调用移动构造或移动赋值。
- 移动后对象仍然合法，但不要依赖其原内容。
- 自己写资源管理类时，要同时认真考虑析构、拷贝、赋值、移动。


# F5 Lambda

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `lambda_basic.cpp`

## 为什么需要 Lambda

前面学过标准算法，例如：

```cpp
std::sort(scores.begin(), scores.end());
```

这类算法只负责通用流程：排序、查找、统计、遍历。

但工程代码里的规则经常不是固定的。例如：

- 玩家按分数从高到低排序；
- 查找第一个分数大于某条线的玩家；
- 统计血量超过某个阈值的玩家；
- 给每个玩家执行一小段临时逻辑。

如果每个小规则都单独写成一个普通函数，代码会分散，名字也会变多。Lambda 的价值是：把“一小段只在这里使用的规则”直接写在调用点附近。

这样读代码的人可以马上看到：

```text
这个算法在处理什么范围，以及它使用什么判断规则。
```

## Lambda 基本写法

最小形式：

```cpp
[](const Player& player) {
    return player.score >= 85;
}
```

可以先把它理解成一个没有名字的小函数。

结构是：

```cpp
[捕获列表](参数列表) {
    函数体
}
```

例如：

```cpp
auto is_passed = [](const Player& player) {
    return player.score >= 85;
};
```

这里 `auto` 让编译器推导 Lambda 的真实类型。Lambda 的真实类型由编译器生成，通常不用手写。

## 配合 sort 自定义排序规则

默认 `std::sort` 会按元素自己的 `<` 规则排序。对于结构体 `Player`，编译器不知道“玩家大小”应该按名字、分数还是血量比较。

所以需要把排序规则传给 `std::sort`：

```cpp
std::sort(players.begin(), players.end(),
          [](const Player& left, const Player& right) {
              return left.score > right.score;
          });
```

这个 Lambda 的意思是：如果 `left` 的分数更高，就让 `left` 排在 `right` 前面。

参数使用 `const Player&`，因为排序规则只需要读取两个玩家，不应该修改它们，也不需要复制整个对象。

## 配合 find_if 自定义查找规则

`std::find` 适合查找“等于某个值”的元素。

工程里更常见的是按条件找，例如“第一个分数不低于及格线的玩家”。这时用 `std::find_if`：

```cpp
int pass_score = 85;

auto it = std::find_if(players.begin(), players.end(),
                       [pass_score](const Player& player) {
                           return player.score >= pass_score;
                       });
```

这里 `[pass_score]` 是捕获列表，表示 Lambda 需要使用外面的局部变量 `pass_score`。

## 值捕获和引用捕获

值捕获：

```cpp
int hp_line = 70;

auto hp_is_enough = [hp_line](const Player& player) {
    return player.hp >= hp_line;
};
```

`[hp_line]` 会把当时的 `hp_line` 值复制进 Lambda。后面即使外面的 `hp_line` 改了，这个 Lambda 里保存的值也不会跟着变。

引用捕获：

```cpp
int total_score = 0;

std::for_each(players.begin(), players.end(),
              [&total_score](const Player& player) {
                  total_score += player.score;
              });
```

`[&total_score]` 表示 Lambda 里使用的是外面那个 `total_score` 的引用。Lambda 修改它，外面的变量也会变。

工程判断：

- 只需要读取一个小变量，优先值捕获；
- 需要把结果写回外部变量，才考虑引用捕获；
- 引用捕获要小心生命周期，不能让 Lambda 比被引用的局部变量活得更久。

## 修改容器元素

Lambda 的参数也能使用引用。

```cpp
std::for_each(players.begin(), players.end(),
              [](Player& player) {
                  player.hp += 5;
              });
```

这里 `Player& player` 表示绑定到容器中的原元素，所以修改 `player.hp` 会修改 `players` 里的对象。

如果写成：

```cpp
[](Player player) {
    player.hp += 5;
}
```

那修改的只是副本，原容器不会变。这和前面范围 `for` 中 `auto` 与 `auto&` 的区别是同一类问题。

## 工程习惯

- Lambda 适合短小、局部、只在一处使用的规则。
- 规则会被多处复用时，可以考虑写成有名字的普通函数。
- 参数只读大对象时，优先写 `const Type&`。
- 需要修改原对象时，参数写 `Type&`。
- 捕获列表尽量显式写清楚，例如 `[pass_score]`、`[&total_score]`，初学阶段不要滥用 `[=]` 或 `[&]`。

# F6 optional 和 variant 基础

## 当前阶段

本知识点属于 `06_modern_cpp` 阶段。

对应代码文件：

- `optional_variant_basic.cpp`

## 为什么需要 optional

工程代码里经常会遇到“可能找不到结果”的情况。

例如在玩家列表里按名字查找玩家：

```cpp
std::optional<std::size_t> find_player_index(...);
```

如果找到了，可以返回下标；如果没找到，就没有一个真正有效的下标。

旧代码里常见做法是返回特殊值，例如：

```cpp
return -1;
```

这种做法的问题是：特殊值不是类型系统的一部分，调用者可能忘记检查。并且下标常用 `std::size_t`，它是无符号整数，拿 `-1` 表示失败会更加容易出错。

`std::optional<T>` 的意思是：

```text
这里可能有一个 T，也可能没有值。
```

这样“可能没有结果”就被写进了返回类型。

## optional 怎么写

返回一个有效值：

```cpp
return i;
```

返回没有值：

```cpp
return std::nullopt;
```

完整例子：

```cpp
std::optional<std::size_t> find_player_index(const std::vector<Player>& players,
                                             const std::string& name) {
    for (std::size_t i = 0; i < players.size(); ++i) {
        if (players[i].name == name) {
            return i;
        }
    }

    return std::nullopt;
}
```

使用结果时要先检查：

```cpp
auto maybe_index = find_player_index(players, "Alice");

if (!maybe_index.has_value()) {
    std::cout << "not found" << std::endl;
    return;
}

std::cout << "index: " << *maybe_index << std::endl;
```

`*maybe_index` 表示取出 `optional` 里面保存的值。前提是它真的有值。

## optional 和 nullptr 的区别

`nullptr` 用来表示指针没有指向对象。

`optional<T>` 用来表示一个普通值可能不存在。

例如：

- `Player*` 可以为 `nullptr`，表示没有指向玩家对象；
- `std::optional<std::size_t>` 可以没有值，表示没有找到下标；
- `std::optional<Player>` 可以没有值，表示没有找到玩家数据。

如果函数不是在表达“指向某个对象”，只是表达“这个返回值可能不存在”，`optional` 往往比裸指针或特殊数字更清楚。

## 为什么需要 variant

工程代码里也经常会遇到“一个值可能是几种固定类型之一”的情况。

例如一条游戏动作可能是：

- 伤害动作 `DamageAction`；
- 治疗动作 `HealAction`；
- 聊天消息 `ChatMessage`。

它们不是同一种结构，但都可以放在“游戏动作”这个概念下面。

`std::variant<A, B, C>` 的意思是：

```text
这个变量当前保存 A、B、C 中的一种。
```

这比用很多互斥字段更安全。例如不要写成：

```cpp
struct Action {
    int type;
    int damage_amount;
    int heal_amount;
    std::string message;
};
```

这种结构容易出现状态不一致：`type` 说是伤害，但 `message` 也被填了，或者字段之间互相矛盾。

## variant 怎么写

先定义几种可能的类型：

```cpp
struct DamageAction {
    std::string target_name;
    int amount;
};

struct HealAction {
    std::string target_name;
    int amount;
};

struct ChatMessage {
    std::string text;
};
```

再定义一个 variant 类型：

```cpp
using GameAction = std::variant<DamageAction, HealAction, ChatMessage>;
```

创建时可以放入其中任意一种：

```cpp
GameAction action = DamageAction{"Alice", 10};
```

读取时先判断当前是哪一种：

```cpp
if (std::holds_alternative<DamageAction>(action)) {
    const DamageAction& damage = std::get<DamageAction>(action);
    std::cout << damage.target_name << std::endl;
}
```


`std::holds_alternative<T>` 用来判断当前是不是 `T`。

`std::get<T>` 用来取出当前保存的 `T`。工程习惯是先判断，再取出，避免拿错类型。

## 工程习惯

- 用 `optional<T>` 表达“可能没有 T”。
- 用 `std::nullopt` 表达 optional 当前没有值。
- 使用 optional 里的值之前，要先检查 `has_value()` 或直接判断 `if (maybe_value)`。
- 用 `variant<A, B, C>` 表达“一个值只可能是 A、B、C 中的一种”。
- 读取 variant 时，先用 `holds_alternative<T>` 判断，再用 `get<T>` 取出。
- `optional` 解决“有没有”的问题；`variant` 解决“是哪一种”的问题。
