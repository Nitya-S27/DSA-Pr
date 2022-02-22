#include <iostream>
using namespace std;

void merge(int *arr, int beg, int mid, int end)
{
    int temp[end - beg + 1];

    int i = beg, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = arr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k += 1;
        i += 1;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        k += 1;
        j += 1;
    }

    for (i = beg; i <= end; i += 1)
    {
        arr[i] = temp[i - beg];
    }
}

void mergeSort(int *arr, int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}
void print(int *arr, int size)
{
    cout << "Sorted array : ";
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
    mergeSort(array, 0, n - 1);
    print(array, n);
    return 0;
}