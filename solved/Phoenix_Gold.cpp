// #include <bits/stdc++.h>
#include "std++.h"

using namespace std;

bool   solve(vector<int>& v, int x) 
{
    long long sum = 0;
    for(size_t i = 0; i < v.size(); ++i)
    {
        sum += v[i];
        if (sum > x)
            return 1;
        else if (sum == x && (*max_element(v.begin() + i, v.end()) == v[i]))
            return 0;
        else
        {
            sum -= v[i];
            swap(v[i], v[max_element(v.begin() + i, v.end()) - v.begin()]);
            sum += v[i];
            if (sum > x)
                return 1;
            else if (sum == x && (*max_element(v.begin() + i, v.end()) == v[i]))
                return 0;
        }
    }
    if (sum < x)
        return 1;
    return 0;
}

int main(void)
{
    int t;
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        int n,x,num;
        vector<int> v;
        cin>>n>>x;
        while (n--)
        {
            cin >> num;
            v.push_back(num);
        }
        bool res = solve(v,x);
        if (res)
        {
            cout << "YES\n";
            for (size_t i = 0; i < v.size(); ++i)
                cout << v[i] << ' ';
            cout << '\n';
        }
        else
            cout << "NO\n";
    }
    return 0;
}