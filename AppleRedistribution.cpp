#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int total = 0;
    int res = 0;

    for (int a : apple)
    {
        total += a;
    }
    sort(capacity.rbegin(), capacity.rend());
    for (int b : capacity)
    {
        res++;
        total -= b;
        if (total <= 0)
            break;
    }

    return res;
}
int main()
{
}