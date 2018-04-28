#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct node {
    int x, y, ind;
    node* left;
    node* right;
    node* prev;
 
    node(int x, int y, int ind) {
        this->x = x;
        this->y = y;
        this->ind = ind;
        this->left = NULL;
        this->right = NULL;
        this->prev = NULL;
    }
};
 
bool cmp(node* a, node* b) {
    if (a->x <= b->x)
        return true;
    return false;
}
 
node* build_n(vector<node*> &in) {
    node* v = NULL;
    sort(in.begin(), in.end(), cmp);
    for (node* x : in) {
        if (v == NULL) {
            v = x;
            continue;
        }
        if ((v->y) < (x->y)) {
            x->prev = v;
            v->right = x;
            v = x;
            continue;
        }
        bool flag = 0;
        if (v->prev == NULL)
            flag = 1;
        while (flag == 0 && (v->y) > (x->y)) {
            if (v->prev != NULL)
                v = v->prev;
            else
                flag = 1;
        }
        if (flag == 0) {
            x->left = v->right;
            x->left->prev = x;
            v->right = x;
            x->prev = v;
            v = x;
            continue;
        }
        else
        {
            x->left = v;
            v->prev = x;
            v = x;
            continue;
        }
    }
    while (v->prev != NULL)
        v = v->prev;
    return v;
}
 
struct o {
    int prev, left, right;
};
 
vector<o> out;
 
void print_tree(node* t, int prev) {
    if (t == NULL)
        return;
    out[t->ind - 1].prev = prev;
    if (t->left == NULL)
        out[t->ind - 1].left = 0;
    else
        out[t->ind - 1].left = t->left->ind;
 
    if (t->right == NULL)
        out[t->ind - 1].right = 0;
    else
        out[t->ind - 1].right = t->right->ind;
 
    print_tree(t->left, t->ind);
    print_tree(t->right, t->ind);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node*> in;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        node* x = new node(a, b, i + 1);
        in.push_back(x);
    }
    node* t = build_n(in);
    cout << "YES" << endl;
    out.resize(n);
    print_tree(t, 0);
    for (o i : out)
        cout << i.prev << " " << i.left << " " << i.right << endl;
    return 0;
}