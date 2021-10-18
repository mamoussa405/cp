#include <bits/stdc++.h>
// #include "std++.h"
using namespace std;

int main(void)
{
	ifstream cin("min.in");
	int n;
	int ans = INT_MAX;
	cin >> n;
	vector<int> v(n);
	for(auto& x:v)
		cin >> x;
	sort(v.begin(), v.end());
	int j = 0;
	while (j <= v.size() - (n / 2))
	{
		ans = min(ans, abs(v[j] - v[(j + n/2) - 1]));
		j++;
	}
	cout << ans << endl;
	return 0;
}