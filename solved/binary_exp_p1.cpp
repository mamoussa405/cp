#include <bits/stdc++.h>
using namespace std;

int bexp(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n&1)
            res *= x;
        x *= x;
        n >>= 1;
    }
    return res; 
}
int main(void)
{
    int x,n,m;
    cin >> x >> n >> m;
    int res = bexp(x,n);
    cout << res % m << endl;
    return 0;
}