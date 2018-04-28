#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define TASK "rmq2"
typedef long long ll;
 
vector<ll> t;
vector<pair<bool, long long>> upd;
long long n;
long long nn;
 
void build(vector<long long> &a)
{
    long long pow = 0;
    while (n > 0) {
        n = (n >> 1);
        pow++;
    }
    n = a.size();
    nn = (1 << pow);
    t.resize(nn * 2, LLONG_MAX);
    upd.resize(nn * 2, { 0,0 });
    for (long long i = 0; i < n; i++)
        t[nn - 1 + i] = a[i];
    for (long long i = nn - 2; i >= 0; i--)
        t[i] = min(t[2 * i + 1], t[2 * i + 2]);
}
 
void new_update(long long v, pair<bool, long long> new_upd)
{
    if (v > nn * 2 - 1)
        return;
    if (new_upd.first == 1)
        upd[v] = new_upd;
    if (new_upd.first == 0)
        upd[v].second += new_upd.second;
}
 
void push(long long v)
{
    bool type = upd[v].first;
    long long val = upd[v].second;
    if (type == 0)
        t[v] += val;
    if(type == 1)
        t[v] = val;
    new_update(v * 2 + 1, upd[v]);
    new_update(v * 2 + 2, upd[v]);
    upd[v] = { 0,0 };
}
 
long long min(long long v, long long tl, long long tr, long long l, long long r)
{
    push(v);
    if (tr < l || tl > r)
        return LLONG_MAX;
    if (l <= tl && tr <= r)
        return t[v];
    long long tm = (tl + tr) / 2;
    return min(min(v * 2 + 1, tl, tm, l, r),    min(v * 2 + 2, tm + 1, tr, l, r));
}
 
void mod(long long v, long long tl, long long tr, long long l, long long r, pair<bool, long long> val)
{
    push(v);
    if (tr < l || tl > r)
        return ;
    if (l <= tl && tr <= r) 
    {
        new_update(v, val);
        push(v);
        return;
    }
    long long tm = (tl + tr) / 2;
    mod(v * 2 + 1, tl, tm, l, r, val);
    mod(v * 2 + 2, tm + 1, tr, l, r, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
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
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    build(a);
    string s;
    while (cin >> s)
    {
        long long a, b, c;
        cin >> a >> b;
        a--;
        b--;
        if (s == "min")
        {
            cout << min(0, 0, nn - 1, a, b) << endl;
        }
        if (s == "set")
        {
            cin >> c;
            mod(0, 0, nn - 1, a, b, { 1,c });
        }
        if (s == "add")
        {
            cin >> c;
            mod(0, 0, nn - 1, a, b, { 0,c });
        }
    }
    return 0;
}