#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
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

ListNode *create_list(int upto)
{
    if (upto > 0)
    {
        ListNode *root = new ListNode(1);
        ListNode *temp = root;
        for (int i = 2; i <= upto; i++)
        {
            ListNode *t = new ListNode(i);
            temp->next = t;
            temp = t;
            t = NULL;
            delete t;
        }
        temp->next = root;
        temp = NULL;
        delete temp;

        return root;
    }
    return NULL;
}

int main()
{
    ListNode *res = create_list(20000);
    ListNode *temp = res;
    while (temp->next->next != temp)
    {
        // ListNode *del = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        // delete del;
    }

    cout << temp->val << endl;
}