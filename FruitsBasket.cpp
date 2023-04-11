// Boiler plate for c++ competative
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int val)
  {
    val = val;
    next = NULL;
  }
};

  int totalFruit(vector<int>& fruits) {
        map<int,int> map;
        int max = 0;
        int count = 0;
        int ele = -1;
        for(int i=0;i<fruits.size();i++){
            map[fruits[i]]++;
            count++;
            if(map.size() == 3){
                count--;
                count > max ? max=count:max = max;
                map.begin()->second--;
                if(map.begin()->second == 0){
                    map.erase(map.begin()->first);
                }
            }
        }
        return count > max ? count:max;
    }

int main()
{
    vector<int> a {1,2,3,2,2};
    cout<< totalFruit(a) << endl;
}