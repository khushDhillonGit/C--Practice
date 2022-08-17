#include <iostream>
#include <string>
using namespace std;

void fun(string *a, int num);
string check(int num);
char IToR(int num);
string intToRoman(int num);

int check(string *a, int num)
{

  if (num >= 4 && num < 5)
  {
    *a += "IV";
    return num -= 4;
  }
  else if (num >= 9 && num < 10)
  {
    *a += "IX";
    return num -= 9;
  }
  else if (num >= 40 && num < 50)
  {
    *a += "XL";
    return num -= 40;
  }
  else if (num >= 90 && num < 100)
  {
    *a += "XC";
    return num -= 90;
  }
  else if (num >= 400 && num < 500)
  {
    *a += "CD";
    return num -= 400;
  }
  else if (num >= 900 && num < 1000)
  {
    *a += "CM";
    return num -= 900;
  }
  return -1;
}

void fun(string *a, int num, int com)
{
  int rem = check(a, num), left = 0;
  if (rem == -1)
  {
    rem = num % com;
    left = num - rem;
    if (check(a, left) == -1)
    {
      left /= com;
      while (left > 0)
      {
        *a += IToR(com);
        left--;
      }
    }
    else
    {
      rem = check(a, left);
    }
  }
  intToRoman(rem);
}
char IToR(int num)
{
  if (num == 1)
  {
    return 'I';
  }
  else if (num == 5)
  {
    return 'V';
  }
  else if (num == 10)
  {
    return 'X';
  }
  else if (num == 50)
  {
    return 'L';
  }
  else if (num == 100)
  {
    return 'C';
  }
  else if (num == 500)
  {
    return 'D';
  }
  else if (num == 1000)
  {
    return 'M';
  }

  return 'E';
}

string intToRoman(int num)
{

  static string a = "";
  if (num > 1000 && num <= 3999)
  {
    fun(&a, num, 1000);
  }
  else if (num <= 1000 && num > 500)
  {
    if (num == 1000)
    {
      a += "M";
    }
    else
    {
      fun(&a, num, 500);
    }
  }
  else if (num <= 500 && num > 100)
  {
    if (num == 500)
    {
      a += "D";
    }
    else
    {
      fun(&a, num, 100);
    }
  }
  else if (num <= 100 && num > 50)
  {
    if (num == 100)
    {
      a += "C";
    }
    else
    {
      fun(&a, num, 50);
    }
  }
  else if (num <= 50 && num > 10)
  {
    if (num == 50)
    {
      return "L";
    }
    else
    {
      fun(&a, num, 10);
    }
  }
  else if (num <= 10 && num > 5)
  {
    if (num == 10)
    {
      a += "X";
    }
    else
    {
      fun(&a, num, 5);
    }
  }
  else if (num <= 5 && num > 1)
  {
    if (num == 5)
    {
      return "V";
    }
    else
    {
      fun(&a, num, 1);
    }
  }
  else if (num == 1)
  {
    a += "I";
  }
  return a;
}

int main()
{
  cout << intToRoman(6) << endl;
}
