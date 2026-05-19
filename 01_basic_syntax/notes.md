# 01_basic_syntax

## 当前知识点

- 最小 C++ 程序结构
- `#include <iostream>` 的作用
- `main` 函数是程序入口
- `std::cout` 用于向终端输出内容
- `return 0` 表示程序正常结束

## 示例文件

- `hello_world.cpp`

## 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/hello_world.cpp -o hello_world
./hello_world
```

预期输出：

```text
Hello, C++!
```

## 暂未掌握或待确认

- 是否已经理解“源文件编译成可执行文件”的过程：不确定
- 是否能独立写出最小 C++ 程序：不确定

## 知识点：变量和基础类型

示例文件：

- `variable_basic.cpp`

### 变量是什么

变量是有名字的一块数据。程序可以通过变量名读取或修改这块数据。

基本形式：

```cpp
类型 变量名 = 初始值;
```

示例：

```cpp
int age = 20;
```

含义：

- `int`：变量类型，表示整数。
- `age`：变量名。
- `20`：初始值。

### 本轮基础类型

| 类型 | 用途 | 示例 |
|---|---|---|
| `int` | 整数 | `int age = 20;` |
| `double` | 小数 | `double height = 1.75;` |
| `char` | 单个字符 | `char grade = 'A';` |
| `bool` | 真或假 | `bool is_student = true;` |
| `std::string` | 字符串文本 | `std::string name = "Cpp learner";` |

### 赋值

变量创建后，可以重新赋值：

```cpp
age = 21;
```

这里不能再写 `int age = 21;`，因为同一个作用域里已经有了一个叫 `age` 的变量。

### 输出变量

可以用 `std::cout` 输出文字和变量：

```cpp
std::cout << "age: " << age << std::endl;
```

### 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/variable_basic.cpp -o variable_basic
./variable_basic
```

### 暂未掌握或待确认

- 是否能区分“声明变量”和“重新赋值”：不确定
- 是否理解 `char` 使用单引号、`std::string` 使用双引号：不确定
- 是否知道 `std::string` 需要 `#include <string>`：不确定

## 知识点：运算符和简单表达式

示例文件：

- `expression_basic.cpp`

### 表达式是什么

表达式是一段可以计算出结果的代码。

示例：

```cpp
int sum = a + b;
```

这里 `a + b` 是表达式，它会计算出一个结果，再赋值给 `sum`。

### 算术运算符

| 运算符 | 含义 | 示例 |
|---|---|---|
| `+` | 加法 | `a + b` |
| `-` | 减法 | `a - b` |
| `*` | 乘法 | `a * b` |
| `/` | 除法 | `a / b` |
| `%` | 取余 | `a % b` |

注意：

- 两个 `int` 相除，结果仍然是 `int`，小数部分会被丢弃。
- `%` 只能直接用于整数类型，常用来判断一个数是否能被另一个数整除。

### 比较运算符

比较运算的结果是 `bool`。

| 运算符 | 含义 | 示例 |
|---|---|---|
| `>` | 大于 | `a > b` |
| `<` | 小于 | `a < b` |
| `>=` | 大于等于 | `a >= b` |
| `<=` | 小于等于 | `a <= b` |
| `==` | 等于 | `a == b` |
| `!=` | 不等于 | `a != b` |

注意：

- `=` 是赋值。
- `==` 是比较是否相等。

### 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/expression_basic.cpp -o expression_basic
./expression_basic
```

### 暂未掌握或待确认

- 是否理解 `=` 和 `==` 的区别：不确定
- 是否理解整数除法会丢弃小数部分：不确定
- 是否理解 `%` 的含义和使用限制：不确定

## 知识点：条件判断

示例文件：

- `if_else_basic.cpp`

### `if` 是什么

`if` 用来根据条件决定是否执行一段代码。

```cpp
if (score >= 60) {
    std::cout << "pass" << std::endl;
}
```

括号里的 `score >= 60` 是条件表达式，结果是 `true` 或 `false`。

### `else if` 和 `else`

```cpp
if (score >= 90) {
    std::cout << "grade: A" << std::endl;
} else if (score >= 80) {
    std::cout << "grade: B" << std::endl;
} else {
    std::cout << "grade: F" << std::endl;
}
```

含义：

- `if`：先判断第一个条件。
- `else if`：前面的条件不满足时，再判断新的条件。
- `else`：前面所有条件都不满足时执行。

### 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/if_else_basic.cpp -o if_else_basic
./if_else_basic
```

## 知识点：循环结构

示例文件：

- `loop_basic.cpp`

### `for` 循环

`for` 适合循环次数比较明确的场景。

```cpp
for (int i = 1; i <= 5; i++) {
    std::cout << i << std::endl;
}
```

它通常包含三部分：

```cpp
for (初始化; 条件; 每轮结束后的更新)
```

示例中：

- `int i = 1`：循环变量从 1 开始。
- `i <= 5`：只要条件为真，就继续循环。
- `i++`：每轮循环结束后，`i` 增加 1。

### `while` 循环

`while` 适合“只要条件成立就继续”的场景。

```cpp
int count = 1;
while (count <= 3) {
    std::cout << count << std::endl;
    count++;
}
```

注意：`while` 循环里通常要修改条件相关变量，否则可能变成无限循环。

### 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/loop_basic.cpp -o loop_basic
./loop_basic
```

### 暂未掌握或待确认

- 是否理解 `for` 三个部分的执行顺序：不确定
- 是否理解 `i++` 的作用：不确定
- 是否能避免 `while` 无限循环：不确定

## 知识点：`const`、枚举、简单类型转换

示例文件：

- `const_enum_cast.cpp`

### 为什么需要 `const`

工程代码里，变量越多，越容易误改。`const` 的作用是告诉编译器：这个名字绑定的值创建后不允许再被修改。

```cpp
const double discount_rate = 0.8;
```

这行代码表示折扣率是一个常量。如果后面写：

```cpp
discount_rate = 0.5;
```

编译器会直接报错。这不是运行时才发现的问题，而是在编译阶段提前拦住错误。

工程原因：

- 让“不会变”的业务规则更明确。
- 防止后续代码误改关键值。
- 编译器可以帮助检查错误。

### 为什么需要枚举

很多程序都有“状态”：订单状态、登录状态、游戏状态、设备状态等。

如果只用整数表示：

```cpp
int status = 1;
```

问题是：`1` 代表什么不清楚，而且任何整数都能塞进去。

枚举让状态有名字：

```cpp
enum class OrderStatus {
    Created,
    Paid,
    Shipped
};
```

使用时：

```cpp
OrderStatus status = OrderStatus::Paid;
```

工程原因：

- 状态名字比裸整数更清楚。
- `enum class` 不会轻易和普通整数混用。
- 编译器能帮你发现一些类型用错的问题。

### 为什么需要类型转换

C++ 是强类型语言。不同类型的数据虽然有时可以一起计算，但结果类型可能不是你想要的。

示例：

```cpp
int original_price = 99;
double discounted_price = original_price * 0.8;
int final_price = static_cast<int>(discounted_price);
```

`discounted_price` 是 `79.2`，但 `final_price` 是 `int`，只能保存整数。`static_cast<int>` 明确告诉编译器：我知道这里会把小数部分丢掉。

工程原因：

- 把“可能丢信息”的地方写明显。
- 让读代码的人知道这是有意转换，不是手滑。
- 减少隐式类型转换带来的意外结果。

### 编译和运行

在项目根目录执行：

```bash
g++ 01_basic_syntax/const_enum_cast.cpp -o const_enum_cast
./const_enum_cast
```

预期输出：

```text
original price: 99
discounted price: 79.2
final price: 79
order status: paid
```

### 暂未掌握或待确认

- 是否理解 `const` 是编译期限制：不确定
- 是否理解 `enum class` 比普通整数状态更安全：不确定
- 是否理解 `static_cast<int>` 会丢弃小数部分：不确定
