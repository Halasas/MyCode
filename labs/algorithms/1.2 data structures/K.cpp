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
int flag = 1;
void calibration(){
    while (a.size() + flag != b.size() && a.size() != b.size())
    {
        if (a.size() > b.size())
        {
            if (flag == -1)
            {
                int tmp = a.front();
                a.pop_front();
                b.push_back(tmp);
            }
            else {
                int tmp = a.back();
                a.pop_back();
                b.push_front(tmp);
            }
        }
        else
        {
            if (flag == 1)
            {
                int tmp = b.front();
                b.pop_front();
                a.push_back(tmp);
            }
            else {
                int tmp = b.back();
                b.pop_back();
                a.push_front(tmp);
            }
        }
    }
}
 
void push_back(int x) {
    if (flag == 1)
        b.push_back(x);
    else
        a.push_back(x);
    calibration();
}
 
void pop_back() {
    if (flag == 1 && !b.empty())
        b.pop_back();
    if(flag == -1 && !a.empty())
        a.pop_back();
    calibration();
}
 
void mom() {
    flag *= -1;
    calibration();
}
 
int main()
{
    freopen("kenobi.in", "r", stdin);
    freopen("kenobi.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            push_back(x);
        }
        if (s == "mum!") 
            mom();
        if (s == "take")
            pop_back();
    }
    cout << a.size() + b.size() << endl;
    if (flag == 1){
        while (!a.empty()) {
            cout << a.front() << " ";
            a.pop_front();
        }
        while (!b.empty()) {
            cout << b.front() << " ";
            b.pop_front();
        }
    }
    if (flag == -1) {
        while(!b.empty()) {
            cout << b.front() << " ";
            b.pop_front();
        }
        while (!a.empty()) {
            cout << a.front() << " ";
            a.pop_front();
        }
 
    }
    return 0;
}