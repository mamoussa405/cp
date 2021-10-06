#include <bits/stdc++.h>

using namespace std;


int arr[100];

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (arr[n])
		return arr[n];
	arr[n] = fib(n - 1) + fib(n - 2);
	return arr[n];
}
int main(void)
{
	int n;
	cin>>n;
	std::cout << fib(n) << std::endl;
	return 0;
}
// 0 1 1 2 3 5 8 13 21 34 55 89 144