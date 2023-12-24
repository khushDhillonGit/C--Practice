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

TreeNode* BuildUtilL(int *counter, int rootIndex, vector<int> &preorder, vector<int> &inorder)
{
        if(*counter >= preorder.size()) return NULL;
        int inOrder = std::find(inorder.begin(),inorder.end(),preorder[*counter]) - inorder.begin();
        if(inOrder > rootIndex)
        {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[*counter]);
        *counter++;
        node->left = BuildUtilL(counter, inOrder,preorder, inorder);
        node->right = BuildUtilR(counter, inOrder,preorder, inorder);  
        return node;
}

TreeNode* BuildUtilR(int *counter, int rootIndex, vector<int> &preorder, vector<int> &inorder)
{
        if(*counter >= preorder.size()) return NULL;
        int inOrder = std::find(inorder.begin(),inorder.end(),preorder[*counter]) - inorder.begin();
        if(inOrder < rootIndex)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[*counter]);
        *counter++;
        node->left = BuildUtilL(counter, inOrder,preorder, inorder);
        node->right = BuildUtilR(counter, inOrder,preorder, inorder);  
        return node;
}

TreeNode* BuildUtilL(int counter, vector<int> &preorder, vector<int> &inorder)
{
        
        std::vector<int>::iterator it = std::find(inorder.begin(),inorder.end(),counter);
        int indexInOrder = it - inorder.begin();

        TreeNode* node = new TreeNode(counter);

        auto indexNext = std::find(inorder.begin(),inorder.end(),preorder[0]);
        if(indexNext != inorder.end())
        {
            vector<int> leftI(inorder.begin(),it);
            vector<int> rightI(it, inorder.end());
            if(indexNext < it)
            {
                 auto indexNextNext = std::find(inorder.begin(),inorder.end(),preorder[1]);
                 if(indexNextNext > it)
                 {
                    node->left = BuildUtilL(indexNext - inorder.begin(),preorder, leftI);
                    node->right = BuildUtilR(counter,preorder,rightI);  
                 }
            }else
            {
            }



        }
        return node;


        if(indexNext < indexInOrder)

}


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.size() == 0) return NULL;
        TreeNode* node = new TreeNode(preorder[0]);
        int inOrder = std::find(inorder.begin(),inorder.end(),preorder[0]) - inorder.begin();
        int counter = 1;
        node->left = BuildUtilL(&counter, inOrder,preorder, inorder);
        node->right = BuildUtilR(&counter, inOrder,preorder, inorder);  
        return node;
}


int main()
{
}