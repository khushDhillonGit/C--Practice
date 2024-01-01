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

    unordered_map<int,bool> map;

    long long res = -1;
    int size = hFences.size();
    for(int i = 0; i< size -1;i++)
    {
        for(int j = 1 + i;j <size;j++)
        {
            map[abs(hFences[i] - hFences[j])] = true;
        }
    }
    size = vFences.size();
    for(int i = 0; i< size -1;i++)
    {
        for(int j = 1 + i;j < size;j++)
        {
            int diff = abs(vFences[i] - vFences[j]);
            if(map[diff])
            {
                res = diff > res ? diff : res; 
            }
        }
    }

    return res == -1 ? res : (res * res) % M;
}

int main()
{
}