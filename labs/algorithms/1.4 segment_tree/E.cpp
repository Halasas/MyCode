#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
 
using namespace std;
 
#define TASK "crypto"
typedef long long ll;
int n, nn;
int r;
 
 
struct matrix {
    int a, b, 
        c, d;
    matrix() {
        a = 1; b = 0;
        c = 0; d = 1;
    }
};
 
vector<matrix> tree;
matrix E = matrix();
 
inline void mul(matrix &x, matrix &a, matrix &b) {
    x.a = (a.a * b.a + a.b * b.c) % r; x.b = (a.a * b.b + a.b * b.d) % r;
    x.c = (a.c * b.a + a.d * b.c) % r; x.d = (a.c * b.b + a.d * b.d) % r;
}
 
inline matrix mul(matrix &a, matrix &b) {
    matrix x;
    x.a = (a.a * b.a + a.b * b.c) % r; x.b = (a.a * b.b + a.b * b.d) % r;
    x.c = (a.c * b.a + a.d * b.c) % r; x.d = (a.c * b.b + a.d * b.d) % r;
    return x;
}
 
inline void scan(matrix& a) {
    scanf("%d%d%d%d", &a.a, &a.b, &a.c, &a.d);
}
 
inline void print(matrix& a) {
    printf("%d %d\n%d %d\n", a.a, a.b, a.c, a.d);
}
 
inline void build(vector<matrix> &a)
{
    nn = n;
    int pow = 0;
    while (n != 0)
        n >>= 1, pow++;
    n = (1<<pow);
    if (n == nn * 2)
        n = nn;
 
    tree.resize(2 * n + 1);
    for (int i = 0; i < nn; i++)
        tree[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; i--)
         mul(tree[i], tree[2 * i + 1], tree[2 * i + 2]);
}
 
matrix res;
 
void mult(int v, int& l, int& r, int tl, int tr) {
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r) {
        res = mul(res, tree[v]);
        return;
    }
    int tm = (tl + tr) / 2;     
    mult(v * 2 + 1, l, r, tl, tm);
    mult(v * 2 + 2, l, r, tm + 1, tr);
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
    scanf("%d%d%d", &r, &n, &m);
    vector<matrix> a(n);
    for (int i = 0; i < n; i++)
        scan(a[i]);
     
    build(a);
 
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if (x != y)
        {
            res = E;
            mult(0, x, y, 0, n - 1);
            print(res);
        }
        else
            print(a[x]);
    }
    return 0;
}