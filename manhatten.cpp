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

pair<int, int> util(vector<vector<int>> &points, int skip = -1)
{
    pair<int, int> sum = {INT_MIN, INT_MAX};
    pair<int, int> diff = {INT_MIN, INT_MAX};
    pair<int, int> sumi = {0, 0};
    pair<int, int> diffi = {0, 0};

    for (int i = 0; i < points.size(); i++)
    {
        if (i == skip)
            continue;
        int sump = points[i][0] + points[i][1];
        int diffp = points[i][0] - points[i][1];
        if (sum.first < sump)
        {
            sum.first = sump;
            sumi.first = i;
        }

        if (sum.second > sump)
        {
            sum.second = sump;
            sumi.second = i;
        }

        if (diff.first < diffp)
        {
            diff.first = diffp;
            diffi.first = i;
        }

        if (diff.second > diffp)
        {
            diff.second = diffp;
            diffi.second = i;
        }
    }

    return max(sum.first - sum.second, diff.first - diff.second) == sum.first - sum.second ? sumi : diffi;
}

int minimumDistance(vector<vector<int>> &points)
{
    pair<int, int> all = util(points);
    pair<int, int> skip1 = util(points, all.first);
    pair<int, int> skip2 = util(points, all.second);
    int first = abs(points[skip1.first][0] - points[skip1.second][0]) + abs(points[skip1.first][1] - points[skip1.second][1]);
    int second = abs(points[skip2.first][0] - points[skip2.second][0]) + abs(points[skip2.first][1] - points[skip2.second][1]);
    return min(first, second);
}

int main()
{
    vector<vector<int>> points = {{3, 10}, {5, 15}, {10, 2}, {4, 4}};
    std::cout << minimumDistance(points) << std::endl;
}