#include "std++.h"
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int ans = 1;
    for(int i = 0, j = 0; i < t.size(); ++i)
    {
        if (t[i] == s[j])
        {
            ans++;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}