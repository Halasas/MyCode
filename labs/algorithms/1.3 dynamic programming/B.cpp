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
    int n;
    cin >> n;
    vector<int> a(n), dp(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], dp[i] = 1;
    int ansm = 1;
    int ansi = 0;
    for (int i = 1; i < n; i++)
    {
        int m = 0, ind = i;
        for (int j = 0; j <= i-1; j++)
            if (m < dp[j] && a[j] < a[i]) ind = j, m = dp[j];
        p[i] = ind;
        dp[i] = m + 1;
        if (ansm < dp[i]) ansm = dp[i], ansi = i;
    }
    vector<int> ans;
    int ind = ansi;
    ans.push_back(ind);
    while(ind != p[ind])    ind = p[ind], ans.push_back(ind);
    cout << ans.size()<< endl;
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << a[i] << " ";
    return 0;
}