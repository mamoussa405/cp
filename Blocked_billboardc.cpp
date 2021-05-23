// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int x1_b1, y1_b1, x2_b1, y2_b1;
int x1_b2, y1_b2, x2_b2, y2_b2;
int x1_tr, y1_tr, x2_tr, y2_tr;
pair<int,int> area(make_pair(0,0));
void B1first(void)
{
    bool p1=false,p2=false,p3=false,p4=false;
    if ((x1_tr >= x1_b1 && x1_tr <= x2_b1) && (y1_tr >= y1_b1 && y1_tr <= y2_b1)) // check for truck buttom left
    {
        area.first = (x2_b1 - x1_tr)  * (y2_b1 - y1_tr);
        p1 = true;
    }
    if ((x1_tr >= x1_b1 && x1_tr <= x2_b1) && (y2_tr >= y1_b1 && y2_tr <= y2_b1)) // check for truck upper left
    {
        area.first = (x2_b1 - x1_tr) * (y1_tr - y1_b1);
        p2 = true; 
    }
    if ((x2_tr >= x1_b2 && x2_tr <= x2_b2) && (y1_tr >= y1_b2 && y1_tr <= y2_b2)) // check for truck buttom right
    {
        p3 = true;
    }
    if ((x2_tr >= x1_b2 && x2_tr <= x2_b2) && (y2_tr >= y1_b2 && y2_tr <= y2_b2)) // check for truck upper right
    {
        p4 = true;
    }
    if (p1 && p2)
    {

    }
    if (p3 && p4)
    {

    }
}
int main(void)
{
    int b1_arrea, b2_arrea, tr_b1_arrea, tr_b2_arrea;
    ifstream in("billboard.in");
    ofstream out("billboard.out");
    in >> x1_b1 >> y1_b1 >> x2_b1 >> y2_b1;
    in >> x1_b2 >> y1_b2 >> x2_b2 >> y2_b2;
    in >> x1_tr >> y1_tr >> x2_tr >> y2_tr;
    b1_arrea = (x2_b1 - x1_b1) * (y2_b1 - y1_b1);
    b2_arrea = (x2_b2 - x1_b2) * (y2_b2 - y1_b2);
    if (x1_b1 < x1_b2)
    {

    }
    else
    {

    }
}
