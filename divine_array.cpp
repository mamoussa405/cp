#include <bits/stdc++.h>

using namespace std;

size_t count(vector<int>& tmp, int& x)
{
	size_t ans(0);
	for(auto y:tmp)
		if (y == x)
			++ans;
	return ans;
}
int main(void)
{
	ifstream cin("input.in");
	int t;
	cin >> t;
	vector<int> ans;
	while (t--)
	{
		int n,q;
		cin >> n;
		vector<int> v(n);
		for(auto& x:v)
			cin >> x;
		cin >> q;
		for(size_t j = 0; j < q; ++j)
		{
			int i,k;
			cin >> i >> k;
			vector<int> tmp(v.begin(), v.end());
			for(size_t j = 0; j < 3; ++j)
			{
				for(auto& x:tmp)
					x = count(tmp, x);
				if (j == k)
					break;
			}
			ans.push_back(tmp[i - 1]);
		}
	}
	for(auto x:ans)
		cout << x << '\n';
	return 0;	
}