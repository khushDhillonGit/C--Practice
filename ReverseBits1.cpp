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
uint32_t reverseBits(uint32_t n)
{
    unsigned int mask = 1 << 31, res = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (n & 1)
            res |= mask;
        mask >>= 1;
        n >>= 1;
    }
    return res;
}
int main()
{
}