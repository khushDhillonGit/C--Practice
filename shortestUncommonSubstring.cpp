#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool util(int i, string k, vector<string> &arr, int size);

vector<string> shortestSubstrings(vector<string> &arr)
{
    unordered_map<string, bool> map;

    int size = arr.size();
    vector<string> res(size);

    int ma = 0;
    int s_size = 0;

    for (int i = 0; i < size; i++)
    {

        ma = arr[i].size();
        s_size = arr[i].size();

        for (int j = 0; j < s_size; j++)
        {
            for (int k = 1; k <= s_size; k++)
            {
                string sub = arr[i].substr(j, k);
                if (ma < k)
                    continue;
                if (map[sub])
                    continue;

                if (!util(i, sub, arr, size))
                {
                    if (ma >= k && (ma != k || res[i] == "" || res[i].compare(sub) >= 0))
                    {
                        ma = k;
                        res[i] = sub;
                    }
                }
                else
                {
                    map[sub] = true;
                }
            }
        }
    }

    return res;
}

bool util(int i, string k, vector<string> &arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        if (j == i)
            continue;
        if (arr[j].find(k) != std::string::npos)
            return true;
    }
    return false;
}

int main()
{
}