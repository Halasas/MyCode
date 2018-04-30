#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
 
using namespace std;
 
#define TASK
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend() 
 
 
struct node {
    long long x, y, sum;
    node* left;
    node* right;
 
    node(long long x, long long y) {
        this->x = x;
        this->y = y;
        this->sum = x;
        this->left = NULL;
        this->right = NULL;
    }
    node(long long x) {
        this->x = x;
        this->y = rand();
        this->sum = x;
        this->left = NULL;
        this->right = NULL;
    }
};
 
vector<bool> used(1e9 + 1);
 
void update(node* &v) {
    if (v == NULL)
        return;
    v->sum = v->x;
    if (v->left != NULL)
        v->sum += v->left->sum;
    if (v->right != NULL)
        v->sum += v->right->sum;
 
}
 
pair<node*, node*> split(node* &t, long long k) {
    if (t == NULL)
        return { NULL, NULL };
 
    if (k > t->x) {
        pair<node *, node*> res = split(t->right, k);
        t->right = res.first;
        update(t);
        return { t, res.second };
    }
    else {
        pair<node *, node*> res = split(t->left, k);
        t->left = res.second;
        update(t);
        return { res.first, t };
    }
}
 
node* merge(node* &t1, node* &t2) {
    if (t1 == NULL) {
        update(t2);
        return t2;
    }
    if (t2 == NULL) {
        update(t1);
        return t1;
    }
 
    if ((t1->y) > (t2->y)) {
        t1->right = merge(t1->right, t2);
        update(t1);
        return t1;
    }
    t2->left = merge(t1, t2->left);
    update(t2);
    return t2;
}
 
void insert(node* &t, node* x) {
    if (used[x->x])
        return;
    used[x->x] = true;
    pair<node*, node*> tmp = split(t, x->x);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    left = merge(left, x);
    t = merge(left, right);
}
 
long long sum(node* &t, long long l, long long r) {
    pair<node*, node*> tmp = split(t, l);
    node* left = tmp.first;
 
    tmp = split(tmp.second, r + 1);
    node* centre = tmp.first;
    node* right = tmp.second;
 
    long long sum = 0;
    if (centre != NULL)
        sum = centre->sum;
 
    left = merge(left, centre);
    t = merge(left, right);
    return sum;
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    //  freopen(TASK".in", "r", stdin);
    //  freopen(TASK".out", "w", stdout);
#endif // _DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    char s;
    srand(time(0));
    node* t = NULL;
    long long n;
    cin >> n;
    long long res;
    char p = ' ';
    for(int i = 0; i < n; i++) {
        cin >> s;
        if (s == '+') {
            long long x;
            cin >> x;
 
            if (p == '?')
                x = (x + res) % (long long)1e9;
 
            insert(t, new node(x));
            p = '+';
        }
        if (s == '?') {
            long long l, r;
            cin >> l >> r;
            res = sum(t, l, r);
            cout << res << endl;
            p = '?';
        }
    }
    return 0;
}