#include <iostream>
using namespace std;
bool sparse_or_not(int **matrix, int rows, int columns)
{
    int count = 0;
    int size = rows * columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
                count++;
            else
                continue;
        }
    }
    if (count >= (size / 2))
        return true;
    else
        return false;
}
int main()
{
    int rows, columns;
    cout << "Enter number of rows and columns : ";
    cin >> rows >> columns;
    int size = (rows * columns);

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    if (sparse_or_not(matrix, rows, columns))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}