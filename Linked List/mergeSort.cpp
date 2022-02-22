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

Node *mergeSort(Node *head1, Node *head2)
{
    Node *result = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeSort(head1->next, head2);
    }
    if (head2->data < head1->data)
    {
        result = head2;
        result->next = mergeSort(head1, head2->next);
    }
    return result;
}

int main()
{
    Node *head1 = takeInput();
    print(head1);
    cout << endl;
    Node *head2 = takeInput();
    print(head2);
    cout << endl;
    Node *result = mergeSort(head1, head2);
    print(result);
    cout << endl;
    return 0;
}