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

void flatten(TreeNode *root)
{
    if (root == NULL) return;
    flatten(root->left);
    flatten(root->right);

    TreeNode temp* = root->left;
    if(temp!=NULL)
    {
        while (temp->right !=NULL)
        {
            temp = temp->right;
        }
        temp.right = root->left;
    }
    root->right = root->left;   
    root->left = NULL;

}

int main()
{
}