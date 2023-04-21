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

class Interval{
    public:
        int start,end;
        Interval(int _start, int _end){
            this->start = _start;
            this->end = _end;
        }
};
void empFreeTime(vector<vector<int>> &interval){

    vector<Interval> res;

    for(vector<int> a: interval){
        for(int i=0;i<a.size();i++){
            Interval k = Interval(i,++i);
            res.push_back(k);
        }
    }

    std:priority_queue pq (res.begin(),res.end(),[](Interval start0,Interval start1){ return start0.start < start1.start; }) ;

    auto ans = pq.poll();
    cout << ans.start << endl;
    cout << ans.end << endl;


}
int main()
{
    vector<int> a {1,2,5,6};
    vector<int> b {1,3};
    vector<int> c {4,7};

    vector<vector<int>> k {a,b,c};

    empFreeTime(k);

}