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
int sumOfDigits(int a){
    int total = 0;
    while(a != 0){
        total += pow((a%10),2);
        a/=10;
    }
    return total;
}
bool isHappy(int n) {
    vector<int> k;
    k.push_back(n);
    n = sumOfDigits(n);
    while(n!=1){
        if(find(k.begin(),k.end(),n) != k.end()){
            return false;
        }
        n = sumOfDigits(n);
        k.push_back(n);
    }
    return true;
}
int main()
{
    cout << isHappy(3) << endl;
}