#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int majorityElement(vector<int> &nums)
{
  int major = nums[0], count = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    if (count == 0)
    {
      count++;
      major = nums[i];
    }
    else if (major == nums[i])
    {
      count++;
    }
    else
      count--;
  }
  return major;
}
int main()
{
  vector<int> a = {3, 2, 3};
  cout << majorityElement(a);
}