# C1 练习：地址、指针、解引用

请基于 `pointer_basic.cpp` 完成以下练习。

## 练习 1：打印新变量的值和地址

新增一个变量：

```cpp
int level = 3;
```

打印：

- `level` 的值；
- `level` 的地址。

## 练习 2：创建指向 `level` 的指针

新增：

```cpp
int* level_ptr = &level;
```

打印：

- `level_ptr` 保存的地址；
- `*level_ptr` 访问到的值。

## 练习 3：通过指针修改变量

写出：

```cpp
*level_ptr = 10;
```

然后打印 `level`，观察它是否变成 `10`。

## 练习 4：让同一个指针改指向另一个变量

新增一个变量：

```cpp
int backup_level = 1;
```

让 `level_ptr` 改为指向 `backup_level`，然后打印 `*level_ptr`。

## 练习 5：思考题

用自己的话回答：

1. 指针变量里保存的是什么？
2. `p` 和 `*p` 有什么区别？
3. 如果 `p` 指向 `level`，为什么 `*p = 10` 会修改 `level`？
4. 指针变量本身能不能改为指向另一个变量？

### 我的回答

1. 指针变量保存地址。
2. `p` 表示一个地址，`*p` 表示取这个地址对应变量的值。
3. 因为 `p` 是一个指针，指向 `level`，所以修改 `*p` 相当于修改这个地址上的值，也就是修改 `level`。
4. 指针变量本身能改为指向另一个变量。

# C2 练习：引用和指针的区别

请基于 `reference_basic.cpp` 完成以下练习。

## 练习 1：新增一个变量和引用

新增：

```cpp
int level = 3;
int& level_ref = level;
```

打印：

- `level` 的值；
- `level_ref` 的值；
- `&level`；
- `&level_ref`。

观察 `level` 和 `level_ref` 的地址是否相同。

## 练习 2：通过引用修改原变量

写出：

```cpp
level_ref = 10;
```

然后打印 `level`，观察它是否变成 `10`。

## 练习 3：对比指针改指向和引用赋值

新增：

```cpp
int backup_level = 1;
int* level_ptr = &level;
```

然后写：

```cpp
level_ptr = &backup_level;
level_ref = backup_level;
```

分别打印：

- `*level_ptr`
- `level`
- `backup_level`

观察：`level_ptr = &backup_level` 和 `level_ref = backup_level` 的含义是否一样。

## 练习 4：思考题

用自己的话回答：

1. 引用变量保存的是地址，还是更像一个已有变量的别名？
2. 修改引用为什么会修改原变量？
3. 指针变量能不能改为指向另一个变量？
4. 引用绑定后能不能改为引用另一个变量？
5. `level_ref = backup_level` 是让引用改绑，还是把值赋给原变量？

### 我的回答

1. 引用更像一个已有变量的别名。
2. 因为引用相当于原有变量的别名，所以修改引用的值会改变原有变量的值。
3. 指针变量可以改为指向另一个变量。
4. 引用绑定以后不能改为引用另一个变量，只能修改当前绑定变量的值。
5. `level_ref = backup_level` 是把值赋给原变量，而不是改变引用的绑定关系。

# C3 练习：指针参数、引用参数

请基于 `function_parameter_basic.cpp` 完成以下练习。

## 练习 1：新增三个函数

新增三个函数：

```cpp
void reset_by_value(int value);
void reset_by_pointer(int* value_ptr);
void reset_by_reference(int& value_ref);
```

分别把参数改成 `0`。

## 练习 2：在 `main` 中观察三种调用

新增：

```cpp
int level = 5;
```

分别调用：

```cpp
reset_by_value(level);
reset_by_pointer(&level);
reset_by_reference(level);
```

每次调用前后都打印 `level`，观察哪一种会修改 `main` 里的 `level`。

提示：为了观察清楚，每次测试前可以重新给 `level` 赋值为 `5`。

## 练习 3：新增一个交换函数

写一个函数：

```cpp
void swap_by_reference(int& left, int& right);
```

让它交换两个变量的值。

在 `main` 中测试：

```cpp
int a = 10;
int b = 20;
swap_by_reference(a, b);
```

打印交换后的 `a` 和 `b`。

## 练习 4：思考题

用自己的话回答：

1. 为什么普通值参数修改不了调用方变量？
2. 为什么指针参数可以修改调用方变量？
3. 为什么引用参数可以修改调用方变量？
4. 指针参数调用时为什么要写 `&level`？
5. 看到函数参数是 `int& value` 时，应该意识到什么？

### 我的回答

1. 因为普通值参数修改的相当于传入参数的副本。
2. 因为指针参数修改的是同一个地址上的值。
3. 因为引用相当于传入参数的别名，而不是副本。
4. 因为 `&level` 代表取 `level` 的地址，把这个地址传给指针参数。
5. 应该意识到函数里修改的其实是调用方传入的同一个变量。

# C4 练习：栈、堆、生命周期

请基于 `lifetime_basic.cpp` 完成以下练习。

## 练习 1：新增一个栈上局部变量

在 `main` 中新增：

```cpp
int level = 5;
```

打印：

- `level` 的值；
- `level` 的地址。

观察它和函数里的 `local_score` 地址是否不同。

## 练习 2：新增一个返回值函数

新增函数：

```cpp
int create_level_by_value() {
    int local_level = 6;
    return local_level;
}
```

在 `main` 中调用：

```cpp
int returned_level = create_level_by_value();
```

打印 `returned_level` 的值和地址。

## 练习 3：新增一个堆对象函数

新增函数：

```cpp
int* create_level_on_heap() {
    int* heap_level = new int(7);
    return heap_level;
}
```

在 `main` 中调用并打印：

- 指针保存的地址；
- `*指针` 访问到的值。

最后记得：

```cpp
delete 指针;
指针 = nullptr;
```

## 练习 4：只写注释，不运行危险代码

在文件末尾写一段注释，解释为什么下面的代码危险：

```cpp
int* bad_create_level() {
    int local_level = 6;
    return &local_level;
}
```

不要把这个函数写成可运行代码。

## 练习 5：思考题

用自己的话回答：

1. 栈上的局部变量什么时候创建，什么时候销毁？
2. 为什么 `return local_score;` 返回值是安全的？
3. 为什么 `return &local_score;` 返回地址是危险的？
4. 堆对象为什么可以在创建它的函数结束后继续存在？
5. `delete` 后为什么不能继续使用 `*指针`？

### 我的回答

1. 栈上的局部变量在定义时创建，函数结束以后销毁。
2. 因为返回的是局部变量的值，局部变量在函数结束时已经销毁，但外部只是用一个新的变量接收了这个值，不会通过这个新变量访问局部变量的地址。
3. 因为返回的是局部变量的地址，函数结束以后局部变量已经销毁，外部拿到这个地址再操作就会访问已经失效的内存，可能导致程序崩溃或者产生不可预期的行为。
4. 堆对象创建以后不会随着函数的结束而销毁，需要通过 `delete` 进行销毁。
5. `delete ptr` 的意思是释放这个地址上的堆对象，并把这块内存交给内存管理器管理；但是指针变量本身通常依然保存那个被释放的旧地址，继续 `*指针` 可能访问到已经失效或已被复用的内存。

### 教练补充

4. 堆对象由 `new` 创建，它的生命周期不跟创建它的函数作用域绑定，而是一直持续到程序执行 `delete`。所以函数结束后，只要调用方还保存着这个堆对象的地址，并且还没有 `delete`，就仍然可以访问它。
5. `delete` 会销毁堆对象并把那块内存交还给内存管理器。此后原指针保存的地址不再代表一个有效对象，继续 `*指针` 就是在访问已经失效的对象，属于未定义行为。把指针设为 `nullptr` 是为了避免误用旧地址。

# C5 练习：`new/delete` 基础

请基于 `new_delete_basic.cpp` 完成以下练习。

## 练习 1：新增一个堆上 `level`

在 `main` 中新增：

```cpp
int* level_ptr = new int(5);
```

打印：

- `level_ptr` 保存的地址；
- `*level_ptr` 的值。

然后把它改成 `8` 并打印。

最后：

```cpp
delete level_ptr;
level_ptr = nullptr;
```

## 练习 2：新增一个创建函数

新增函数：

```cpp
int* create_level(int value) {
    int* level_ptr = new int(value);
    return level_ptr;
}
```

在 `main` 中调用它，打印地址和值，然后释放。

## 练习 3：新增一个动态数组

新增：

```cpp
int* levels = new int[4];
```

给 `levels[0]` 到 `levels[3]` 赋值并打印。

最后使用：

```cpp
delete[] levels;
levels = nullptr;
```

## 练习 4：只写注释，不运行危险代码

在文件末尾用注释解释下面几种代码为什么危险：

```cpp
int* p = new int(80);
delete p;
delete p;
```

```cpp
int* p = new int(80);
// 忘记 delete p;
```

```cpp
int* arr = new int[3];
delete arr;
```

不要把这些危险代码写成可运行代码。

## 练习 5：思考题

用自己的话回答：

1. `new int(80)` 做了什么？
2. 为什么 `new` 返回的结果要用指针保存？
3. `delete p;` 做了什么？
4. 为什么 `delete` 后建议写 `p = nullptr;`？
5. `new[]` 创建的数组为什么要用 `delete[]` 释放？

### 我的回答

1. `new int(80)` 在堆内存中创建了 `int` 类型的变量，变量值为 `80`。
2. `new` 创建的变量存储在堆内存中，用户要选择在合适的时候释放这块内存。如果不用指针保存返回地址，就无法释放这块内存，会造成内存泄漏。
3. `delete p;` 释放了 `p` 指向地址上的堆对象，并把这块内存交还给内存管理器。
4. `delete` 后建议写 `p = nullptr;`，表示这个指针不再指向有效对象，避免继续访问已经释放的内存。
5. `new[]` 创建的是动态数组，需要用对应的 `delete[]` 释放；如果用 `delete`，释放方式不匹配，会导致未定义行为。

### 危险代码解释

```cpp
int* p = new int(80);
delete p;
delete p;
```

第一次 `delete` 已经释放了堆对象，第二次重复释放同一个旧地址会导致未定义行为。

```cpp
int* p = new int(80);
// 忘记 delete p;
```

如果丢失地址或一直不释放，会导致堆内存无法回收，造成内存泄漏。

```cpp
int* arr = new int[3];
delete arr;
```

`new[]` 创建的是动态数组，应该使用 `delete[] arr;`。用 `delete arr;` 是释放方式不匹配，会导致未定义行为。

# C6 练习：野指针、悬空引用、内存泄漏

请基于 `memory_error_basic.cpp` 完成以下练习。

## 练习 1：新增一个安全释放函数调用

在 `main` 中新增：

```cpp
int* level_ptr = create_heap_score(60);
```

打印地址和值，然后调用：

```cpp
safe_delete(level_ptr);
```

再用 `if (level_ptr == nullptr)` 打印一条信息，确认它已经置空。

## 练习 2：只写注释，不运行野指针代码

在文件末尾用注释解释下面代码为什么危险：

```cpp
int* p;
*p = 10;
```

不要把这段代码写成可运行代码。

## 练习 3：只写注释，不运行悬空指针代码

用注释解释下面代码为什么危险：

```cpp
int* p = new int(80);
delete p;
*p = 90;
```

不要把这段代码写成可运行代码。

## 练习 4：只写注释，不运行内存泄漏代码

用注释解释下面代码为什么会泄漏：

```cpp
int* p = new int(80);
p = new int(90);
```

不要把这段代码写成可运行代码。

## 练习 5：思考题

用自己的话回答：

1. 什么是野指针？
2. 什么是悬空指针？
3. 为什么引用也可能悬空？
4. 什么是内存泄漏？
5. 为什么释放后把指针设为 `nullptr` 能降低误用风险？

### 我的回答

1. 野指针是指针没有初始化就使用。
2. 悬空指针是指针指向的对象已经被销毁，但指针没有指向 `nullptr`，还保存着旧地址。
3. 因为引用绑定的对象也可能被销毁，所以引用也可能悬空。
4. 内存泄漏就是申请的堆内存没有被正确管理和销毁，导致占用的堆内存越来越多。
5. 释放后把指针设为 `nullptr`，后续如果误用，代码可以通过空指针判断发现它已经不指向有效对象，降低继续使用旧地址的风险。

### 教练补充

1. 野指针的危害是：它可能访问或修改不属于当前程序逻辑的内存，导致程序崩溃、数据损坏，或者看起来正常但行为不确定。
5. `nullptr` 本身不是自动防护罩，但它让状态更明确。工程里可以先判断 `if (p != nullptr)` 再解引用，从而避免误用已经释放的旧地址。
