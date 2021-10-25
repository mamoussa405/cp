#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m;
    vector<string> v;
    cin>>n>>m;
    while (n--)
    {
        string s,tmp;
        cin>>s;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'b')
                tmp.push_back(s[i]);
        }
        if (!tmp.empty())
            v.push_back(tmp);
        tmp.clear();
    }
    if (!v.empty() && (v.size() > v[0].size()))
    return 0; 
}