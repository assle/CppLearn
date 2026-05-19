#include <iostream>

class BrokenArray {
private:
    int* data;
    int size;
    bool owner;

public:
    BrokenArray(int array_size)
        : data(new int[array_size]), size(array_size), owner(true) {
        std::cout << "construct BrokenArray, data: " << data << std::endl;
    }

    BrokenArray(const BrokenArray& other)
        : data(other.data), size(other.size), owner(false) {
        std::cout << "shallow copy BrokenArray, copied data address: " << data
                  << std::endl;
    }

    ~BrokenArray() {
        std::cout << "destruct BrokenArray, data: " << data
                  << ", owner: " << owner << std::endl;

        if (owner) {
            delete[] data;
        }
    }

    void print_address() const {
        std::cout << "data address: " << data << std::endl;
    }
};

class FakeFile {
private:
    const char* path;
    bool opened;

public:
    FakeFile(const char* file_path) : path(file_path), opened(true) {
        std::cout << "open file: " << path << std::endl;
    }

    FakeFile(const FakeFile& other) = delete;
    FakeFile& operator=(const FakeFile& other) = delete;

    ~FakeFile() {
        if (opened) {
            std::cout << "close file: " << path << std::endl;
        }
    }

    void write_line(const char* text) {
        if (!opened) {
            return;
        }

        std::cout << "write to " << path << ": " << text << std::endl;
    }
};

void shallow_copy_example() {
    std::cout << "shallow_copy_example begin" << std::endl;

    BrokenArray first(3);
    BrokenArray second = first;

    first.print_address();
    second.print_address();

    std::cout << "Both objects now store the same data address." << std::endl;
}

void file_raii_example() {
    std::cout << "file_raii_example begin" << std::endl;

    FakeFile file("report.txt");
    file.write_line("hello RAII");

    std::cout << "leave file_raii_example" << std::endl;
}

int main() {
    shallow_copy_example();

    std::cout << std::endl;

    file_raii_example();

    std::cout << std::endl;
    std::cout << "main end" << std::endl;

    return 0;
}

/*
练习1:
地址相同
说明复制的是堆地址
会重复删除，因为第一次已经释放了对应地址的内存，第二次相当于释放未成型的资源

练习2:
因为这样避免了重复释放对应地址的内存
析构会发生重复释放资源的错误操作

练习3:
模拟了创建和删除文件句柄的动作
因为他涉及到了创建和删除（释放资源），这类动作适合用RAII进行管理

练习4:
文件操作
线程操作
堆内存操作
*/