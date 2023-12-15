#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void CreateAndConnectNewNode(TreeNode **node, int x)
{
    TreeNode *temp = new TreeNode(x);
    *node = temp;
}

void InsertRecurse(TreeNode **root, int x)
{
    if (*root == NULL)
    {
        CreateAndConnectNewNode(root, x);
    }
    else if (x > (*root)->val)
    {
        InsertRecurse(&((*root)->right), x);
    }
    else
    {
        InsertRecurse(&((*root)->left), x);
    }
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string result = "[";
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        if (node == NULL)
        {
            result += "null,";
            queue.pop();
        }
        else
        {
            result += to_string(node->val) + ",";
            queue.push(node->left);
            queue.push(node->right);
            queue.pop();
        }
    }

    result.erase(result.length() - 1);
    result += "]";
    return result;
}
//"[11,5,15,3,7,13,17,1,null,null,null,12,14,16,20,null,null,null,null,null,null,null,null,18,22,null,null,null,null]"
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data[0] == '[' && data[1] == ']')
        return NULL;
    TreeNode *root = new TreeNode();
    queue<TreeNode **> queue;
    queue.push(&root);
    int length = data.size();
    int i = 1;
    while (i < length)
    {
        string value = "";
        while ((i < length-1) && (data[i] != ','))
        
        {
            value += data[i++];
        }
        i++;

        char j = data[i];
        TreeNode **node = queue.front();
        if (value != "null")
        {
            (*node)->val = stoi(value);
            (*node)->left = new TreeNode();
            (*node)->right = new TreeNode();
            queue.push(&((*node)->left));
            queue.push(&((*node)->right));
            queue.pop();
        }
        else
        {
            *node = NULL;
            queue.pop();
        }
    }
    while (!queue.empty())
    {
        TreeNode **node = queue.front();
        *node = NULL;
        queue.pop();
    }
    return root;
}
//"[11,5,15,3,7,13,17,1,null,null,null,12,14,16,20,null,null,null,null,null,null,null,null,18,22,null,null,null,null]"
//"[11,5,15,3,7,13,17,1,0,0,0,12,14,16,20,0,0,null,null,null,null,null,null,0,0,0,0,0,0,18,22,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,0,0,0,0,null,null,null,null,null,null,null,null]"
int main()
{
    int a[] = {11, 5, 15, 3, 7, 1, 13, 17, 12, 14, 16, 20, 18, 22};
    TreeNode *root = NULL;
    for (int i : a)
    {
        InsertRecurse(&root, i);
    }
    string result = serialize(root);
    TreeNode *test = deserialize(result);
    string res = serialize(test);
    string stop = "";
}