// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

struct Sheet
{
    int x1,x2,y1,y2;
};
Sheet black1,black2,white;
// bool covred_by_black1(void)
// {
//     if (white.x1 >= black1.x1 && white.y1 <= black1.y1 && 
//     white.x2 <= black1.x2 && white.y2 >= black1.x2)
//         return true;
//     return false;
// }

// bool covred_by_black2(void)
// {
//     if (white.x1 >= black2.x1 && white.y1 <= black2.y1 && 
//     white.x2 <= black2.x2 && white.y2 >= black2.x2)
//         return true;
//     return false;
// }
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;
    if (check_for_x())
        cout << "NO\n";
    else 
        cout << "YES\n";
    return 0;
}