#include "std++.h"
#include <cmath>
using namespace std;

int main()
{
    int y,w;
    cin>>y>>w;
    y = max(y,w);
    y = 6 - y + 1;
    int g = gcd(6, y);
    cout<<y/g<<"/"<<6/g<<endl;
    return 0;
}