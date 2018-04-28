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
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    string in;
    string buff;
    cin >> in;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '(' || in[i] == '{' || in[i] == '[') {
            buff.push_back(in[i]); continue;}
        if (buff.back() == '(' && in[i] == ')') {
            buff.pop_back(); continue;}
        if (buff.back() == '{' && in[i] == '}') {
            buff.pop_back(); continue;}
        if (buff.back() == '[' && in[i] == ']') {
            buff.pop_back(); continue;}
        cout << "NO";
        return 0;
    }
    if (buff.size() != 0) {
        cout << "NO"; return 0;}
    cout << "YES";
    return 0;
}