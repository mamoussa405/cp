#include "std++.h"
using namespace std;

int main()
{
	int k,r;
	cin>>k>>r;
	int i = 1;
	while (1)
	{
		int res = i*k;
		if ((res%10) == r || (res%10) == 0)
		{
			cout<<i<<endl;
			break;
		}
		i++;
	}
	return 0;
}
