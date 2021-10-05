#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string res = "hello|world",s;
    stringstream ss(res);
    while (getline(ss, s, '|'))
    {
        cout << s << endl;
    }
    
    return 0;
}