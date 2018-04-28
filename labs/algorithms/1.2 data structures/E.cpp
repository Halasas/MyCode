#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
 
#pragma warning(disable: 4996)
 
using namespace std;
 
int count;
 
struct one_set {
    int parent;
    int size;
    int min;
    int max;
    one_set() {
        parent = NULL;
        min = NULL;
        max = NULL;
        size = NULL;
    }
};
 
vector<one_set> dsu(1000000);
 
int find(int a)
{
    if (dsu[a].parent == a)
        return a;
    return dsu[a].parent = find(dsu[a].parent);
}
 
void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (dsu[b].size > dsu[a].size)
        swap(a, b);
    dsu[b].parent = a;
    dsu[a].size += dsu[b].size;
    dsu[a].max = max(dsu[a].max, dsu[b].max);
    dsu[a].min = min(dsu[a].min, dsu[b].min);   
}
 
int main()
{
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dsu[i].parent = i;
        dsu[i].max = i;
        dsu[i].min = i;
        dsu[i].size = 1;
    }
    string op;
    while (cin >> op)
    {
        if (op == "get")
        {
            int a;
            scanf("%d",&a);
            a = find(a);
            printf("%d %d %d \n", dsu[a].min, dsu[a].max, dsu[a].size);
            continue;
        }
        if (op == "union")
        {
            int a, b;
            scanf("%d %d", &a, &b);
            union_set(a, b);
        }
    }
    return 0;
}