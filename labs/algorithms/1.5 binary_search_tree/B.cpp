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
    int x, y;
    node* left;
    node* right;
 
    node(int x, int y) {
        this->x = x;
        this->y = y;
        this->left = NULL;
        this->right = NULL;
    }
    node(int x) {
        this->x = x;
        this->y = rand();
        this->left = NULL;
        this->right = NULL;
    }
};
 
node* merge(node* &t1, node* &t2) {
    if (t1 == NULL)
        return t2;
 
    if (t2 == NULL)
        return t1;
 
    if ((t1->y) > (t2->y)) {
        t1->right = merge(t1->right, t2);
        return t1;
    }
    t2->left = merge(t1, t2->left);
    return t2;
}
 
pair<node*, node*> split(node* &t, int k) {
    if (t == NULL)
        return { NULL, NULL };
 
    if (k > t->x) {
        pair<node *, node*> res = split(t->right, k);
        t->right = res.first;
        return { t, res.second };
    }
 
    else {
        pair<node *, node*> res = split(t->left, k);
        t->left = res.second;
        return { res.first, t };
    }
}
 
void insert(node* &t, node* x) {
    pair<node*, node*> tmp = split(t, x->x);
 
    node* left = tmp.first;
    node* right = tmp.second;
 
    left = merge(left, x);
 
    t = merge(left, right);
}
 
 
 
void remove(node* &t, int x) {
    pair<node*, node*> tm1 = split(t, x);
    node* left = tm1.first;
 
    pair<node*, node*> tm2 = split(tm1.second, x + 1);
    node* right = tm2.second;
 
    t = merge(left, right);
}
 
node* find(node* &t, int k) {
    node* v = t;
    while ((v != NULL) && ((v->x) != k)) {
        if (k < v->x)
            v = v->left;
        else if (v->x < k)
            v = v->right;
    }
    return v;
}
 
bool exists(node* &t, int k) {
    node* v = find(t, k);
    if (v != NULL)
        return true;
    else
        return false;
}
 
pair<bool, int> next(node* &t, int k) {
    pair<node*, node*> tm1 = split(t, k + 1);
    node* left = tm1.first;
    node* right = tm1.second;
 
    node* v = right;
    while (v != NULL && v->left != NULL)
        v = v->left;
 
    t = merge(left, right);
    if (v != NULL)
        return { true, v->x };
    return { false,0 };
}
 
pair<bool, int> prev(node* &t, int k) {
    pair<node*, node*> tm1 = split(t, k);
    node* left = tm1.first;
    node* right = tm1.second;
 
    node* v = left;
    while (v != NULL && v->right != NULL)
        v = v->right;
 
    t = merge(left, right);
    if (v != NULL)
        return { true, v->x };
    return { false,0 };
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
    string s;
    srand(time(0));
    node* t = NULL;
    while (cin >> s) {
        if (s == "insert") {
            int x;
            cin >> x;
            insert(t, new node(x));
        }
        else if (s == "delete") {
            int x;
            cin >> x;
            remove(t, x);
        }
        else if (s == "exists") {
            int x;
            cin >> x;
            if (exists(t, x))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (s == "next") {
            int k;
            cin >> k;
            pair<bool, int> ans = next(t, k);
            if (ans.first == true)
                cout << ans.second << endl;
            else
                cout << "none" << endl;
        }
        else if (s == "prev") {
            int k;
            cin >> k;
            pair<bool, int> ans = prev(t, k);
            if (ans.first == true)
                cout << ans.second << endl;
            else
                cout << "none" << endl;
        }
    }
    return 0;
}