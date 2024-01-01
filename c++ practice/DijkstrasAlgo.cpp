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

long long ChangeElement(vector<vector<pair<int, int>>> graph, int from, int to)
{
    long long res = 0;
    vector<long long> shortestCost(26, LONG_MAX);
    shortestCost[from] = 0;
    queue<pair<int, long long>> queue;
    queue.push({from, 0});

    while (!queue.empty())
    {
        pair<int, long long> pair = queue.front();   queue.pop();
        for (::pair<int, int> path : graph[pair.first])
        {
            int cost = pair.second + path.second;
            if (cost < shortestCost[path.first])
            {
                shortestCost[path.first] = cost;
                queue.push({path.first, cost});
                if (path.first == to) res = cost;
            }
        }
     
    }

    return res == 0 ? -1 : res;
}

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    long long res = 0;
    vector<vector<pair<int, int>>> graph(26);
    // created directed graph
    for (int i = 0; i < original.size(); i++)
    {
        graph[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
    }
    unordered_map<int, long long> map;
    long long t = 0;
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] != target[i])
        {
            int hash = (source[i] - 'a')*100 + (target[i] - 'a');
            if(map[hash] != 0)
            {
                t = ChangeElement(graph, source[i] - 'a', target[i] - 'a');
                if (t == -1)
                    return t;
                
                map[hash] = t;
                t = 0;
            }
            res += map[hash];
        }
    }

    return res == 0 ? -1 : res;
}

int main()
{
}