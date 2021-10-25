#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d;
    int ans1 = 0,ans2 = 0;
    ifstream in("paint.in");
    ofstream out("paint.out");
    in>>a>>b>>c>>d;
    if (c > a && d < b)
        ans1 = b - a;
    else if ( a > c && b < d)
        ans1 = d - c;
    else if (a < c)
    {
        if (b > c) 
            b = c;
        ans1 = b - a;
        ans2 = d - c;
    }
    else if (c < a)
    {
        if (d > a)
            d = a;
        ans1 = d - c;
        ans2 = b - a;
    }
    else
        ans1 = (b > d) ? b - a: d - a;
    out << ans1 + ans2 << '\n';
    return 0;
}
