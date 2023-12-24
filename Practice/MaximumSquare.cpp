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

int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
{
    long long M = 1000000007;
    if (m == n)
    {
        return ((m - 1) * (m - 1)) %M;
    }
    hFences.push_back(m);
    vFences.push_back(n);
    hFences.push_back(1);
    vFences.push_back(1);

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    if (m < n)
    {


        while (m > 0)
        {
            if (hasDiff(vFences, m) && hasDiff(hFences, m))
            {
                return (m * m) % M;
            }
            m--;
        }
    }
    else
    {
             while (n > 0)
        {
            if (hasDiff(vFences, n) && hasDiff(hFences, n))
            {
                return (n * n) % M;
            }
            n--;
        }
    }

    return -1;
}

bool hasDiff(vector<int> &vec, int diff)
{
    int i = 0;
    int j = 1;
    while (i <= j && j < vec.size())
    {
        if (vec[j] - vec[i] > diff)
        {
            i++;
        }
        else if (vec[j] - vec[i] == diff)
        {
            return true;
        }
        else
        {
            j++;
        }
    }

    return false;
}

int main()
{
}