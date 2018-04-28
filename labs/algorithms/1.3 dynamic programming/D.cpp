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
    freopen(TASK1".txt", "r", stdin);
    freopen(TASK2".txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int m = s2.size();
    int n = s1.size();
    vector<vector<int>> dp(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if ( j > 0 && i > 0) {
                dp[i][j] = min({ dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + (s1[i] == s2[j] ? 0 : 1) });
            }
 
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}