#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
{
    vector<vector<int>> adj(n);
    vector<int> cost(n, INT_MAX);

    for (vector<int> edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    vector<int> group(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (group[i] == -1)
        {
            group[i] = i;
            q.push(i);
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                cost[i] = cost[i] & cost[a];
                for (int v : adj[a])
                {
                    if (group[v] == -1)
                    {
                        group[v] = i;
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<int> res;
    for (vector<int> que : query)
    {
        int a = que[0], b = que[1];
        if (a == b)
            res.push_back(0);
        else
        {
            if (group[a] == group[b])
            {
                res.push_back(cost[group[a]]);
            }
            else
            {
                res.push_back(-1);
            }
        }
    }
    return res;
}

int main()
{
}