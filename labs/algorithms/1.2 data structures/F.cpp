#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
 
#pragma warning(disable: 4996)
 
using namespace std;
struct soldier {
    int left;
    int right;
    soldier() { left = 0; right = 0;}
};
 
vector<soldier> solds;
 
void insert_l(int i, int j){
    int l = solds[j].left;
    solds[l].right = i;
    solds[j].left = i;
    solds[i].right = j;
    solds[i].left = l;
}
 
void insert_r(int i, int j) {
    int r = solds[j].right;
    solds[r].left = i;
    solds[j].right = i;
    solds[i].left = j;
    solds[i].right = r;
}
 
void leave(int i)
{
    int l = solds[i].left;
    int r = solds[i].right;
    solds[l].right = r;
    solds[r].left = l;
    solds[i].left = 0;
    solds[i].right = 0;
}
 
int main()
{
    freopen("formation.in", "r", stdin);
    freopen("formation.out", "w", stdout);
 
    int n, m;
    cin >> n;
    solds.resize(n + 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if(op == "left"){
            int x, y;
            cin >> x >> y;
            insert_l(x, y);
        }
        if (op == "right") {
            int x, y;
            cin >> x >> y;
            insert_r(x, y);
        }
        if (op == "leave") {
            int x;
            cin >> x;
            leave(x);
        }
        if (op == "name") {
            int x;
            cin >> x;
            cout << solds[x].left << " " << solds[x].right << '\n';
        }
    }
    return 0;
}