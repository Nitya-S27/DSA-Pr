// push pop top size isEmpty
#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    T size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    void push(T data)
    {
        size++;
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    T pop()
    {
        size--;
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl
                 << "TRY TO PUSH AN ELEMENT !!!";
        }
        else
        {
            int value = head->data;
            Node<T> *del_head = head;
            head = head->next;
            delete del_head;
            return value;
        }
    }
    T top()
    {
        return head->data;
    }
    void display()
    {
        cout << endl
             << "Stack : ";
        Node<T> *temp = head;
        if (isEmpty())
        {
            cout << "List is empty!!!";
        }

        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next == NULL)
            {
                cout << " ";
            }
            else
            {
                cout << "->";
            }

            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack<char> s;
    int choice;
    while (1)
    {
        cout << endl
             << "1 : Push an element" << endl
             << "2 : Pop an element" << endl
             << "3 : Topmost element of stack" << endl
             << "4 : Size of stack" << endl
             << "5 : Display the list" << endl
             << "6 : Quit" << endl;
        cout << endl
             << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            char data;
            cout << "Enter the element you want to push : ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            cout << "Element removed from the top : " << s.pop();
            break;
        case 3:
            cout << "Topmost element : " << s.top();
            break;
        case 4:
            cout << s.getSize();
            break;
        case 5:
            s.display();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Ivalid choice!";
            break;
        }
    }

    return 0;
}