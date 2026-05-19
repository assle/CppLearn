# 练习：作用域、局部变量和全局变量

## 练习 1：观察局部变量

在 `scope_basic.cpp` 中，给 `main` 增加一个新的局部变量：

```cpp
int user_score = 88;
```

然后在 `main` 里输出它。

目标：确认局部变量可以在定义它的函数内部使用。

## 练习 2：观察代码块作用域

把下面这行代码放到代码块 `{}` 外面：

```cpp
std::cout << "block_count outside block: " << block_count << std::endl;
```

然后尝试编译。

目标：观察编译器报错，理解 `block_count` 离开代码块后名字不可见。

## 练习 3：观察全局变量

把 `global_count` 的值从 `100` 改成 `200`，重新编译运行。

目标：确认 `main` 和 `print_global_count` 都能看到同一个全局变量。

## 练习 4：思考题

回答下面两个问题：

1. 为什么 `local_count` 可以在内部代码块中使用？
2. 为什么全局变量在工程里要谨慎使用？

# 练习：函数声明和定义分离

## 练习 5：修改函数调用

在 `function_declaration.cpp` 中，把：

```cpp
int result = add(3, 4);
```

改成：

```cpp
int result = add(10, 20);
```

重新编译运行。

目标：确认 `main` 可以通过函数声明调用后面才定义的函数。

## 练习 6：观察没有声明时的错误

临时注释掉这行声明：

```cpp
int add(int left, int right);
```

然后尝试编译。

目标：观察编译器报错，理解编译器在看到函数调用前需要先知道函数声明。

完成后请把声明恢复。

## 练习 7：观察声明和定义不匹配

临时把声明改成：

```cpp
double add(int left, int right);
```

然后尝试编译。

目标：观察声明和定义返回类型不一致时会发生什么。

完成后请恢复成：

```cpp
int add(int left, int right);
```

## 练习 8：新增一个函数

新增一个函数声明：

```cpp
int multiply(int left, int right);
```

再在文件末尾新增它的定义：

```cpp
int multiply(int left, int right)
{
    return left * right;
}
```

然后在 `main` 中调用并输出结果。

目标：练习“先声明，后调用，最后定义”的结构。

## 练习 9：思考题

回答下面两个问题：

1. 函数声明告诉编译器哪些信息？
2. 为什么工程代码不适合把所有函数都堆在 `main` 前面？

# 练习：多文件编译和 .h / .cpp 组织

## 练习 10：编译多文件程序

在项目根目录运行：

```sh
g++ 03_function_scope_compile/main_multi_file.cpp 03_function_scope_compile/math_utils.cpp -o /private/tmp/cpplearn_multi_file
/private/tmp/cpplearn_multi_file
```

目标：确认多个 `.cpp` 文件可以一起编译成一个可执行程序。

## 练习 11：观察少编译一个 .cpp 的错误

尝试只编译 `main_multi_file.cpp`：

```sh
g++ 03_function_scope_compile/main_multi_file.cpp -o /private/tmp/cpplearn_multi_file
```

目标：观察错误，理解 `main` 看到了函数声明，但最终程序找不到函数定义。

## 练习 12：新增一个函数

在 `math_utils.h` 中新增声明：

```cpp
int subtract(int left, int right);
```

在 `math_utils.cpp` 中新增定义：

```cpp
int subtract(int left, int right)
{
    return left - right;
}
```

然后在 `main_multi_file.cpp` 中调用并输出：

```cpp
int difference = subtract(20, 10);
std::cout << "difference: " << difference << std::endl;
```

目标：练习“声明在 `.h`，定义在 `.cpp`，调用在另一个 `.cpp`”。

## 练习 13：思考题

回答下面两个问题：

1. `main_multi_file.cpp` 为什么要 `#include "math_utils.h"`？
2. 为什么编译命令里必须同时写上 `main_multi_file.cpp` 和 `math_utils.cpp`？

# 练习：编译、链接和头文件保护

## 练习 14：分步编译

在项目根目录运行：

```sh
g++ -c 03_function_scope_compile/main_multi_file.cpp -o /private/tmp/main_multi_file.o
g++ -c 03_function_scope_compile/math_utils.cpp -o /private/tmp/math_utils.o
g++ /private/tmp/main_multi_file.o /private/tmp/math_utils.o -o /private/tmp/cpplearn_link_steps
/private/tmp/cpplearn_link_steps
```

目标：理解 `.cpp` 可以先分别变成 `.o` 目标文件，再链接成可执行程序。

## 练习 15：观察链接阶段缺少目标文件

只链接 `main_multi_file.o`：

```sh
g++ /private/tmp/main_multi_file.o -o /private/tmp/cpplearn_link_steps_missing
```

目标：观察 `Undefined symbols`，理解链接器需要找到函数定义。

## 练习 16：编译头文件保护示例

运行：

```sh
g++ 03_function_scope_compile/header_guard_demo.cpp -o /private/tmp/cpplearn_header_guard_demo
/private/tmp/cpplearn_header_guard_demo
```

目标：确认 `header_guard_demo.cpp` 即使重复包含 `build_config.h`，也可以正常编译。

## 练习 17：观察没有头文件保护的错误

临时注释掉 `build_config.h` 中的三行：

```cpp
#ifndef BUILD_CONFIG_H
#define BUILD_CONFIG_H
#endif
```

然后重新编译：

```sh
g++ 03_function_scope_compile/header_guard_demo.cpp -o /private/tmp/cpplearn_header_guard_demo
```

目标：观察重复包含头文件带来的重复定义错误。

完成后请恢复头文件保护。

## 练习 18：思考题

回答下面三个问题：

1. 编译阶段主要检查什么？
2. 链接阶段主要解决什么？
3. 头文件保护为什么能避免重复包含带来的问题？
