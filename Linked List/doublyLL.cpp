#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *takeInput()
{
    int data;
    char choice;
    Node *head = NULL;
    Node *tail = NULL;
    do
    {
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "y/n : ";
        cin >> choice;
    } while (choice != 'n');
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        else
            cout << " ";
        temp = temp->next;
    }
}

void reverseLL(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->prev != NULL)
            cout << " -> ";
        else
            cout << " ";
        temp = temp->prev;
    }
}

int main()
{

    Node *head = takeInput();
    cout << "Linked List : " << endl;
    print(head);
    cout << endl
         << "Reversed LL : " << endl;
    reverseLL(head);
    return 0;
}