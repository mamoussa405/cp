// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

void solve(vector<int>& v)
{
    int spec = 3;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (spec == 3)
        {
            if (v[i] == 3)
            {
                cout << "NO\n";
                return;
            }
            spec = (v[i] == 1) ? 2:1;
        }
        else if (spec == 2)
        {
            if (v[i] == 2)
            {
                cout << "NO\n";
                return;
            }
            spec = (v[i] == 1) ? 3:1;

        }
        else if (spec == 1)
        {
            if (v[i] == 1)
            {
                cout << "NO\n";
                return;
            }
            spec = (v[i] == 2) ? 3:2;
        }
    }
    cout << "YES\n";
}
int main(void)
{
    int n;
    vector<int> v;
    cin>>n;
    while (n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    solve(v);
    return 0; 
}