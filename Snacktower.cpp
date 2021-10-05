#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    vector<int> s;
    vector<int> tmp;
    cin>>n;
    while (n--)
    {
        int num;
        cin>>num;
        s.push_back(num);
    }
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (*max_element(s.begin(), s.end()) == s[i])
        {
            cout<<s[i];
            s[i] = 0;
            sort(tmp.rbegin(), tmp.rend());
            while (tmp.size() > 0)
            {
                if (*max_element(s.begin(), s.end()) > tmp[0])
                {
                    cout<<"\n";
                    break;
                }
                cout<<" "<<tmp[0];
                tmp.erase(tmp.begin());
            }
            if (!tmp.size())
                cout<<"\n";
        }
        else
        {
            tmp.push_back(s[i]);
            s[i] = 0;
            cout<<"\n";
        }
    }
    return 0; 
}