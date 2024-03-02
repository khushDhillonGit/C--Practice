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

   vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(root == NULL) return res;

        std::queue<TreeNode*> queue;
        queue.push(root);
        int levelCount = 1;
        vector<int> sibling;
        while(!queue.empty())
        {
            TreeNode *node = queue.front();
            if(node->left != NULL) queue.push(node->left);
            if(node->right != NULL) queue.push(node->right);

            if(levelCount > 0)
            {
                sibling.push_back(node->val);
                queue.pop();
                levelCount--;
            }

            if(levelCount == 0)
            {
                levelCount = queue.size();
                res.push_back(sibling);
                vector<int>().swap(sibling);
            }
        }
        return res;

    }   

int main()
{
}