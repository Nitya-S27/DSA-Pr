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
    Node *front;
    Node *rear;
    int size;

public:
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

    void enqueue(int element)
    {
        Node *newNode = new Node(element);
        if (front == NULL)
        {
            front = newNode;
            rear = front;
        }
        else
        {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        Node *temp = front;
        int value = temp->data;
        if ((front == NULL) && (rear == NULL))
            printf("\nQueue is Empty");
        else if (front == rear)
        {
            front = rear = NULL;
            delete temp;
        }
        else
        {
            front = front->next;
            rear->next = front;
            delete temp;
        }
        return value;
    }

    void display()
    {
        Node *temp = front;
        cout << temp->data << " ";
        temp = temp->next;
        while (temp != front)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    cout << q.dequeue();
    return 0;
}