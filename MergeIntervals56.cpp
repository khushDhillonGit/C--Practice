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
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0] < b[0];});
    res.push_back(intervals[0]);
    for(int i= 1;i<intervals.size();i++){
        if(intervals[i][0] <= res.back()[1]){
            res.back()[1] = res.back()[1] > intervals[i][1] ? res.back()[1] : intervals[i][1];
        }else{
            res.push_back(intervals[i]);
        }
    }
    return res;

}
int main()
{

}