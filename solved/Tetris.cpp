#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,_min = 1e3+1;
    vector<int> v;
    cin>>n>>m;
    while (m--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (size_t i = 1; i <= n; ++i)
    {
        auto it = equal_range(v.begin(), v.end(), i);
        int num;
        num = it.second - it.first;
        _min = min(_min, num);
    }
    if (!_min)
        cout << 1 << '\n';
    else
        cout << _min << '\n';
    return 0;
}