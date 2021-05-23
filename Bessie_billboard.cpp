#include <bits/stdc++.h>
// #include "std++.h"
using namespace std;

struct rec
{
    int x1,x2,y1,y2,area;
    void cal_area(void)
    {
        this->area = (this->x2 - this->x1) * (this->y2 - this->y1);
    }
};
int main(void)
{
    rec l,f;

    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
    cin >> f.x1 >> f.y1 >> f.x2 >> f.y2;
    l.cal_area();
    if (((f.x1 <= l.x1) && (f.y1 <= l.y1) && (f.y2 >= l.y2)) && 
    (f.x2 >= l.x2))
        cout << 0 << '\n';
    else
    {
        if ((f.y2 < l.y2 && f.y1 > l.y1) || (f.x2 < l.x2 && f.x1 > l.x1))
            cout << l.area << '\n';
        else if ((f.y2 >= l.y2) && (f.y1 <= l.y1))
        {
            cout << l.area - ((l.y2 - l.y1) * (max(0, min(l.x2, f.x2) - 
            max(f.x1, l.x1)))) << '\n';
        } 
        else if ((f.x2 >= l.x2) && (f.x1 <= l.x1))
        {
            cout << l.area - ((l.x2 - l.x1) * (max(0, min(l.y2, f.y2)
            - max(l.y1, f.y1)))) << '\n';
        }
        else
            cout << l.area << '\n';
    }
    return 0;
}
