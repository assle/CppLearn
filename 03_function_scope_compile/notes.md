# 作用域、局部变量和全局变量

## 为什么需要作用域

程序变大以后，变量名会越来越多。如果所有名字在所有地方都能使用，代码很容易出现冲突：

- 两个地方都想用 `count`，但含义不同。
- 一个函数不小心修改了另一个函数内部的数据。
- 编译器不知道某个名字到底指的是哪个变量。

作用域就是 C++ 用来管理“名字在哪里有效”的规则。

简单说：

```text
作用域 = 一个名字能被看见、能被使用的代码范围
```

## 局部变量

定义在函数内部或代码块 `{}` 内部的变量，通常叫局部变量。

```cpp
int main()
{
    int local_count = 10;
    std::cout << local_count << std::endl;
}
```

`local_count` 只在 `main` 函数内部有效。出了 `main`，这个名字就不能再使用。

工程原因：

- 局部变量让数据更安全，不容易被其他函数意外修改。
- 编译器可以更清楚地判断变量的使用范围。
- 函数之间可以使用相同的局部变量名，互不影响。

## 代码块作用域

一对 `{}` 会形成一个更小的作用域。

```cpp
int main()
{
    int local_count = 10;

    {
        int block_count = 20;
        std::cout << block_count << std::endl;
    }

    // block_count 在这里已经不可见
}
```

`block_count` 只在它所在的 `{}` 内有效。

## 全局变量

定义在所有函数外面的变量叫全局变量。

```cpp
int global_count = 100;
```

它可以被同一个源文件里后面的函数使用。

工程上要谨慎使用全局变量，因为：

- 任何能看到它的函数都可能修改它。
- 程序变大后，很难追踪它在哪里被改过。
- 多文件工程中，全局变量还会引入链接和重复定义问题。

现阶段先知道：全局变量方便，但工程里不能随便滥用。

## 作用域和生命周期的区别

这两个概念容易混：

```text
作用域：名字在哪里能用
生命周期：对象从什么时候存在到什么时候销毁
```

本阶段先重点理解作用域。生命周期会在后面的指针、引用、栈、堆里继续深入。

## 编译运行

在项目根目录运行：

```sh
g++ 03_function_scope_compile/scope_basic.cpp -o /private/tmp/cpplearn_scope_basic
/private/tmp/cpplearn_scope_basic
```

# 函数声明和定义分离

## 为什么需要函数声明

C++ 编译器通常从上到下读取一个 `.cpp` 文件。

如果 `main` 里面调用了一个函数，但编译器在前面还没有见过这个函数，它就不知道：

- 这个函数叫什么名字。
- 这个函数需要几个参数。
- 每个参数是什么类型。
- 这个函数有没有返回值，返回什么类型。

所以在调用函数之前，至少要先让编译器知道这个函数的“接口”。这就是函数声明。

## 声明是什么

函数声明只告诉编译器“有这样一个函数”，不写具体怎么做。

```cpp
int add(int left, int right);
```

这行的意思是：

```text
有一个叫 add 的函数；
它接收两个 int 参数；
它返回一个 int；
具体实现稍后再说。
```

注意末尾有分号 `;`。

## 定义是什么

函数定义会写出函数体，也就是这个函数具体怎么执行。

```cpp
int add(int left, int right)
{
    return left + right;
}
```

定义里面有 `{}`，里面是真正的执行逻辑。

## 为什么要分离

小程序可以把所有函数都写在 `main` 前面。但工程代码会越来越大，如果所有函数都堆在一个地方，会带来几个问题：

- `main` 很难快速看到程序主流程。
- 函数之间互相调用时，顺序很难安排。
- 后面拆成多个 `.cpp` 和 `.h` 文件时，必须理解声明和定义的区别。

声明和定义分离之后，可以先把“能调用什么”告诉编译器，再把“具体怎么做”放在后面。

## 最小例子

```cpp
int add(int left, int right);

int main()
{
    int result = add(3, 4);
    return 0;
}

int add(int left, int right)
{
    return left + right;
}
```

编译器看到 `main` 调用 `add(3, 4)` 时，前面已经有了 `int add(int left, int right);`，所以它知道这个调用是合法的。

## 声明和定义必须匹配

声明和定义的返回类型、函数名、参数类型必须匹配。

例如声明是：

```cpp
int add(int left, int right);
```

定义也必须对应：

```cpp
int add(int left, int right)
{
    return left + right;
}
```

参数名可以不同，但参数类型、数量、顺序必须一致。

## 编译运行

在项目根目录运行：

```sh
g++ 03_function_scope_compile/function_declaration.cpp -o /private/tmp/cpplearn_function_declaration
/private/tmp/cpplearn_function_declaration
```

# 多文件编译和 .h / .cpp 组织

## 为什么要拆成多个文件

单个 `.cpp` 文件适合小程序，但工程代码不能一直堆在一个文件里。

当函数越来越多时，会出现几个问题：

- `main` 变得很长，很难看出主流程。
- 不同功能混在一起，修改一个函数时容易影响别的函数。
- 多人协作时，大家都改同一个文件，冲突会很多。
- 后面复用某些函数时，很难只拿出需要的那部分。

所以工程里通常把代码分成：

```text
.h   文件：放声明，告诉别人“这里有什么可以用”
.cpp 文件：放定义，写清楚“这些东西具体怎么做”
```

## 本轮最小结构

```text
03_function_scope_compile/
├── main_multi_file.cpp
├── math_utils.h
└── math_utils.cpp
```

职责分别是：

```text
main_multi_file.cpp：程序入口，负责主流程
math_utils.h：函数声明，提供给 main 使用
math_utils.cpp：函数定义，真正实现 add 和 multiply
```

## 头文件做什么

`math_utils.h` 里写：

```cpp
int add(int left, int right);
int multiply(int left, int right);
```

这让 `main_multi_file.cpp` 可以知道：

```text
add 和 multiply 存在；
它们各接收两个 int；
它们都返回 int。
```

## 源文件做什么

`math_utils.cpp` 里写函数定义：

```cpp
int add(int left, int right)
{
    return left + right;
}
```

也就是说，`.cpp` 文件负责真正生成函数实现。

## include 是复制声明，不是复制实现

当 `main_multi_file.cpp` 写：

```cpp
#include "math_utils.h"
```

可以先粗略理解为：编译前，预处理器把 `math_utils.h` 里的声明放到这里。

所以 `main_multi_file.cpp` 能调用 `add`，但真正的 `add` 实现来自 `math_utils.cpp`。

## 多文件编译命令

在项目根目录运行：

```sh
g++ 03_function_scope_compile/main_multi_file.cpp 03_function_scope_compile/math_utils.cpp -o /private/tmp/cpplearn_multi_file
/private/tmp/cpplearn_multi_file
```

注意：只编译 `main_multi_file.cpp` 不够，因为 `add` 和 `multiply` 的定义在 `math_utils.cpp` 里。

## 先记住

```text
声明给编译器看，让它知道函数能不能这样调用。
定义给链接器用，让最终程序找到函数真正在哪里。
```

链接器会在下一节继续详细讲。

# 编译、链接和头文件保护

## 为什么要区分编译和链接

前面你已经看到一个现象：

```sh
g++ 03_function_scope_compile/main_multi_file.cpp -o /private/tmp/cpplearn_multi_file_missing_cpp
```

会报类似：

```text
Undefined symbols:
  add(int, int)
  multiply(int, int)
```

这说明 `main_multi_file.cpp` 里有函数声明，所以编译器知道 `add(10, 20)` 这种调用形式是合法的。

但是最终生成可执行程序时，链接器还要找到 `add` 和 `multiply` 的真正定义。定义在 `math_utils.cpp` 里，如果编译命令没有带上这个文件，链接器就找不到。

## 一个粗略流程

可以先把流程理解成：

```text
预处理：处理 #include，把头文件内容展开到当前 .cpp
编译：检查语法和类型，把每个 .cpp 变成目标文件
链接：把多个目标文件合成一个可执行程序，并解决函数定义在哪里
```

现阶段不需要背完整底层细节，先记住：

```text
编译器主要关心：这个名字能不能这样用？
链接器主要关心：这个名字真正定义在哪里？
```

## 分步编译

你可以把两个 `.cpp` 分别编译成目标文件：

```sh
g++ -c 03_function_scope_compile/main_multi_file.cpp -o /private/tmp/main_multi_file.o
g++ -c 03_function_scope_compile/math_utils.cpp -o /private/tmp/math_utils.o
```

这一步只生成 `.o` 目标文件，还不是最终程序。

然后链接：

```sh
g++ /private/tmp/main_multi_file.o /private/tmp/math_utils.o -o /private/tmp/cpplearn_link_steps
/private/tmp/cpplearn_link_steps
```

如果链接时少写 `/private/tmp/math_utils.o`，就会再次出现 `Undefined symbols`。

## 为什么头文件需要保护

头文件会被 `#include` 展开。

如果同一个头文件被重复包含，而里面有类型定义，例如：

```cpp
enum class BuildMode
{
    Debug,
    Release
};
```

没有保护时，编译器可能会在同一个 `.cpp` 里看到两次 `BuildMode` 定义，于是报“重复定义”相关错误。

所以我们写头文件保护：

```cpp
#ifndef BUILD_CONFIG_H
#define BUILD_CONFIG_H

// 头文件内容

#endif
```

这表示：

```text
如果 BUILD_CONFIG_H 还没有定义，就定义它，并保留这段头文件内容；
如果已经定义过，就跳过这段头文件内容。
```

## 最小例子

`header_guard_demo.cpp` 故意包含两次同一个头文件：

```cpp
#include "build_config.h"
#include "build_config.h"
```

因为 `build_config.h` 有头文件保护，所以重复包含也不会重复定义 `BuildMode`。

## 编译运行

```sh
g++ 03_function_scope_compile/header_guard_demo.cpp -o /private/tmp/cpplearn_header_guard_demo
/private/tmp/cpplearn_header_guard_demo
```
