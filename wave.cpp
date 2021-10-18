// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

int main(void)
{
	ifstream cin("wave.in");
	int T;
	cin >> T;
	while (T--)
	{
		int ans(1);
		int count(1);
		string s;
		cin >> s;
		if (s.size() == 1)
			cout << 1 << endl;
		else
		{
			for(size_t i = 0; i < s.size() - 1; ++i)
			{
				if (s[i] != s[i+1])	
				{
					++count;
					ans = max(count, ans);
				}
				else
					count = 1;
			}
			cout << ans << endl;
		}
	}
	return 0;
}