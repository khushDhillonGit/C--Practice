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

long long ChangeElement(vector<vector<pair<int, int>>> graph, string from, string to)
{
    long long res = 0;
    vector<long long> shortestCost(26, LONG_MAX);
    shortestCost[from] = 0;
    queue<pair<int, long long>> queue;
    queue.push({from, 0});

    while (!queue.empty())
    {
        pair<int, long long> pair = queue.front();
        queue.pop();
        for (::pair<int, int> path : graph[pair.first])
        {
            int cost = pair.second + path.second;
            if (cost < shortestCost[path.first])
            
            {
                shortestCost[path.first] = cost;
                queue.push({path.first, cost});
                if (path.first == to)
                    res = cost;
            }
        }
    }

    return res == 0 ? -1 : res;
}
long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
{
    long long res = 0;
    unordered_map<string,vector<pair<string,int>> graph;
    for(int i = 0;i<original.size();i++)
    {
        graph[original[i]].insert({changed[i],cost[i]});
    }

    return res == 0 ? -1 :res;
}
int main()
{
}