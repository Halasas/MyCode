#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
#define TASK "rsq"
 
vector<long long> t;
 
long long f(long long r) { return (r & (r + 1)); }
long long rf(long long r) { return (r | (r + 1)); }
 
long long sum(long long r)
{
    long long res = 0;
    while (r >= 0)
        res += t[r], r = f(r) - 1;
    return res;
}
 
long long sum(long long l, long long r)
{
    return sum(r) - sum(l - 1);
}
 
void set(long long i, long long d, long long n)
{
    while (i < n)
        t[i] += d, i = rf(i);
}
 
void build(vector<long long> a, long long n)
{
    t.resize(n); 
    for (long long i = 0; i < n; i++)
        set(i, a[i], n);
}
 
int main()
{
#ifdef _DEBUG
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif // DEBUG
 
    long long n;
    cin >> n;
    vector<long long> a(n + 16);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    build(a, n);
    string s;
    while (cin >> s)
    {
        long long x, y;
        cin >> x >> y;
        if (s == "sum")
            cout << sum(x - 1, y - 1) << endl;
        else if (s == "set")
            set(x - 1, y - a[x - 1], n), a[x - 1] = y;
    }   
    return 0;
}