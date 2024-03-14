#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int>> ans;
void Recursion(int start, vector<int> &candidates, int target, int sum, vector<int> *k)
{
  if (target == sum)
  {
    ans.push_back(*k);
    return;
  }
  if (sum > target)
  {
    return;
  }
  for (int i = start; i < candidates.size(); i++)
  {
    sum += candidates[i];
    k->push_back(candidates[i]);
    Recursion(i, candidates, target, sum, k);
    sum -= candidates[i];
    k->pop_back();
  }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<int> a;
  Recursion(0, candidates, target, 0, &a);
  return ans;
}
int main()
{
  vector<int> c = {2, 3, 5};
  vector<vector<int>> k = combinationSum(c, 8);
  for (vector<int> a : ans)
  {
    for (int x : a)
    {
      cout << x << " ";
    }
    cout << "" << endl;
  }
}
// More Optimised
//  class Solution {
//  public:

//     void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
//     {

//         if(target == 0)
//         {
//             // if we get exact answer
//             res.push_back(r);
//             return;
//         }

//         while(i <  candidates.size() && target - candidates[i] >= 0)
//         {
//             // Till every element in the array starting
//             // from i which can contribute to the target
//             r.push_back(candidates[i]);// add them to vector

//             // recur for next numbers
//             Sum(candidates,target - candidates[i],res,r,i);
//             ++i;

//             // Remove number from vector (backtracking)
//             r.pop_back();
//         }
// }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end()); // sort candidates array

//         // remove duplicates
//         candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());

//         vector<int> r;
//         vector<vector<int> > res;

//         Sum(candidates,target,res,r,0);

//         return res;
//     }
// };