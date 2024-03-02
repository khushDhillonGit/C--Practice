// Boiler plate for c++ competative
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
int minimum(int a,int b){
    return a < b ? a:b;
}
int maximum(int a,int b){
    return a < b ? b:a;
}
 int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    long *b = new long[n+1]{0};
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        b[i+1] = b[i] + nums[i]; 
    }
    deque<int> dq;
    for(int i=0;i<n+1;i++){
        if(b[i] >= k){
            min = minimum(min,i);
        }
        while (!dq.empty() && b[i] <= b[dq.back()])
        {
            /* code */
            dq.pop_back();
        }
        while (!dq.empty() && b[i] - b[dq.front()] >= k)
        {
            /* code */
            min = minimum(min,i-dq.front());
            dq.pop_front();
        }
        
        dq.push_back(i);
        
    }
    return min == INT_MAX?-1:min;

 }

int main()
{
    vector<int> a{2,7,3,-8,4,10};
    cout << shortestSubarray(a,12) << endl;
}