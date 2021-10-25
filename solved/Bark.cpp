#include <bits/stdc++.h>
using namespace std;

string  solve(vector<string> const& strings, string const& pass)
{
    for (size_t i = 0; i < strings.size(); i++)
    {
        if (strings[i] == pass)
            return "YES\n";
        if (strings[i][0] == pass[1])
            for (size_t j = 0; j < strings.size(); j++)
            {
                if (strings[j][1] == pass[0])
                    return "YES\n";
            }
    }
    return "NO\n";
}

int main(void)
{
    string pass;
    int n;
    vector<string> strings;
    cin>>pass>>n;
    while (n--)
    {
        string s;
        cin>>s;
        strings.push_back(s);
    }
    cout << solve(strings, pass);
    return 0;
}