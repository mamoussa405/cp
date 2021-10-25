#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, max = 0, res = 0, ans = 0,i = 0;
    vector<int> c;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        c.push_back(num);
    }
    max = accumulate(c.begin(), c.end(), 0);
    sort(c.rbegin(), c.rend());
    while (res <= (max / 2))
    {
        res += c[i++];
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}