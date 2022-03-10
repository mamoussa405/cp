#include <bits/stdc++.h>
// #include "std++.h"
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, one_count(0), zero_count(0);
		cin >> n;
		vector<int> v(n);
		for(auto &x:v)
		{
			cin>>x;
			if (x == 1)
				++one_count;
			else if (x == 0)
				++zero_count;
		}
		cout << one_count * (long long)pow((long long)2, (long long)zero_count) << endl;
	}
	return 0;
}