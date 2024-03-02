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

   int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        return n1 > n2 ? util(text1,text2,n1,n2) : util(text2,text1,n2,n1); 
    }
    int util(string text1, string text2,int n1,int n2)
    {
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof dp);

        for(int i =1;i<=n1;i++)
        {
            for(int j =1;j<=n2;j++)
            {
                if(text1[i-1] == text2[j-1]) 
                {    
                    dp[i][j] =  1 + dp[i-1][j-1];
                }else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
  
        return dp[n1][n2];
    }

int main()
{
}