// enqueue dequeue front size isEmpty

#include <iostream>
using namespace std;

class Queue
{
    int *data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int s)
    {
        data = new int[s];
        front = -1;
        rear = 0;
        capacity = s;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void enqueue(int element)
    {
        if (size == capacity)
        {
            int *newData = new int[capacity * 2];
            int j = 0;
            for (int i = front; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < front; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            front = 0;
            rear = capacity;
            capacity *= 2;
        }

        data[rear] = element;
        rear = (rear + 1) % capacity;
        if (front == -1)
        {
            front++;
        }
        size++;
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[front];
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!";
            return 0;
        }

        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0)
        {
            front = -1;
            rear = 0;
        }

        return value;
    }

    void display()
    {
        int temp = front;
        for (int i = 1; i <= size; i++)
        {
            cout << data[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    Queue s(4);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60); // queue is full

    s.display(); // 10 20 30 40 50

    cout << s.getFront() << endl; // 10
    cout << s.dequeue() << endl;  // 10
    cout << s.dequeue() << endl;  // 20
    cout << s.dequeue() << endl;  // 30

    cout << s.getSize() << endl; // 2

    cout << s.dequeue() << endl; // 40
    cout << s.dequeue() << endl; // 50
    cout << s.dequeue() << endl; // queue is empty

    return 0;
}