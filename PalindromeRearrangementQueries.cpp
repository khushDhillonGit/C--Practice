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

vector<bool> canMakePalindromeQueries(string s, vector<vector<int>> &queries)
{
    vector<bool> res;
    int size = s.size();
    vector<int> vis(size, 0);
    int mid = s.size() / 2;

    int l = 0, r = (mid * 2) - 1;

    for (auto q : queries)
    {
        bool good = true;
        unordered_map<char, int> usedL;
        unordered_map<char, int> usedLProR;
        for (int i = q[0]; i <= q[1]; i++)
        {
            usedL[s[i]]++;
            usedLProR[s[size - 1 - i]]++;
        }

        unordered_map<char, int> usedR;
        unordered_map<char, int> usedRProL;
        for (int i = q[2]; i <= q[3]; i++)
        {
            usedR[s[i]]++;
            usedLProR[s[size - 1 - i]]++;
        }

        while (l < mid)
        {
            if (s[l] != s[r])
            {
                //l is outside
                if (l < q[0] || l > q[1])
                {
                    // this means both l and r are outside
                    if (r < q[2] || r > q[3])
                    {
                        good = false;
                        break;
                    }
                    // l outside, r inside
                    else
                    {

                        usedR[s[l]]--;

                        if()
                        usedRProL[s[r]]--;
                        if (usedR[s[r]] < 0 || usedRProL[s[r]]-- < 0)
                        {
                            good = false;
                            break;
                        }
                    }
                }
                //l is inside
                else
                {
                    //r is outside
                     if (r < q[2] || r > q[3])
                     {
                        usedL[s[l]]--;
                        usedLProR[s[l]]--;
                        if (usedR[s[l]] < 0 || usedLProR[s[l]]-- < 0)
                        {
                           good = false;
                            break;
                        }
                     }
                     //r is inside
                     else
                     {
                        usedL[s[l]]--;
                        usedLProR[s[l]]--;
                        if (usedR[s[l]] < 0 || usedLProR[s[l]]-- < 0)
                        {
                            good = false;
                            break;
                        }

                        usedR[s[l]]--;
                        usedRProL[s[l]]--;
                        if (usedR[s[l]] < 0 || usedRProL[s[l]]-- < 0)
                        {
                            good = false;
                            break;
                        }
                     }
                }
            }
            l++;
            r--;
        }

        res.push_back(good);
    }

    return res;
}

int main()
{
}