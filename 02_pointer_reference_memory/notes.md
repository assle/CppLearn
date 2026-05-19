# C1: 地址、指针、解引用

## 为什么需要指针

普通变量名可以直接访问一个值，例如 `score` 表示分数。

但是在 C++ 工程里，我们经常不仅要关心“值是多少”，还要关心“这个值放在内存哪里”。原因包括：

- 函数有时需要修改调用方传进来的变量。
- 程序有时需要操作一段动态申请的内存。
- 对象和资源需要明确生命周期，避免用到已经失效的内存。
- 工程中很多底层接口会通过地址传递数据，避免复制大对象。

所以 C++ 提供了指针。指针变量保存的不是普通数值本身，而是另一个变量的地址。

## 地址

可以把内存粗略想成很多连续的小格子，每个格子都有编号。变量的值存在某个位置，这个位置编号就是地址。

```cpp
int score = 80;
std::cout << &score << std::endl;
```

`&score` 表示取变量 `score` 的地址。

注意：每次运行程序时，打印出来的地址可能不同，这是正常的。操作系统会为程序安排内存位置。

## 指针变量

```cpp
int* score_ptr = &score;
```

这行代码可以拆开理解：

- `int*`：这是一个指针类型，表示它保存的是 `int` 变量的地址。
- `score_ptr`：指针变量名。
- `&score`：取 `score` 的地址。

所以 `score_ptr` 保存的是 `score` 的地址。

## 解引用

```cpp
std::cout << *score_ptr << std::endl;
```

这里的 `*score_ptr` 表示：根据 `score_ptr` 保存的地址，找到那个地址上的 `int` 值。

这叫解引用。

如果 `score_ptr` 指向 `score`，那么：

```cpp
*score_ptr = 95;
```

等价于通过地址修改 `score`，所以 `score` 的值会变成 `95`。

## `*` 在不同位置的含义

```cpp
int* p = &score;
```

这里的 `*` 是类型声明的一部分，表示 `p` 是指针。

```cpp
*p = 95;
```

这里的 `*` 是解引用，表示访问 `p` 指向的变量。

同一个符号在不同语境下含义不同，这是 C++ 里很常见的现象。

## 本轮最小编译命令

```bash
g++ 02_pointer_reference_memory/pointer_basic.cpp -o /private/tmp/cpplearn_pointer_basic
/private/tmp/cpplearn_pointer_basic
```

## 本轮要掌握的判断标准

学完后应能回答：

- `&score` 是什么意思？
- `int* p` 是什么意思？
- `p` 和 `*p` 的区别是什么？
- 为什么通过 `*p = 95` 可以修改原变量？
- 为什么每次运行打印出来的地址可能不同？

# C2: 引用和指针的区别

## 为什么需要引用

指针能表达“我保存了某个变量的地址”，但它也带来一些负担：

- 使用时经常要写 `*p` 解引用。
- 指针变量可以改为指向别处。
- 指针后面还会出现空指针、野指针、悬空指针等风险。

有些场景里，我们只是想给一个已有变量起一个别名，或者让函数直接修改调用方传入的变量，不需要“改指向”这个能力。

这时引用更合适。

## 引用是已有变量的别名

```cpp
int score = 80;
int& score_ref = score;
```

`score_ref` 是 `score` 的引用。可以先粗略理解为：`score_ref` 是 `score` 的另一个名字。

所以：

```cpp
score_ref = 95;
```

会修改 `score` 本身。

## 指针和引用的最小对比

```cpp
int score = 80;

int* score_ptr = &score;
int& score_ref = score;
```

指针：

```cpp
*score_ptr = 90;
```

需要通过 `*score_ptr` 解引用后修改原变量。

引用：

```cpp
score_ref = 95;
```

引用本身像普通变量名一样使用，修改的是它绑定的原变量。

## 引用绑定后不能改绑

指针变量可以改为保存另一个变量的地址：

```cpp
int another_score = 60;
score_ptr = &another_score;
```

这表示 `score_ptr` 现在指向 `another_score`。

但引用绑定后不能改绑：

```cpp
score_ref = another_score;
```

这不是让 `score_ref` 改为引用 `another_score`。

它表示：把 `another_score` 的值赋给 `score_ref` 当前绑定的变量，也就是赋给 `score`。

## 工程上的直觉

指针更像“可保存地址的变量”，适合表达：

- 可能没有指向任何对象。
- 需要改为指向另一个对象。
- 需要和底层内存、数组、动态内存打交道。

引用更像“已有对象的别名”，适合表达：

- 这个参数必须绑定到一个真实对象。
- 不希望调用方传空。
- 不需要在函数内部改为指向另一个对象。

后面学习函数参数时会继续用到这个区别。

## C2 最小编译命令

```bash
g++ 02_pointer_reference_memory/reference_basic.cpp -o /private/tmp/cpplearn_reference_basic
/private/tmp/cpplearn_reference_basic
```

## C2 要掌握的判断标准

学完后应能回答：

- `int& ref = value;` 是什么意思？
- 为什么修改 `ref` 会修改 `value`？
- 指针变量能不能改指向？
- 引用绑定后能不能改绑？
- `ref = other;` 是改绑，还是赋值？

# C3: 指针参数、引用参数

## 为什么函数参数需要指针和引用

普通函数参数默认是值传递：

```cpp
void add_by_value(int value) {
    value = value + 10;
}
```

调用：

```cpp
int score = 80;
add_by_value(score);
```

这里函数里的 `value` 是 `score` 的一份拷贝。函数修改的是拷贝，不会修改 `main` 里的 `score`。

但是工程里经常需要函数修改调用方的变量，例如：

- 读取输入并写入一个变量。
- 修改对象状态。
- 返回多个结果。
- 对已有数据做原地更新，避免创建不必要的副本。

这时可以用指针参数或引用参数。

## 指针参数

```cpp
void add_by_pointer(int* value_ptr) {
    *value_ptr = *value_ptr + 10;
}
```

调用时传地址：

```cpp
add_by_pointer(&score);
```

运行过程可以分三步理解：

1. `&score` 取出 `score` 的地址。
2. `value_ptr` 保存这个地址。
3. `*value_ptr = ...` 沿着地址找到 `score` 并修改它。

所以指针参数可以修改调用方变量。

## 引用参数

```cpp
void add_by_reference(int& value_ref) {
    value_ref = value_ref + 10;
}
```

调用时直接传变量：

```cpp
add_by_reference(score);
```

`value_ref` 是 `score` 的引用，也就是 `score` 的别名。函数里修改 `value_ref`，实际就是修改 `score`。

## 三种参数的直觉对比

值参数：

```cpp
void f(int value);
```

函数拿到一份拷贝。适合只读小数据，函数内修改不会影响调用方。

指针参数：

```cpp
void f(int* value_ptr);
```

函数拿到地址。调用方需要写 `&score`，函数里需要写 `*value_ptr`。这能明确表达“函数可能通过地址修改原变量”。

引用参数：

```cpp
void f(int& value_ref);
```

函数拿到原变量的别名。调用方写起来像普通变量，函数里也像普通变量。它适合表达“必须传入一个真实变量，并允许函数修改它”。

## 工程提醒

引用参数虽然写起来方便，但调用处不如指针参数明显：

```cpp
add_by_reference(score);
```

从调用处看不出 `score` 会不会被修改，必须看函数声明：

```cpp
void add_by_reference(int& value_ref);
```

所以工程里要养成习惯：看到非 `const` 引用参数，就要意识到函数可能修改调用方变量。

后面会学 `const int&`，它常用于避免复制大对象，同时承诺不修改原对象。

## C3 最小编译命令

```bash
g++ 02_pointer_reference_memory/function_parameter_basic.cpp -o /private/tmp/cpplearn_function_parameter_basic
/private/tmp/cpplearn_function_parameter_basic
```

## C3 要掌握的判断标准

学完后应能回答：

- 为什么 `add_by_value(score)` 不能修改 `main` 里的 `score`？
- `add_by_pointer(&score)` 为什么能修改 `score`？
- `add_by_reference(score)` 为什么能修改 `score`？
- 指针参数调用时为什么要写 `&score`？
- 看到 `int&` 参数时，工程上应该警惕什么？

# C4: 栈、堆、生命周期

## 为什么要学生命周期

前面已经知道指针可以保存地址，引用可以作为变量别名。

但工程里真正危险的问题是：这个地址或别名对应的变量还活着吗？

如果变量已经销毁，还继续通过指针或引用访问它，就会产生严重错误。很多 C++ 内存问题都来自这里。

所以这一节要理解三个问题：

- 变量什么时候创建？
- 变量什么时候销毁？
- 指针或引用能不能继续访问它？

## 栈上的局部变量

函数里的普通局部变量通常具有自动生命周期。可以先粗略理解为：进入作用域时创建，离开作用域时销毁。

```cpp
void print_stack_variable() {
    int local_score = 80;
    std::cout << local_score << std::endl;
}
```

`local_score` 在函数调用时创建，函数结束时销毁。

所以函数外不能直接访问 `local_score`。这和你之前学过的作用域有关，但生命周期更进一步：不只是名字不可见，变量本身也已经结束了。

## 返回值是安全的

```cpp
int create_score_by_value() {
    int local_score = 90;
    return local_score;
}
```

这段代码是安全的。

原因是返回的是 `local_score` 的值。函数返回时，值会被带回调用方，调用方得到自己的变量：

```cpp
int returned_score = create_score_by_value();
```

`returned_score` 是 `main` 里的新变量，不是已经销毁的 `local_score`。

## 不要返回局部变量的地址

下面这种思路是危险的：

```cpp
int* bad_create_score() {
    int local_score = 90;
    return &local_score;
}
```

`local_score` 函数结束时销毁。返回它的地址，就相当于把一个已经失效的位置交给调用方。

这种指针叫悬空指针。后面 C6 会专门学习。

本轮示例文件里不写这段可运行代码，因为它属于未定义行为：程序可能看起来能跑，也可能输出奇怪结果，也可能崩溃。

## 堆上的对象

栈上的局部变量会随作用域自动结束。堆上的对象则可以活得更久，但需要程序员管理。

```cpp
int* heap_score = new int(100);
```

这会在堆上创建一个 `int`，并返回它的地址。

只要还没有：

```cpp
delete heap_score;
```

这个堆对象就还存在。

本节只先理解：堆对象不会因为创建它的函数结束而自动销毁。`new/delete` 的细节会在 C5 单独学。

## 释放后不要继续使用

```cpp
delete heap_score;
heap_score = nullptr;
```

`delete` 之后，堆对象已经销毁。原来的地址不能继续解引用。

把指针设为 `nullptr` 是一个好习惯，它表示“这个指针当前不指向有效对象”。

## 工程上的直觉

栈：

- 自动创建和销毁。
- 生命周期通常跟作用域绑定。
- 局部变量离开函数后就不能再访问。

堆：

- 可以让对象活过创建它的函数。
- 需要明确释放。
- 忘记释放会泄漏，释放后继续使用会出错。

后面学习 RAII 和智能指针，就是为了让堆资源也能像栈变量一样自动、安全地管理生命周期。

## C4 最小编译命令

```bash
g++ 02_pointer_reference_memory/lifetime_basic.cpp -o /private/tmp/cpplearn_lifetime_basic
/private/tmp/cpplearn_lifetime_basic
```

## C4 要掌握的判断标准

学完后应能回答：

- 局部变量什么时候创建，什么时候销毁？
- 为什么返回局部变量的值通常是安全的？
- 为什么返回局部变量的地址是危险的？
- 堆对象和栈上局部变量的生命周期有什么不同？
- `delete` 后为什么不能继续解引用原指针？

# C5: `new/delete` 基础

## 为什么需要 `new/delete`

普通局部变量会随着作用域自动创建和销毁：

```cpp
int score = 80;
```

但有些对象需要在函数结束后继续存在，或者大小、数量要到运行时才决定。这时可以在堆上动态创建对象：

```cpp
int* score_ptr = new int(80);
```

`new` 做两件事：

1. 在堆上申请足够的内存。
2. 在这块内存里创建一个对象，并返回对象地址。

返回值是地址，所以要用指针保存：

```cpp
int* score_ptr = new int(80);
```

## 使用堆对象

`score_ptr` 保存地址，`*score_ptr` 访问堆上的值：

```cpp
std::cout << *score_ptr << std::endl;
*score_ptr = 95;
```

这和之前学过的指针、解引用完全接上了。

## 用完必须 `delete`

堆对象不会自动随函数结束销毁，所以用完后要手动释放：

```cpp
delete score_ptr;
score_ptr = nullptr;
```

`delete score_ptr;` 表示销毁 `score_ptr` 指向的堆对象，并把那块内存交还给内存管理器。

`score_ptr = nullptr;` 表示这个指针现在不指向有效对象，防止误用旧地址。

## `new` 和 `delete` 要配对

单个对象：

```cpp
int* p = new int(80);
delete p;
```

数组对象：

```cpp
int* numbers = new int[3];
delete[] numbers;
```

规则：

- `new` 配 `delete`
- `new[]` 配 `delete[]`

不要混用。

## `delete nullptr` 是安全的

```cpp
int* p = nullptr;
delete p;
```

这是安全的，什么也不会发生。

所以释放后把指针设为 `nullptr`，可以降低误删旧地址的风险。

## 不要重复释放同一个堆对象

危险代码：

```cpp
int* p = new int(80);
delete p;
delete p;
```

第二次 `delete p` 是错误的，因为第一次已经释放了堆对象。此时 `p` 仍可能保存旧地址，但旧地址已经不是有效对象。

这类问题叫重复释放。后面 C6 会继续归入常见内存错误。

## 不要忘记释放

危险代码：

```cpp
int* p = new int(80);
// 忘记 delete p;
```

如果程序一直丢失这个地址，又没有释放堆对象，这块内存就无法再被程序正常管理，叫内存泄漏。

## 工程上的直觉

手写 `new/delete` 很容易犯错：

- 忘记 `delete`：内存泄漏。
- `delete` 后继续用：访问失效对象。
- 重复 `delete`：重复释放。
- `new[]` 和 `delete` 混用：释放方式不匹配。

现代 C++ 工程中会尽量用 RAII、标准容器和智能指针减少手写 `new/delete`。但在学习阶段必须先理解它们，因为智能指针和 RAII 的目的就是替你管理这些释放规则。

## C5 最小编译命令

```bash
g++ 02_pointer_reference_memory/new_delete_basic.cpp -o /private/tmp/cpplearn_new_delete_basic
/private/tmp/cpplearn_new_delete_basic
```

## C5 要掌握的判断标准

学完后应能回答：

- `new int(80)` 做了什么？
- 为什么 `new` 返回的结果要用指针保存？
- `delete p;` 做了什么？
- 为什么释放后建议写 `p = nullptr;`？
- `new` / `delete` 和 `new[]` / `delete[]` 为什么不能混用？

# C6: 野指针、悬空引用、内存泄漏

## 为什么要学常见内存错误

到这里，你已经学过：

- 指针保存地址。
- 解引用会访问地址上的对象。
- 栈上局部变量会随作用域结束而销毁。
- 堆对象需要 `delete`。

C++ 内存错误通常不是因为某个语法神秘，而是因为程序继续使用了“不再有效的地址”，或者忘记释放“还在堆上的对象”。

这节要把三类错误分清楚：

- 野指针：指针没有被初始化，却拿来用。
- 悬空指针/悬空引用：曾经指向有效对象，但对象已经销毁。
- 内存泄漏：堆对象还存在，但程序已经失去释放它的机会。

## 野指针

危险代码：

```cpp
int* p;
*p = 10;
```

`p` 没有初始化，里面的地址不可靠。你不知道它指向哪里。解引用它就是未定义行为。

更安全的习惯：

```cpp
int* p = nullptr;
```

`nullptr` 表示这个指针当前不指向有效对象。

## 释放后的悬空指针

危险代码：

```cpp
int* p = new int(80);
delete p;
*p = 90;
```

`delete p` 后，堆对象已经销毁。`p` 可能仍保存旧地址，但旧地址不再代表有效对象。

更安全的习惯：

```cpp
delete p;
p = nullptr;
```

## 返回局部变量地址造成悬空指针

危险代码：

```cpp
int* bad_create_score() {
    int local_score = 80;
    return &local_score;
}
```

`local_score` 是栈上局部变量，函数结束后销毁。返回它的地址，会让调用方拿到已经失效的位置。

## 悬空引用

引用也有生命周期风险。危险思路：

```cpp
int& bad_ref() {
    int local_score = 80;
    return local_score;
}
```

函数返回后，`local_score` 已经销毁，返回的引用就绑定到一个已经不存在的对象。

引用语法看起来不像指针，但它同样不能引用已经销毁的对象。

## 内存泄漏

危险代码：

```cpp
int* p = new int(80);
p = new int(90);
```

第一次 `new int(80)` 创建的堆对象还没有 `delete`，但它的地址被覆盖丢失了。程序再也找不到它，也就无法释放它。

这就是内存泄漏。

另一个常见形式：

```cpp
void f() {
    int* p = new int(80);
}
```

函数结束时，指针变量 `p` 被销毁，但 `p` 指向的堆对象没有自动销毁，也没有被 `delete`。

## 工程上的检查顺序

看到指针或引用时，先问：

1. 它初始化了吗？
2. 它指向或引用的对象还活着吗？
3. 如果是 `new` 出来的对象，谁负责 `delete`？
4. `delete` 以后有没有继续使用旧指针？
5. 有没有可能丢失堆对象地址，导致无法释放？

现代 C++ 会用 RAII、容器和智能指针降低这些风险，但理解这些错误是后面学习 RAII 的前提。

## C6 最小编译命令

```bash
g++ 02_pointer_reference_memory/memory_error_basic.cpp -o /private/tmp/cpplearn_memory_error_basic
/private/tmp/cpplearn_memory_error_basic
```

## C6 要掌握的判断标准

学完后应能回答：

- 什么是野指针？
- 什么是悬空指针？
- 为什么引用也可能悬空？
- 什么是内存泄漏？
- 为什么释放后把指针设为 `nullptr` 能降低误用风险？
