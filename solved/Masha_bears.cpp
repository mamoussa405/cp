#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int v1,v2,v3,vm;
    cin>>v1>>v2>>v3>>vm;
    if ((v1 < vm) || (v2 < vm) || (v3 < vm))
        cout << "-1\n";
    else
        cout << v1 << '\n' << v2 << '\n' << v3 << '\n';
    return 0;
}