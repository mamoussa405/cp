#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    int ans = 0;
    cin >> s;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'Q')
        {
            for(size_t j = i + 1; j < s.size(); ++j)
            {
                if (s[j] == 'A')
                {
                    for (size_t k = j + 1; k < s.size(); ++k)
                    {
                        if (s[k] == 'Q')
                            ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}