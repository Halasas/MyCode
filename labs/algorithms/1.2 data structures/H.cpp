#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>  
#include <queue>  
 
#pragma warning(disable: 4996)
 
using namespace std;
 
queue<int> que;
 
void refresh(int t)
{
    while (!que.empty() && t >= que.front()) {
        que.pop();
    }
}
 
void print_time(int t){
    cout << t / 60 << " " << t - (t / 60) * 60 << endl;
}
 
int main()
{
    freopen("saloon.in", "r", stdin);
    freopen("saloon.out", "w", stdout);
    int n;
    int next_free = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, m, r;
        cin >> h >> m >> r;
        int t = h * 60 + m;
        refresh(t);
        if (que.empty())
            next_free = t + 20, que.push(next_free), print_time(next_free);
        else if (r >= que.size())
        {
            next_free += 20;
            print_time(next_free);
            que.push(next_free);
        }
        else print_time(t);
    }
    return 0;
}