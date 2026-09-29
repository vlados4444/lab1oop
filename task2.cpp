#include <iostream>

void process(int*& arr, int& size)
{
    int firstNeg = -1;
    for (int i = 0; i < size; ++i)
        if (arr[i] < 0) { firstNeg = i; break; }

    if (firstNeg == -1) return;

    int newSize = firstNeg;
    int* newArr = new int[newSize]{};
    for (int i = 0; i < newSize; ++i)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
    size = newSize;
}

int main()
{
    int N;
    std::cout << "введите N: ";
    std::cin >> N;

    int* arr = new int[N]{};
    std::cout << "Enter  " << N << " elements:\n";
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];

    process(arr, N);

    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
    arr = nullptr;

    if (arr != nullptr)
        std::cout << *arr << "\n";
    else
        std::cout << "Pointer is null\n";

    return 0;
}
