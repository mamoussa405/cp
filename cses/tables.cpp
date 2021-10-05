#include <bits/stdc++.h>
using namespace std;

int next_one(int i, string & s)
{
    for(int j = i + 1; j < s.size(); ++j)
    {
        if (s[j] == '1')
            return j;
    }
    return 0;
}

int prv_one(int i, string & s)
{
    for(int j = j - 1; j >= 0; --j)
    {
        if (s[j] == '1')
            return j;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k,ans=0;
        string s;
        cin >> n >> k >> s;
        for (size_t i = 0; i < s.size(); ++i)
        {
            int nex_one = next_one(i,s);
            int pr_one = prv_one(i,s);
            if (!nex_one && !pr_one)
            {
                s[i] = '1';
                ans++;
            }
            else if ((abs((int)(i-nex_one)) > k) && (abs((int)(i-pr_one)) > k))
            {
                s[i] = '1';
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
