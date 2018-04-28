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
//  freopen(TASK2".txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(10, 1));
    dp[1][0] = 0, dp[1][8] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][4] + dp[i - 1][6])%((ll)1e9);
        dp[i][1] = (dp[i - 1][8] + dp[i - 1][6]) % ((ll)1e9);
        dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % ((ll)1e9);
        dp[i][3] = (dp[i - 1][8] + dp[i - 1][4]) % ((ll)1e9);
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % ((ll)1e9);
        dp[i][5] = 0;
        dp[i][6] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]) % ((ll)1e9);
        dp[i][7] = (dp[i - 1][6] + dp[i - 1][2]) % ((ll)1e9);
        dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % ((ll)1e9);
        dp[i][9] = (dp[i - 1][4] + dp[i - 1][2]) % ((ll)1e9);
    }
    ll sum = 0;
    for (int i = 0; i <= 9; i++)
        sum = (sum + dp[n][i]) % (ll)(1e9);
    cout << sum;
    return 0;
}