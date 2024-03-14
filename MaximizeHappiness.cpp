#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    long long res = 0;

    std::sort(happiness.rbegin(), happiness.rend());

    int c = 0, i = 0;

    while (k > 0)
    {
        int a = happiness[i++] - c;
        if (a < 0)
            a = 0;
        cout << a << endl;
        res += a;
        c++;
        k--;
    }

    return res;
}

int main()
{
}