#include "std++.h"
typedef long long ll;
using namespace std;
ll sum(int n)
{
	return n*(n+1)/2;
}	

ll Sn(int n)
{
	ll ans = 0;
	for(int i = 1; i <= n ; ++i)
		ans += i*i*i;	
	return ans;
}
int main(void)
{
	int n;
	cin >>n;
	ll res1 = sum(n);
	ll res2 = Sn(n);
	cout<<"sum = "<<res1<<" Sn = "<<res2<<endl;
	return 0;
}
