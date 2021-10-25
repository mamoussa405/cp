// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
    int n,S_num=0,F_num=0;
    string s;
    cin>>n>>s;
    for (size_t i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == 'S' && s[i+1] == 'F')
            S_num++;
        else if (s[i] == 'F' && s[i+1] == 'S')
            F_num++;
    }
    if (S_num > F_num) 
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}