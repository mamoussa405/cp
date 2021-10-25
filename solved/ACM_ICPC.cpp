#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v)
{
    for (size_t i = 0; i < v.size(); i++)
        for (size_t j =  i + 1; j < v.size(); j++)
            for (size_t k = j + 1; k < v.size(); k++)
            {
                int sum = 0;
                for (size_t s = 0; s < v.size(); s++)
                {
                    if ((s != i) && (s != j) && (s != k))
                        sum += v[s];
                }
                if (sum == (v[i] + v[j] + v[k]))
                {
                    cout << "YES\n";
                    return;
                }
            }
    cout << "NO\n";
}
int main(void)
{
    vector<int> v;
    int n = 6;
    while (n--)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    solve(v);
    return 0;
}