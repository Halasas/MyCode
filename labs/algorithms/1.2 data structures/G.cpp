#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>  
 
#pragma warning(disable: 4996)
 
using namespace std;
 
deque<int> a, b;
void calibration(){
    while (a.size() != b.size() + 1 && a.size() != b.size())
    {
        if (a.size() > b.size())
        {
            int tmp = a.back();
            a.pop_back();
            b.push_front(tmp);
        }
        else
        {
            int tmp = b.front();
            b.pop_front();
            a.push_back(tmp);
        }
    }
}
 
void push_midle(int x)
{
    a.push_back(x);
    calibration();
}
 
void push_back(int x)
{
    b.push_back(x);
    calibration();
}
 
int pop_front(){
    int tmp = a.front();
    a.pop_front();
    calibration();
    return tmp;
}
 
int main()
{
    freopen("hospital.in", "r", stdin);
    freopen("hospital.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            push_back(x);
        }
        if (c == '*') {
            int x;
            cin >> x;
            push_midle(x);
        }
        if (c == '-') {
            cout << pop_front() << endl;
        }
    }
    return 0;
}