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

class Interval{
    public:
        int start,end;
        Interval(int _start, int _end){
            this->start = _start;
            this->end = _end;
        }
};

//this is called a functor
class myComparison{
    bool reverse;
    public:
        myComparison(const bool &revparam = false){
            reverse = revparam;
        }

        bool operator()(const Interval& lhs,const Interval& rhs)const {
            if(reverse) return (rhs.start < lhs.start);
            else return (lhs.start < rhs.start);
        }

};
std::ostream& operator<<(std::ostream& stream,const vector<Interval>& interval)
{
    for (Interval a: interval)
    {
        stream << a.start << ", " << a.end << std::endl;
    }

    return stream;
    
} 
vector<Interval> empFreeTime(vector<vector<int>> &interval){

    vector<Interval> res;


    priority_queue <Interval,vector<Interval>,myComparison> pq(myComparison(true));

     for (const auto& a : interval) {
        for (int i = 0; i + 1 < a.size(); i += 2) {
            Interval k = Interval(a[i], a[i + 1]);
            pq.push(k);
        }
    }

    auto current = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        if(current.end >= pq.top().start){
            Interval out = pq.top();
            pq.pop();
            current.end = max(current.end,out.end);
        }else{
            res.push_back(Interval(current.end,pq.top().start));
            current = pq.top();
            pq.pop();
        }
    }

    return res;

}
int main()
{
    vector<int> a {1,3,6,7};
    vector<int> b {2,4};
    vector<int> c {2,5,9,12};
    vector<vector<int>> k {a,b,c};
    std:: cout << empFreeTime(k) << endl;

}