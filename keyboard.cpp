#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string key = "qwertyuiopasdfghjkl;zxcvbnm,./", s;
    char sh_type;
    int index;
    cin>>sh_type>>s;
    if(sh_type == 'L')
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            index = key.find(s[i]);
            cout<<key[index + 1];
        }
        cout<<endl; 
    }
    else
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            index = key.find(s[i]);
            cout<<key[index - 1];
        }
        cout<<endl; 
    }
    return 0;
}