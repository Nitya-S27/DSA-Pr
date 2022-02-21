#include <iostream>
// #include "../queue.h"
#include <limits>
#include <queue>
using namespace std;

class Tree
{
public:
    int data;
    Tree *lChild;
    Tree *rChild;

    Tree(int data)
    {
        this->data = data;
        this->lChild = NULL;
        this->rChild = NULL;
    }
};

Tree *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    Tree *rootNode = new Tree(rootData);
    queue<Tree *> pendingNodes;
    pendingNodes.push(rootNode);

    while (pendingNodes.size() != 0)
    {
        Tree *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Enter left child of " << frontNode->data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            Tree *leftNode = new Tree(leftChild);
            frontNode->lChild = leftNode;
            pendingNodes.push(leftNode);
        }
        int rightChild;
        cout << "Enter right child of " << frontNode->data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            Tree *rightNode = new Tree(rightChild);
            frontNode->rChild = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return rootNode;
}

void print(Tree *root)
{
    Tree *tempRoot = root;
    if (tempRoot == NULL)
    {
        return;
    }
    queue<Tree *> pendingNodes;
    pendingNodes.push(tempRoot);
    while (!pendingNodes.empty())
    {
        Tree *frontNode = pendingNodes.front();
        cout << frontNode->data << " : ";
        pendingNodes.pop();
        if (frontNode->lChild != NULL)
        {
            cout << "L" << frontNode->lChild->data << " ";
            pendingNodes.push(frontNode->lChild);
        }
        if (frontNode->rChild != NULL)
        {
            cout << "R" << frontNode->rChild->data << " ";
            pendingNodes.push(frontNode->rChild);
        }
        cout << endl;
    }
}

int numNodes(Tree *root)
{
    int num = 1;
    if (root->lChild != NULL)
    {
        num += numNodes(root->lChild);
    }
    if (root->rChild != NULL)
    {
        num += numNodes(root->rChild);
    }
    return num;
}

int height(Tree *root)
{
    int hL = 0, hR = 0;
    if (root == NULL)
    {
        return 0;
    }
    hL = height(root->lChild);
    hR = height(root->rChild);
    if (hL > hR)
    {
        return hL + 1;
    }
    else
    {
        return hR + 1;
    }
}

void preorder(Tree *root)
{
    Tree *temp = root;
    if (root != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->lChild);
        preorder(temp->rChild);
    }
}

void inorder(Tree *root)
{
    Tree *temp = root;
    if (root != NULL)
    {
        inorder(temp->lChild);
        cout << temp->data << " ";
        inorder(temp->rChild);
    }
}

void postorder(Tree *root)
{
    Tree *temp = root;
    if (root != NULL)
    {
        postorder(temp->lChild);
        postorder(temp->rChild);
        cout << temp->data << " ";
    }
}

void levelorder(Tree *root)
{
    Tree *temp = root;
    queue<Tree *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        Tree *frontNode = nodes.front();
        cout << frontNode->data << " ";
        nodes.pop();
        if (frontNode->lChild != NULL)
        {
            nodes.push(frontNode->lChild);
        }
        if (frontNode->rChild != NULL)
        {
            nodes.push(frontNode->rChild);
        }
    }
}

bool isPresent(Tree *root, int node)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == node)
        return true;
    bool result1 = isPresent(root->lChild, node);
    if (result1)
        return true;

    bool result2 = isPresent(root->rChild, node);
    return result2;
}

void mirrorTree(Tree *root)
{
    Tree *temp = root;
    if (temp == NULL)
    {
        cout << "Tree is empty!";
    }

    queue<Tree *> nodesQueue;
    nodesQueue.push(temp);
    while (nodesQueue.size() != 0)
    {
        Tree *frontNode = nodesQueue.front();
        cout << frontNode->data << " ";
        nodesQueue.pop();
        if (frontNode->lChild != NULL)
        {
            nodesQueue.push(frontNode->rChild);
        }
        if (frontNode->rChild != NULL)
        {
            nodesQueue.push(frontNode->lChild);
        }
    }
}

int diameter(Tree *root)
{
    Tree *temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    int option1 = height(temp->lChild) + height(temp->rChild);
    int option2 = diameter(temp->lChild);
    int option3 = diameter(temp->rChild);
    return max(option1, max(option2, option3));
}

int findMax(Tree *root)
{
    if (root == NULL)
        return INT8_MIN;

    int maximum = root->data;
    int lMax = findMax(root->lChild);
    int rMax = findMax(root->rChild);
    if (lMax > maximum)
        maximum = lMax;
    if (rMax > maximum)
        maximum = rMax;
    return maximum;
}

bool isBalanced(Tree *root)
{
    Tree *temp = root;
    int lHeight = height(temp->lChild);
    int rHeight = height(temp->rChild);
    if (lHeight == rHeight)
        return true;
    else
        return false;
}

Tree *leafDelete(Tree *root)
{
    if (root == NULL)
        return NULL;
    if (root->lChild == NULL && root->rChild == NULL)
    {
        delete (root);
        return NULL;
    }

    root->lChild = leafDelete(root->lChild);
    root->rChild = leafDelete(root->rChild);

    return root;
}

int main()
{
    Tree *root = takeInput();

    print(root);

    cout << "Number of nodes present in the binary tree are : " << numNodes(root) << endl;

    cout << "Height of tree : " << height(root) << endl;

    cout << "Pre-Order traversal of tree : ";
    preorder(root);

    cout << endl
         << "In-order traversal of tree : ";
    inorder(root);

    cout << endl
         << "Post-order traversal of tree : ";
    postorder(root);

    cout << endl
         << "Level-order traversal of tree : ";
    levelorder(root);

    cout << endl;
    cout << "Mirror tree : ";
    mirrorTree(root);

    cout << endl
         << "Diameter of the tree : " << diameter(root) << endl;

    cout << "Maximum element is : " << findMax(root) << endl;

    cout << "Tree is balanced or not : " << isBalanced(root) << endl;

    cout << "Tree after removing leaf nodes : " << endl;
    Tree *root1 = leafDelete(root);
    print(root1);

    int node;
    cout << "Enter the node you want to find : ";
    cin >> node;
    cout << "Root is present or not : " << isPresent(root, node);
    cout << endl;
    return 0;
}