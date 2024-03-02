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

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> ch;
    vector<string> res;
    util(s, wordDict, ch, "", res);
    return res;
}

void util(string s, vector<string> &wordDict, unordered_map<string, bool> ch, string t, vector<string> &res)
{
    if (s.size() == 0)
    {
        res.push_back(t.substr(1));
        return;
    }
    for (int i = 0; i < wordDict.size(); i++)
    {
        if (!ch[s])
        {
            auto a = s.find(wordDict[i]);
            if (a == 0)
            {
                ch[s] = true;
                util(s.substr(wordDict[i].size()), wordDict, ch, t + " " + wordDict[i], res);
                ch[s] = false;
            }
        }
    }
    ch[s] = true;
    return;
}

int main()
{
}