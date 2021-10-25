#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    string s;
    cin>>n>>s;
    int x = 0, y = 0, ans = 0;
    vector<pair<int,int>> gates;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'U')
            y++;
        if (s[i] == 'R')
            x++;
        gates.push_back(make_pair(x,y));
    }
    for(int i = 1; i < gates.size() - 1; ++i)
    {
        if (gates[i].first == gates[i].second)
        {
            if ((gates[i-1].first == gates[i].first && gates[i].first == gates[i+1].first) ||
            (gates[i-1].second == gates[i].second && gates[i].second == gates[i+1].second))
                ans++;
        }
    }
    cout << ans << endl;
    return 0; 
}