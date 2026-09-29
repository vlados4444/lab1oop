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
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "Студент " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j)
            std::cin >> matrix[i][j];
    }
}
void printMatrix(int** matrix, int rows, int cols,
                 bool showBorders = true,
                 std::string title = "Matrix")
{
    std::cout << "\n=== " << title << " ===\n";
    if (showBorders)
    {
        for (int j = 0; j < cols; ++j) std::cout << "--------";
        std::cout << "-\n";
    }
    for (int i = 0; i < rows; ++i)
    {
        if (showBorders) std::cout << "|";
        for (int j = 0; j < cols; ++j)
            std::cout << std::setw(5) << matrix[i][j];
        if (showBorders) std::cout << " |";
        std::cout << "\n";
    }
    if (showBorders)
    {
        for (int j = 0; j < cols; ++j) std::cout << "--------";
        std::cout << "-\n";
    }
}
void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main()
{
    int rows = 3, cols = 4;
    int** grades = allocateMatrix(rows, cols);
    fillMatrix(grades, rows, cols);

    printMatrix(grades, rows, cols);
    printMatrix(grades, rows, cols, true, "Оценки студентов");
    printMatrix(grades, rows, cols, false, "Без рамки");

    freeMatrix(grades, rows);
    grades = nullptr;
    return 0;
}




