#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
        x = std::rand() % 100;
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int arr[10]{};
    fillArray(arr);
    return 0;
}