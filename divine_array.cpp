#include <bits/stdc++.h>
// #include "std++.h"

using namespace std;

size_t count(vector<int>& v, int& x)
{
	size_t ans(0);
	for(auto y:v)
		if (y == x)
			++ans;
	return ans;
}
int main(void)
{
	// ifstream cin("input.in");
	int t;
	cin >> t;
	while (t--)
	{
		int n,q;
		cin >> n;
		vector<int> v(n);
		vector<int> tmp;
		for(auto& x:v)
		{
			cin >> x;
			tmp.push_back(x);
		}
		cin >> q;
		for(size_t j = 0; j < q; ++j)
		{
			int i,k;
			cin >> i >> k;
			if (k == 0)
			{
				cout << v[i - 1] << '\n';
				continue;
			}
			for(size_t x = 1; x <= n; ++x)
			{
				for(auto& y:tmp)
					y = count(v, y);
				v.assign(tmp.begin(), tmp.end());
				if (x == k)
				{
					cout << v[i - 1] << '\n';
					break;
				}
			}
			if (k > n)
				cout << v[i - 1] << '\n';
		}
	}
	return 0;	
}