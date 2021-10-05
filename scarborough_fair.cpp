#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,l,r;
    string s;
    char c1,c2;
    cin>>n>>m>>s;
    while (m--)
    {
        cin>>l>>r>>c1>>c2;
        for (size_t i = l-1; i < r; ++i)
        {
            if (s[i] == c1)
                s[i] = c2;
        }
    }
    cout << s << '\n';
    return 0;
}