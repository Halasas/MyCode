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
    int x, y, size;
    node* left;
    node* right;
 
    node(int x, int y) {
        this->x = x;
        this->y = y;
        this->size = 1;
        this->left = NULL;
        this->right = NULL;
    }
    node(int x) {
        this->x = x;
        this->y = rand();
        this->size = 1;
        this->left = NULL;
        this->right = NULL;
    }
};
 
int size_of(node* v) {
    if (v != NULL)
        return v->size;
    else
        return 0;
}
 
void update(node* t) {
 
    t->size = size_of(t->left) + size_of(t->right) + 1;
}
 
node* merge(node* &t1, node* &t2) {
    if (t1 == t2 && t1 == NULL)
        return NULL;
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
 
pair<node*, node*> split_k(node* &t, int k) {
    if (t == NULL)
        return { NULL, NULL };
    int l = size_of(t->left);
    if (l > k) {
        pair<node *, node*> res = split_k(t->left, k);
        t->left = res.second;
        update(t);
        return { res.first, t };
    }
    else {
        pair<node *, node*> res = split_k(t->right, k - l - 1);
        t->right = res.first;
        update(t);
        return { t, res.second };
    }
}
 
pair<node*, node*> split_x(node* &t, int x) {
    if (t == NULL)
        return { NULL, NULL };
 
    if (x < t->x) {
        pair<node *, node*> res = split_x(t->right, x);
        t->right = res.first;
        update(t);
        return { t, res.second };
    }
 
    else {
        pair<node *, node*> res = split_x(t->left, x);
        t->left = res.second;
        update(t);
        return { res.first, t };
    }
}
 
void insert(node* &t, node* x) {
    pair<node*, node*> tmp = split_x(t, x->x);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    left = merge(left, x);
 
    t = merge(left, right);
}
 
void remove(node* &t, int x) {
    pair<node*, node*> tm1 = split_x(t, x);
    node* left = tm1.first;
 
    pair<node*, node*> tm2 = split_x(tm1.second, x - 1);
    node* right = tm2.second;
 
    t = merge(left, right);
}
 
int get_kth_max(node* &t, int k) {
    pair<node*, node*> tmp = split_k(t, k - 1);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    node* v = right;
    while (v != NULL && v->left != NULL)
        v = v->left;
 
    t = merge(left, right);
    return v->x;
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
    int n;
    cin >> n;
    node *t = NULL;
    for (int i = 0; i < n; i++) {
        int type, k;
        cin >> type >> k;
        if(type == -1)
            remove(t, k);
        if (type == 0)
            cout << get_kth_max(t, k - 1) << endl;
        if (type == 1)
            insert(t, new node(k));
    }
    return 0;
}