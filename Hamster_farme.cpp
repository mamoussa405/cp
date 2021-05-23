// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;
typedef long long ll;
int main(void)
{
    ll N,k,kind = 0, num = 0, min_mod, mod;
    cin >> N >> k;
    vector<ll> v;
    while (k--)
    {
        ll num;
        cin >> num;
        v.push_back(num);
    }
    min_mod = v[0];
    for (size_t i = 0; i < v.size(); ++i)
    {
        mod = N%v[i];
        if (mod < min_mod)
        {
            kind = i + 1;
            num = N/v[i];
            min_mod = mod;
        }
    }
    cout << kind << " " << num << '\n';
    return 0;
}