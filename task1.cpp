#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
        x = std::rand() % 100;
}


void printArray(const int (&arr)[10])
{
    for (auto x : arr)
        std::cout << x << " ";
    std::cout << "\n";
}
void swapElements(int (&arr)[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
        x *= 2;
}
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int arr[10]{};
    fillArray(arr);
    printArray(arr);
    return 0;
}