#include "std++.h"

using namespace std;
int main()
{
	string str;
	cin>>str;
	int index;
	int start = 0;
	int step;
	int ans = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		index = str[i]-97;
		step = abs(start - index);
		if (step < 13)
			ans += step;
		else
			ans += (26 - step);
		start = index;
	}
	cout<<ans<<endl;
	return 0;
}

