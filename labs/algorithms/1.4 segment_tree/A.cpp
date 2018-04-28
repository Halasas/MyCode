#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define TASK "sum0"
 
long long mod(long long a, long long b)
{
    if (a < 0)
        return b + a;
    return a % b;
}
 
void next_gen(long long &v, long long a, long long b, long long x)
{
    v = mod((a * v + b), x);
}
 
int main()
{
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    long long a, b;
    long long x, y, z, t, n, m;
    const long long mod1 = (1 << 16);
    const long long mod2 = (1 << 30);
    cin >> n >> x >> y >> a;
    cin >> m >> z >> t >> b;
    vector<long long> pref(1e7 + 32, 0);
    vector<int> c((1e7 + 32) * 2, 0);
 
    pref[1] = a;
    for (int i = 2; i <= n; i++)
    {
        next_gen(a, x, y, mod1);
        pref[i] = pref[i - 1] + a;
    }
    c[0] = mod(b, n);
    for (int i = 1; i < 2 * m; i++)
    {
        next_gen(b, z, t, mod2);
        c[i] = mod(b, n);
    }
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int l = min(c[2 * i], c[2 * i + 1]);
        int r = max(c[2 * i], c[2 * i + 1]) + 1;
        long long res = pref[r] - pref[l];
        sum += res;
    }
    cout << sum;
    return 0;
}