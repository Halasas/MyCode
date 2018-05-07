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
 
void build_st() {
    for (int j = 1; j <= lg2[n]; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
 
int get_min(int l, int r) {
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
    return 0;
}