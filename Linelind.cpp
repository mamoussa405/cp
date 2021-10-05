#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(void){
    int n;
    vector<int> c;
    int mid;

    cin>>n;
    while (n--)
    {
        int num;
        cin>>num;
        c.push_back(num);
    }
    mid = c.size() - 1;
    for (int i = 0; i < c.size(); ++i)
    {
        ll _min = 1e18, _max = 0;
        _max = max((ll)abs(c[i] - c[mid]), (ll)abs(c[i] - c[0]));
        if (i + 1 <= mid)
            _min = abs(c[i] - c[i+1]);
        if (i - 1 >= 0)
            _min = min(_min , (ll)abs(c[i] - c[i-1]));
       cout<<_min<<" "<<_max<<"\n";
    }
   return 0; 
}