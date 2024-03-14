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
int countSubstrings(string s)
{
    int total = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        int j = i - 1, k = i;
        while (k < n - 1 && s[k] == s[k + 1])
            k++;
        total += (k - j) * (k - j + 1) / 2;
        i = k;
        k++;
        while (j >= 0 && k < n && s[j--] == s[k++])
            total++;
    }
    return total;
}
int main()
{
}