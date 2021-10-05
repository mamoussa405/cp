#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1,s2;

    cin>>s1>>s2;
    if (s1 == s2)
        cout<<"-1\n";
    else
        cout<<max(s1.length(), s2.length())<<"\n";
    return 0;
}