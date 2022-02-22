#include <iostream>
#include <queue>
using namespace std;

void bfs(int **matrix, int n, int sv, bool *visited)
{
    queue<int> elements;
    elements.push(sv);
    visited[sv] = true;
    while (!elements.empty())
    {
        int frontElement = elements.front();
        cout << frontElement << " ";
        elements.pop();
        for (int i = 0; i < n; i++)
        {
            if (matrix[frontElement][i] == 1 && !visited[i])
            {
                elements.push(i);
                visited[i] = true;
            }
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

    bfs(matrix, n, 0, visited);

    return 0;
}