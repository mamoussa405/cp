#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream cin("cowsignal.in");
    ofstream cout("cowsignal.out");
    vector<string> v;
    int M,N,K;
    cin >> M >> N >> K;
    while (M--)
    {
        string s,tmp;
        cin >> tmp;
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < K; ++j)
                s += tmp[i];
        }
        for (size_t i = 0; i < K; ++i)
            cout << s << '\n';
    }
    return 0;
}