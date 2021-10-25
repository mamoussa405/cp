#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
	int n,k;
	cin >> n >> k;
	int rest = 240 - k; // 240 = 4 * 60;
	int sum(0), ans(0);
	for(size_t i = 1; i <= n; ++i)
	{
		sum += (i * 5);
		if (sum <= rest)
			++ans;
	}
	cout << ans << '\n';
	return 0;
}
