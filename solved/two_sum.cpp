#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(auto &x:v)
		cin>>x;
	sort(v.begin(), v.end());
	for(auto x:v)
		if (binary_search(v.begin(), v.end(), k - x) && (k - x) != x)
		{
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}