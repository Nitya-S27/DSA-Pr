#include <iostream>
using namespace std;

void TOH(int n, char src, char aux, char des)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        TOH(n - 1, src, des, aux);
        cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
        TOH(n - 1, aux, src, des);
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks : ";
    cin >> n;
    cout << "Source : A" << endl
         << "Auxiliary : B" << endl
         << "Destination : C" << endl;
    TOH(n, 'A', 'B', 'C');
    return 0;
}