#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define TASK "painter"
typedef long long ll;
 
struct line
{
    char upd;
    int min_B;
    int max_B;
    int num;
    int len;
    line() {
        upd = ' ';
        max_B = -INT_MAX;
        min_B = INT_MAX;
        len = 0;
        num = 0;
    }
    line(int min_Bn, int max_Bn, int numn, char updn, int lenn) {
        min_B = min_Bn;
        max_B = max_Bn;
        num = numn;
        upd = updn;
        len = lenn;
    }
};
 
line operator+ (line &a, line &b) {
    if (a.max_B >= b.max_B || a.min_B >= a.min_B)
        exit;
    line c(min(a.min_B, b.min_B), max(a.max_B, b.max_B), a.num + b.num, ' ', a.len + b.len);
    if (a.max_B + 1 == b.min_B)
        c.num--;
    return c;
}
 
 
const int N = 1048576;
//const int N = 16;
vector<line> t(2 * N);
 
void push(int v, int tl, int tr) {
    if (t[v].upd == ' ')
        return;
    if (t[v].upd == 'B') {
        t[v].min_B = tl;
        t[v].max_B = tr;
        t[v].num = 1;
        t[v].len = tr - tl + 1;
    }
    if (t[v].upd == 'W') {
        t[v].min_B = INT_MAX;
        t[v].max_B = -INT_MAX;
        t[v].len = 0;
        t[v].num = 0;
    }
    if (v < N - 1)
        t[v * 2 + 1].upd = t[v * 2 + 2].upd = t[v].upd;
    t[v].upd = ' ';
}
 
void paint(int v, int l, int r, int tl, int tr, char col)
{
    push(v, tl, tr);
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r) {
        t[v].upd = col;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    paint(v * 2 + 1, l, r, tl, tm, col);
    paint(v * 2 + 2, l, r, tm + 1, tr, col);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
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
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char col;
        int x, l;
        cin >> col >> x >> l;
        paint(0, x + N/2, x + l - 1 + N / 2, 0, N - 1, col);
        cout << t[0].num << " " << t[0].len << endl;
    }
    return 0;
}