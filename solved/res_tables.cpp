// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
    int n,a,b,ans=0,t_one=0;
    vector<int> v;
    cin>>n>>a>>b;
    while (n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] == 1)
        {
            if (a > 0)
                a--;
            else if (b > 0)
            {
                t_one++;
                b--;
            }
            else if (t_one > 0)
                t_one--;
            else
                ans++;
        }
        else
        {
            if (b > 0)
                b--;
            else
                ans += 2;
        }
    }
    cout << ans << '\n';
    return 0; 
}