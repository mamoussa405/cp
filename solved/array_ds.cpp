#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> v{1,2,3};
    auto it = find(v.begin() + 1, v.end(), 2);
    cout << *it << endl;
    if (it != v.end())
        *it = -1;
    for(auto x:v)
        cout << x << " ";
    cout << endl;
    return 0;
}