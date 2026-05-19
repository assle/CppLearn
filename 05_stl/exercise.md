# E1 std::vector 练习

## 练习 1：新增元素

在 `vector_basic.cpp` 中，给 `scores` 再新增两个分数，例如 `88` 和 `76`。

观察：

- `size()` 是否变化？
- 输出结果是否包含新增元素？

## 练习 2：修改元素

把第一个分数改为 `100`。

提示：

```cpp
scores[0] = 100;
```

思考：

- 为什么可以像数组一样使用 `scores[0]`？
- 如果访问不存在的下标，会有什么风险？

## 练习 3：观察 capacity

保留示例中的 `print_vector_state`，每次 `push_back` 后观察 `capacity()`。

思考：

- `size()` 和 `capacity()` 是否总是相等？
- 当容量变化时，说明 `vector` 内部可能做了什么？

## 练习 4：和 new[] 对比

用注释写出这两个问题的答案：

1. 使用 `new[]` 创建动态数组时，谁负责释放内存？
2. 使用 `std::vector<int>` 时，为什么通常不需要手动 `delete`？

# E2 std::string 练习

## 练习 1：修改字符串内容

在 `string_basic.cpp` 中，把 `name` 改成你的名字或任意英文名，把 `title` 改成另一个英文单词。

观察：

- 拼接后的 `profile` 是否变化？
- `size()` 是否变化？

## 练习 2：追加字符串

在 `profile += " C++";` 后面，再追加一个字符串，例如：

```cpp
profile += " STL";
```

观察输出结果。

## 练习 3：查找子串

新增一次查找，判断 `profile` 中是否包含 `"C++"`。

提示：

```cpp
std::size_t cpp_pos = profile.find("C++");
if (cpp_pos != std::string::npos) {
    std::cout << "C++ found at index: " << cpp_pos << std::endl;
}
```

思考：

- 为什么要和 `std::string::npos` 比较？
- 如果没有找到，能不能直接把返回值当下标使用？

## 练习 4：截取子串

使用 `substr()` 截取 `profile` 的前 5 个字符并打印。

提示：

```cpp
std::string first_five = profile.substr(0, 5);
```

## 练习 5：和 char 数组对比

用注释写出这两个问题的答案：

1. `std::string` 相比 `char name[100]`，工程上更方便在哪里？
2. `std::string` 为什么通常不需要你手动维护结尾的 `'\0'`？

# E3 std::map 和 std::unordered_map 练习

## 练习 1：新增键值对

在 `map_basic.cpp` 中，给 `scores` 新增一个学生，例如：

```cpp
scores["Diana"] = 91;
```

观察：

- `scores.size()` 是否变化？
- `std::map` 遍历输出时，名字顺序是什么样？

## 练习 2：修改已有值

把 `"Charlie"` 的分数改成一个新值。

思考：

- 修改已有键对应的值时，`size()` 是否变化？
- 为什么？

## 练习 3：查找不存在的键

新增查找 `"Eve"` 的代码。如果找不到，输出：

```text
Eve not found
```

要求：

- 使用 `find()`。
- 和 `scores.end()` 比较。
- 不要用 `scores["Eve"]` 来判断是否存在。

## 练习 4：观察 operator[] 的插入行为

在代码中临时新增：

```cpp
std::cout << scores["Unknown"] << std::endl;
std::cout << "scores size after Unknown: " << scores.size() << std::endl;
```

观察：

- 访问不存在的 `"Unknown"` 后，`size()` 是否变化？
- 为什么只检查是否存在时，不建议直接用 `[]`？

## 练习 5：unordered_map 的顺序

给 `config` 再新增一个键值对，例如：

```cpp
config["log_level"] = "info";
```

观察：

- `std::unordered_map` 的遍历顺序是否一定等于插入顺序？
- 如果工程里需要按键排序输出，应该选 `map` 还是 `unordered_map`？

## 练习 6：用注释回答工程问题

在 `map_basic.cpp` 末尾用注释回答：

1. `std::map<std::string, int>` 中，`std::string` 和 `int` 分别表示什么？
2. `find()` 返回 `end()` 表示什么？
3. 只想判断键是否存在时，为什么优先用 `find()` 而不是 `operator[]`？

# E4 std::set 练习

## 练习 1：新增元素

在 `set_basic.cpp` 中，给 `tags` 新增两个标签，例如：

```cpp
tags.insert("debug");
tags.insert("compile");
```

观察：

- `tags.size()` 是否变化？
- `std::set` 遍历输出时，标签顺序是什么样？

## 练习 2：观察重复插入

再插入一次已经存在的标签，例如：

```cpp
tags.insert("cpp");
```

观察：

- `size()` 是否变化？
- 为什么？

## 练习 3：查找元素

新增查找 `"stl"` 的代码。如果找到，输出：

```text
stl tag exists
```

要求：

- 使用 `find()`。
- 和 `tags.end()` 比较。

## 练习 4：删除元素

新增删除 `"network"` 的代码：

```cpp
std::size_t removed_network_count = tags.erase("network");
std::cout << "removed network count: " << removed_network_count << std::endl;
```

观察：

- 删除不存在的元素时，返回值是多少？
- 删除存在的元素时，返回值是多少？

## 练习 5：unordered_set 的顺序

给 `online_users` 新增一个用户，例如：

```cpp
online_users.insert("Diana");
```

观察：

- 重复插入 `"Alice"` 后，`online_users.size()` 是否把它算两次？
- `std::unordered_set` 的遍历顺序是否一定等于插入顺序？

## 练习 6：用注释回答工程问题

在 `set_basic.cpp` 末尾用注释回答：

1. `std::set<std::string>` 中的 `std::string` 表示什么？
2. `set` 和 `map` 的核心区别是什么？
3. 如果只想保存“不重复的标签”，为什么 `set` 比 `vector` 更合适？

# E5 迭代器练习

## 练习 1：新增 vector 元素

在 `iterator_basic.cpp` 中，给 `scores` 再新增两个分数，例如：

```cpp
scores.push_back(60);
scores.push_back(100);
```

观察：

- `print_vector_with_iterator(scores)` 是否能输出新增元素？
- 迭代器遍历是否需要知道容器里有几个元素？

## 练习 2：修改 vector 元素

把 `add_bonus(scores, 5)` 改成 `add_bonus(scores, 10)`。

观察：

- 每个元素是否都增加了 10？
- 为什么 `add_bonus` 可以通过 `*it += bonus` 修改原容器里的元素？

## 练习 3：手动移动迭代器

在 `first_score` 后面新增：

```cpp
++first_score;
if (first_score != scores.end()) {
    std::cout << "second score: " << *first_score << std::endl;
}
```

思考：

- `++first_score` 表示什么？
- 为什么解引用前要检查它是否等于 `scores.end()`？

## 练习 4：set 迭代器

给 `tags` 新增一个标签，例如：

```cpp
tags.insert("algorithm");
```

观察：

- `print_set_with_iterator(tags)` 输出顺序是什么样？
- 为什么 `set` 不能像 `vector` 那样用下标访问？

## 练习 5：map 迭代器

在 `named_scores` 中新增一个人，例如：

```cpp
named_scores["Diana"] = 77;
```

观察：

- `print_map_with_iterator(named_scores)` 是否输出新键值对？
- `it->first` 和 `it->second` 分别表示什么？

## 练习 6：用注释回答工程问题

在 `iterator_basic.cpp` 末尾用注释回答：

1. `begin()` 和 `end()` 分别表示什么？
2. `*it` 和 `++it` 分别表示什么？
3. 为什么 `end()` 不能解引用？
4. 为什么迭代器比下标更通用？

# E6 常用算法练习

## 练习 1：编译运行算法示例

编译并运行 `algorithm_basic.cpp`：

```bash
g++ 05_stl/algorithm_basic.cpp -o /private/tmp/cpplearn_algorithm_basic
/private/tmp/cpplearn_algorithm_basic
```

观察：

- `std::sort` 前后，`scores` 的顺序是否发生变化？
- `std::sort` 是否修改了原来的 `vector`？

## 练习 2：修改排序数据

在 `algorithm_basic.cpp` 中，把 `scores` 改成：

```cpp
std::vector<int> scores = {88, 75, 100, 75, 92};
```

观察排序后的输出。

思考：

- 排序默认是从小到大还是从大到小？
- 重复的 `75` 会不会丢失？

## 练习 3：查找存在和不存在的值

把查找 `80` 的代码改成查找 `75`。

然后再改成查找一个不存在的值，例如 `66`。

观察：

- 找到时，`std::find` 返回的迭代器能否解引用？
- 没找到时，为什么不能直接 `*found_score`？

## 练习 4：统计重复值

把统计 `90` 的代码改成统计 `75`。

观察：

- 如果 `75` 出现两次，`std::count` 返回多少？
- 如果统计不存在的值，返回多少？

## 练习 5：字符串排序、查找、计数

在 `names` 中新增一个名字，例如：

```cpp
names.push_back("Diana");
```

再新增一个重复的 `"Bob"`：

```cpp
names.push_back("Bob");
```

观察：

- `std::sort` 对字符串排序时，输出顺序是什么样？
- `std::find` 找到的是第几个匹配项？
- `std::count` 是否能统计重复名字？

## 练习 6：用注释回答工程问题

在 `algorithm_basic.cpp` 末尾用注释回答：

1. 为什么标准算法通常接收 `begin()` 和 `end()`，而不是只接收一个容器？
2. `std::find` 找不到时返回什么？
3. 为什么解引用 `find` 的结果前要先判断它是否等于 `end()`？
4. `std::sort`、`std::find`、`std::count` 中，哪些会修改原容器，哪些不会？
5. 标准算法相比手写循环的工程好处是什么？
