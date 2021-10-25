#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		string s,a;
		cin >> s;
		char _min = s[0];
		char _c = s[0];
		for(auto x:s)
			_c = min(_c, x);
		a.push_back(_c);
		s.erase(s.begin() + s.find(_c));
		cout << a << " " << s << '\n';
	}
	return 0;	
}