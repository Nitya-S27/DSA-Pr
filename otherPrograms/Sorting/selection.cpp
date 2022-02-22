#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void print(int *arr, int size)
{
    cout << endl
         << "Sorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter size of an array : ";
    cin >> n;
    int *array = new int[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    selectionSort(array, n);
    print(array, n);
    return 0;
}