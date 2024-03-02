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

vector<int> beautifulIndices(string s, string a, string b, int k)
{
    int maxI = s.size() - a.size();
    int maxJ = s.size() - b.size();

    vector<int> res;

    vector<int> allI;
    vector<int> allJ;

    int inI = -1;
    while (inI <= maxI)
    {
        inI = s.find(a, inI + 1);
        if (inI != -1)
        {
            allI.push_back(inI);
        }
        else
        {
            break;
        }
    }

    int inJ = -1;
    while (inJ <= maxJ)
    {
        inJ = s.find(b, inJ + 1);
        if (inJ != -1)
        {
            allJ.push_back(inJ);
        }
        else
        {
            break;
        }
    }

    for (auto i : allI)
    {
        for (auto j : allJ)
        {
            if (abs(j - i) <= k)
            {
                res.push_back(i);
                break;
            }
        }
    }

    return res;
}

int main()
{
}