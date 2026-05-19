#include <iostream>

class ScoreArray {
private:
    int* data;
    int size;

public:
    ScoreArray(int array_size) : data(new int[array_size]), size(array_size) {
        std::cout << "construct ScoreArray, data: " << data << std::endl;

        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    ScoreArray(const ScoreArray& other) = delete;
    ScoreArray& operator=(const ScoreArray& other) = delete;

    ~ScoreArray() {
        std::cout << "destruct ScoreArray, data: " << data << std::endl;
        delete[] data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            return;
        }

        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            return 0;
        }

        return data[index];
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

void manual_resource_example(bool early_return) {
    std::cout << "manual_resource_example begin" << std::endl;

    int* scores = new int[3];
    scores[0] = 10;
    scores[1] = 20;
    scores[2] = 30;

    if (early_return) {
        std::cout << "early return, manual delete is easy to forget" << std::endl;
        delete[] scores;
        return;
    }

    delete[] scores;
}

void raii_resource_example(bool early_return) {
    std::cout << "raii_resource_example begin" << std::endl;

    ScoreArray scores(3);
    scores.set(0, 10);
    scores.set(1, 20);
    scores.set(2, 30);
    scores.print();

    if (early_return) {
        std::cout << "early return, destructor still runs automatically"
                  << std::endl;
        return;
    }
}

void nested_scope_example() {
    std::cout << "enter nested scope" << std::endl;
    {
        ScoreArray scores(2);
        scores.set(0, 7);
        scores.set(1, 8);
        scores.print();
    }
    std::cout << "leave nested scope" << std::endl;
}

int main() {
    manual_resource_example(true);

    std::cout << std::endl;

    raii_resource_example(true);

    // ScoreArray a(3);
    // ScoreArray b = a;

    nested_scope_example();

    std::cout << std::endl;
    std::cout << "main end" << std::endl;

    return 0;
}

/*
练习1:
有执行
说明局部对象离开作用域会调用析构函数并且释放在构造函数中创建的资源

练习2:
构造函数在堆中创建了一个动态数组
析构函数delete[] arr,并且把arr = nullptr相当于释放了堆变量
这是针对于数组的释放改地址内存的方式

练习3：
因为在拷贝构造中设定了=delete说明了禁止拷贝构造，所以编译器执行的时候会检查，报错
可能会保存相同的变量，但是地址不同
这个不理解

练习4:
在ScoreArray scores(2);的时候构造，在离开内部作用域的时候析构
*/

/*
思考题：
1.核心思想是在构造函数中创建资源，在析构函数中释放资源
2.因为构造函数和析构函数在离开作用域的时候会自动调用，如果程序中途return，也会因为离开作用域而调用释放资源，从而避免了内存泄漏
3.构造函数负责创建申请资源，析构函数负责释放资源
4.这个不了解
5.这个我也不知道
*/
