#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> result;
    if(root == NULL) return result;
    queue<TreeNode*> queue;
    queue.push(root);

    int n = 0;
    while(!queue.empty())
    {
        TreeNode *node = queue.front();
        if(node->left != NULL) {queue.push(node->left);}
        if(node->right != NULL) {queue.push(node->right);}
        queue.pop(); 
        if(n == 0)
        {
            result.push_back(node->val);
            n = queue.size();
        }
        n--;
    }
return result;
}

int main()
{
}