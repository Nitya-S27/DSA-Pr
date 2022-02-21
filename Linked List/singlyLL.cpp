#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
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
            tail->next = newNode;
            tail = tail->next;
        }
        cout << "Do you want to enter data? y/n :  ";
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

void checkNode(Node *head)
{
    int data;
    cout << "Enter the node data you want to find : ";
    cin >> data;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "Yes node is present.";
            return;
        }
        temp = temp->next;
    }
    cout << "Node not present! Create one...";
    return;
}

void findNodeAtIndex(Node *head)
{
    int index;
    cout << "Enter the index of element you want to find : ";
    cin >> index;
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "List is empty!";
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        if (temp->data)
            cout << temp->data;
        else
            cout << "Index Invalid.";
    }
}

void insertNode(Node *head)
{
    int data;
    cout << "Enter the node to be inserted : ";
    cin >> data;
    Node *newNode = new Node(data);
    int index;
    cout << "Enter the index of node to be inserted : ";
    cin >> index;
    Node *temp = head;
    if (index == 0)
    {
        head = newNode;
        newNode->next = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *tempNext = temp->next;
        temp->next = newNode;
        newNode->next = tempNext;
    }
    print(head);
}

void deleteNode(Node *head)
{
    Node *temp = head;
    int index;
    cout << "Enter the index of node to be deleted : ";
    cin >> index;
    if (index == 0)
    {
        head = temp->next;
        delete temp;
    }

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node *tempNext = temp->next;
    temp->next = temp->next->next;
    delete tempNext;

    print(head);
}

Node *takeInputSinglyCircular()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    char choice;
    do
    {
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = tail->next;
        }
        cout << "y/n : ";
        cin >> choice;

    } while (choice != 'n');
    return head;
}

void printCircularLL(Node *head)
{
    Node *temp = head;
    cout << temp->data << " -> ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data;
        if (temp->next != head)
            cout << " -> ";
        else
            cout << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl;
    checkNode(head);
    cout << endl;
    findNodeAtIndex(head);
    cout << endl;
    deleteNode(head);
    cout << endl;
    insertNode(head);
    cout << endl
         << "Enter the data of circular linked list : " << endl;
    Node *circularHead = takeInputSinglyCircular();
    printCircularLL(circularHead);

    return 0;
}