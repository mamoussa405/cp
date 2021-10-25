#include <bits/stdc++.h>
// #include "std++.h"
using namespace std;

struct rec
{
    int x1,x2,y1,y2;
};

int main(void)
{
    int ans;
    rec r1,r2,s;
    ifstream cin("square.in");
    ofstream cout("square.out");
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    s.x2 = max(r1.x2, r2.x2);
    s.y2 = max(r1.y2, r2.y2);
    s.x1 = min(r1.x1, r2.x1);
    s.y1 = min(r1.y1, r2.y1);
    ans = max(s.x2 - s.x1, s.y2 - s.y1);
    cout << ans * ans;
    return 0;
}