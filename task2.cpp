#include <iostream>

void process(int*& arr, int& size)
{
    // пока пусто
}

int main()
{
    int N;
    std::cout << "N: ";
    std::cin >> N;

    int* arr = new int[N]{};
    std::cout << "Введите " << N << " элементов:\n";
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
        std::cout << "Указатель обнулён\n";

    return 0;
}