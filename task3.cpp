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

void printSafe(const SafeArray& arr)
{
    std::cout << "SafeArray[" << arr.size << "]: ";
    for (int i = 0; i < arr.size; ++i)
        std::cout << arr.data[i] << " ";
    std::cout << "\n";
}

int main()
{
    SafeArray myArr = createArray(5);

    getElement(myArr, 2) = 999;
    printSafe(myArr);

    getElement(myArr, 10) = 123;
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}