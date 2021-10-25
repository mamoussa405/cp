#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ifstream cin("shell.in");
    ofstream cout("shell.out");
    int n, loop = 3, ans = 0, ans_for_case = 0;
    vector<array<int, 3>> v;
    array<char, 3> t{'p', 'e', 'e'};
    cin >> n;
    while (n--)
    {
        array<int, 3> arr;
        cin >> arr[0]  >> arr[1] >> arr[2];
        v.push_back(arr);
    }
    while (loop--)
    {
        ans_for_case = 0;
        for(auto x:v)
        {
            swap(t[x[0] - 1], t[x[1] - 1]);
            if (t[x[2] - 1] == 'p')
                ans_for_case++;
        }
        ans = max(ans, ans_for_case);
        if (loop == 2)
            t = {'e', 'p', 'e'};
        else
            t = {'e', 'e', 'p'};
    }
    cout << ans; 
    return 0;
}