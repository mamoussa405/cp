#include "std++.h"

using namespace std;
typedef long long ll;
int main(void)
{
	int n, j = 0, k = 0;
	ll ans = 0;
	cin>>n;
	if (!n)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		ans += log(i);
	}
	cout<<exp(ans)<<endl;
	return 0;
}
						
