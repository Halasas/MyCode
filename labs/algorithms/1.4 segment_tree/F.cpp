#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
#define TASK "sparse"
typedef long long ll;
int n;
vector<int> lg2;
vector<vector<int>> st;
 
void precalc_lg2() {
    int pow = 2;
    lg2.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        lg2[i] = lg2[i - 1];
        if (pow == i)
            pow *= 2, lg2[i]++;
    }
}
 
void build_st()
{
    for (int j = 1; j <= lg2[n]; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
 
int get_min(int l, int r)
{
    int len = r - l + 1;
    int lg = lg2[len];
    return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}
 
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif // DEBUG
    int m;
    cin >> n >> m;
     
    precalc_lg2();
    st.resize(n, vector<int>(lg2[n] + 1, INT_MAX));
    cin >> st[0][0];
    for (int i = 1; i < n; i++)
        st[i][0] = (23 * st[i-1][0] + 21563) % 16714589;
    build_st();
 
    int u, v, ans;
    cin >> u >> v;
    ans = get_min(min(u - 1, v - 1), max(u - 1, v - 1));
    for (int i = 2; i <= m; i++) {
        u = ((17 * u + 751 + ans + 2 * i - 2) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i - 5) % n) + 1;
        ans = get_min(min(u - 1, v - 1), max(u - 1, v - 1));
    }
    cout << u << " " << v << " " << ans;
    return 0;
}