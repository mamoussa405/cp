#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

ll fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	ll ans(1);
	for(ll i = 2; i <= n; ++i)
		ans = ((ans % MOD) * (i % MOD)) % MOD;
	return ans;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << fac(2*n) << std::endl;
	}
	return 0;	
}