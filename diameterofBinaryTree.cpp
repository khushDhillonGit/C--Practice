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

  int diameterOfBinaryTree(TreeNode* root) {
        int highest = 0; 
        longest(root, &highest);
        return highest;
    }

     int longest(TreeNode* root, *highest) {
        if (root == NULL) return -1;
        int left = longest(root->left) + 1;
        int right = longest(root->right) + 1;
        if(left + right > highest) highest = left + right;
        return  left > right ? left :right;
    }

int main()
{
}