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

int& getElement(SafeArray& arr, int index)
{
    static int stub = 0;
    if (index < 0 || index >= arr.size)
    {
        std::cout << "Error: index " << index
                  << " out of range [0, " << arr.size - 1 << "]\n";
        stub = 0;
        return stub;
    }
    return arr.data[index];
}

int main()
{
    SafeArray myArr = createArray(5);

    getElement(myArr, 2) = 999;
    std::cout << "After [2] = 999: ";
    for (int i = 0; i < myArr.size; ++i)
        std::cout << myArr.data[i] << " ";
    std::cout << "\n";

    getElement(myArr, 10) = 123;
    std::cout << "After [10] = 123: ";
    for (int i = 0; i < myArr.size; ++i)
        std::cout << myArr.data[i] << " ";
    std::cout << "\n";

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}