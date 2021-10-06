#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s, s1;
	cin >> s;
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			cout << "NO\n";
			return 0;
		}
		i++;
		j--;
	}
	cout << "YES\n";
	return 0;
}