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

	node(int x, int y, int ind) {
		this->x = x;
		this->y = y;
		this->ind = ind;
		this->left = NULL;
		this->right = NULL;
	}
};

node* merge(node* &t1, node* &t2) {
	if (t1 == NULL)
		return t2;

	if (t2 == NULL)
		return t1;

	if ((t1->y) < (t2->y)) {
		t1->right = merge(t1->right, t2);
		return t1;
	}

	else {
		t2->left = merge(t1, t2->left);
		return t2;
	}
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

	t = merge(merge(left, x), right);
}



void remove(node* &t, int x) {
	pair<node*, node*> tm1 = split(t, x);
	node* left = tm1.first;

	pair<node*, node*> tm2 = split(tm1.second, x + 1);
	node* right = tm2.second;

	t = merge(left, right);
}

node* find(node* t, int k) {
	node* v = t;
	int x = v->x;
	while (x != k || v != NULL) {
		if (k < x)
			v = v->left;
		if (x < k)
			v = v->right;
	}
	return v;
}

node* next(node* t, int k) {
	pair<node*, node*> tm1 = split(t, k + 1);
	node* left = tm1.first;
	node* right = tm1.second;

	node* v = right;
	while (v->left != NULL)
		v = v->left;

	return v;
}

node* prev(node* t, int k) {
	pair<node*, node*> tm1 = split(t, k);
	node* left = tm1.first;
	node* right = tm1.second;

	node* v = left;
	while (v->right != NULL)
		v = v->right;

	t = merge(left, right);
	return v;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}