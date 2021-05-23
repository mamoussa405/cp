// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
    int vm,tmp_ans,n = 3;
    vector<int> v,ans;
    while (n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>vm;
    for (size_t i = 0; i < v.size(); ++i)
    {
        tmp_ans = max(v[i],vm);
        if ((v[i] <= tmp_ans) && ((2*v[i]) >= tmp_ans))
            ans.push_back(tmp_ans);
    }
    if (ans.size() != 3)
        cout << -1 << '\n';
    else
    {
        for (size_t i = 0; i < ans.size(); ++i)
            cout << ans[i] << '\n';
    }
    return 0;
}