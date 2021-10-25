// #include<bits/std++.h>
#include "std++.h"
using namespace std;
typedef long long ll;
int main(void)
{
    ll n, k,odd_num,mid,ans;
    cin >> n >> k;
    odd_num = (!(n%2)) ? n/2:(n/2)+1;
    mid = (!(n%2)) ? n/2:(n/2)+1;
    if (k <= mid)
        ans = 1 + ((2*(k-1)));
    else
    {
        k -= odd_num;    
        ans = 2 + ((2*(k-1)));
    }
    cout << ans << '\n';
    return 0;
}