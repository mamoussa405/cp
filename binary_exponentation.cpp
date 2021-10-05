#include <bits/stdc++.h>
using namespace std;

int expo(int a, int n)
{
    if (n == 0)
        return 1;
    int res = expo(a, n/2);
    if (n%2)
        return res * res * a;
    return res * res;
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout << expo(a, n) << endl;
    return 0;
}