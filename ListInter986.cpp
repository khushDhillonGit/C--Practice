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
 vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> final;
        final.insert(final.end(),firstList.begin(),firstList.end());
        final.insert(final.end(),secondList.begin(),secondList.end());
        sort(final.begin(),final.end(),[](vector<int> a,vector<int> b){
            
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
            
            });

        vector<vector<int>> res;
        for(int i=0;i<final.size()-1;i++){
            if(final[i][1] >= final[i+1][0]){

                while(i<final.size()-1 && (final[i][1] > final[i+1][1])){
                    res.push_back(final[i+1]);
                    final[i+1][1] = final[i][1];
                    i++;
                }
                
                if(i < final.size()-1){

                    vector<int> k;
                    k.push_back(final[i+1][0]);
                    k.push_back(final[i][1]);

                    if(final[i][1] >= final[i+1][0]){
                        res.push_back(k);
                    }
                }
            }
        }
        return res;
        
    }
int main()
{

}