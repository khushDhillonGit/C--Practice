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

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    int i = 0;
    long long res = 0;
    while (source[i] != '\0')
    {
        if (source[i] != target[i])
        {
            vector<char> cant;
            long long sys = change(target[i], source[i], cant, original, changed, cost);
            if (sys > -1)
            {
                res += sys;
            }
            else
            {
                return -1;
            }
        }
        i++;
    }

    return res == 0 ? -1 : res;
}

long long change(char from, char to, vector<char> &cant, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    long long res = -1;
    if (from == to) return 0;

    int j = 0;
    while (j < original.size())
    {
        if (changed[j] == from && find(cant.begin(), cant.end(), original[j]) == cant.end())
        {
            long long sys = cost[j];
            cant.push_back(changed[j]);
            long long next = change(original[j], to, cant, original, changed, cost);
            if (next != -1)
            {
                sys += next;
                res = res == -1 ? sys : min(sys, res);
            }
        }
        j++;
    }
    return res;
}

int main()
{
}