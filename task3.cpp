#include <iostream>

struct SafeArray
{
    int* data;
    int size;
};

SafeArray createArray(int size)
{
    SafeArray arr;
    arr.size = size;
    arr.data = new int[size]{};
    return arr;
}

int main()
{
    SafeArray myArr = createArray(5);
    std::cout << "Size: " << myArr.size << "\n";

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}