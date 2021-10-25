// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
    int n,k,c_num = 0, ans = 0;
    vector<int> v;
    cin >> n >> k;
    while (n--)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] > 8)
        {
            c_num += 8;
            if (i+1 < v.size())
                v[i+1] += v[i] - 8;
        }
        else
            c_num += v[i];
        ans++;
        if (c_num >= k)
        {
            cout << ans << '\n';
            break;
        }
    }
    if (c_num < k) 
        cout << -1 << '\n';
    return 0;
}