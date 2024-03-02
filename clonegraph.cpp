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

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *util(unordered_map<Node *, bool> &vis,Node *node);
Node *cloneGraph(Node *node)
{
    unordered_map<Node *, bool> vis;
    if (node == NULL)
        return node;
    return util(vis, node);
}

Node *util(unordered_map<Node *, bool> &vis, Node *node)
{
    if (vis[node]) return node;
    vis[node] = true;
    Node *t = new Node(node->val);
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        Node *a = util(vis, node->neighbors[i]);
        t->neighbors.push_back(a);
    }
    return t;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    // Creating edges to form a circular graph
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node3->neighbors.push_back(node4);
    node3->neighbors.push_back(node2);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Node *res = cloneGraph(node1);
    return 1;
}