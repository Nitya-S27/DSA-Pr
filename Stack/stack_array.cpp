#include <iostream>
using namespace std;

class Stack
{
public:
    int *array;
    int nextIndex;
    int size;

    Stack(int size)
    {
        this->array = new int[size];
        this->nextIndex = 0;
        this->size = size;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int data)
    {
        if (nextIndex == size)
        {
            int *newArray = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            delete array;
            array = newArray;
            size *= 2;
        }
        array[nextIndex] = data;
        nextIndex++;
    }

    void pop()
    {
        nextIndex--;
    }

    inline int top()
    {
        return array[nextIndex - 1];
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s(5);
    s.push(10);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.print();
    cout << "Topmost element : " << s.top() << endl;
    s.pop();
    cout << "Topmost element popped !!!" << endl;
    s.print();
    cout << "Topmost element : " << s.top() << endl;
    return 0;
}