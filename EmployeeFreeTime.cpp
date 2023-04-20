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
}
void empFreeTime(vector<vector<int>> &interval){

    vector<Interval> res;

    for(vector<int> a: interval){
        for(int b: a){
            res.push_back(b);
        }
    }

    std:priority_queue<Interval,vector<Interval>,[](Interval start0,Interval start1){ return start0.start < start1.start; }>
    pq(res.begin(),res.end());

    auto ans = pq.poll();
    cout << ans.start << endl;
    cout << ans.end << endl;


}
int main()
{
    vector<Interval> a {1,2,5,6};
    vector<Interval> b {1,3};
    vector<Interval> c {4,7};

}