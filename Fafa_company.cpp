// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
    int n,ans=0;
    cin>>n;
    for (size_t i = 1; i < n; ++i)
    {
        if (!(n%i))
            ans++;
    }
    cout << ans << '\n';
    return 0;
}