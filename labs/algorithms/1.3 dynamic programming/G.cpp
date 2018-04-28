#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
 
#pragma warning(disable: 4996)
 
#define ll long long
#define TASK1 "input"
#define TASK2 "output"
using namespace std;
 
int main() {
#ifdef _DEBUG 
    freopen("input.in", "r", stdin);
#else 
    //freopen(TASK1".txt", "r", stdin);
    //freopen(TASK2".txt", "w", stdout);
#endif
    string s;
    int n;
    cin >> s;
    n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    for (int len = 2; len <= n; len++)
        for (int left = 0; left + len - 1 < n; left++) {
            int right = left + len - 1;
            string m = "";
            for (int k = left; k < right; k++)
                if (dp[left][k].size() + dp[k + 1][right].size() > m.size())
                    m = dp[left][k] + dp[k + 1][right];
            if ((s[left] == '(' && s[right] == ')'
                || s[left] == '[' && s[right] == ']'
                || s[left] == '{' && s[right] == '}') 
                && dp[left+1][right -1].size() + 2 > m.size())
                m = s[left] + dp[left + 1][right - 1] + s[right];
            dp[left][right] = m;
        }
    cout << dp[0][n - 1];
    return 0;
}