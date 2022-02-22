// DEPTH FIRST SEARCHING

#include <iostream>
using namespace std;

void print(int **matrix, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (matrix[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(matrix, n, i, visited);
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices : ";
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    cout << "Enter number of edges : ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "Enter (f, s) : ";
        cin >> f >> s;
        matrix[f][s] = 1;
        matrix[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    print(matrix, n, 0, visited);

    delete visited;
    return 0;
}