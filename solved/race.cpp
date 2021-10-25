// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;
int main(void)
{
    float h,m,s,t1,t2,tmp;
    cin >> h>> m >> s >> t1 >> t2;
    tmp = t1;
    t1 = min(t1, t2);
    t2 = max(tmp, t2);
    m += s / 60.0;
    h += m / 60.0;
    m = m/5.0;
    s = s/5.0;
    if ((t1  < h  && h  < t2 ) && (t1 < m && m < t2) && (t1 < s && s < t2))
        cout << "YES\n";
    else if (!(t1  < h  && h  < t2 ) && !(t1 < m && m < t2) && !(t1 < s && s < t2))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}