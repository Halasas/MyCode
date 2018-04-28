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
 
int main()
{
    freopen("bureaucracy.in", "r", stdin);
    freopen("bureaucracy.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (m != 0)
    {
        if (q.size() == 0)
            break;
        int k = max(1, (m / (int)q.size()));
        int n = q.size();
        for (int i = 0; i < n; i++) {
            if (m == 0) break;
            if (q.front() > k)
                q.push(q.front() - k);
            m -= min(q.front(), k);
            q.pop();
        }
    }
    if (q.size() == 0){
        cout << -1;
        return 0;
    }
    cout << q.size() << '\n';
    while(!q.empty())
        cout << q.front() << " ", q.pop();
    return 0;
}