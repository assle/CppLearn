# F1 auto 和范围 for 练习

## 练习 1：确认 auto 是推导类型

在 `auto_range_for_basic.cpp` 中找到：

```cpp
auto it = scores.begin();
```

思考并用注释回答：

1. `auto` 是不是表示变量没有类型？
2. 这里的 `it` 大概代表什么类型的东西？

## 练习 2：观察 auto 拷贝

运行示例，观察：

```cpp
for (auto score : scores) {
    score += 10;
}
```

思考并用注释回答：

1. 这个循环后，`scores` 原来的元素有没有变化？
2. 为什么？

## 练习 3：观察 auto& 修改原元素

观察：

```cpp
for (auto& score : scores) {
    score += 10;
}
```

思考并用注释回答：

1. 这个循环后，`scores` 原来的元素有没有变化？
2. `auto&` 中的 `&` 和之前学过的引用有什么关系？

## 练习 4：给 Player 增加等级

给 `Player` 增加一个成员变量：

```cpp
int level;
```

并修改初始化代码，例如：

```cpp
{"Alice", 100, 3}
```

然后修改 `print_players`，输出名字、分数和等级。

## 练习 5：使用范围 for 修改对象

新增一个循环，让所有玩家的 `level` 都加 `1`。

要求：

- 使用范围 `for`；
- 使用 `auto&`；
- 观察原来的 `players` 是否真的被修改。

## 练习 6：map 遍历思考

观察：

```cpp
for (const auto& item : name_to_score) {
    std::cout << item.first << ": " << item.second << std::endl;
}
```

用注释回答：

1. `item.first` 表示什么？
2. `item.second` 表示什么？
3. 为什么这里适合用 `const auto&`？

## 练习 7：工程判断题

用注释回答：

1. 只读遍历 `std::vector<Player>` 时，为什么通常优先用 `const auto&`？
2. 需要修改 `std::vector<int>` 中的元素时，为什么要用 `auto&`？
3. 如果写成 `for (auto player : players)`，可能发生什么额外成本？

# F2 nullptr 练习

## 练习 1：观察空指针检查

编译运行 `nullptr_basic.cpp`。

观察：

```cpp
current_player = nullptr;
print_player(current_player);
heal_player(current_player, 10);
```

用注释回答：

1. `current_player = nullptr` 表示什么？
2. 为什么 `print_player` 和 `heal_player` 里要先判断 `player == nullptr`？

## 练习 2：新增一个空指针安全函数

新增函数：

```cpp
void damage_player(Player* player, int amount)
```

要求：

- 如果 `player == nullptr`，输出 `"cannot damage null player"` 并返回；
- 否则让 `player->hp -= amount`。

在 `main` 中分别对有效指针和空指针调用它。

## 练习 3：观察 nullptr 和 0 的重载区别

观察：

```cpp
choose_target(0);
choose_target(nullptr);
```

用注释回答：

1. `choose_target(0)` 调用了哪个版本？
2. `choose_target(nullptr)` 调用了哪个版本？
3. 为什么现代 C++ 更推荐用 `nullptr` 表达空指针？

## 练习 4：delete 后置空

观察：

```cpp
delete heap_player;
heap_player = nullptr;
print_player(heap_player);
```

用注释回答：

1. `delete heap_player` 释放的是什么？
2. `heap_player = nullptr` 改变的是堆对象，还是指针变量本身？
3. 如果 `delete` 后不置空，继续使用旧指针有什么风险？

## 练习 5：工程判断题

用注释回答：

1. 为什么 `nullptr` 比 `0` 更适合表示空指针？
2. 一个函数接收 `Player*` 参数时，什么时候必须检查 `nullptr`？
3. 如果一个函数确定永远不接受空对象，用引用参数 `Player&` 是否可能比指针参数更合适？为什么？

# F3 智能指针练习

## 练习 1：编译运行并观察析构

编译运行 `smart_pointer_basic.cpp`。

观察输出中的：

```text
construct Player
destroy Player
```

用注释回答：

1. 示例中有没有手写 `delete`？
2. 为什么仍然能看到 `destroy Player`？

## 练习 2：观察 unique_ptr 的独占所有权

观察：

```cpp
std::unique_ptr<Player> owner = std::move(alice);
```

用注释回答：

1. `std::move(alice)` 表示什么？
2. 移动后，为什么要检查 `alice == nullptr`？
3. 为什么 `unique_ptr` 不允许普通复制？

## 练习 3：借用 unique_ptr 管理的对象

新增一个函数：

```cpp
void damage_player(Player& player, int amount)
```

要求：

- 使用引用参数；
- 让 `player.hp -= amount`；
- 在 `main` 中对 `owner` 指向的对象调用它。

思考：

1. 为什么这个函数不需要接收 `std::unique_ptr<Player>`？
2. `damage_player(*owner, 10)` 中的 `*owner` 表示什么？

## 练习 4：观察 shared_ptr 的引用计数

观察：

```cpp
std::shared_ptr<Player> another_owner = shared_alice;
```

用注释回答：

1. 复制 `shared_ptr` 后，`use_count()` 如何变化？
2. 内层作用域结束后，`use_count()` 如何变化？
3. 什么时候 `shared_ptr` 管理的对象才会被释放？

## 练习 5：工程判断题

用注释回答：

1. 默认情况下，为什么优先考虑 `unique_ptr`？
2. 什么时候才应该考虑 `shared_ptr`？
3. 如果函数只是临时读取一个对象，参数更适合写成 `const Player&`、`Player*`，还是 `std::shared_ptr<Player>`？为什么？

# F4 移动语义练习

## 练习 1：编译运行并观察拷贝和移动

编译运行 `move_semantics_basic.cpp`。

观察输出中的：

```text
copy construct
move construct
copy assign
move assign
```

用注释回答：

1. `ScoreBuffer copied = first;` 调用了拷贝构造还是移动构造？
2. `ScoreBuffer moved = std::move(first);` 调用了拷贝构造还是移动构造？
3. `assigned = std::move(copied);` 调用了拷贝赋值还是移动赋值？

## 练习 2：解释 std::move

观察：

```cpp
ScoreBuffer moved = std::move(first);
```

用注释回答：

1. `std::move(first)` 会不会自己移动内存？
2. `std::move(first)` 会不会自己释放 `first`？
3. 真正转移资源的是谁？

## 练习 3：观察移动后的对象

运行后观察 `first.print()` 和 `copied.print()` 在移动后的输出。

用注释回答：

1. 移动后的对象还会不会正常析构？
2. 移动后的对象是否还能假设保留原来的数据？
3. 为什么移动构造中要把 `other.data_` 设为 `nullptr`？

## 练习 4：新增一次拷贝赋值

在 `main` 中新增：

```cpp
ScoreBuffer copy_assigned("copy_assigned", 1);
copy_assigned = from_factory;
copy_assigned.print();
from_factory.print();
```

观察它调用的是拷贝赋值还是移动赋值。

思考：

1. 为什么这里不能偷走 `from_factory` 的资源？
2. 如果想表达可以偷走资源，应该怎么写？

## 练习 5：工程判断题

用注释回答：

1. 拷贝适合什么场景？
2. 移动适合什么场景？
3. 为什么移动语义对管理堆内存、文件、线程这类资源的对象很重要？
4. 为什么 `std::unique_ptr` 不能复制，但可以移动？

# F5 Lambda 练习

## 练习 1：编译运行并观察排序规则

编译运行 `lambda_basic.cpp`。

观察：

```cpp
std::sort(players.begin(), players.end(),
          [](const Player& left, const Player& right) {
              return left.score > right.score;
          });
```

用注释回答：

1. 这个 Lambda 的参数 `left` 和 `right` 表示什么？
2. `left.score > right.score` 会让玩家按什么顺序排列？
3. 为什么参数适合写成 `const Player&`？

## 练习 2：改成按 hp 排序

把排序规则改成按 `hp` 从低到高排序。

要求：

- 仍然使用 `std::sort`；
- 仍然使用 Lambda；
- 排序后调用 `print_players(players)` 观察结果。

思考：

1. 从低到高时，比较表达式应该写成 `<` 还是 `>`？
2. 这里是否需要修改 `Player` 对象本身？

## 练习 3：观察值捕获

观察：

```cpp
int hp_line = 70;
auto hp_is_enough = [hp_line](const Player& player) {
    return player.hp >= hp_line;
};

hp_line = 90;
```

用注释回答：

1. Lambda 捕获的是 `70` 还是后来的 `90`？
2. 为什么 `[hp_line]` 后，外面的变量变化不会影响已经创建的 Lambda？

## 练习 4：观察引用捕获

观察：

```cpp
int total_score = 0;
std::for_each(players.begin(), players.end(),
              [&total_score](const Player& player) {
                  total_score += player.score;
              });
```

用注释回答：

1. 为什么这里需要 `&total_score`？
2. 如果写成 `[total_score]`，能不能直接修改外面的 `total_score`？
3. 引用捕获为什么要注意生命周期？

## 练习 5：工程判断题

用注释回答：

1. Lambda 适合什么样的小逻辑？
2. 如果同一个判断规则要在多个文件复用，应该继续写 Lambda，还是考虑普通函数？
3. Lambda 参数里的 `Player`、`Player&`、`const Player&` 分别有什么区别？

# F6 optional 和 variant 练习

## 练习 1：编译运行并观察 optional

编译运行 `optional_variant_basic.cpp`。

观察：

```cpp
std::optional<std::size_t> maybe_index = find_player_index(players, name);
```

用注释回答：

1. `std::optional<std::size_t>` 表示什么？
2. `std::nullopt` 表示什么？
3. 为什么这里比返回 `-1` 更清楚？

## 练习 2：检查 optional 后再取值

观察：

```cpp
if (!maybe_index.has_value()) {
    std::cout << name << " not found" << std::endl;
    return;
}

const Player& player = players[*maybe_index];
```

用注释回答：

1. 为什么要先检查 `has_value()`？
2. `*maybe_index` 表示什么？
3. 如果 optional 没有值，还强行取值，会有什么风险？

## 练习 3：观察 variant 保存不同动作

观察：

```cpp
using GameAction = std::variant<DamageAction, HealAction, ChatMessage>;
```

用注释回答：

1. `GameAction` 当前一次能保存几种动作？
2. 它一次能不能同时既是 `DamageAction` 又是 `HealAction`？
3. 为什么这比一个结构体里塞很多互斥字段更清楚？

## 练习 4：新增一种 LevelUpAction

新增一种动作：

```cpp
struct LevelUpAction {
    std::string target_name;
    int levels;
};
```

要求：

- 把 `LevelUpAction` 加进 `GameAction`；
- 在 `apply_action` 中处理它；
- 如果找到目标玩家，就让 `players[*maybe_index].level += levels`；
- 在 `actions` 里新增一次升级动作并运行观察。

## 练习 5：工程判断题

用注释回答：

1. `optional` 适合解决什么问题？
2. `variant` 适合解决什么问题？
3. 如果函数只是可能找不到一个下标，应该优先考虑 `optional<std::size_t>`、`int` 返回 `-1`，还是 `Player*`？为什么？
