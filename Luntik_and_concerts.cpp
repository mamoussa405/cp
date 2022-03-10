#include <bits/stdc++.h>
// #include "std++.h"

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int sum = 0;
		sum += a;
		sum += b * 2;
		sum += c * 3;
		if (sum % 2)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}