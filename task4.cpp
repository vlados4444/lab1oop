#include <iostream>
#include <string>
#include <iomanip>

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols]{};
    return matrix;
}

int main() { return 0; }
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "Студент " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j)
            std::cin >> matrix[i][j];
    }
}