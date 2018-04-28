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
    freopen("hemoglobin.in", "r", stdin);
    freopen("hemoglobin.out", "w", stdout);
    vector<pair<int, int>> a;
    int m, last_sum = 0;
    scanf("%d", &m);
    a.push_back({ 0,  0 });
    for (int i = 0; i < m; i++) {
        char t;
        scanf("%c", &t);
        scanf("%c", &t);
        if (t == '+') {
            int x;
            cin >> x;
            last_sum = last_sum + x;
            a.push_back({ x,  last_sum });
        }
        if (t == '-') {
            printf("%d \n", a.back().first);
            a.pop_back();
            if (!a.empty())
                last_sum = a.back().second;
            else
                last_sum = 0;
        }
        if (t == '?') {
            int k;
            scanf("%d", &k);
            printf("%d \n", last_sum - a[a.size()-k-1].second);
        }
    }
    return 0;
}