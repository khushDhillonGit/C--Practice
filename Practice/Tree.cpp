#include <iostream>
#include <vector>
#include <string>
#include <Queue>
#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *rootPtr = NULL;

void CreateAndConnectNewNode(Node **node, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->left = NULL;
    temp->left = NULL;
    *node = temp;
}

void InsertRecurse(Node **root, int x)
{
    if (*root == NULL)
    {
        CreateAndConnectNewNode(root, x);
    }
    else if (x > (*root)->data)
    {
        InsertRecurse(&((*root)->right), x);
    }
    else
    {
        InsertRecurse(&((*root)->left), x);
    }
}

int FindHeightRecurse(Node *root)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = FindHeightRecurse(root->left);
    int right = FindHeightRecurse(root->right);

    if(left > right)  return left + 1 ; 
    return right + 1;
}

Node* SearchRecurse(Node *root, int x)
{
    if (x == root->data)
    {
        return root;
    }
    else if (x > root->data)
    {
        root = SearchRecurse(root->right, x);
    }
    else
    {
        root = SearchRecurse(root->left, x);
    }
    return root;
}



void Insert(int x)
{
    if (rootPtr == NULL)
    {
        CreateAndConnectNewNode(&rootPtr, x);
    }

    Node *temp = rootPtr;
    while (temp->left != NULL && temp->right != NULL)
    {
        if (x > temp->data)
        {
            if (temp->right == NULL)
            {
                CreateAndConnectNewNode(&temp->right, x);
            }
            temp = temp->right;
        }
        else
        {
            if (temp->left == NULL)
            {
                CreateAndConnectNewNode(&temp->left, x);
            }
            temp = temp->right;
        }
    }
}

void PrintLevelOrder(Node *root)
{
   queue<Node*> queue;
   // enqueue the first node
   queue.push(root);
   while(!queue.empty())
   {
    Node* current_node = queue.front();
    queue.pop();
    cout << current_node->data << " ";
    /* Enqueue left child */
    if(current_node->left  != NULL)
    queue.push(current_node->left);
    /*Enqueue right child*/
    if(current_node->right!=NULL)
    queue.push(current_node->right);
    }
    cout << "" << endl;
}
void PreOrderRecursion(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << endl;

    PreOrderRecursion(root->left);
    PreOrderRecursion(root->right);
}

void InOrderRecursion(Node *root)
{
    if(root == NULL)
    {
        return;
    }


    InOrderRecursion(root->left);
    cout << root->data << endl;
    InOrderRecursion(root->right);
}

void PostOrderRecursion(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrderRecursion(root->left);
    PostOrderRecursion(root->right);
    cout << root->data << endl;
}

bool BSTUtil(Node* root, int min, int max)
{
    if(root == NULL) return true;
    if(BSTUtil(root->left,min,root->data) && root->data >= min && root->data < max  && BSTUtil(root->right,root->data,max)) return true;
    return false;
}

bool IsBST(Node *root)
{
    if(root == NULL) return true;

    if(IsBST(root->left) && IsBST(root->right))
    {
        if(root->left != NULL)
        {
            if(root->data < root->left->data) return false;
        }

        if(root->right != NULL)
        {
            if(root->data >= root->right->data) return false;
        }
        return true;
    }
    return false;
}
Node* findLowestInRight(Node* root)
{
    if(root == NULL) return root;
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node* DeleteNode(Node *root, int x)
{
    if(root == NULL) return root;

    if(root->data == x)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete (root);
            root = NULL;
        }else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }else
        {
            Node* lowest = findLowestInRight(root->right);
            root->data = lowest->data;
            root->right = DeleteNode(root->right,lowest->data);
        }
    }else if(x < root->data)
    { 
        root->left =  DeleteNode(root->left,x);

    }else 
    {
        root->right = DeleteNode(root->right,x);
    }
    return root;
}



int main()
{
    int a[] = {11,5,15,3,7,1,13,17,12,14,16,20,18,22};
    for (int i: a)
    {
        InsertRecurse(&rootPtr,i);
    }
    PrintLevelOrder(rootPtr);
    cout <<  IsBST(rootPtr) << endl;
    rootPtr = DeleteNode(rootPtr, 15);
    cout <<  IsBST(rootPtr) << endl;
    PrintLevelOrder(rootPtr);


    // Node* result = SearchRecurse(rootPtr,20);
    // cout << result->data <<endl;
    //PrintLevelOrder(rootPtr);
    //PreOrderRecursion(rootPtr);
    // InOrderRecursion(rootPtr);
    // PostOrderRecursion(rootPtr);
}