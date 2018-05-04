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
 
#define TASK ""
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend() 
 
struct node {
    int x, y, size;
    node* left;
    node* right;
    bool exists_null;
 
    node(int x) {
        this->x = x;
        this->y = rand();
        this->size = 1;
        this->left = NULL;
        this->right = NULL;
        this->exists_null = (x == 0? 1: 0);
    }
};
 
int max_ind = -1;
 
int size_of(node* v) {
    if (v != NULL)
        return v->size;
    return 0;
}
 
bool exists_in(node* v) {
    if (v != NULL)
        return v->exists_null;
    return 0;
}
 
void update(node* t) {
    t->size = size_of(t->left) + size_of(t->right) + 1;
    t->exists_null = exists_in(t->left) + exists_in(t->right) + (t->x == 0 ? 1 : 0);
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
 
pair<node*, node*> split(node* &t, int k) {
    if (t == NULL)
        return { NULL, NULL };
    int l = size_of(t->left);
    if (l >= k) {
        pair<node *, node*> res = split(t->left, k);
        t->left = res.second;
        update(t);
        return { res.first, t };
    }
    else {
        pair<node *, node*> res = split(t->right, k - l - 1);
        t->right = res.first;
        update(t);
        return { t, res.second };
    }
}
 
void insert(node* &t, node* x, int k) {
    pair<node*, node*> tmp = split(t, k);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    left = merge(left, x);
 
    t = merge(left, right);
}
 
void remove(node* &t, int k) {
    pair<node*, node*> tm1 = split(t, k + 1);
    node* right = tm1.second;
 
    pair<node*, node*> tm2 = split(tm1.first, k);
    node* left = tm2.first;
 
    t = merge(left, right);
}
 
int find_mex(node* &t, int k) {
    pair<node*, node*> tm1 = split(t, k);
    node* v = tm1.second;
    int ans = tm1.first->size;
     
    while (true) {
        if (exists_in(v->left))
            v = v->left;
        else {
            ans += size_of(v->left);
            if (v->x != 0)
                ans++, v = v->right;
            else
                break;
        }
    }
 
    t = merge(tm1.first, tm1.second);
    return ans;
}
 
void insert(node* &t, int ind, int x) {
    int mex = find_mex(t, ind);
    remove(t, mex);
    max_ind = max(max_ind, mex);
    insert(t, new node(x), ind);
}
 
void print_tree(node* &t) {
    if (t == NULL)
        return;
    print_tree(t->left);
    cout << t->x << " ";
    print_tree(t->right);
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif // _DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    node* t = NULL;
    insert(t, new node(0), 0);
    for (int i = 1; i <= 300001; i++)
        insert(t, new node(0), i);
 
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        insert(t, l, i);
    }
    pair<node*, node*> tmp1 = split(t, max_ind + 1);
    pair<node*, node*> tmp2 = split(tmp1.first, 1);
    cout << max_ind << endl;
    print_tree(tmp2.second);
    return 0;
}