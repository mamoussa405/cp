#include <bits/stdc++.h>
// #include "std++.h"
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n,m,ans = 0;
    array<int , 100> arr{};
    ifstream cin("speeding.in");
    ofstream cout("speeding.out");
    cin >> n >> m;
    int i = 0;
    while (n--)
    {
        int len, speed;
        cin >> len >> speed;
        for (size_t j = 0; j < len; j++)
            arr[i++]  = speed;
    }
    i = 0;
    while (m--)
    {
        int len, speed;
        cin >> len >> speed;
        for(int j = 0; j < len; ++j)
            ans = max(ans, speed - arr[i++]);
    }
    cout << ans << endl;
    return 0; 
}
