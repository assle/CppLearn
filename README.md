# CppLearn

这是一个 C++ 工程学习仓库，用来系统学习 C++ 语言机制和工程开发能力。

当前重点不是刷算法题，而是逐步补齐 C++ 工程能力：语言基础、内存与生命周期、面向对象、STL、现代 C++、编译构建、调试测试和小型项目实践。

## 学习目标

- 掌握 C++ 基础语法、函数、作用域和多文件组织。
- 理解指针、引用、栈、堆、生命周期、所有权和 RAII。
- 掌握类、对象、构造析构、拷贝控制、继承、多态和虚函数。
- 熟悉 STL 容器、迭代器和常用算法。
- 学习现代 C++：`auto`、范围 `for`、`nullptr`、智能指针、移动语义、Lambda、`optional` 和 `variant`。
- 继续补齐工程能力：`g++`、CMake、目录组织、Debug、单元测试和 Git 工作流。

## 当前进度

当前已完成：

- `01_basic_syntax`：基础语法
- `02_pointer_reference_memory`：指针、引用、内存和生命周期
- `03_function_scope_compile`：函数、作用域、多文件编译和头文件机制
- `04_oop`：面向对象和 RAII
- `05_stl`：STL 基础
- `06_modern_cpp`：现代 C++ 基础

下一阶段：

- `07_build_system`：从 `g++` 常用参数、编译/链接流程和 CMake 开始补工程构建能力。

详细学习状态见：

- `Cpp_Learning_State.md`

历史完整学习记录归档见：

- `learning_state_archive/2026-05-19-Cpp_Learning_State_full.md`

## 目录结构

```text
.
├── 01_basic_syntax/
├── 02_pointer_reference_memory/
├── 03_function_scope_compile/
├── 04_oop/
├── 05_stl/
├── 06_modern_cpp/
├── learning_state_archive/
├── Cpp_Learning_State.md
└── README.md
```

## 编译示例

单个示例文件可以直接用 `g++` 编译：

```bash
g++ -std=c++17 06_modern_cpp/lambda_basic.cpp -o /tmp/lambda_basic
/tmp/lambda_basic
```

后续会继续补充更规范的 CMake 构建方式。

## 学习方式

每个知识点尽量遵循：

1. 先解释为什么需要这个机制。
2. 再给出最小可运行代码。
3. 编译运行观察结果。
4. 总结工程原因，例如编译、链接、内存、作用域、生命周期和接口设计。
5. 更新学习状态文件，记录当前进度、薄弱点和下一步计划。

## 后续计划

- 学习 `g++` 常用参数：`-std=c++17`、`-Wall`、`-Wextra`、`-g`、`-o`。
- 学习 CMake 最小项目。
- 学习 `include/`、`src/`、`tests/` 工程目录组织。
- 学习断点调试、变量观察和调用栈。
- 学习单元测试基础。
- 新建独立项目 `MiniLogSearch`，用项目驱动训练 C++ 企业级开发能力。
