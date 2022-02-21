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

class Stack
{
public:
    Node *head;
    int size;

    Stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    // int getSize()
    // {
    //     return size;
    // }
    void push(int element)
    {
        Node *newNode = new Node(element);
        if (head == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    int top()
    {
        return head->data;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Queue
{
public:
    Stack s1;
    Stack s2;

    bool empty()
    {
        return s1.isEmpty() && s2.isEmpty();
    }
    void enqueue(int data)
    {
        s1.push(data);
    }
    int dequeue()
    {
        int x, y;
        while (!s1.isEmpty())
        {
            x = s1.top();
            s2.push(x);
            s1.pop();
        }
        y = s2.top();
        while (!s2.isEmpty())
        {
            x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return y;
    }
    void display()
    {
        s1.display();
    }
    int getSize() {}
};

int main()
{
    //     Stack s;
    //     s.push(10);
    //     s.push(20);
    //     s.push(30);
    //     s.push(40);
    //     s.push(50);
    //     s.display();
    //     cout << s.top();
    //     cout << endl
    //          << "Size : " << s.getSize();
    //     s.pop();
    //     cout << endl;
    //     s.display();
    //     cout << s.top();
    //     cout << endl
    //          << "Size : " << s.getSize();
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << q.dequeue();
    return 0;
}