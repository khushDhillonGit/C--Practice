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

std::vector<TreeNode> objectPool;
std::vector<TreeNode *> availableObjects;

TreeNode *getObject()
{
    if(availableObjects.empty())
    {
        objectPool.emplace_back();
        availableObjects.push_back(&objectPool.back());
    }

    TreeNode* tree = availableObjects.back();
    availableObjects.pop_back();
    return tree;
}

int main()
{
    std::unique_ptr<int> ptr(new int(5));
    std::shared_ptr<int> sh = std::make_shared<int>(5);
}