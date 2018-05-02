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
    node* prev;
 
    node(int x, int y) {
        this->x = x;
        this->y = y;
        this->size = 1;
        this->prev = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    node(int x) {
        this->x = x;
        this->y = rand();
        this->size = 1;
        this->prev = NULL;
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
    if (l >= k) {
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
 
void insert(node* &t, node* x, int k) {
    pair<node*, node*> tmp = split_k(t, k);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    left = merge(left, x);
 
    t = merge(left, right);
}
 
 
void move_to_head(node* &t, int l, int r) {
    pair<node*, node*> tmp2 = split_k(t, r + 1);
    pair<node*, node*> tmp1 = split_k(tmp2.first, l);
    node* right = tmp2.second;
    node* centre = tmp1.second;
    node* left = tmp1.first;
    left = merge(centre, left);
    t = merge(left, right);
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
    //  freopen(TASK".in", "r", stdin);
    //  freopen(TASK".out", "w", stdout);
#endif // _DEBUG
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    node* t = NULL;
    for (int i = 0; i < n; i++)
        insert(t, new node(i + 1), i);
    cout << endl;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        move_to_head(t, l, r);
    }
    print_tree(t);
    return 0;
}