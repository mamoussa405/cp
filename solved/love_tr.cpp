// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;


void    solve(vector<int>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[v[v[i]-1]-1] == i+1)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(void)
{
    int n;
    vector<int> v;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    solve(v);
    return 0; 
}