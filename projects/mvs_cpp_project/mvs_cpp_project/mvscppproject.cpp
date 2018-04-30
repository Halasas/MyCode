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
	int shift = 0;
	long long x, y, L;
	node* left;
	node* right;

	node(long long x, int L, long long y) {
		this->x = x;
		this->y = y;
		this->L = L;
		this->left = NULL;
		this->right = NULL;
	}
	node(long long x, int L) {
		this->x = x;
		this->y = rand();
		this->L = L;
		this->left = NULL;
		this->right = NULL;
	}
};

vector<bool> used(1e9 + 1);

pair<node*, node*> split(node* &t, long long k) {
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

node* merge(node* &t1, node* &t2) {
	if (t1 == NULL) {
		return t2;
	}
	if (t2 == NULL) {
		return t1;
	}

	if ((t1->y) > (t2->y)) {
		t1->right = merge(t1->right, t2);
		return t1;
	}
	t2->left = merge(t1, t2->left);
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
	//	freopen(TASK".out", "w", stdout);
#endif // _DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	string s;

	srand(time(0));
	node* t = NULL;

	long long n;
	cin >> n;

	for (int i = 0; i < n; i++) {
	}
	return 0;
}