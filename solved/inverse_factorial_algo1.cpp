#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	size_t n, fac = 1;
	cin>>n;
	if (n == 1)
	{
		std::cout << 1 << std::endl;
		return 0;
	}
	for(size_t i  = 2; i <= n; ++i)
	{
		fac *= i;
		if (fac == n)
		{
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << -1 << std::endl;	
	return 0;
}