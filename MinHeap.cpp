#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdexcept>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }
};
class MinHeap
{
private:
    vector<int> nums;

public:
    Node *head;

    MinHeap()
    {
        head = NULL;
    }

    void create_heap(vector<int> &vals)
    {
        nums = vals;
        std::sort(nums.rbegin(), nums.rend());
        create();
    }

    void create()
    {
        int nums_size = nums.size();
        if (nums_size == 0)
            return;
        std::queue<Node *> node_queue;
        int idx = nums_size - 1;
        head = new Node(nums[idx--]);
        node_queue.push(head);
        while (!node_queue.empty() && idx >= 0)
        {
            Node *temp = node_queue.front();
            temp->left = new Node(nums[idx--]);
            node_queue.push(temp->left);
            if (idx == -1)
                break;
            temp->right = new Node(nums[idx--]);
            node_queue.push(temp->right);
            node_queue.pop();
        }
    }

    int pop()
    {
        int res = 0;
        if (head == NULL)
            throw std::invalid_argument("head is empty");
        res = head->val;
        delete head;
        nums.pop_back();
        create();
        return res;
    }

    int top()
    {
        if (head == NULL)
            throw std::invalid_argument("head is empty");
        return head->val;
    }
    void add(int val)
    {
        vector<Node *> nodes;

        nums.push_back(val);
        std::sort(nums.rbegin(), nums.rend());
        delete head;
        create();
    }
};
int main()
{
    vector<int> res = {8, 5, 4, 9, 2, 16, 20};
    MinHeap heap;
    heap.create_heap(res);
    cout << heap.top() << endl;
    cout << heap.pop() << endl;
}