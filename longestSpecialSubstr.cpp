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

int maximumLength(string s)
{
    unordered_map<string, int> map;
    int res = -1;
    int i = 0;
    for (int j = 0; j <= s.size(); j++)
    {
        if (j == s.size() || s[j] != s[i])
        {
            int c = j - i;
            for (int k = 1; k <= c; k++)
            {
                map[s.substr(i, j - i)] += k;
                if (map[s.substr(i, j - i)] >= 3)
                    res = j - i > res ? j - i : res;
                i++;
            }
            i = j;
        }
    }

    return res;
}

int main()
{
}