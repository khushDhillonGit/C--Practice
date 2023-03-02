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
int index(int a,int p,int s){
    while(a>=0){
        if(p == s){
            p = -1;
        }
        p++;
        a--;
    } 
    return p;
}
bool circularArrayLoop(vector<int>& nums) {
        int s = nums.size();
        vector<char> store(s,'N');
        
        for(int j=0;j<s;j++){
            int p=j;
            bool pos = nums[j] > 0;
            for(int i=j;i<s;i++){
                
                i = p;
                if(nums[i] > 0 != pos){
                    break;
                }
                if(store[i] == 'V'){
                    break;
                }
                store[i] = 'C';
                p+=nums[i];
                while(p>s-1){
                    p-=s;
                }
                while(p<0){
                    p+=s;
                }
                if(i == p){
                    replace(store.begin(),store.end(),'C','V');
                    break;
                }
                if(store[p] == 'C'){
                    return true;
                }
            }
        }
        return false;
}
int main()
{
    // vector<int> test = {2,-1,1,2,2};
    // vector<int> test = {1,-1,5,1,4};
    // vector<int> test = {-1,-2,-3,-4,-5,6};
    // vector<int> test = {2,2,2,2,2,4,7};
    vector<int> test = {-1,-2,-3,-4,-5,6};
    cout << circularArrayLoop(test) << endl;
}