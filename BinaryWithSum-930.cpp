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

       int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0,count=0;
        int prev=0;
        bool done = false;
        for(i,j;j<nums.size();j++){
            goal-=nums[j];
            while(goal <=0 && i<nums.size()){
                if(goal==0){

                count++;
                }
                if(nums[j+1]==0){
                    prev = j;
                    done = true;
                    j++;
                    while(nums[j]==0){
                        count++;
                        j++;
                    }
                }
                if(done){
                    j = prev+1;
                    done = false;
                }
                goal+=nums[i++];
            }

        }
        return count;
    }

int main()
{
    // vector<int> n{1,0,1,0,1};
    vector<int> n{0,0,0,0,0,0,1,0,0,0};
    cout<< numSubarraysWithSum(n,0) << endl;
}