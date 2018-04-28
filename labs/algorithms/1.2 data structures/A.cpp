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
    freopen("decode.in", "r", stdin);
    freopen("decode.out", "w", stdout);
    string in;
    string out;
    cin >> in;
    for (int i = 0; i < in.size(); i++)
    {
        out.push_back(in[i]);
        if (out.size() > 1 && out[out.size() - 1] == out[out.size() - 2])
            out.pop_back(), out.pop_back();
    }
    cout << out;
    return 0;
}