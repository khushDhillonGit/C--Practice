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
int *const util_fill_lps(string st, int size);

int string_search(string main, string to_search)
{
    int m = main.size();
    int n = to_search.size();
    int *const lps = util_fill_lps(to_search, n);
    int i = 0, j = 0;
    while (i < m)
    {
        if (main[i] == to_search[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
        if (j == n)
            return i - j;
    }

    return -1;
}

int *const util_fill_lps(string st, int size)
{
    int *const lps = new int[size];
    int i = 1, j = 0;
    lps[j] = 0;
    while (j < size)
    {
        if (st[i] == st[j])
        {
            lps[i++] = ++j;
        }
        else
        {
            if (j == 0)
                lps[i++] = j;
            else
                j = lps[j - 1];
        }
    }
    return lps;
}

int main()
{
    cout << string_search("absdtredgdsadkdnaikbdajndwaskkdmkdfsjkuiadsadwd", "ikbd") << endl;
}