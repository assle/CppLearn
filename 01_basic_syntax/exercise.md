# 01_basic_syntax 练习

## 练习：Hello World

## 练习目标

通过修改 `hello_world.cpp`，熟悉最小 C++ 程序、标准输出和编译运行流程。

## 练习 1：修改输出内容

把程序输出改成：

```text
I am learning C++.
```

要求：

- 保持程序可以成功编译。
- 运行后终端输出内容与上面一致。

## 练习 2：输出两行文本

让程序输出：

```text
Hello, C++!
This is my first C++ program.
```

要求：

- 使用两次 `std::cout`，或在字符串里使用换行符。
- 能说明 `std::endl` 或 `\n` 的作用。

## 练习记录

完成情况：已完成

遇到的问题：未记录具体问题

## 练习：变量和基础类型

## 练习目标

通过修改 `variable_basic.cpp`，熟悉变量声明、赋值、基础类型和输出变量值。

## 练习 3：修改变量值

修改 `variable_basic.cpp` 中的变量值，让程序输出你自己的：

- 名字或昵称
- 年龄
- 身高
- 等级字符
- 是否是学生

要求：

- 程序可以成功编译。
- 至少修改 5 个变量的初始值。

## 练习 4：新增一个变量

新增一个 `int year` 变量，表示当前年份，并输出：

```text
year: 2026
```

要求：

- 使用 `int` 类型。
- 使用 `std::cout` 输出变量。

## 练习记录

完成情况：已完成

遇到的问题：未记录具体问题

## 练习：运算符和简单表达式

## 练习目标

通过修改 `expression_basic.cpp`，熟悉算术运算符、比较运算符和表达式结果。

## 练习 5：修改参与运算的变量

修改 `expression_basic.cpp` 中的 `a` 和 `b`：

```cpp
int a = 20;
int b = 6;
```

要求：

- 程序可以成功编译。
- 运行后观察 `/` 和 `%` 的输出结果。
- 能说明 `20 / 6` 和 `20 % 6` 分别表示什么。

## 练习 6：新增比较表达式

新增两个 `bool` 变量：

```cpp
bool is_less = a < b;
bool is_not_equal = a != b;
```

并输出它们。

要求：

- 使用 `std::cout` 输出两个比较结果。
- 能说明 `=`、`==`、`!=` 三者的区别。

## 练习记录

完成情况：已完成

遇到的问题：未记录具体问题

## 练习：条件判断

## 练习目标

通过修改 `if_else_basic.cpp`，熟悉 `if`、`else if`、`else` 的执行顺序。

## 练习 7：修改分数

修改 `score` 的值，分别测试：

- `95`
- `85`
- `70`
- `50`

要求：

- 每次修改后都能成功编译运行。
- 能说明程序为什么输出对应等级。

## 练习记录

完成情况：未记录具体练习过程，用户自述已掌握条件判断

遇到的问题：未记录具体问题

## 练习：循环结构

## 练习目标

通过修改 `loop_basic.cpp`，熟悉 `for`、`while`、循环条件和循环变量更新。

## 练习 8：修改 `for` 循环范围

让 `for` 循环输出 1 到 10。

要求：

- 程序可以成功编译。
- 能说明循环从几开始，到几结束。

## 练习 9：修改 `while` 循环

让 `while` 循环输出 3 到 1。

要求：

- 使用 `count--`。
- 能说明为什么循环会停止。

## 练习记录

完成情况：已完成

遇到的问题：未记录具体问题

## 练习：`const`、枚举、简单类型转换

## 练习目标

通过修改 `const_enum_cast.cpp`，理解 `const`、`enum class` 和 `static_cast` 在工程代码里的作用。

## 练习 10：尝试修改常量

在 `const double discount_rate = 0.8;` 后面临时加一行：

```cpp
discount_rate = 0.5;
```

要求：

- 尝试编译。
- 观察编译器报错。
- 能说明为什么这是编译错误。
- 观察后把这行代码删掉或注释掉，恢复程序可编译。

## 练习 11：增加订单状态

给 `OrderStatus` 增加一个状态：

```cpp
Cancelled
```

然后把：

```cpp
OrderStatus status = OrderStatus::Paid;
```

改成：

```cpp
OrderStatus status = OrderStatus::Cancelled;
```

并增加一个 `if` 判断，输出：

```text
order status: cancelled
```

要求：

- 程序可以成功编译。
- 能说明 `OrderStatus::Cancelled` 为什么比直接写 `3` 更清楚。

## 练习 12：观察类型转换

把价格改成：

```cpp
int original_price = 101;
```

要求：

- 运行后观察 `discounted price` 和 `final price` 的区别。
- 能说明 `static_cast<int>` 对小数部分做了什么。

## 练习记录

完成情况：已完成

遇到的问题：已理解 `static_cast<int>` 会显式转换为 `int`，转换 `80.8` 时小数部分被丢弃，结果为 `80`。
