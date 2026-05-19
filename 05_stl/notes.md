# E1 std::vector 笔记

## 为什么需要 std::vector

在前面的内存阶段，我们已经学过动态数组：

```cpp
int* scores = new int[3];
scores[0] = 90;
scores[1] = 80;
scores[2] = 70;
delete[] scores;
```

这种写法能工作，但工程上有几个明显问题：

1. 调用者必须记得 `delete[]`，否则会内存泄漏。
2. 数组长度需要自己保存，否则不知道有几个有效元素。
3. 如果元素数量不够用，需要自己重新申请更大的数组、复制旧数据、释放旧数组。
4. 如果中途提前 `return` 或发生异常，释放逻辑容易漏掉。

`std::vector` 是标准库提供的动态数组容器。它内部通常会在堆上管理一块连续内存，但它把申请、扩容、释放这些细节封装起来。对象析构时，`vector` 会自动释放它管理的资源，这正是 RAII 思想在标准库中的典型应用。

## 最小用法

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;

    scores.push_back(90);
    scores.push_back(80);
    scores.push_back(70);

    for (int score : scores) {
        std::cout << score << std::endl;
    }

    return 0;
}
```

## size 和 capacity

- `size()` 表示当前有多少个有效元素。
- `capacity()` 表示当前已经分配的存储空间最多能容纳多少个元素。

当 `push_back` 新元素而容量不够时，`vector` 通常会：

1. 申请一块更大的连续内存。
2. 把旧元素搬到新内存。
3. 释放旧内存。
4. 把新元素放进去。

这就是为什么 `vector` 既像数组一样能按下标访问，又能动态增长。

## 工程理解

`std::vector<int>` 可以理解为一个负责管理一组 `int` 的对象。它不仅保存数据，还保存数据个数、容量，并负责释放内部内存。

所以在普通工程代码里，优先使用：

```cpp
std::vector<int> scores;
```

而不是：

```cpp
int* scores = new int[100];
```

除非你正在学习底层内存、实现容器，或有非常明确的性能和接口原因。

# E2 std::string 常用操作笔记

## 为什么需要 std::string

C++ 里也可以用字符数组保存文本：

```cpp
char name[] = "Alice";
```

这种写法接近底层，但工程上有几个麻烦：

1. 字符数组长度需要提前考虑。
2. 字符串结尾依赖隐藏的 `'\0'`。
3. 拼接、查找、截取都需要更小心地处理内存和边界。
4. 作为函数参数传递时，容易退化成指针，长度信息容易丢失。

`std::string` 是标准库提供的字符串对象。它会管理内部字符存储，记录字符串长度，并提供拼接、查找、截取、比较等常用操作。

从工程角度看，`std::string` 和 `std::vector` 一样，都是“用对象管理资源”的例子。它内部可能管理一段字符内存，但使用者通常不需要手动 `new`、`delete` 或维护结尾的 `'\0'`。

## 最小用法

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Alice";
    std::string title = "Engineer";

    std::string profile = name + " - " + title;
    std::cout << profile << std::endl;

    return 0;
}
```

## 常用操作

- `size()`：字符串中有多少个字符。
- `empty()`：字符串是否为空。
- `+`：拼接两个字符串，生成一个新字符串。
- `+=`：把内容追加到已有字符串后面。
- `[]`：按下标访问字符。
- `find()`：查找子串或字符的位置。
- `substr()`：截取一段子串。
- `==`：比较两个字符串内容是否相等。

## find 和 npos

`find()` 找到内容时返回下标，找不到时返回 `std::string::npos`。

```cpp
std::size_t pos = text.find("C++");
if (pos != std::string::npos) {
    std::cout << "found" << std::endl;
}
```

`std::string::npos` 可以理解为“没有找到”的特殊值。不要把 `find()` 的结果直接当作一定有效的下标使用。

## 工程理解

在工程代码中，文本通常不只是“字符序列”，还需要：

1. 知道长度。
2. 能安全复制和传递。
3. 能方便拼接、查找和截取。
4. 自动管理内部内存。

所以普通业务代码里优先使用：

```cpp
std::string name = "Alice";
```

而不是直接操作：

```cpp
char name[100];
```

# E3 std::map 和 std::unordered_map 笔记

## 为什么需要 map

`std::vector` 适合“按位置”保存一组数据：

```cpp
scores[0];
scores[1];
```

但工程里经常遇到另一种需求：不是按第几个元素找，而是按一个“键”找一个“值”。

例如：

1. 按用户名查分数：`"Alice" -> 90`
2. 按配置名查配置值：`"port" -> "8080"`
3. 按商品编号查库存：`"book-001" -> 12`

这类数据叫键值对。标准库中常用：

- `std::map<Key, Value>`
- `std::unordered_map<Key, Value>`

## 最小用法

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores;

    scores["Alice"] = 90;
    scores["Bob"] = 82;

    std::cout << scores["Alice"] << std::endl;

    return 0;
}
```

`std::map<std::string, int>` 表示：键是 `std::string`，值是 `int`。

## map 和 unordered_map 的区别

`std::map`：

- 按键自动排序。
- 遍历时会按键的顺序输出。
- 底层通常是平衡树。

`std::unordered_map`：

- 不保证遍历顺序。
- 更关注通过键快速查找。
- 底层通常是哈希表。

初学阶段可以先这样选：

- 需要按键有序遍历：用 `std::map`。
- 只关心按键查找，不关心顺序：用 `std::unordered_map`。

## find 和 end

查找时推荐使用 `find()`：

```cpp
auto it = scores.find("Alice");
if (it != scores.end()) {
    std::cout << it->second << std::endl;
}
```

这里的 `it` 是迭代器。现在可以先把它理解为“指向容器中某个键值对的位置”。

- `it->first` 是键。
- `it->second` 是值。
- `scores.end()` 表示“没有指向任何有效元素的结束位置”。

如果 `find()` 返回 `end()`，说明没找到。

## operator[] 的注意点

`scores["Alice"]` 很方便，但有一个重要行为：

如果键不存在，`operator[]` 会自动插入一个新元素。

```cpp
std::map<std::string, int> scores;
std::cout << scores["Unknown"] << std::endl;
```

这段代码会创建 `"Unknown"` 这个键，并给它一个默认值 `0`。

所以：

- 确定要插入或修改时，可以用 `[]`。
- 只是想检查是否存在时，优先用 `find()`。

## 工程理解

`map` 类容器解决的是“从一个键找到一个值”的工程问题。

它比两组平行数组更稳：

```cpp
std::vector<std::string> names;
std::vector<int> scores;
```

因为平行数组需要靠下标保持对应关系，一旦插入、删除或排序，很容易让名字和分数错位。

使用 `std::map<std::string, int>` 时，键和值天然绑定在一起：

```cpp
scores["Alice"] = 90;
```

# E4 std::set 笔记

## 为什么需要 set

`std::map` 保存的是“键 -> 值”：

```cpp
scores["Alice"] = 90;
```

但有些场景里，我们只关心某个值是否存在，不需要额外的值。

例如：

1. 一篇文章有哪些标签：`"cpp"`、`"stl"`、`"memory"`
2. 当前有哪些在线用户：`"Alice"`、`"Bob"`
3. 一批订单里出现过哪些状态：`"created"`、`"paid"`、`"cancelled"`

这些场景适合用集合。标准库中常用：

- `std::set<T>`
- `std::unordered_set<T>`

集合的核心特点是：每个元素最多出现一次。

## 最小用法

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> tags;

    tags.insert("cpp");
    tags.insert("stl");
    tags.insert("cpp");

    std::cout << tags.size() << std::endl;

    return 0;
}
```

上面插入了两次 `"cpp"`，但集合里只会保留一个。

## set 和 unordered_set 的区别

`std::set`：

- 元素唯一。
- 元素会自动排序。
- 遍历时按元素顺序输出。
- 底层通常是平衡树。

`std::unordered_set`：

- 元素唯一。
- 不保证遍历顺序。
- 更关注快速判断某个元素是否存在。
- 底层通常是哈希表。

初学阶段可以先这样选：

- 需要有序遍历：用 `std::set`。
- 只关心是否存在，不关心顺序：用 `std::unordered_set`。

## find、end 和 erase

查找：

```cpp
auto it = tags.find("cpp");
if (it != tags.end()) {
    std::cout << "exists" << std::endl;
}
```

如果 `find()` 返回 `end()`，表示没找到。

删除：

```cpp
std::size_t removed_count = tags.erase("cpp");
```

`erase(value)` 返回被删除的元素数量。对于 `set`，返回值通常是 `0` 或 `1`，因为元素不会重复。

## set 和 map 的关系

可以粗略理解为：

- `set<T>`：只保存键。
- `map<Key, Value>`：保存键和值。

如果你只想判断一个名字是否出现过，用 `set`：

```cpp
std::set<std::string> names;
```

如果你还要保存这个名字对应的分数，用 `map`：

```cpp
std::map<std::string, int> scores;
```

## 工程理解

`set` 适合表达“唯一集合”。

它比用 `vector` 手动去重更稳：

```cpp
std::vector<std::string> tags;
```

如果用 `vector`，每次插入前都要手动检查是否已经存在；如果忘了检查，重复值就会混进去。

使用 `std::set` 时，容器本身会维护唯一性：

```cpp
tags.insert("cpp");
tags.insert("cpp");
```

最终集合里仍然只有一个 `"cpp"`。

# E5 迭代器笔记

## 为什么需要迭代器

前面我们已经用过范围 `for`：

```cpp
for (int score : scores) {
    std::cout << score << std::endl;
}
```

范围 `for` 很方便，但工程里还需要更细的控制：

1. 从某个位置开始遍历。
2. 找到某个元素后继续操作它。
3. 在遍历时修改元素。
4. 用同一套方式遍历 `vector`、`set`、`map` 等不同容器。

迭代器就是标准库提供的“容器位置对象”。它让不同容器都能用类似的方式遍历。

## begin 和 end

每个常见容器都有：

- `begin()`：指向第一个元素。
- `end()`：指向最后一个元素后面的位置。

注意：`end()` 不指向有效元素，不能解引用。

```cpp
auto it = scores.begin();
std::cout << *it << std::endl;
```

这里：

- `it` 是迭代器。
- `*it` 表示访问迭代器当前指向的元素。
- `++it` 表示移动到下一个元素。

## 最小遍历

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    std::cout << *it << std::endl;
}
```

这段代码的执行过程可以模拟为：

1. `it = scores.begin()`：从第一个元素开始。
2. `it != scores.end()`：只要还没走到结束位置，就继续。
3. `*it`：访问当前位置的元素。
4. `++it`：移动到下一个位置。

## 迭代器和修改元素

对于 `std::vector<int>`，如果容器不是 `const`，可以通过迭代器修改元素：

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    *it += 5;
}
```

这里 `*it` 就是当前元素本身。

如果函数参数是 `const std::vector<int>&`，那么 `begin()` 得到的是只读迭代器，不能通过 `*it` 修改元素。

## map 迭代器

`std::map` 的迭代器指向的是键值对：

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
}
```

- `it->first` 是键。
- `it->second` 是值。

在 `std::map` 中，键不能随便改，因为改键会破坏容器内部排序结构；值可以改。

## 工程理解

迭代器把“怎么走过一个容器”抽象成统一接口。

你可以把它理解成比下标更通用的位置标记：

- `vector` 可以用下标，也可以用迭代器。
- `set` 没有下标，只能用迭代器这类方式遍历。
- `map` 遍历时拿到的是键值对，也通过迭代器访问。

后续学习标准算法，比如 `std::find`、`std::sort`、`std::count`，会大量使用迭代器范围：

```cpp
scores.begin(), scores.end()
```

# E6 常用算法笔记

## 为什么需要标准算法

学完 `vector`、`string`、`map`、`set` 后，我们已经知道容器负责保存数据。

但工程代码里，仅仅保存数据不够，还经常需要处理数据：

1. 把一组分数排序。
2. 查找某个名字是否存在。
3. 统计某个值出现了多少次。

这些需求当然可以手写循环完成：

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    if (*it == 80) {
        std::cout << "found" << std::endl;
    }
}
```

手写循环能工作，但工程上有几个问题：

1. 每个人写法可能不同，阅读成本更高。
2. 边界条件容易写错，例如漏掉最后一个元素。
3. 代码表达的是“怎么循环”，而不是“我要查找”。

标准算法把常见操作封装成清楚的名字：

- `std::sort`：排序。
- `std::find`：查找。
- `std::count`：计数。

这样代码表达的是意图，而不是一堆重复循环。

## 为什么算法接收 begin 和 end

标准算法通常不直接接收整个容器，而是接收一段迭代器范围：

```cpp
std::find(scores.begin(), scores.end(), 80);
```

这里的范围是左闭右开：

- `scores.begin()`：起点，指向第一个元素。
- `scores.end()`：终点，指向最后一个元素之后的位置。

可以把它理解成：

```text
[ begin, end )
```

也就是包含 `begin` 指向的元素，不包含 `end`。

这种设计的工程价值是：算法不需要知道自己处理的是整个容器，还是容器中的一部分。它只要知道“从哪里开始，到哪里结束”。

## 容器和算法为什么分开

如果每个容器都自己实现一套排序、查找、计数，标准库会变得重复而复杂：

```cpp
scores.sort();
names.sort();
tags.sort();
```

标准库采用的是“容器负责存储，算法负责处理”的设计。

容器提供统一的迭代器接口：

```cpp
begin(), end()
```

算法通过迭代器访问元素：

```cpp
std::count(container.begin(), container.end(), value);
```

这样同一个算法可以作用在多种容器上。只要容器能提供算法需要的迭代器能力，算法就能工作。

## std::sort

`std::sort` 用于排序，需要包含头文件：

```cpp
#include <algorithm>
```

最小写法：

```cpp
std::vector<int> scores = {70, 90, 80};
std::sort(scores.begin(), scores.end());
```

排序后，`scores` 自身的元素顺序会被修改。

注意：`std::sort` 需要能高效地跳到不同位置，因此主要用于 `std::vector` 这类支持随机访问迭代器的容器。`std::set` 本身已经按元素排序，不需要再用 `std::sort` 排它。

## std::find

`std::find` 用于在一个范围中查找某个值：

```cpp
auto it = std::find(scores.begin(), scores.end(), 80);
if (it != scores.end()) {
    std::cout << "found: " << *it << std::endl;
}
```

如果找到了，返回指向该元素的迭代器。

如果没找到，返回第二个参数，也就是这个范围的结束位置。

所以使用 `find` 后，一定要先判断：

```cpp
it != scores.end()
```

再解引用 `*it`。

## std::count

`std::count` 用于统计某个值在范围中出现了几次：

```cpp
int count = std::count(scores.begin(), scores.end(), 90);
```

如果没有出现，结果就是 `0`。

`count` 不会修改容器，只是遍历范围并统计匹配次数。

## 工程理解

标准算法让代码更像是在描述任务：

```cpp
std::sort(scores.begin(), scores.end());
std::find(scores.begin(), scores.end(), 80);
std::count(scores.begin(), scores.end(), 90);
```

这比手写循环更容易读，也更能减少重复代码。

从工程角度看，算法和容器通过迭代器连接起来：

- 容器管理元素、内存和生命周期。
- 迭代器表示一段可遍历范围。
- 算法对这段范围执行通用操作。
