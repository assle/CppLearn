# C++ 工程学习状态档案

## 1. 学习目标

系统学习 C++，补齐工程开发能力。  
重点包括 C++ 语言机制、内存模型、面向对象、STL、现代 C++、编译构建、调试测试和小型工程项目。  
当前不是以刷算法为主要目标。

## 2. 当前学习阶段

当前阶段：06_modern_cpp（F1 `auto` 和范围 `for`、F2 `nullptr`、F3 智能指针、F4 移动语义、F5 Lambda、F6 `optional` / `variant` 基础已完成；下一轮建议进入 07_build_system 阶段 G1：命令行编译 `g++` 常用参数）

正在学习：`06_modern_cpp` 阶段。F1 `auto` 和范围 `for`、F2 `nullptr`、F3 智能指针、F4 移动语义、F5 Lambda、F6 `optional` / `variant` 基础已完成。已通过 `06_modern_cpp/auto_range_for_basic.cpp` 练习 `auto` 类型推导、范围 `for`、`auto` 拷贝元素、`auto&` 引用原元素、`const auto&` 只读引用，以及 `vector` 和 `map` 的现代遍历写法；已通过 `06_modern_cpp/nullptr_basic.cpp` 练习 `nullptr`、空指针检查、函数重载中的 `0` 和 `nullptr` 区别、`delete` 后置空，以及指针参数和引用参数的接口含义；已通过 `06_modern_cpp/smart_pointer_basic.cpp` 练习 `std::unique_ptr` 独占所有权、`std::shared_ptr` 共享所有权、`std::make_unique`、`std::make_shared`、`std::move` 转移 `unique_ptr` 所有权、引用参数借用智能指针管理的对象，以及 `shared_ptr::use_count()` 观察引用计数；已通过 `06_modern_cpp/move_semantics_basic.cpp` 练习拷贝构造、移动构造、拷贝赋值、移动赋值、`std::move`、移动后对象状态和移动语义与 RAII 的边界；已通过 `06_modern_cpp/lambda_basic.cpp` 练习 Lambda、捕获列表、值捕获、引用捕获，以及配合 `std::sort`、`std::find_if`、`std::count_if`、`std::for_each` 表达自定义规则；已通过 `06_modern_cpp/optional_variant_basic.cpp` 练习 `std::optional` 表达可能没有值、`std::variant` 表达一个值可能是几种固定类型之一，并能用 `std::nullopt`、`has_value()`、`holds_alternative`、`get` 处理分支。下一轮建议进入 `07_build_system` 阶段 G1：命令行编译 `g++` 常用参数。

上一阶段结果：`02_pointer_reference_memory` 已完成当前记录范围内的地址、指针、解引用、引用、指针参数、引用参数、栈、堆、生命周期、`new/delete`、野指针、悬空引用、内存泄漏，以及所有权、借用、释放责任和释放后置空的阶段复盘。

更早阶段结果：`03_function_scope_compile` 已完成当前记录范围内的函数作用域和编译组织内容，包括作用域、局部变量、全局变量、函数声明和定义分离、多文件编译、`.h` / `.cpp` 组织、编译、链接和头文件保护。

本阶段结果：`06_modern_cpp` 已完成 F1 `auto` 和范围 `for`、F2 `nullptr`、F3 智能指针、F4 移动语义、F5 Lambda、F6 `optional` / `variant` 基础。当前能理解 `auto` 是编译期类型推导，不是没有类型；能理解范围 `for` 背后仍依赖 `begin()` / `end()`；能区分 `auto` 拷贝元素、`auto&` 修改原元素、`const auto&` 只读且避免拷贝的工程意义；能理解 `nullptr` 是现代 C++ 中专门表示空指针的值，优于用整数 `0` 或旧式 `NULL` 表达空指针；能理解 `unique_ptr` 表达独占所有权，`shared_ptr` 表达共享所有权，智能指针通过 RAII 自动释放堆对象；能理解 `std::move` 本身不移动、不释放，真正转移资源的是移动构造/移动赋值；能区分 RAII 负责自动释放资源，移动语义负责避免不必要深拷贝并转移资源所有权；能理解 Lambda 用于在算法调用处表达短小的局部规则，能区分值捕获、引用捕获，以及 `Player`、`Player&`、`const Player&` 参数的拷贝和修改语义；能理解 `optional` 解决“有没有值”的问题，`variant` 解决“是哪一种固定类型”的问题。

下一阶段建议：进入 `07_build_system` 阶段 G1，学习命令行编译 `g++` 常用参数、输出文件、C++ 标准版本参数、警告参数和调试信息参数。

## 2.1 教学计划编号说明

本节用于保证新会话只读取本文件也能理解学习计划。编号来自一次学习盘点，不应脱离本节单独使用。

| 编号 | 知识点 | 当前状态 |
|---|---|---|
| A1 | 最小 C++ 程序、`main`、`#include`、`std::cout` | 已掌握 |
| A2 | 变量、赋值、基础类型：`int`、`double`、`char`、`bool`、`std::string` | 已掌握 |
| A3 | 算术运算、比较运算、`=`、`==`、`!=` | 已掌握 |
| A4 | 条件判断：`if`、`else if`、`else` | 已掌握 |
| A5 | 循环结构：`for`、`while`、循环变量、停止条件 | 已掌握 |
| A6 | 输入：`std::cin` | 已掌握 |
| A7 | 数组基础、字符串基础操作 | 已掌握 |
| A8 | `const`、枚举、简单类型转换 | 已掌握 |
| B1 | 函数定义、参数、返回值 | 已掌握 |
| B2 | 作用域、局部变量、全局变量 | 已掌握 |
| B3 | 函数声明和定义分离 | 已掌握 |
| B4 | 多文件编译：`.h` / `.cpp` 组织 | 已掌握 |
| B5 | 编译、链接、头文件保护 | 已掌握 |
| C1 | 地址、指针、解引用 | 已掌握 |
| C2 | 引用和指针的区别 | 已掌握 |
| C3 | 指针参数、引用参数 | 已掌握 |
| C4 | 栈、堆、生命周期 | 已掌握 |
| C5 | `new/delete` 基础 | 已掌握 |
| C6 | 野指针、悬空引用、内存泄漏 | 已掌握 |
| D1 | 类、对象、成员变量、成员函数 | 已掌握 |
| D2 | 构造函数、析构函数 | 已掌握 |
| D3 | `this`、访问控制：`public/private` | 已掌握 |
| D4 | 拷贝构造、赋值运算符 | 已掌握 |
| D5 | 继承、多态、虚函数 | 已掌握 |
| D6 | RAII 基础 | 已掌握 |
| E1 | `std::vector` | 已掌握 |
| E2 | `std::string` 常用操作 | 已掌握 |
| E3 | `std::map`、`std::unordered_map` | 已掌握 |
| E4 | `std::set` | 已掌握 |
| E5 | 迭代器 | 已掌握 |
| E6 | 常用算法：`sort`、`find`、`count` | 已掌握 |
| F1 | `auto`、范围 `for` | 已掌握 |
| F2 | `nullptr` | 已掌握 |
| F3 | 智能指针：`unique_ptr`、`shared_ptr` | 已掌握 |
| F4 | 移动语义：右值引用、`std::move` | 已掌握 |
| F5 | Lambda | 已掌握 |
| F6 | `optional`、`variant` 基础 | 已掌握 |
| G1 | 命令行编译：`g++` 常用参数 | 未掌握 |
| G2 | CMake 最小项目 | 未掌握 |
| G3 | 工程目录组织：`include/`、`src/`、`tests/` | 未掌握 |
| G4 | Debug：断点、变量观察、调用栈 | 未掌握 |
| G5 | 单元测试基础 | 未掌握 |
| G6 | Git 基础工作流 | 未掌握 |
| H1 | 文件读写：`ifstream`、`ofstream` | 未掌握 |
| H2 | 异常：`try`、`catch`、`throw` | 未掌握 |
| H3 | 基础并发：`thread`、`mutex` | 未掌握 |
| H4 | 小项目：命令行通讯录 | 未掌握 |
| H5 | 小项目：文件统计工具 | 未掌握 |
| H6 | 小项目：小型 C++ 工程重构 | 未掌握 |

## 3. 已掌握内容

- 能理解并运行最小 C++ 程序 `01_basic_syntax/hello_world.cpp`。
- 已掌握 `#include <iostream>`、`int main()`、`std::cout`、`std::endl`、`return 0` 在 Hello World 程序中的基本作用。
- 已掌握使用 `g++ 01_basic_syntax/hello_world.cpp -o /private/tmp/cpplearn_hello_world` 编译，并运行生成的可执行文件查看输出。
- 已掌握 `01_basic_syntax/variable_basic.cpp` 中的变量声明、基础类型、赋值和输出变量值。
- 已掌握 `01_basic_syntax/expression_basic.cpp` 中的算术运算符、比较运算符、整数除法、取余和简单表达式。
- 已掌握 `01_basic_syntax/if_else_basic.cpp` 中的 `if`、`else if`、`else` 基本结构。掌握依据：用户自述“这个内容我也掌握了”。
- 已掌握 `01_basic_syntax/loop_basic.cpp` 中的 `for`、`while`、循环变量更新和循环停止条件。掌握依据：用户要求“标记为已掌握”。
- 已掌握 `std::cin` 输入。掌握依据：用户盘点清单中标记“输入：`std::cin`”已掌握；本地尚未创建对应示例文件。
- 已掌握数组基础和字符串基础操作。掌握依据：用户盘点清单中标记“数组基础、字符串基础操作”已掌握；本地尚未创建对应示例文件。
- 已掌握函数定义、参数、返回值。掌握依据：用户盘点清单中标记“函数定义、参数、返回值”已掌握；本地尚未创建对应示例文件。
- 已掌握 `01_basic_syntax/const_enum_cast.cpp` 中的 `const`、`enum class` 和 `static_cast<int>` 基础用法。掌握依据：用户完成练习 10-12，并自述“`static_cast<int>` 强制转换为了 `int`”；本地编译运行输出 `80.8` 转换为 `80`。
- 已掌握 `03_function_scope_compile/scope_basic.cpp` 中的作用域、局部变量、代码块变量和全局变量基础。掌握依据：用户完成练习 1-4，能说明内部代码块可以访问外层局部变量，也能说明全局变量在工程中容易被误用或意外修改；本地编译运行通过。
- 已掌握 `03_function_scope_compile/function_declaration.cpp` 中的函数声明和定义分离。掌握依据：用户完成练习 5-9，新增 `multiply` 函数并正确使用先声明、后调用、再定义的结构；本地编译运行输出 `result: 30` 和 `result: 200`。
- 已掌握 `03_function_scope_compile/main_multi_file.cpp`、`03_function_scope_compile/math_utils.h`、`03_function_scope_compile/math_utils.cpp` 中的多文件编译和 `.h` / `.cpp` 基础组织。掌握依据：用户完成练习 10-13，新增 `subtract` 函数并正确放置声明、定义和调用；本地多文件编译运行输出 `difference: 10`、`sum: 30`、`product: 200`。
- 已掌握 `03_function_scope_compile/build_config.h` 和 `03_function_scope_compile/header_guard_demo.cpp` 中的分步编译、链接和头文件保护基础。掌握依据：用户完成练习 14-18；本地验证 `.cpp` 可先编译成 `.o`，多个 `.o` 可链接成可执行程序，缺少 `math_utils.o` 时出现 `Undefined symbols`，重复包含带头文件保护的 `build_config.h` 可正常编译运行。
- 已掌握 `02_pointer_reference_memory/pointer_basic.cpp` 中的地址、指针变量和解引用基础。掌握依据：用户完成练习 1-5，能说明指针变量保存地址、`p` 表示地址、`*p` 表示访问地址上的值、通过 `*p = 10` 修改原变量、指针变量本身可以改为指向另一个变量；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/reference_basic.cpp` 中的引用基础和引用、指针对比。掌握依据：用户完成 C2 代码练习和思考题，能说明引用更像已有变量的别名、修改引用会修改原变量、指针变量可以改为指向另一个变量、引用绑定后不能改绑、`level_ref = backup_level` 是把值赋给原变量而不是改变引用绑定关系；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/function_parameter_basic.cpp` 中的值参数、指针参数和引用参数基础。掌握依据：用户完成 C3 代码练习和思考题，能说明普通值参数修改的是副本、指针参数通过地址修改调用方变量、引用参数通过别名修改调用方变量、指针参数调用时需要传 `&level`，看到非 `const` 引用参数应意识到函数可能修改调用方传入的同一个变量；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/lifetime_basic.cpp` 中的栈、堆、生命周期基础。掌握依据：用户完成 C4 代码练习和思考题，能说明栈上局部变量随函数作用域创建和销毁，返回局部变量的值安全，返回局部变量地址危险，堆对象不会随创建它的函数结束而销毁，需要通过 `delete` 销毁；能说明 `delete ptr` 释放的是堆对象，指针变量本身通常仍保存旧地址，继续解引用可能访问失效或被复用的内存；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/new_delete_basic.cpp` 中的 `new/delete` 基础。掌握依据：用户完成 C5 代码练习和思考题，能说明 `new int(80)` 在堆上创建值为 `80` 的 `int`，`new` 返回地址所以需要指针保存，`delete p` 释放 `p` 指向的堆对象并交还内存，释放后置为 `nullptr` 可避免误用旧地址，`new[]` 创建的动态数组需要用 `delete[]` 释放；能说明重复释放、忘记释放、`new[]`/`delete` 混用的风险；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/memory_error_basic.cpp` 中的野指针、悬空指针、悬空引用和内存泄漏基础。掌握依据：用户完成 C6 代码练习和思考题，能说明野指针是未初始化就使用的指针，悬空指针是指向对象已销毁但仍保存旧地址的指针，引用绑定对象销毁后也会悬空，内存泄漏是申请的堆内存没有被正确释放；能说明释放后置为 `nullptr` 可降低误用旧地址的风险；本地编译运行通过。
- 已掌握 `02_pointer_reference_memory/ownership_lifetime_review.cpp` 中的所有权、借用、释放责任和指针引用收尾复盘。掌握依据：用户完成 `increase_borrowed_score(int* score_ptr)` 编码练习，能说明借用函数不能随便 `delete` 参数地址，`create_owned_score` 返回的堆对象地址交给调用方后应由调用方释放，`destroy_owned_score(int*& score_ptr)` 中的引用解决了只修改指针副本的问题；本地编译运行通过。
- 已掌握 `04_oop/class_object_basic.cpp` 中的类、对象、成员变量和成员函数基础。掌握依据：用户完成 D1 练习，新增 `hp` 成员变量、`level_up()` 成员函数、类外普通函数 `print_player_score(Player player)`，并能说明 `Player` 是类、`alice` 是对象实例，`alice.score` 和 `bob.score` 不是同一个变量，`alice.gain_score(15)` 操作的是 `alice` 的 `score`；本地编译运行通过。
- 已掌握 `04_oop/constructor_destructor_basic.cpp` 和 `04_oop/constructor_init_review.cpp` 中的构造函数、析构函数和对象创建即初始化基础。掌握依据：用户完成 D2 练习和补强，能说明构造函数在对象创建过程中初始化对象、析构函数在作用域结束或 `delete` 时自动调用，能观察栈对象、堆对象和函数局部对象的析构时机，并理解构造时初始化能避免半初始化对象；本地编译运行通过。
- 已掌握 `04_oop/this_private_basic.cpp` 中的 `this`、`private` 和 `public` 受控接口基础。掌握依据：用户完成 D3 练习，能说明 `this` 表示当前对象地址，`this->name = name` 左边是当前对象成员变量、右边是参数，成员变量不应全部 `public`，`private` 不代表外部不能使用对象，外部应通过 `public` 接口规范操作；本地编译运行通过，并修正 `set_max_hp(int value)` 使其能维护 `hp <= max_hp`。
- 已掌握 `04_oop/copy_assignment_basic.cpp` 和 `04_oop/copy_assignment_review.cpp` 中的拷贝构造、赋值运算符、自赋值检查和引用传参避免拷贝。掌握依据：用户完成 D4 练习和补强，能区分 `Player bob = alice` 是创建新对象时拷贝构造，`charlie = bob` 是已有对象赋值；能说明 `operator=` 是赋值运算符函数，`const Player& other` 中引用避免递归拷贝、`const` 保护来源对象，自赋值检查可保护资源对象；本地编译运行通过。
- 已掌握 `04_oop/inheritance_polymorphism_basic.cpp` 和 `04_oop/virtual_override_review.cpp` 中的继承、多态、虚函数、`override`、`protected/private`。掌握依据：用户完成 D5 练习和补强，能写出基类 `Character` 和派生类 `Warrior`、`Mage`、`Archer`，能说明基类引用 `run_turn(const Character&)` 会根据真实对象类型调用派生类实现，能区分重载和重写，理解 `virtual` 启用动态绑定、`override` 做编译期重写检查；本地编译运行通过。
- 已掌握 `04_oop/raii_basic.cpp` 和 `04_oop/raii_copy_review.cpp` 中的 RAII 基础。掌握依据：用户完成 D6 练习和补强，能说明 RAII 核心是构造函数获取资源、析构函数释放资源，能观察提前 `return` 和嵌套作用域结束时自动析构，理解默认拷贝会复制同一堆地址并可能重复释放，能列举文件、线程、堆内存等适合 RAII 管理的资源；本地编译运行通过。
- 已完成 `04_oop/oop_stage_review.cpp` 阶段复盘。掌握依据：用户完成阶段复盘练习；本地编译运行通过。当前能把类、对象、构造析构、`private/public`、拷贝构造、赋值运算符、继承、多态、虚函数、虚析构函数和 RAII 放到同一个资源管理例子中理解。
- 已掌握 `05_stl/vector_basic.cpp` 中的 `std::vector` 基础。掌握依据：用户完成 E1 练习，能使用 `push_back` 新增元素、使用范围 `for` 遍历、使用下标访问和修改元素，能说明越界访问风险，能区分 `size()` 表示当前元素数量、`capacity()` 表示当前容量，并能从工程角度说明 `vector` 自动管理内部内存，因此通常不需要手动 `delete`；本地编译运行通过。
- 已掌握 `05_stl/string_basic.cpp` 中的 `std::string` 常用操作。掌握依据：用户完成 E2 练习，能创建和修改字符串，使用 `+` 拼接、`+=` 追加、`size()` 和 `empty()` 观察状态、下标访问首尾字符、`find()` 查找子串、与 `std::string::npos` 比较判断是否找到、使用 `substr()` 截取子串，并能说明 `std::string` 相比 `char[]` 会自动管理字符存储和长度，通常不需要手动维护 `'\0'`；本地编译运行通过。
- 已掌握 `05_stl/map_basic.cpp` 中的 `std::map` 和 `std::unordered_map` 基础。掌握依据：用户完成 E3 练习，能使用 `std::map<std::string, int>` 表达键值对，使用 `operator[]` 插入和修改值，使用 `find()` 和 `end()` 判断键是否存在，能观察 `std::map` 按键排序遍历，能说明 `operator[]` 访问不存在键会自动插入默认值，能使用 `std::unordered_map<std::string, std::string>` 保存配置项，并理解其遍历顺序不保证等于插入顺序；本地编译运行通过。
- 已掌握 `05_stl/set_basic.cpp` 中的 `std::set` 和 `std::unordered_set` 基础。掌握依据：用户完成 E4 练习，能使用 `std::set<std::string>` 表达不重复集合，使用 `insert()` 插入元素并观察重复插入不会增加元素数量，使用 `find()` 和 `end()` 判断元素是否存在，使用 `erase()` 删除元素并观察返回删除数量，能观察 `std::set` 按元素排序遍历，能使用 `std::unordered_set<std::string>` 保存不重复在线用户，并理解其遍历顺序不保证等于插入顺序；本地编译运行通过。
- 已掌握 `05_stl/iterator_basic.cpp` 中的迭代器基础。掌握依据：用户完成 E5 练习，能使用 `begin()` 和 `end()` 表示容器遍历范围，理解 `end()` 是最后一个元素之后的位置且不能解引用，能使用 `*it` 访问当前元素、`++it` 移动到下一个元素，能通过 `vector` 迭代器修改原容器元素，能使用迭代器遍历无下标的 `set`，能使用 `map` 迭代器访问 `it->first` 和 `it->second`，并能说明迭代器比下标更通用；本地编译运行通过。
- 已掌握 `05_stl/algorithm_basic.cpp` 中的常用标准算法基础。掌握依据：用户完成 E6 练习，能使用 `std::sort(scores.begin(), scores.end())` 对 `vector` 原地排序，使用 `std::find` 查找元素并在解引用前和 `end()` 比较，使用 `std::count` 统计重复值；能观察整数和字符串 `vector` 的排序、查找和计数结果。曾将 `std::sort` 的“顺序变化”误认为“不修改容器”，并曾把 `std::find` 查找失败误写为返回 `-1`；已在练习答案中修正为：`std::sort` 会修改原容器，`std::find` 找不到时返回结束迭代器 `end()`；本地编译运行通过。
- 已掌握 `06_modern_cpp/auto_range_for_basic.cpp` 中的 `auto` 和范围 `for` 基础。掌握依据：用户完成 F1 练习，能说明 `auto` 不是没有类型，而是由编译器根据初始化表达式推导类型；能说明 `auto` 遍历会拷贝元素，修改副本不会修改原容器；能使用 `auto&` 修改 `vector<int>` 和 `vector<Player>` 中的原元素；能使用 `const auto&` 只读遍历 `vector<Player>` 和 `map`，理解 `item.first` 是键、`item.second` 是值；本地编译运行通过。
- 已掌握 `06_modern_cpp/nullptr_basic.cpp` 中的 `nullptr` 基础。掌握依据：用户完成 F2 练习，能实现带空指针检查的 `damage_player(Player* player, int amount)`，能说明 `nullptr` 表示空指针，指针参数在解引用前需要检查，`choose_target(0)` 会调用整数版本而 `choose_target(nullptr)` 会调用指针版本，`delete` 释放堆对象而 `ptr = nullptr` 修改的是指针变量本身；已理解函数确定不接受空对象时，引用参数 `Player&` 比指针参数 `Player*` 更能表达“必须传入有效对象”的接口约束；本地编译运行通过。
- 已掌握 `06_modern_cpp/smart_pointer_basic.cpp` 中的智能指针基础。掌握依据：用户完成 F3 练习，能说明示例没有手写 `delete` 但仍会析构，因为智能指针离开作用域时通过 RAII 自动释放对象；能实现 `damage_player(Player& player, int amount)` 作为借用函数修改智能指针管理的对象；能观察 `shared_ptr` 复制后 `use_count()` 增加、作用域结束后减少、计数归零时释放对象；已补清 `std::move` 转移 `unique_ptr` 所有权但本身不释放对象，以及 `shared_ptr` 应用于多个所有者共同延长对象生命周期的场景；本地编译运行通过。
- 已掌握 `06_modern_cpp/lambda_basic.cpp` 中的 Lambda 基础。掌握依据：用户完成 F5 练习，能使用 Lambda 为 `std::sort` 提供自定义比较规则，将玩家按 `hp` 从低到高排序；能说明值捕获保存创建 Lambda 时的外部变量值，引用捕获可修改外部累计变量；能区分 Lambda 参数中 `Player` 会拷贝、`Player&` 可修改原对象、`const Player&` 避免拷贝且只读；本地编译运行通过。
- 已掌握 `06_modern_cpp/optional_variant_basic.cpp` 中的 `optional` 和 `variant` 基础。掌握依据：用户完成 F6 练习，能说明 `std::optional<std::size_t>` 表示可能有下标也可能没有值，`std::nullopt` 表示没有值；能在取值前检查 `has_value()`，并理解对空 optional 强行取值属于未定义行为；能把 `LevelUpAction` 加入 `std::variant` 并在 `apply_action` 中处理，使 Alice 的 `level` 从 `3` 增加到 `23`；本地编译运行通过。

## 4. 半掌握内容

- 无。`06_modern_cpp` 阶段 F1 `auto` 和范围 `for`、F2 `nullptr`、F3 智能指针、F4 移动语义、F5 Lambda、F6 `optional` / `variant` 基础已标记为已掌握。

## 5. 薄弱点

- 函数和编译阶段当前记录范围内暂无未掌握项；后续仍需在 `07_build_system` 阶段继续深入 `g++` 常用参数、CMake 和规范工程目录组织。
- 指针引用内存阶段当前记录范围内暂无未掌握项；后续进入现代 C++ 阶段时，还需要继续学习 `const` 引用、智能指针和更规范的资源管理。
- 面向对象阶段当前记录范围内 D1-D6 和阶段复盘暂无半掌握项；后续可在 STL、智能指针和小项目中继续自然加固类设计、拷贝控制和 RAII。
- STL 薄弱点：当前 E1-E6 已完成；后续仍可在标准算法谓词、迭代器失效、对象元素生命周期、扩容失效、字符串边界安全、集合去重和哈希容器选择问题中继续加固。E6 曾出现两个需复盘点：`std::sort` 会修改原容器顺序，`std::find` 找不到时返回 `end()` 而不是 `-1`。
- 现代 C++ 薄弱点：当前 F1-F6 基础已完成；后续在 STL 算法、项目代码、错误处理和接口设计中继续自然复盘 `auto`、范围 `for`、`nullptr`、智能指针、移动语义、Lambda、`optional` 和 `variant`。
- 工程能力薄弱点：`g++` 常用参数、CMake 最小项目、`include/`、`src/`、`tests/` 目录组织、Debug、单元测试、Git 基础工作流。
- 文件、异常、并发和项目薄弱点：`ifstream`、`ofstream`、`try/catch/throw`、`thread/mutex`、命令行通讯录、文件统计工具、小型 C++ 工程重构。

## 6. 已完成代码文件

| 文件路径 | 内容 | 掌握情况 |
|---|---|---|
| 01_basic_syntax/hello_world.cpp | 最小 C++ Hello World 程序 | 已掌握 |
| 01_basic_syntax/variable_basic.cpp | 变量、基础类型、赋值和输出变量值 | 已掌握 |
| 01_basic_syntax/expression_basic.cpp | 算术运算符、比较运算符和简单表达式 | 已掌握 |
| 01_basic_syntax/if_else_basic.cpp | 条件判断 `if`、`else if`、`else` | 已掌握（用户自述） |
| 01_basic_syntax/loop_basic.cpp | `for` 循环、`while` 循环、循环变量更新 | 已掌握（用户自述） |
| 01_basic_syntax/const_enum_cast.cpp | `const`、`enum class`、`static_cast<int>` 简单类型转换 | 已掌握（用户完成练习） |
| 03_function_scope_compile/scope_basic.cpp | 作用域、局部变量、代码块变量、全局变量 | 已掌握（用户完成练习，本地编译运行通过） |
| 03_function_scope_compile/function_declaration.cpp | 函数声明、函数定义、声明和定义分离 | 已掌握（用户完成练习，本地编译运行通过） |
| 03_function_scope_compile/main_multi_file.cpp | 多文件程序入口、包含头文件、调用其他源文件中的函数 | 已掌握（用户完成练习，本地编译运行通过） |
| 03_function_scope_compile/math_utils.h | 函数声明、头文件保护、对外提供函数接口 | 已掌握（用户完成练习） |
| 03_function_scope_compile/math_utils.cpp | 函数定义、实现头文件中声明的函数 | 已掌握（用户完成练习） |
| 03_function_scope_compile/build_config.h | 头文件保护、枚举类型定义、常量定义 | 已掌握（用户完成练习，本地编译运行通过） |
| 03_function_scope_compile/header_guard_demo.cpp | 重复包含同一头文件、验证头文件保护 | 已掌握（用户完成练习，本地编译运行通过） |
| 02_pointer_reference_memory/pointer_basic.cpp | 地址、指针变量、解引用、通过指针修改变量、指针改指向 | 已掌握（用户完成代码练习 1-4 和练习 5 思考题，本地编译运行通过） |
| 02_pointer_reference_memory/reference_basic.cpp | 引用基础、引用作为已有变量的别名、引用和指针对比、指针改指向和引用赋值区别 | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 02_pointer_reference_memory/function_parameter_basic.cpp | 值参数、指针参数、引用参数，函数通过指针或引用修改调用方变量，引用参数交换变量 | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 02_pointer_reference_memory/lifetime_basic.cpp | 栈上局部变量、返回值、堆对象、生命周期、`delete` 后置空 | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 02_pointer_reference_memory/new_delete_basic.cpp | `new` 创建单个堆对象、`delete` 释放、`new[]`/`delete[]` 动态数组、`delete nullptr` | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 02_pointer_reference_memory/memory_error_basic.cpp | 野指针、悬空指针、悬空引用、内存泄漏、安全释放后置空 | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 02_pointer_reference_memory/ownership_lifetime_review.cpp | 所有权、借用、释放责任、`int*&` 修改调用方指针、释放后置空的阶段复盘 | 已掌握（用户完成代码练习和思考题，本地编译运行通过） |
| 04_oop/class_object_basic.cpp | 类、对象、成员变量、成员函数、对象成员独立性、成员函数和普通函数对比 | 已掌握（用户完成 D1 练习和思考题，本地编译运行通过） |
| 04_oop/constructor_destructor_basic.cpp | 构造函数、成员初始化列表、析构函数、栈对象作用域结束析构、堆对象 `delete` 时析构、同一作用域内对象逆序析构 | 已掌握（用户完成 D2 代码练习和思考题补强，本地编译运行通过） |
| 04_oop/constructor_init_review.cpp | 构造函数补强：半初始化对象风险、对象创建即初始化、构造函数和普通返回对象函数的区别 | 已掌握（用户完成 D2 补充练习，本地编译运行通过） |
| 04_oop/this_private_basic.cpp | `this` 指针、`private` 成员变量、`public` 受控接口、对象内部状态保护 | 已掌握（用户完成 D3 练习和思考题，本地编译运行通过；已修正 `set_max_hp` 受控接口） |
| 04_oop/copy_assignment_basic.cpp | 拷贝构造函数、赋值运算符、自赋值检查、按值传参触发拷贝、`const` 引用传参避免拷贝 | 已掌握（用户完成 D4 代码练习和补强理解，本地编译运行通过） |
| 04_oop/copy_assignment_review.cpp | D4 补强：`const Player& other`、引用避免递归拷贝、`const` 保护来源对象、自赋值检查保护堆资源 | 已掌握（用户完成 D4 补强提问并表示理解，本地编译运行通过） |
| 04_oop/inheritance_polymorphism_basic.cpp | 继承、`protected`、虚函数、`override`、基类引用触发多态、构造析构顺序 | 已掌握（用户完成 D5 代码练习和补强理解，本地编译运行通过） |
| 04_oop/virtual_override_review.cpp | D5 补强：`virtual` 动态绑定、`override` 重写检查、重载和重写区别、`protected/private` 访问边界 | 已掌握（用户完成 D5 补充练习，本地编译运行通过） |
| 04_oop/raii_basic.cpp | RAII 基础、构造函数获取资源、析构函数释放资源、提前返回仍自动析构、禁用拷贝避免重复释放 | 已掌握（用户完成 D6 代码练习和补强理解，本地编译运行通过） |
| 04_oop/raii_copy_review.cpp | D6 补强：浅拷贝复制同一堆地址、重复释放风险、文件型 RAII 打开和关闭资源 | 已掌握（用户完成 D6 补充练习，本地编译运行通过） |
| 04_oop/oop_stage_review.cpp | `04_oop` 阶段复盘：对象生命周期、资源所有权、深拷贝、赋值运算符、多态、虚析构函数和 RAII | 已掌握（用户完成阶段复盘练习，本地编译运行通过） |
| 05_stl/vector_basic.cpp | `std::vector` 基础：创建、`push_back`、范围 `for` 遍历、下标访问和修改元素、观察 `size()` 与 `capacity()` | 已掌握（用户完成 E1 练习，本地编译运行通过） |
| 05_stl/string_basic.cpp | `std::string` 常用操作：创建、拼接、追加、长度检查、空字符串判断、下标访问、`find()`、`npos`、`substr()`、内容比较 | 已掌握（用户完成 E2 练习，本地编译运行通过） |
| 05_stl/map_basic.cpp | `std::map` / `std::unordered_map` 基础：键值对、插入、修改、查找、`end()`、遍历顺序、`operator[]` 自动插入行为 | 已掌握（用户完成 E3 练习，本地编译运行通过） |
| 05_stl/set_basic.cpp | `std::set` / `std::unordered_set` 基础：唯一集合、插入、重复插入、查找、`end()`、删除、遍历顺序 | 已掌握（用户完成 E4 练习，本地编译运行通过） |
| 05_stl/iterator_basic.cpp | 迭代器基础：`begin()`、`end()`、`*it`、`++it`、`vector` 修改元素、`set` 遍历、`map` 键值对访问 | 已掌握（用户完成 E5 练习，本地编译运行通过） |
| 05_stl/algorithm_basic.cpp | 常用标准算法：`std::sort`、`std::find`、`std::count`，迭代器范围、原地排序、查找失败返回 `end()`、统计重复值 | 已掌握（用户完成 E6 练习，本地编译运行通过；已修正 `sort` 是否修改容器和 `find` 失败返回值的表述） |
| 06_modern_cpp/auto_range_for_basic.cpp | `auto` 类型推导、范围 `for`、`auto`/`auto&`/`const auto&` 的拷贝和引用区别、`map` 键值对遍历 | 已掌握（用户完成 F1 练习，本地编译运行通过；已补清 `const auto&` 的工程原因是只读且避免拷贝） |
| 06_modern_cpp/nullptr_basic.cpp | `nullptr`、空指针检查、函数重载中的 `0` 和 `nullptr` 区别、`delete` 后置空、指针参数和引用参数的接口含义 | 已掌握（用户完成 F2 练习，本地编译运行通过；已补清确定不接受空对象时优先用引用参数表达接口约束） |
| 06_modern_cpp/smart_pointer_basic.cpp | `std::unique_ptr` 独占所有权、`std::shared_ptr` 共享所有权、智能指针 RAII 自动释放、`std::move` 转移所有权、`shared_ptr::use_count()` | 已掌握（用户完成 F3 练习，本地编译运行通过；已补清 `std::move` 不释放对象、`shared_ptr` 用于共享生命周期所有权） |
| 06_modern_cpp/move_semantics_basic.cpp | 拷贝构造、移动构造、拷贝赋值、移动赋值、`std::move`、移动后对象状态、`vector` 搬迁元素 | 已掌握（用户完成 F4 练习，本地编译运行通过；已补清 `std::move` 不移动也不释放、移动构造/移动赋值负责转移资源、RAII 负责自动释放） |
| 06_modern_cpp/lambda_basic.cpp | Lambda、捕获列表、值捕获、引用捕获、配合 `std::sort` / `std::find_if` / `std::count_if` / `std::for_each` 表达自定义规则 | 已掌握（用户完成 F5 练习，本地编译运行通过；已补清比较函数参数和实操排序规则） |
| 06_modern_cpp/optional_variant_basic.cpp | `std::optional`、`std::nullopt`、`std::variant`、`holds_alternative`、`get`，表达可能没有值和固定多类型之一 | 已掌握（用户完成 F6 练习，本地编译运行通过；已补清空 optional 取值是未定义行为，并完成 `LevelUpAction` 实操） |

## 7. 已完成练习

| 练习 | 所属知识点 | 完成情况 | 问题 |
|---|---|---|---|
| `01_basic_syntax/exercise.md` 练习 1：修改输出内容 | 最小 C++ 程序、标准输出、编译运行 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 2：输出两行文本 | `std::cout`、`std::endl` 或 `\n` 换行 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 3：修改变量值 | 变量声明、基础类型、标准输出 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 4：新增 `int year` 变量并输出 | 变量声明、赋值、标准输出 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 5：修改参与运算的变量 | 算术运算符、整数除法、取余 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 6：新增比较表达式 | 比较运算符、`bool`、`=`/`==`/`!=` 区分 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 7：修改分数测试条件分支 | 条件判断 `if`、`else if`、`else` | 未记录具体练习过程，用户自述已掌握 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 8：修改 `for` 循环范围 | `for` 循环、循环变量、循环边界 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 9：修改 `while` 循环 | `while` 循环、`count--`、循环停止条件 | 已完成 | 未记录具体问题 |
| `01_basic_syntax/exercise.md` 练习 10：尝试修改常量 | `const`、编译期错误检查 | 已完成 | 已观察 `const` 变量不能重新赋值 |
| `01_basic_syntax/exercise.md` 练习 11：增加订单状态 | `enum class`、状态建模 | 已完成 | 已能使用 `OrderStatus::Cancelled` 表达状态 |
| `01_basic_syntax/exercise.md` 练习 12：观察类型转换 | `static_cast<int>`、小数转整数 | 已完成 | 已理解显式转换为 `int` 时小数部分被丢弃 |
| `06_modern_cpp/exercise.md` F1 练习 1-7：`auto` 和范围 `for` | 类型推导、范围遍历、拷贝、引用、只读引用、`map` 键值对遍历 | 已完成 | 初始答案中 `const auto&` 的原因表述不够准确；已补清其关键是只读保护和避免复制，不是“解引用方便” |
| `06_modern_cpp/exercise.md` F2 练习 1-5：`nullptr` | 空指针表达、空指针检查、重载区别、`delete` 后置空、指针参数和引用参数选择 | 已完成 | 初始不确定何时用 `Player&` 替代 `Player*`；已补清引用参数表达必须传入有效对象，指针参数表达可能为空并需要检查 |
| `06_modern_cpp/exercise.md` F3 练习 1-5：智能指针 | `unique_ptr`、`shared_ptr`、RAII 自动释放、所有权转移、引用计数、借用对象 | 已完成 | 初始把 `std::move` 表述成自动释放，并把 `shared_ptr` 使用场景表述成多个变量操作对象；已补清 `std::move` 是所有权转移，`shared_ptr` 适合多个所有者共同延长对象生命周期 |
| `06_modern_cpp/exercise.md` F4 练习 1-5：移动语义 | 拷贝和移动、`std::move`、移动后对象、拷贝赋值和移动赋值、资源所有权转移 | 已完成 | 初始把真正转移资源的主体写成拷贝构造，把移动语义的作用写成减少释放操作；已补清真正转移资源的是移动构造/移动赋值，RAII 负责自动释放，移动语义负责避免不必要深拷贝并转移资源所有权 |
| `06_modern_cpp/exercise.md` F5 练习 1-5：Lambda | 匿名函数、捕获列表、值捕获、引用捕获、标准算法自定义排序/查找/统计/遍历规则 | 已完成 | 初始将 `left` / `right` 表述成固定前后对象，且第一次只写出按 `hp` 排序答案未实际改代码；已补清它们是算法拿来比较的两个元素，并完成按 `hp` 从低到高排序的实操 |
| `06_modern_cpp/exercise.md` F6 练习 1-5：`optional` 和 `variant` | `optional` 表达可能没有值、`nullopt`、取值前检查、`variant` 表达固定类型之一、扩展动作类型 | 已完成 | 初始把空 optional 强行取值的风险写成悬空指针/错别字，并让 `LevelUpAction` 指向不存在目标；已补清风险是未定义行为，并改为命中 Alice 观察 `level` 增加 |
| `03_function_scope_compile/exercise.md` 练习 1：新增并输出 `user_score` | 局部变量、函数作用域 | 已完成 | 未记录具体问题 |
| `03_function_scope_compile/exercise.md` 练习 2：在代码块外访问 `block_count` | 代码块作用域、编译错误观察 | 已完成 | 已将错误访问语句保留为注释，理解离开代码块后名字不可见 |
| `03_function_scope_compile/exercise.md` 练习 3：修改 `global_count` 为 `200` | 全局变量、多个函数共享同一变量 | 已完成 | 已观察 `main` 和 `print_global_count` 输出同一个全局变量值 |
| `03_function_scope_compile/exercise.md` 练习 4：作用域思考题 | 外层作用域访问、全局变量工程风险 | 已完成 | 已说明内部代码块能访问外层局部变量，全局变量可能被多处误用或意外修改 |
| `03_function_scope_compile/exercise.md` 练习 5：修改 `add` 调用参数 | 函数声明、函数调用 | 已完成 | 已观察 `main` 可通过声明调用后面才定义的函数 |
| `03_function_scope_compile/exercise.md` 练习 6：观察没有声明时的错误 | 函数声明、编译错误观察 | 已完成 | 已理解编译器在看到函数调用前需要先知道函数声明 |
| `03_function_scope_compile/exercise.md` 练习 7：观察声明和定义不匹配 | 函数返回类型、声明定义一致性 | 已完成 | 已观察声明和定义返回类型不一致会产生错误 |
| `03_function_scope_compile/exercise.md` 练习 8：新增 `multiply` 函数 | 先声明、后调用、再定义 | 已完成 | 已新增 `multiply` 声明和定义，并在 `main` 中调用输出 |
| `03_function_scope_compile/exercise.md` 练习 9：函数声明思考题 | 函数接口、工程组织 | 已完成 | 已理解函数声明能让编译器提前知道函数存在，并开始理解声明对降低耦合和组织代码的作用 |
| `03_function_scope_compile/exercise.md` 练习 10：编译多文件程序 | 多文件编译、`.h` / `.cpp` 组织 | 已完成 | 已确认多个 `.cpp` 文件可以一起编译成一个可执行程序 |
| `03_function_scope_compile/exercise.md` 练习 11：只编译 `main_multi_file.cpp` | 链接错误、缺少函数定义 | 已完成 | 已观察 `Undefined symbols`，理解只有声明但没有链接定义会失败 |
| `03_function_scope_compile/exercise.md` 练习 12：新增 `subtract` 函数 | 头文件声明、源文件定义、跨文件调用 | 已完成 | 已在 `.h` 新增声明、在 `.cpp` 新增定义、在 `main` 中调用输出 |
| `03_function_scope_compile/exercise.md` 练习 13：多文件思考题 | 头文件包含、多文件编译命令 | 已完成 | 已通过练习理解 `main` 需要包含头文件以看到声明，编译命令需要包含实现所在的 `.cpp` |
| `03_function_scope_compile/exercise.md` 练习 14：分步编译 | `.cpp`、`.o`、链接生成可执行程序 | 已完成 | 已确认 `.cpp` 可以先分别编译成 `.o`，再链接成可执行程序 |
| `03_function_scope_compile/exercise.md` 练习 15：缺少目标文件链接 | 链接错误、目标文件、函数定义 | 已完成 | 已观察缺少 `math_utils.o` 时出现 `Undefined symbols`，理解链接器需要找到函数定义 |
| `03_function_scope_compile/exercise.md` 练习 16：编译头文件保护示例 | 头文件保护、重复包含 | 已完成 | 已确认重复包含带保护的 `build_config.h` 仍可正常编译 |
| `03_function_scope_compile/exercise.md` 练习 17：去掉头文件保护 | 重复包含、重复定义错误 | 已完成 | 用户已完成观察并恢复头文件保护；本地确认最终文件可编译 |
| `03_function_scope_compile/exercise.md` 练习 18：编译链接思考题 | 编译阶段、链接阶段、头文件保护 | 已完成 | 用户自述已完成；本地验证相关示例均通过 |
| `02_pointer_reference_memory/exercise.md` 练习 1：打印 `level` 的值和地址 | 地址、取地址运算符 `&` | 已完成 | 已新增 `level` 并打印值和地址 |
| `02_pointer_reference_memory/exercise.md` 练习 2：创建指向 `level` 的指针 | 指针变量、保存地址、解引用读取 | 已完成 | 已新增 `level_ptr`，打印指针保存的地址和 `*level_ptr` 访问到的值 |
| `02_pointer_reference_memory/exercise.md` 练习 3：通过指针修改变量 | 解引用写入、通过地址修改原变量 | 已完成 | 已写出 `*level_ptr = 10`，并补充打印 `level` 验证值变为 `10` |
| `02_pointer_reference_memory/exercise.md` 练习 4：让同一个指针改指向另一个变量 | 指针变量可重新保存另一个变量地址 | 已完成 | 已新增 `backup_level`，让 `level_ptr` 改为指向 `backup_level` 并打印 `*level_ptr` |
| `02_pointer_reference_memory/exercise.md` 练习 5：指针思考题 | 指针保存地址、`p` 和 `*p` 区别、指针改指向 | 已完成 | 用户能说明指针变量保存地址，`p` 是地址，`*p` 是取地址对应的值，修改 `*p` 相当于修改该地址上的原变量，指针变量本身可以改为指向另一个变量 |
| `02_pointer_reference_memory/exercise.md` C2 练习 1：新增 `level` 和 `level_ref` 并打印值和地址 | 引用作为已有变量的别名、引用地址 | 已完成 | 已观察 `level` 和 `level_ref` 地址相同 |
| `02_pointer_reference_memory/exercise.md` C2 练习 2：通过引用修改原变量 | 引用赋值、修改绑定对象 | 已完成 | 已写出 `level_ref = 10`，并打印 `level` 验证原变量被修改 |
| `02_pointer_reference_memory/exercise.md` C2 练习 3：对比指针改指向和引用赋值 | 指针可改指向、引用赋值不是改绑 | 已完成 | 已观察 `level_ptr = &backup_level` 让指针指向 `backup_level`，而 `level_ref = backup_level` 是把值赋给 `level` |
| `02_pointer_reference_memory/exercise.md` C2 练习 4：引用和指针区别思考题 | 引用别名、指针改指向、引用不能改绑 | 已完成 | 用户能说明引用更像已有变量的别名，修改引用会修改原变量，指针可以改指向，引用绑定后不能改绑，`level_ref = backup_level` 是赋值而不是改绑 |
| `02_pointer_reference_memory/exercise.md` C3 练习 1：新增 `reset_by_value`、`reset_by_pointer`、`reset_by_reference` | 值参数、指针参数、引用参数 | 已完成 | 三个函数分别将参数改为 `0`，用于观察是否影响调用方变量 |
| `02_pointer_reference_memory/exercise.md` C3 练习 2：在 `main` 中观察三种 reset 调用 | 值传递副本、指针/引用修改调用方变量 | 已完成 | 已观察 `reset_by_value(level)` 后 `level` 仍为 `5`，`reset_by_pointer(&level)` 和 `reset_by_reference(level)` 后 `level` 变为 `0` |
| `02_pointer_reference_memory/exercise.md` C3 练习 3：新增 `swap_by_reference` | 引用参数、通过别名修改两个调用方变量 | 已完成 | 已通过 `swap_by_reference(a, b)` 将 `a` 和 `b` 从 `10/20` 交换为 `20/10` |
| `02_pointer_reference_memory/exercise.md` C3 练习 4：指针参数、引用参数思考题 | 值参数副本、指针传地址、引用传别名、非 `const` 引用风险 | 已完成 | 用户能说明普通值参数修改的是副本，指针参数修改同一地址上的值，引用参数是传入变量的别名，`&level` 是取地址，看到 `int& value` 应意识到函数可能修改调用方变量 |
| `02_pointer_reference_memory/exercise.md` C4 练习 1：新增 `level` 并打印值和地址 | 栈上局部变量、地址观察 | 已完成 | 已新增 `level` 并打印值和地址，观察其与函数内部 `local_score` 地址不同 |
| `02_pointer_reference_memory/exercise.md` C4 练习 2：新增 `create_level_by_value` | 返回局部变量的值 | 已完成 | 已通过 `returned_level` 接收返回值并打印值和地址 |
| `02_pointer_reference_memory/exercise.md` C4 练习 3：新增 `create_level_on_heap` | 堆对象、`new`、`delete`、指针置空 | 已完成 | 已创建堆上 `int`，打印地址和值，随后 `delete` 并将指针置为 `nullptr` |
| `02_pointer_reference_memory/exercise.md` C4 练习 4：解释返回局部变量地址的危险 | 局部变量生命周期、悬空指针 | 已完成 | 已用注释说明函数返回后栈上局部变量销毁，返回的地址不再指向有效对象，解引用属于未定义行为 |
| `02_pointer_reference_memory/exercise.md` C4 练习 5：生命周期思考题 | 栈生命周期、返回值、堆生命周期、`delete` 后不可用 | 已完成 | 用户能说明栈上局部变量随函数结束销毁，返回局部变量的值安全，返回局部变量地址危险，堆对象不会随函数结束自动销毁而需要 `delete`，`delete ptr` 释放堆对象但指针变量通常仍保存旧地址，继续解引用可能访问失效或被复用的内存 |
| `02_pointer_reference_memory/exercise.md` C5 练习 1：新增堆上 `level` | `new` 创建单个堆对象、解引用读写、`delete` 释放 | 已完成 | 已新增 `level_ptr = new int(5)`，打印地址和值，将值改为 `8`，最后 `delete level_ptr` 并置为 `nullptr` |
| `02_pointer_reference_memory/exercise.md` C5 练习 2：新增 `create_level` | 函数返回堆对象地址、调用方负责释放 | 已完成 | 已新增 `create_level(int value)`，在 `main` 中打印返回指针的地址和值，最后释放并置空 |
| `02_pointer_reference_memory/exercise.md` C5 练习 3：新增动态数组 `levels` | `new[]`、数组元素访问、`delete[]` | 已完成 | 已新增 `levels = new int[4]` 并打印 4 个元素，最后使用 `delete[] levels` 并置为 `nullptr` |
| `02_pointer_reference_memory/exercise.md` C5 练习 4：解释危险代码 | 重复释放、内存泄漏、释放方式不匹配 | 已完成 | 已用注释说明重复 `delete` 会导致未定义行为，忘记 `delete` 会造成内存泄漏，`new[]` 后用 `delete` 是释放方式不匹配 |
| `02_pointer_reference_memory/exercise.md` C5 练习 5：`new/delete` 思考题 | 堆对象创建、地址保存、释放、置空、数组释放规则 | 已完成 | 用户能说明 `new int(80)` 在堆上创建值为 `80` 的 `int`，需要保存地址以便之后释放，`delete p` 释放堆对象，释放后置空避免误用旧地址，`new[]` 需要用 `delete[]` 释放 |
| `02_pointer_reference_memory/exercise.md` C6 练习 1：新增 `level_ptr` 并安全释放 | 安全释放、`nullptr` 置空检查 | 已完成 | 已通过 `create_heap_score(60)` 创建堆对象，打印地址和值，调用 `safe_delete(level_ptr)` 后检查指针为 `nullptr` |
| `02_pointer_reference_memory/exercise.md` C6 练习 2：解释野指针代码 | 野指针、未初始化指针 | 已完成 | 用户能说明未初始化指针直接使用会造成野指针；已补充说明可能导致崩溃、数据损坏或未定义行为 |
| `02_pointer_reference_memory/exercise.md` C6 练习 3：解释悬空指针代码 | 释放后悬空指针、访问失效对象 | 已完成 | 用户能说明 `delete` 后堆对象已销毁，指针仍保存旧地址，继续使用会导致未定义行为 |
| `02_pointer_reference_memory/exercise.md` C6 练习 4：解释内存泄漏代码 | 地址丢失、无法释放堆对象 | 已完成 | 用户能说明第一次 `new` 的地址被覆盖且未释放，会造成内存泄漏 |
| `02_pointer_reference_memory/exercise.md` C6 练习 5：常见内存错误思考题 | 野指针、悬空指针、悬空引用、内存泄漏、`nullptr` | 已完成 | 用户能说明野指针、悬空指针、悬空引用和内存泄漏的基本含义，并知道释放后置为 `nullptr` 能降低误用旧地址的风险 |
| `02_pointer_reference_memory/ownership_lifetime_review.cpp` 阶段收尾练习 1：修改 `create_owned_score` 参数并运行 | 堆对象创建、调用方接收所有权 | 已完成 | 用户将 `create_owned_score(95)` 改为其他值并完成编译运行 |
| `02_pointer_reference_memory/ownership_lifetime_review.cpp` 阶段收尾练习 2：新增 `increase_borrowed_score(int* score_ptr)` | 借用指针、空指针检查、通过解引用修改对象 | 已完成 | 用户实现 `nullptr` 检查，并在非空时通过 `*score_ptr += 10` 修改值 |
| `02_pointer_reference_memory/ownership_lifetime_review.cpp` 阶段收尾练习 3：分别对栈对象地址和堆对象指针调用借用函数 | 栈对象借用、堆对象借用、释放后空指针防护 | 已完成 | 初始代码把堆对象调用放在释放之后，只观察到 `nullptr` 分支；后续已调整为释放前观察堆对象加 10，释放后观察空指针防护 |
| 所有权和借用思考题 | 借用函数不能释放、返回堆地址的释放责任、`int*&` 修改调用方指针 | 已完成 | 用户能说明借用函数不能随便释放参数地址，`create_owned_score` 返回地址后调用方应释放，`int*&` 解决传参是指针变量副本的问题 |
| `04_oop/exercise.md` D1 练习 1：新增 `hp` 成员变量 | 类、对象、成员变量、对象成员独立性 | 已完成 | 用户给 `Player` 新增 `hp`，分别设置 `alice.hp` 和 `bob.hp`，本地编译运行通过 |
| `04_oop/exercise.md` D1 练习 2：新增 `level_up()` 成员函数 | 成员函数、通过对象调用成员函数、修改具体对象状态 | 已完成 | 用户新增 `level_up()` 并调用，运行结果显示 `alice` 和 `bob` 各自的 `level` 独立变化 |
| `04_oop/exercise.md` D1 练习 3：对比普通函数和成员函数 | 成员函数调用、普通函数参数、对象作为参数传递 | 已完成 | 用户新增 `print_player_score(Player player)`，并对比 `alice.print_info()` 和 `print_player_score(alice)` |
| `04_oop/exercise.md` D1 思考题 | 类和对象、成员变量归属、成员函数操作对象、类的工程组织价值 | 已完成 | 用户能说明 `Player` 是类、`alice` 是实例，`alice.score` 和 `bob.score` 不是同一个变量，成员函数操作调用对象的数据，把相关变量组织到类里更便于维护并体现从属关系 |
| `04_oop/exercise.md` D2 练习 1：新增 `hp` 构造参数 | 构造函数、成员初始化列表、对象创建时初始化成员变量 | 已完成 | 用户新增 `hp` 成员变量，将 `hp` 加入构造函数参数和成员初始化列表，并更新 `alice`、`bob`、`temp`、`heap_player` 创建代码；本地编译运行通过 |
| `04_oop/exercise.md` D2 练习 2：观察析构顺序 | 析构函数、作用域、堆对象 `delete`、对象生命周期 | 已完成 | 运行结果显示 `Bob` 在内部代码块结束时析构，`HeapPlayer` 在 `delete` 时析构，`Temp` 在函数结束时析构，`Alice` 在 `main` 结束前最后析构 |
| `04_oop/exercise.md` D2 练习 3：新增 `create_two_players()` | 函数作用域、局部对象生命周期、同一作用域内对象逆序析构 | 已完成 | 用户新增 `first`、`second` 两个局部对象；运行结果显示 `Second` 先析构、`First` 后析构 |
| `04_oop/exercise.md` D2 思考题 | 构造函数、析构函数、`new/delete` 和内存泄漏 | 已完成 | 用户能说明析构函数在作用域结束或 `delete` 时调用，`new Player(...)` 和 `delete heap_player` 分别触发构造和析构，忘记 `delete` 可能造成内存泄漏；经补强后已理解构造函数不是普通返回函数，创建时初始化能避免半初始化对象 |
| `04_oop/exercise.md` D2 补充练习：对象创建即初始化 | 半初始化对象风险、构造函数初始化、普通函数返回对象和构造函数区别 | 已完成 | 用户能说明 `LoosePlayer` 创建后没有初始化，不能直接当完整对象使用；构造函数创建的 `Player` 已有完整属性，比依赖后续 `setup` 更不容易遗漏且更便于维护；能区分 `create_player()` 是普通函数、有返回值类型，构造函数没有返回值类型 |
| `04_oop/exercise.md` D3 练习 1：观察 `this` | `this` 指针、当前对象地址、成员函数操作调用对象 | 已完成 | 用户观察到 `&alice` 和 `alice.print_info()` 中的 `this` 相同，`&bob` 和 `bob.print_info()` 中的 `this` 相同，能说明 `this` 指向当前对象地址 |
| `04_oop/exercise.md` D3 练习 2：观察 `private` 编译错误 | 访问控制、私有成员、封装 | 已完成 | 用户取消注释观察到私有成员不能从类外直接访问，能说明外部随意修改会破坏对象状态；原回答中有少量错别字但概念方向正确 |
| `04_oop/exercise.md` D3 练习 3：新增 `set_max_hp(int value)` | `public` 受控接口、对象不变量、内部状态保护 | 已完成 | 用户新增接口后，本地检查发现初始实现未正确更新 `max_hp` 和压低过高 `hp`；已修正为先校验正数、再更新 `max_hp`、最后保证 `hp <= max_hp`，并在 `main` 中调用验证 |
| `04_oop/exercise.md` D3 思考题 | `this`、`this->`、`private`、`public` 接口、封装 | 已完成 | 用户能说明 `this` 是当前对象地址，`this->name = name` 左边表示当前对象成员、右边表示参数；能说明成员变量不应全部 `public`，`private` 不等于外部不能使用对象，外部可通过 `public` 接口规范行为 |
| `04_oop/exercise.md` D4 练习 1：观察拷贝构造 | 拷贝构造函数、创建新对象时用已有对象初始化 | 已完成 | 用户能说明 `Player bob = alice` 是创建新对象，输出中的新对象地址和来源对象地址不同，修改 `bob` 不会影响 `alice` |
| `04_oop/exercise.md` D4 练习 2：观察赋值运算符 | 赋值运算符、已有对象被另一个对象覆盖状态 | 已完成 | 用户能说明 `charlie` 在赋值前已经存在，`charlie = bob` 调用赋值运算符，赋值后 `charlie` 状态变成 `bob` 的状态 |
| `04_oop/exercise.md` D4 练习 3：观察按值传参 | 按值传参、参数对象、拷贝构造、参数生命周期 | 已完成 | 用户能说明 `print_by_value(alice)` 因为传参发生拷贝，函数结束时参数对象会析构；本地运行输出验证参数对象析构 |
| `04_oop/exercise.md` D4 练习 4：改成引用传参 | `const` 引用参数、避免拷贝、只读借用 | 已完成 | 用户新增 `print_by_const_reference(const Player& player)`，能观察调用该函数不触发拷贝构造，并说明因为传入的是引用 |
| `04_oop/exercise.md` D4 思考题 | 拷贝构造、赋值运算符、`const Player&`、自赋值检查 | 已完成 | 用户能说明拷贝构造在创建新对象时调用，赋值运算符在对象已创建后用 `=` 调用，`Player bob = alice` 和 `charlie = bob` 最大区别是前者创建新对象、后者操作已有对象；经补强后已理解 `const Player& other` 的引用避免递归拷贝、`const` 保护来源对象，以及自赋值检查保护资源对象 |
| `04_oop/exercise.md` D4 补充练习：拷贝参数和自赋值检查 | `const Player& other`、自赋值检查、堆资源所有权、深拷贝 | 已完成 | 用户提出并理解 `ScoreBuffer& operator=(...)` 是赋值运算符函数，`ScoreBuffer(const ScoreBuffer& other)` 是拷贝构造函数；已理解 `ScoreBuffer(int value)` 和 `ScoreBuffer(const ScoreBuffer& other)` 是构造函数，`operator=` 不是构造函数，而是对象已存在时调用的赋值函数 |
| `04_oop/exercise.md` D5 练习 1：观察继承 | 基类、派生类、构造顺序、继承成员函数 | 已完成 | 用户能说明创建 `Warrior` 时会先创建 `Character` 部分，`Warrior` 和 `Mage` 能调用 `print_status()` 是因为继承了基类方法 |
| `04_oop/exercise.md` D5 练习 2：观察多态 | 基类引用、虚函数、运行时多态 | 已完成 | 用户能说明 `run_turn` 参数类型是 `Character` 引用，传入 `warrior` 或 `mage` 时调用派生类重写后的 `act()` |
| `04_oop/exercise.md` D5 练习 3：新增 `Archer` 派生类 | 派生类扩展、重写虚函数、基类引用多态调用 | 已完成 | 用户新增 `Archer : public Character`，实现 `act()` 并调用 `archer.print_status()`、`archer.act()`、`run_turn(archer)`；本地编译运行通过 |
| `04_oop/exercise.md` D5 练习 4：观察去掉 `virtual` | 虚函数、静态绑定和动态绑定对比 | 已通过补强完成 | 用户最终文件已恢复 `virtual` 和 `override`；后续通过 `virtual_override_review.cpp` 补强理解 `virtual` 动态绑定和无签名匹配时 `override` 编译检查 |
| `04_oop/exercise.md` D5 思考题 | 继承、`protected/private`、`virtual`、`override`、多态 | 已完成 | 用户能说明 `Character` 是基类、`Warrior` 和 `Mage` 是派生类；经补强后能说明多态、动态绑定、`override` 检查签名不一致、`protected name` 可被派生类使用而 `private id` 不能被派生类直接访问 |
| `04_oop/exercise.md` D5 补充练习 1：区分重载和重写 | 重载 overload、重写 override、函数签名 | 已完成 | 用户能识别 `act()` 和 `act(int times)` 是重载关系，`Warrior::act()` 是重写基类虚函数；补充说明完整表述为 `Character::act()` 和 `Character::act(int)` 构成重载 |
| `04_oop/exercise.md` D5 补充练习 2：观察动态绑定 | `virtual`、基类引用、真实对象类型、运行时多态 | 已完成 | 用户能说明 `run_turn` 参数类型是 `Character` 引用，`run_turn(warrior)` 根据真实对象类型调用 `Warrior::act()` |
| `04_oop/exercise.md` D5 补充练习 3：观察 `override` 检查 | `override`、重写签名检查、编译错误 | 已完成 | 用户能说明把 `void act() const override` 改成 `void act(int value) const override` 后编译器报错，因为参数变了，不再匹配基类虚函数签名，`override` 帮助发现重写签名错误 |
| `04_oop/exercise.md` D5 补充练习 4：观察 `protected/private` | 派生类访问权限、封装、公共接口 | 已完成 | 用户能说明派生类可访问基类 `protected name`，不能直接访问 `private id`；`print_id()` 是基类提供的公共接口，用于在不暴露私有成员的情况下允许外部使用相关行为 |
| `04_oop/exercise.md` D6 练习 1：观察自动析构 | RAII、局部对象生命周期、提前 `return` 自动析构 | 已完成 | 用户能说明函数中途 `return` 时 `ScoreArray` 析构函数仍执行，局部对象离开作用域会调用析构函数并释放构造函数中创建的资源；本地编译运行通过 |
| `04_oop/exercise.md` D6 练习 2：理解构造和析构职责 | 构造函数获取资源、析构函数释放资源、`new[]/delete[]` 配对 | 已完成 | 用户能说明构造函数在堆上创建动态数组，析构函数用 `delete[]` 释放数组；需修正：当前示例析构函数没有把指针置为 `nullptr`，对象马上销毁时通常不需要再置空 |
| `04_oop/exercise.md` D6 练习 3：观察禁用拷贝 | `= delete`、资源所有权、浅拷贝、重复释放 | 已完成 | 用户能说明因为拷贝构造被 `= delete` 禁止，所以编译器会报错；经补强后已理解默认拷贝会复制指针值，使两个对象保存相同堆地址，析构时可能重复 `delete[]` |
| `04_oop/exercise.md` D6 练习 4：新增嵌套作用域函数 | 局部作用域、构造时机、析构时机 | 已完成 | 用户新增 `nested_scope_example()`，能说明 `ScoreArray scores(2)` 时构造，离开内部作用域时析构；已调整 `main end` 输出位置避免误导 |
| `04_oop/exercise.md` D6 思考题 | RAII、资源生命周期、自动释放、资源类型 | 已完成 | 用户能说明 RAII 核心是构造函数创建资源、析构函数释放资源，RAII 比手动 `delete` 更稳，因为离开作用域时会自动释放；经补强后已理解拥有堆内存的 RAII 类不能随便默认拷贝，并能列举文件、线程、堆内存等适合 RAII 管理的资源 |
| `04_oop/exercise.md` D6 补充练习 1：观察浅拷贝 | 默认拷贝、指针值复制、同一堆地址、重复释放风险 | 已完成 | 用户能说明 `first` 和 `second` 打印出的 `data address` 相同，说明默认拷贝指针时复制的是堆地址；如果两个对象都执行 `delete[] data`，会产生重复释放风险 |
| `04_oop/exercise.md` D6 补充练习 2：理解 `owner` | 所有权标记、重复释放防护 | 已完成 | 用户能说明 `second.owner` 被设置为 `false` 是为了避免重复释放同一地址；如果两个对象的 `owner` 都是 `true`，析构时可能重复释放资源 |
| `04_oop/exercise.md` D6 补充练习 3：观察文件型 RAII | 文件资源、打开和关闭、构造析构绑定资源生命周期 | 已完成 | 用户能说明 `FakeFile` 构造函数模拟创建或打开文件句柄，析构函数模拟关闭或释放文件资源；文件有获取和释放动作，因此适合 RAII 管理 |
| `04_oop/exercise.md` D6 补充练习 4：列举资源 | RAII 资源类型、获取动作、释放动作 | 已完成 | 用户列举文件操作、线程操作、堆内存操作；补充说明线程资源通常对应启动线程和 `join`/`detach`，堆内存对应申请和释放，文件对应打开和关闭 |
| `04_oop/exercise.md` 阶段复盘练习 1：观察深拷贝 | 拷贝构造、深拷贝、资源地址独立性 | 已完成 | 用户完成 `oop_stage_review.cpp` 阶段复盘练习；本地示例中 `Player bob = alice` 触发拷贝构造，`ScoreLog` 申请新堆数组，修改 `bob` 不影响 `alice` |
| `04_oop/exercise.md` 阶段复盘练习 2：观察赋值运算符 | 已有对象赋值、自赋值检查、旧资源处理 | 已完成 | 用户完成阶段复盘；本地示例中 `charlie = alice` 触发赋值运算符，赋值前 `charlie` 已存在，因此需要处理已有资源和自赋值风险 |
| `04_oop/exercise.md` 阶段复盘练习 3：观察析构顺序 | 局部对象生命周期、析构释放资源、RAII | 已完成 | 用户完成阶段复盘；能继续通过输出观察函数作用域结束时 `Player`、`ScoreLog`、`Character` 的析构顺序，理解析构函数释放堆数组资源 |
| `04_oop/exercise.md` 阶段复盘练习 4：观察多态 | 基类引用、虚函数、动态绑定 | 已完成 | 用户完成阶段复盘；本地示例中 `run_turn(const Character&)` 可接收 `Player`，并通过虚函数调用 `Player::take_turn()` |
| `04_oop/exercise.md` 阶段复盘练习 5：新增 `heal(int value)` | `private` 状态、`public` 受控接口、对象不变量 | 已完成 | 用户自述已完成；用于加固外部不能直接修改 `private hp`，应通过 `public` 接口安全改变对象状态 |
| `05_stl/exercise.md` E1 练习 1-4：`std::vector` 基础 | 动态数组容器、`push_back`、下标访问、`size()`、`capacity()`、RAII 自动内存管理 | 已完成 | 用户完成新增元素、修改元素、观察容量变化和对比 `new[]` 的练习；本地编译运行通过。补强点：修改元素后增加一次打印，便于观察结果 |
| `05_stl/exercise.md` E2 练习 1-5：`std::string` 常用操作 | 字符串对象、拼接、追加、查找、`npos`、截取、和字符数组对比 | 已完成 | 用户完成修改字符串、追加 `"STL"`、查找 `"C++"`、截取前 5 个字符和对比 `char[]` 的练习；本地编译运行通过。补强点：将 `npos` 表述为 `std::size_t` 特殊最大值，不能作为有效下标使用 |
| `05_stl/exercise.md` E3 练习 1-6：`std::map` / `std::unordered_map` 基础 | 键值对、插入、修改、查找、`end()`、遍历顺序、`operator[]` 自动插入行为 | 已完成 | 用户完成新增键值对、修改已有值、查找不存在键、观察 `operator[]` 插入默认值、观察 `unordered_map` 顺序和工程问题回答；本地编译运行通过。补强点：`unordered_map` 的遍历顺序标准不保证等于插入顺序 |
| `05_stl/exercise.md` E4 练习 1-6：`std::set` / `std::unordered_set` 基础 | 唯一集合、插入、重复插入、查找、`end()`、删除、遍历顺序、和 `vector` / `map` 对比 | 已完成 | 用户完成新增标签、观察重复插入、查找 `"stl"`、删除不存在元素、观察 `unordered_set` 顺序和工程问题回答；本地编译运行通过。补强点：插入 `Diana` 后补充打印集合和 size，便于观察结果 |
| `05_stl/exercise.md` E5 练习 1-6：迭代器基础 | `begin()`、`end()`、`*it`、`++it`、容器遍历、修改元素、`map` 键值对访问 | 已完成 | 用户完成新增 `vector` 元素、通过迭代器修改元素、手动移动迭代器、遍历 `set`、遍历 `map` 和工程问题回答；本地编译运行通过。补强点：修正先 `++first_score` 后仍输出 `first score` 的标签误导 |
| `05_stl/exercise.md` E6 练习 1-6：常用算法 | `std::sort`、`std::find`、`std::count`、迭代器范围、排序、查找、计数 | 已完成 | 用户完成编译运行、修改排序数据、查找存在和不存在的值、统计重复值、字符串排序查找计数和工程问题回答；本地编译运行通过。补强点：`std::sort` 是原地修改容器顺序，`std::find` 找不到时返回 `end()` 而不是 `-1` |

## 8. 常见错误记录

- 链接错误：只编译或只链接 `main_multi_file.cpp` / `main_multi_file.o` 时会出现 `Undefined symbols`，原因是调用处看到了函数声明，但链接阶段找不到 `add`、`multiply`、`subtract` 的定义。
- 头文件重复包含风险：如果头文件里有类型定义且没有头文件保护，同一个 `.cpp` 重复包含该头文件可能导致重复定义错误。
- 指针复盘练习中的观察顺序问题：初始代码在 `destroy_owned_score(heap_score)` 之后才调用 `increase_borrowed_score(heap_score)`，此时 `heap_score` 已被置为 `nullptr`，因此只能观察到空指针保护，不能观察堆对象被加 10；已调整为释放前先调用一次，释放后再验证空指针保护。
- 输出标签误导：曾用 `&stack_score:` 作为输出标签但实际打印的是 `stack_score` 的值，不是地址；后续整理为 `stack_score after increase`，避免把取地址符号和普通值输出混淆。
- D3 受控接口实现问题：初始 `set_max_hp(int value)` 能编译，但没有正确维护 `max_hp` 和 `hp <= max_hp`；已修正为先校验正数、更新 `max_hp`，再在必要时把 `hp` 压回 `max_hp`。
- D4 语法辨认卡点：曾不确定 `ScoreBuffer& operator=(const ScoreBuffer& other)` 是否是函数，因为函数名里有 `=`；已明确它是赋值运算符函数，`second = first` 等价于调用 `second.operator=(first)`。
- D4 构造函数辨认卡点：曾不确定 `ScoreBuffer(const ScoreBuffer& other)` 什么时候调用；已明确它是拷贝构造函数，在用已有对象创建新对象时调用，例如 `ScoreBuffer second = first`。
- D5 概念混淆：曾把 `virtual` 和 `override` 表述为“重载”；已补清重载 overload 是同名不同参数，重写 override 是派生类重新实现基类虚函数，`virtual` 启用动态绑定，`override` 做编译期重写检查。
- D6 默认拷贝误解：曾误以为默认拷贝可能让两个对象保存“相同变量但地址不同”；已补清默认拷贝指针时复制的是同一个堆地址，两个对象都释放会导致重复释放风险。
- D6 析构函数置空误解：曾认为析构函数中 `delete[] data` 后还需要把 `data = nullptr`；已修正为对象马上销毁时通常不需要置空，因为成员变量生命周期也随对象结束。
- 项目状态检查：本轮尝试执行 `git diff` / `git status` 时出现 `Not a git repository`，说明当前项目目录尚未初始化为 Git 仓库或不在 Git 仓库内；后续学习 Git 工作流前需要单独处理。
- E2 `std::string::npos` 表述细节：曾把 `npos` 简化理解为 `-1`；已补清它是 `std::size_t` 类型的特殊最大值，用来表示查找失败，不是有效下标。
- E3 `unordered_map` 顺序误解：曾根据一次运行结果认为 `unordered_map` 遍历顺序等于插入顺序；已补清标准不保证其遍历顺序，若工程里需要按键排序输出应选择 `std::map`。
- E5 迭代器位置标签误导：曾在 `first_score` 已经执行 `++` 后仍输出 `first score`，实际此时迭代器已指向第二个元素；已调整为先输出第一个元素，再移动迭代器输出第二个元素。
- E6 标准算法概念误差：曾认为 `std::sort` “只是顺序发生变化，没有修改容器”；已补清顺序变化发生在原 `vector` 内部，所以 `std::sort` 是原地修改算法。曾把 `std::find` 查找失败写成返回 `-1`；已补清对迭代器范围而言，查找失败返回结束迭代器 `end()`。
- F1 `const auto&` 表述误差：曾把 `map` 遍历使用 `const auto&` 的原因说成“不使用引用类型的话需要解引用，编码麻烦”；已补清范围 `for` 中 `auto` 本身也能直接拿到元素副本，`const auto&` 的工程原因是只读保护和避免复制键值对或对象。
- F2 指针和引用接口选择卡点：曾不确定如果函数确定永远不接受空对象，为什么 `Player&` 可能比 `Player*` 更合适；已补清引用参数表达“必须有对象”，指针参数表达“可能没有对象”，允许为空时才需要 `nullptr` 检查。
- F3 `std::move` 表述误差：曾把 `std::move(alice)` 理解成移动后独占指针自动释放；已补清 `std::move` 本身不释放对象，而是把 `alice` 转成可被移动的形式，所有权转移给 `owner` 后对象仍由 `owner` 管理。
- F3 `shared_ptr` 使用场景表述误差：曾把使用 `shared_ptr` 的理由说成“多个变量对内容进行操作”；已补清关键不是谁能操作对象，而是谁共同拥有并延长对象生命周期。临时读取或修改仍优先传引用。
- F4 `std::move` 和移动函数边界误差：曾把真正转移资源的主体写成“拷贝构造中的行为逻辑”；已补清 `std::move` 只是把表达式转换成可移动形式，真正转移资源的是移动构造函数或移动赋值运算符。
- F4 移动语义和 RAII 边界误差：曾把移动语义的重要性表述成“不用写繁琐的释放操作，减少内存泄漏”；已补清自动释放资源主要来自 RAII，移动语义主要用于避免昂贵深拷贝并转移资源所有权。
- F5 Lambda 比较函数理解误差：曾把 `std::sort` 中 Lambda 参数 `left` / `right` 理解成固定的前后对象；已补清它们只是算法拿来比较的两个元素，比较表达式决定排序规则。
- F5 Lambda 实操缺口：第一次只在注释里写出按 `hp` 从低到高排序应使用 `<`，但代码仍按 `score` 降序排序；已改为 `return left.hp < right.hp;` 并运行观察 `hp` 升序结果。
- F6 optional 取值风险表述误差：曾把空 `optional` 强行取值的风险写成“悬空指针”并出现错别字；已补清对没有值的 `optional` 强行取值属于未定义行为。
- F6 variant 实操观察缺口：第一次新增 `LevelUpAction` 时目标写成不存在的 `bibi`，只能观察到找不到目标分支；已改为命中已有玩家 Alice，并观察 `level` 从 `3` 增加到 `23`。

## 9. 重要概念理解记录

| 概念 | 当前理解程度 | 需要继续补的点 |
|---|---|---|
| 编译 | 基础掌握：知道 `.cpp` 源文件可以通过 `g++` 编译成可执行文件，也可以用 `g++ -c` 先编译成 `.o` 目标文件 | 后续在 `07_build_system` 继续补充预处理、汇编、编译参数和构建系统 |
| 链接 | 基础掌握：知道链接阶段会把多个 `.o` 合成可执行程序，并解决函数定义在哪里；已观察缺少目标文件时出现 `Undefined symbols` | 后续在 `07_build_system` 继续学习更复杂的库链接和构建错误 |
| 头文件 | 基础掌握：知道头文件可以放函数声明，其他 `.cpp` 通过 `#include "xxx.h"` 使用声明；知道头文件保护可以避免重复包含导致的重复定义问题 | 后续学习更规范的工程头文件组织、`include/` 目录和只暴露必要接口 |
| `const` | 基础掌握：知道常量创建后不能重新赋值，编译器会在编译阶段拦截修改常量的错误 | 后续学习 `const` 参数、`const` 成员函数、指针和引用中的 `const` |
| 枚举 | 基础掌握：知道 `enum class` 可以用有名字的状态替代裸整数 | 后续学习枚举底层类型、`switch` 搭配枚举、枚举和类型安全 |
| 类型转换 | 基础掌握：知道 `static_cast<int>` 是显式类型转换，`double` 转 `int` 会丢弃小数部分 | 后续学习隐式转换风险、`static_cast` 的适用范围、其他转换形式 |
| 作用域 | 基础掌握：知道名字只在特定代码范围内可见；外层局部变量可以在内部代码块使用，内部代码块变量离开代码块后不可见 | 后续结合函数声明、头文件和多文件编译继续理解名字可见性 |
| 全局变量 | 基础掌握：知道定义在函数外的变量可以被同一源文件中的多个函数访问，也知道工程里要谨慎使用 | 后续学习多文件工程中的声明、定义、链接和重复定义问题 |
| 函数声明 | 基础掌握：知道声明告诉编译器函数名、返回类型、参数类型和参数数量，使 `main` 能调用后面才定义的函数 | 后续学习把声明放进 `.h` 头文件，把定义放进 `.cpp` 源文件 |
| 函数定义 | 基础掌握：知道定义包含函数体 `{}`，描述函数具体怎么执行；声明和定义的返回类型、函数名、参数类型需要匹配 | 后续学习多文件编译时定义如何参与链接 |
| 多文件编译 | 基础掌握：知道一个程序可以由多个 `.cpp` 一起编译生成；`main_multi_file.cpp` 负责主流程，`math_utils.cpp` 提供函数实现 | 后续学习分步编译、目标文件 `.o` 和链接过程 |
| `.h` / `.cpp` 组织 | 基础掌握：知道 `.h` 通常放声明，`.cpp` 通常放定义，调用方通过包含头文件获得接口信息 | 后续学习更规范的工程目录组织和 CMake 管理 |
| 头文件保护 | 基础掌握：知道 `#ifndef` / `#define` / `#endif` 可以让同一头文件内容在一个翻译单元中只生效一次 | 后续学习 `#pragma once`、大型工程中的头文件依赖和前置声明 |
| 指针 | 基础掌握：已能写出最小代码，理解 `&变量` 取地址、指针变量保存地址、`*指针` 解引用访问或修改原变量；已能说明 `p` 和 `*p` 的区别，知道指针变量可以改为保存另一个变量地址；已理解指针参数通过地址修改调用方变量 | 后续继续学习空指针、指针和生命周期风险 |
| 引用 | 基础掌握：已能写出最小代码，理解引用更像已有变量的别名，修改引用会修改原变量；已能区分指针可改指向，而引用绑定后不能改绑，`ref = other` 是赋值不是改绑；已理解引用参数通过别名修改调用方变量 | 后续继续学习 `const` 引用、引用和生命周期风险 |
| 生命周期 | 基础掌握：已理解栈上局部变量随作用域创建和销毁，返回局部变量的值安全，返回局部变量地址危险；已理解堆对象不会随创建函数结束自动销毁，需要 `delete`；已理解 `delete` 后原指针通常仍保存旧地址，但不能继续解引用 | 后续继续学习悬空引用、野指针、内存泄漏 |
| `new/delete` | 基础掌握：已理解 `new` 在堆上创建对象并返回地址，`delete` 销毁堆对象并交还内存；已理解 `new`/`delete` 和 `new[]`/`delete[]` 必须配对，释放后建议置为 `nullptr`，重复释放、忘记释放和释放方式不匹配会出问题 | 后续继续学习野指针、悬空引用、内存泄漏，并在现代 C++ 阶段学习智能指针 |
| 常见内存错误 | 基础掌握：已能区分野指针、悬空指针、悬空引用和内存泄漏；知道未初始化指针、释放后继续使用、返回局部变量地址、丢失堆对象地址都是危险模式 | 后续通过 RAII、智能指针、调试工具继续加固 |
| 所有权与借用 | 基础掌握：已理解借用函数可以读取或修改对象但不负责释放；通过 `new` 创建并返回的堆对象地址需要由接收方负责释放；`int*&` 可用于让函数释放堆对象后把调用方指针置为 `nullptr` | 后续在类、构造函数、析构函数、RAII 和智能指针阶段继续学习更规范的所有权表达 |
| RAII | 基础掌握：已能写出 `ScoreArray` RAII 类，构造函数中 `new[]` 获取堆数组，析构函数中 `delete[]` 释放；已能观察提前 `return` 和嵌套作用域结束时局部对象自动析构；已能使用 `= delete` 禁止拷贝；已理解默认拷贝会复制指针地址导致两个对象拥有同一堆资源并可能重复释放；已通过 `oop_stage_review.cpp` 进一步观察深拷贝、赋值释放旧资源和析构顺序；已理解 RAII 可管理堆内存、文件、线程、锁、连接等需要获取和释放的资源 | 后续在现代 C++ 阶段继续学习 `std::unique_ptr`、`std::shared_ptr`、移动语义和标准库 RAII 类型 |
| 类和对象 | 基础掌握：已能写出最小 `class Player`，创建 `alice`、`bob` 两个对象，理解成员变量属于具体对象，成员函数通过对象调用并操作该对象的数据；已能对比成员函数和类外普通函数 | 后续学习构造函数、析构函数、`this`、访问控制、构造析构和类的 `.h` / `.cpp` 拆分 |
| 构造函数和析构函数 | 基础掌握：已能写出带参数构造函数、成员初始化列表和析构函数；已能观察栈对象离开作用域自动析构、堆对象 `delete` 时析构、函数局部对象在函数结束时析构、同一作用域内后创建对象先析构；已理解构造函数没有返回值类型，因为它发生在对象创建过程中，职责是初始化正在创建的对象；已理解创建时初始化比先创建再 `setup` 更稳妥，可以避免半初始化对象；已在 RAII 和阶段复盘中连接资源获取、资源释放和对象生命周期 | 后续在 STL 和现代 C++ 阶段继续观察标准库对象如何自动管理资源 |
| `this` 和访问控制 | 基础掌握：已理解成员函数中的 `this` 指向当前调用对象；已能通过地址输出观察 `&alice == this`、`&bob == this`；已理解 `this->name = name` 用于区分成员变量和同名参数；已理解 `private` 用于保护对象内部状态，`public` 成员函数是外部使用对象的受控接口 | 后续学习拷贝构造和赋值运算符时继续关注对象状态、资源所有权和接口边界 |
| 拷贝构造和赋值运算符 | 基础掌握：已能写出拷贝构造函数和赋值运算符，能观察 `Player bob = alice` 触发拷贝构造、`charlie = bob` 触发赋值运算符、按值传参触发拷贝构造、`const Player&` 引用传参不触发拷贝；已理解 `operator=` 是赋值运算符函数，`ScoreBuffer(const ScoreBuffer& other)` 是拷贝构造函数；已理解 `const Player& other` 中引用避免递归拷贝，`const` 保护来源对象；已理解自赋值检查对资源对象的重要性；已通过阶段复盘观察深拷贝和赋值时旧资源处理 | 后续在现代 C++ 阶段继续学习移动语义和智能指针 |
| 继承、多态、虚函数 | 基础掌握：已能写出 `Character` 基类和 `Warrior`、`Mage`、`Archer` 派生类；能观察派生类创建时先构造基类部分；能通过 `run_turn(const Character&)` 观察基类引用调用派生类 `act()` 的多态效果；已能区分重载 overload 和重写 override，理解 `virtual` 启用动态绑定、`override` 做编译期重写检查；已理解 `protected` 可被派生类访问，`private` 不能被派生类直接访问；已在阶段复盘中补充虚析构函数的资源安全意义 | 后续在项目练习中继续加固基类接口设计和派生类职责边界 |
| STL | 基础掌握：E1 `std::vector`、E2 `std::string` 常用操作、E3 `std::map` / `std::unordered_map`、E4 `std::set`、E5 迭代器、E6 常用算法已掌握；能使用 `begin()` / `end()` 表示范围，并用 `std::sort`、`std::find`、`std::count` 处理 `vector` 数据 | 后续结合 `auto`、范围 `for`、Lambda 和算法谓词继续加固；`vector` 后续还可结合迭代器失效和对象生命周期继续加固，`string` 后续还可结合边界检查、查找失败处理和文本处理继续加固，关联容器后续继续加固容器选择和迭代器使用 |
| `auto` 和范围 `for` | 基础掌握：知道 `auto` 是编译期类型推导，不是没有类型；知道范围 `for` 背后仍依赖容器的 `begin()` / `end()`；已能区分 `auto` 拷贝元素、`auto&` 绑定原元素并可修改、`const auto&` 只读且避免拷贝 | 后续结合 Lambda、标准算法谓词、智能指针容器和项目代码继续复盘 |
| `nullptr` | 基础掌握：知道 `nullptr` 是现代 C++ 专门表示空指针的值，不是整数 `0`；已能在指针参数解引用前做空指针检查；能观察 `choose_target(0)` 调用整数版本、`choose_target(nullptr)` 调用指针版本；知道 `delete` 释放堆对象，`ptr = nullptr` 修改指针变量本身以降低悬空指针误用风险；已理解必须有对象时用引用参数更能表达接口约束 | 后续结合智能指针、所有权和借用继续加固 |
| 智能指针 | 基础掌握：知道 `std::unique_ptr` 表达独占所有权，离开作用域时自动释放对象；知道 `unique_ptr` 不能复制，需要用 `std::move` 显式转移所有权；知道借用智能指针管理的对象时优先传 `Player&` 或 `const Player&`，不接管所有权；知道 `std::shared_ptr` 表达共享所有权，复制会增加引用计数，最后一个所有者销毁时对象释放 | 后续在 F4 移动语义中正式理解右值引用和 `std::move`，并在项目代码中继续练习所有权设计 |
| 移动语义 | 基础掌握：已能运行和观察拷贝构造、移动构造、拷贝赋值、移动赋值；知道移动后对象仍会正常析构且不应假设保留原数据；知道 `unique_ptr` 可移动不可复制；已能区分 `std::move` 本身不移动也不释放，真正转移资源的是移动构造/移动赋值；已能区分 RAII 自动释放和移动语义避免深拷贝 | 后续在 STL 容器、返回值、智能指针和项目代码中继续自然复盘 |
| Lambda | 基础掌握：已能把短小的局部规则写成 Lambda 并传给标准算法；能用 `std::sort` 的 Lambda 比较函数按 `hp` 从低到高排序；能用 `std::find_if`、`std::count_if`、`std::for_each` 配合 Lambda 表达查找、统计和遍历逻辑；已能区分值捕获和引用捕获，知道引用捕获需要注意被引用变量的生命周期；能区分 Lambda 参数按值、非 const 引用、const 引用的拷贝和修改语义 | 后续结合更多标准算法、对象生命周期和项目代码继续复盘 |
| `optional` 和 `variant` | 基础掌握：知道 `optional<T>` 表达可能有一个 `T`、也可能没有值；知道 `std::nullopt` 表示没有值，使用 `*maybe_value` 前应先检查；知道 `variant<A, B, C>` 表达一个值当前保存固定类型集合中的一种；能用 `holds_alternative<T>` 判断类型并用 `get<T>` 取值；已能新增 `LevelUpAction` 并处理升级动作 | 后续结合错误处理、函数返回值和项目命令解析继续复盘 |
| CMake | 未掌握 | 需要学习最小 CMake 项目、目录组织、构建流程 |

## 10. 当前项目目录状态

当前项目根目录：`/Users/assle/dev/cppProj/CppLearn`

已创建目录：`01_basic_syntax`、`02_pointer_reference_memory`、`03_function_scope_compile`、`04_oop`、`05_stl`、`06_modern_cpp`

正在使用目录：`06_modern_cpp`。F1 `auto` 和范围 `for`、F2 `nullptr`、F3 智能指针、F4 移动语义、F5 Lambda、F6 `optional` / `variant` 基础已完成，下一轮建议进入 `07_build_system` 阶段 G1：命令行编译 `g++` 常用参数。

当前建议：下一轮最小新增 `07_build_system/gpp_command_basic.cpp`，并创建或更新 `07_build_system/notes.md`、`07_build_system/exercise.md`，正式学习 G1 命令行编译 `g++` 常用参数。CMake、调试测试、并发和小项目仍不急着跳。

## 11. 下一步计划

1. 下一轮建议进入 `07_build_system` 阶段 G1：命令行编译 `g++` 常用参数。
2. 建议创建 `07_build_system/gpp_command_basic.cpp`、`07_build_system/notes.md`、`07_build_system/exercise.md`。
3. 学习 G1 时继续关联前面已学内容：单文件编译、`-std=c++17`、输出文件 `-o`、警告参数、调试信息参数和编译错误定位。

## 12. 最近一次更新

更新时间：2026-05-18 CST

本次更新来源：本轮对话完成并补强 `06_modern_cpp` 阶段 F5 Lambda 和 F6 `optional` / `variant` 基础。用户完成 `lambda_basic.cpp`、`optional_variant_basic.cpp` 和 `exercise.md` 中 F5-F6 练习，本地编译运行通过；关键概念已补清，F5、F6 已标记为已掌握。下一轮建议进入 `07_build_system` 阶段 G1 命令行编译 `g++` 常用参数。

本次新增内容：

- 用户完成 `06_modern_cpp/exercise.md` 中 F5 练习，包括 Lambda 比较函数、按 `hp` 从低到高排序、值捕获、引用捕获和工程判断题。
- 用户完成 `06_modern_cpp/exercise.md` 中 F6 练习，包括 `optional` 返回可能没有的下标、取值前检查、`variant` 保存固定动作类型之一、扩展 `LevelUpAction` 和工程判断题。
- 本地编译运行 `06_modern_cpp/lambda_basic.cpp` 通过。
- 本地编译运行 `06_modern_cpp/optional_variant_basic.cpp` 通过。
- 补强记录：已补清 `std::sort` 中 Lambda 的 `left` / `right` 是算法拿来比较的两个元素，不应固定理解成“前面/后面对象”；已补齐按 `hp` 从低到高排序的实际代码修改。
- 补强记录：已补清空 `optional` 强行取值属于未定义行为，不是悬空指针；已将 `LevelUpAction` 改为命中已有玩家 Alice，并观察 `level` 从 `3` 增加到 `23`。
- `06_modern_cpp` 阶段 F5 Lambda 和 F6 `optional` / `variant` 基础已完成；下一步建议进入 `07_build_system` 阶段 G1 命令行编译 `g++` 常用参数。
