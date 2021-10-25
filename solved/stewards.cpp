#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    long long min_num = 0, max_num = 0;
    vector<int> v;
    cin>>n;
    while (n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    if (v.size() == 1)
    {
        cout<<0<<"\n";
        return 0;
    }
    sort(v.begin(), v.end());
    auto it1 = lower_bound(v.begin(), v.end(), v[0]);
    auto it2 = upper_bound(v.begin(), v.end(), v[0]);
    auto it3 = lower_bound(v.begin(), v.end(), v[v.size() - 1]);
    auto it4 = upper_bound(v.begin(), v.end(), v[v.size() - 1]);
    min_num = it2 - it1;
    max_num = it4 - it3; 
    if (min_num + max_num > v.size())
    {
        cout<<0<<"\n";
        return 0;
    }
    cout<<v.size() - (min_num + max_num)<<"\n";
    return 0;
}