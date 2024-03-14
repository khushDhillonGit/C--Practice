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

int main()
{
    vector<int> soldiers;

    for (int i = 1; i <= 20000; i++)
        soldiers.push_back(i);

    int size = soldiers.size();
    int remain = size / 2;
    int i = 0;
    int c = size % 2 == 0 ? 0 : 1;

    while (remain != 1)
    {
        if (i >= size)
        {
            i = 0;
            continue;
        }
        if (soldiers[i] == -1)
        {
            i += 2;
            continue;
        }
        c++;
        if (c == 2)
        {
            soldiers[i] = -1;
            remain -= 1;
            c = 0;
        }
        i += 2;
    }
    i = 0;
    while (soldiers[i] == -1)
    {
        i += 2;
    }

    cout << soldiers[i] << endl;
}