#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    int size;

    Queue()
    {
        front = NULL;
        rear = NULL;
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
    void enQueue(int element)
    {
        Node *newNode = new Node(element);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void deQueue()
    {
        if (front == rear)
        {
            front = rear = NULL;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    int getFront()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!";
            return 0;
        }
        return front->data;
    }
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next == NULL)
                cout << " ";
            else
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.display();                                // 10 20 30 40
    cout << "Front : " << q.getFront() << endl; // 10
    cout << "Size : " << q.getSize() << endl;   // 4
    q.deQueue();                                // 10
    q.display();                                // 20 30 40
    cout << "Front : " << q.getFront() << endl; // 20
    cout << "Size : " << q.getSize() << endl;   // 3

    return 0;
}