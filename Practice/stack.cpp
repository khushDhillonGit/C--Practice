#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void Reverse(string *c, int n)
{
    stack<char> stack;
    int i = 0;
    while ((*c)[i] != '\0')
    {
        stack.push((*c)[i++]);
    }
    i = 0;
    while (!stack.empty())
    {
        (*c)[i++] = stack.top();
        stack.pop();
    }
}
bool CheckParentheses(string a)
{
    stack<char> stack;
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            stack.push(a[i]);
        }
        else if (a[i] == ')')
        {
            if (stack.top() != '(')
                return false;
            else
            {
                stack.pop();
            }
        }
        else if (a[i] == '}')
        {
            if (stack.top() != '{')
                return false;
            else
            {
                stack.pop();
            }
        }
        else if (a[i] == ']')
        {
            if (stack.top() != '[')
                return false;
            else
            {
                stack.pop();
            }
        }
        i++;
    }
    if (!stack.empty())
        return false;
    a[0] = 'K';
    return true;
}

float Evaluate(char c, int a, int b)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '/')
        return a / b;
    if (c == '*')
        return a * b;
    return -1;
}

float EvaluatePostFix(string exp)
{
    stack<float> stack;
    for (auto i : exp)
    {
        if (isdigit(i))
        {
            stack.push(i - '0');
        }
        else
        {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            stack.push(Evaluate(i, a, b));
        }
    }
    return stack.top();
}

int OrderOfPrecedence(char c)
{
    if (c == '*' || c == '/')
        return 1;
    if (c == '+' || c == '-')
        return 0;
    return -1;
}

string InfixToPostfix(string exp)
{
    string result = "";
    stack<char> stack;
    int size = exp.size();
    for (int k = 0; k < size; k++)
    {
        char i = exp[k];

        if (i == ' ')
            continue;

        if (isalpha(i) || isdigit(i))
            result += i;
        else
        {
            while (!stack.empty() && OrderOfPrecedence(stack.top()) > OrderOfPrecedence(i))
            {
                result += stack.top();
                stack.pop();
            }
            stack.push(i);
        }
    }

    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main()
{
    string a = "2+3*6-9*82";
    string r = InfixToPostfix(a);
    for (auto i : r)
    {
        cout << i << endl;
    }
    cout << EvaluatePostFix(r) << endl;
}