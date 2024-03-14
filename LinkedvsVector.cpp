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
    for (int i = 1; i < 5; i++)
        soldiers.push_back(i);

    int remain = soldiers.size();
    int size = remain;
    int i = 0;
    int c = 0;

    while (remain != 1)
    {
        if (soldiers[i] == -1)
            continue;
        c++;
        if (c == 2)
        {
            soldiers[i] = -1;
            remain--;
            c = 0;
        }
        i++;
        if (i == size)
            i = 0;
    }
    i = 0;
    // while (soldiers[i] != -1)
    // {
    //     i++;
    // }

    cout << soldiers[--i] << endl;
}