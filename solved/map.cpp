#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> v{3,4,5,6};
    sort(v.begin(), v.end());
    if (lower_bound(v.begin(), v.end(), 8) != v.end())
        cout << "yes\n";
    return 0;
}