#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool is_gyme = false, is_context = false;
	int n, ans = 0;
	cin >> n;
	std::vector<int> v(n);
	for(auto &x:v)
		cin >> x;

	for (auto x:v)	
	{
		if ((x == 0) || (x == 2 && is_gyme) || (x == 1  && is_context))
			++ans;
		if ((x == 2 || x == 3) && !is_gyme)
		{
			is_gyme = true;
			is_context = false;
		}
		else if ((x == 1 || x == 3) && !is_context)
		{
			is_gyme = false;
			is_context = true;
		}
	}
	std::cout << ans << '\n';
	return 0;
}