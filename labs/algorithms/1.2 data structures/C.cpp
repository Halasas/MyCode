#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
 
#pragma warning(disable: 4996)
 
using namespace std;
 
 
int main()
{
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    vector<int> res;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i+=2)
    {
        if (s[i] >= '0' && s[i] <= '9')
            res.push_back(s[i] - '0');
        else
        {
            if (s[i] == '+') {
                int tmp = res[res.size() - 2] + res[res.size() - 1];
                res.pop_back(), res.pop_back();
                res.push_back(tmp);
            }
            if (s[i] == '-') {
                int tmp = res[res.size() - 2] - res[res.size() - 1];
                res.pop_back(), res.pop_back();
                res.push_back(tmp);
            }
            if (s[i] == '*') {
                int tmp = res[res.size() - 2] * res[res.size() - 1];
                res.pop_back(), res.pop_back();
                res.push_back(tmp);
            }
        }
    }
    cout << res[0];
    return 0;
}