#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (!(a % b))
		return b;
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a,b);
}
int main(void)
{
	std::cout << lcm(5,7) << std::endl;
	return 0;
}