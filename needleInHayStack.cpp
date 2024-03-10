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

void util(string needle, int ns, int *lps)
{
    int len = 0, i = 1;
    lps[len] = 0;
    while (i < ns)
    {
        if (needle[i] == needle[len])
        {
            lps[i++] = len + 1;
            len++;
        }
        else
        {
            if (len == 0)
            {
                lps[i++] = 0;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int strStr(string haystack, string needle)
{
    int hs = haystack.size();
    int ns = needle.size();

    int *lps = new int[ns];
    util(needle, ns, lps);

    int i = 0, j = 0;

    while (i < hs)
    {

        if (haystack[i] == needle[j])
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
        if (j == ns)
            break;
    }
    if (i == hs && j == ns - 1)
        return i - j;
    return j == ns ? i - j : -1;
}

int main()
{
    strStr("ababcaababcaabc", "ababcaabc");
}