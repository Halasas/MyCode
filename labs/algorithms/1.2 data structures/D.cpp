#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
 
#pragma warning(disable: 4996)
 
using namespace std;
 
 
int main()
{
    freopen("stack-min.in", "r", stdin);
    freopen("stack-min.out", "w", stdout);
    vector<pair<int, int>> a;
    int m, last_min = INT_MAX;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            cin >> x;
            last_min = min(last_min, x);
            a.push_back({ x,  last_min});
        }
        if (t == 2) {
            a.pop_back();
            if (!a.empty())
                last_min = a.back().second;
            else
                last_min = INT_MAX;
        }
        if (t == 3)
            printf("%d \n",last_min);
    }
    return 0;
}