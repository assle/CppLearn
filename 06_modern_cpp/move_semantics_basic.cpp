#include <iostream>
#include <string>
#include <utility>
#include <vector>

class ScoreBuffer {
public:
    ScoreBuffer(std::string owner, int size)
        : owner_(owner), size_(size), data_(new int[size]) {
        for (int i = 0; i < size_; ++i) {
            data_[i] = 0;
        }

        std::cout << "construct: " << owner_ << std::endl;
    }

    ~ScoreBuffer() {
        std::cout << "destroy: " << owner_ << std::endl;
        delete[] data_;
    }

    ScoreBuffer(const ScoreBuffer& other)
        : owner_(other.owner_ + "_copy"),
          size_(other.size_),
          data_(new int[other.size_]) {
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }

        std::cout << "copy construct: " << owner_ << std::endl;
    }

    ScoreBuffer& operator=(const ScoreBuffer& other) {
        if (this == &other) {
            return *this;
        }

        int* new_data = new int[other.size_];
        for (int i = 0; i < other.size_; ++i) {
            new_data[i] = other.data_[i];
        }

        delete[] data_;
        owner_ = other.owner_ + "_copy_assigned";
        size_ = other.size_;
        data_ = new_data;

        std::cout << "copy assign: " << owner_ << std::endl;
        return *this;
    }

    ScoreBuffer(ScoreBuffer&& other) noexcept
        : owner_(other.owner_ + "_moved"),
          size_(other.size_),
          data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
        other.owner_ = "moved_from";

        std::cout << "move construct: " << owner_ << std::endl;
    }

    ScoreBuffer& operator=(ScoreBuffer&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] data_;

        owner_ = other.owner_ + "_move_assigned";
        size_ = other.size_;
        data_ = other.data_;

        other.size_ = 0;
        other.data_ = nullptr;
        other.owner_ = "moved_from";

        std::cout << "move assign: " << owner_ << std::endl;
        return *this;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size_) {
            return;
        }

        data_[index] = value;
    }

    void print() const {
        std::cout << owner_ << " size: " << size_ << " values:";
        for (int i = 0; i < size_; ++i) {
            std::cout << " " << data_[i];
        }
        std::cout << std::endl;
    }

private:
    std::string owner_;
    int size_;
    int* data_;
};

ScoreBuffer create_buffer() {
    ScoreBuffer buffer("factory", 3);
    buffer.set(0, 10);
    buffer.set(1, 20);
    buffer.set(2, 30);
    return buffer;
}

int main() {
    std::cout << "copy demo" << std::endl;
    ScoreBuffer first("first", 3);
    first.set(0, 1);
    first.set(1, 2);
    first.set(2, 3);
    first.print();

    ScoreBuffer copied = first;
    copied.print();
    first.print();

    std::cout << "move demo" << std::endl;
    ScoreBuffer moved = std::move(first);
    moved.print();
    first.print();

    std::cout << "move assignment demo" << std::endl;
    ScoreBuffer assigned("assigned", 2);
    assigned = std::move(copied);
    assigned.print();
    copied.print();

    std::cout << "return value demo" << std::endl;
    ScoreBuffer from_factory = create_buffer();
    from_factory.print();

    std::cout << "vector demo" << std::endl;
    std::vector<ScoreBuffer> buffers;
    buffers.push_back(create_buffer());
    buffers.emplace_back("emplaced", 2);

    ScoreBuffer copy_assigned("copy_assigned", 1);
    copy_assigned = from_factory;
    copy_assigned.print();
    from_factory.print();

    std::cout << "end of main" << std::endl;
    return 0;
}

/*
练习答案写在这里：
练习1:
1.调用了拷贝构造
2.调用了移动构造
3.调用了移动赋值
练习2:
1.不会自己移动内存
2.不会自己释放 first，first 仍然是一个合法对象，之后会正常析构
3.真正转移资源的是移动构造函数或移动赋值运算符
练习3:
1.还会正常析构
2.不能假设还保有数据
3.因为资源指针已经交给新对象，如果源对象还保留旧指针，两个对象析构时会重复释放同一块堆内存
练习4:
1.调用的是拷贝赋值
2.copy_assigned = std::move(from_factory);
补充：copy_assigned = from_factory 不能偷走 from_factory 的资源，因为 from_factory 是普通左值，后续还可能继续使用
练习5:
1.拷贝适合需要保留源对象内容，并且新对象需要一份独立内容的场景；资源对象也可以深拷贝，只是成本可能较高
2.移动适合源对象不再需要原内容，可以把资源所有权转交给新对象的场景
3.因为移动语义可以避免昂贵的深拷贝，同时保持资源只有一个明确所有者；自动释放资源主要来自 RAII
4.因为 unique_ptr 表达独占所有权，复制会造成两个 unique_ptr 以为自己都拥有同一资源；移动可以把所有权从源指针转移给目标指针，并让源指针变空
*/
