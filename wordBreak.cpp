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

bool util(string s,vector<string>& wordDict,unordered_map<string,bool> &ch)
{
    if(s.size() == 0) return true;
    for(int i = 0;i<wordDict.size();i++)
    {
        if(!ch[s]){
            auto a = s.find(wordDict[i]); 
            if(a == 0)
            {
                bool res = util(s.substr(wordDict[i].size()),wordDict);
                if(res == true) return true;
            }
        }
    }
    ch[s] = true;
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> ch(301,false);
    return util(s,wordDict,ch);
}
int main()
{
    vector<string> wordDict;
    wordDict.push_back("bc");
    wordDict.push_back("ca");
    string s = "cbca";
    cout<<wordBreak(s,wordDict)<<endl;
}