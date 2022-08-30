#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string capitalizeTitle(string title)
{
  int count = 0;
  int start = 0;
  for (int i = 0; i < title.length(); i++)
  {
    if (title[i] == ' ' || i == title.length() - 1)
    {

      if (count >= 2)
      {
        title[start] = toupper(title[start]);
      }
      start = i + 1;
      count = 0;
    }
    else
    {
      title[i] = title[i] <= 90 ? title[i] + 32 : title[i];
      count++;
    }
  }
  return title;
}
int main()
{
}