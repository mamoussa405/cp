// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

long long ans;

bool solve(int i, int j, vector<vector<char> >& arr, int button, vector<long long>& v)
{
	if (i == arr.size() - 1 && j == arr[0].size() - 1 && button)
		return 1;
	if (i == arr.size() - 1 && j == arr[0].size() - 1 && !button)
		return 0;
	if (arr[i][j] == 'c')	
		return 0;
	if (arr[i][j] == 'b')
		button = 1;
	if (v[i * arr[0].size() + j] != -1)
	{
		ans += v[i * arr[0].size() + j];
		return 1;
	}
	else
		v[i * arr[0].size() + j] = 0;
	if (j + 1 < arr[0].size())
		return solve(i , j + 1, arr, button, v);
	if (i + 1 < arr.size())
		return solve(i + 1, j, arr, button, v);
		if (res1.first)
			v[i * arr[0].size() + j].second += res1.second; 
	}
	v[i * arr[0].size() + j].first = (res.first) ? res.first:res1.first;
	return v[i * arr[0].size() + j];
}

int main(void)
{
	ifstream cin("mission.in");
	int t,n,m,k,l;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> l;
		ans = 0;
		vector<vector<char> >  arr(n, vector<char>(m, 'a') );
		vector<long long> v(n*m,  -1);
		while (k--)
		{
			int i,j;
			cin  >> i >> j;
			arr[i - 1][j - 1] = 'c';
		}
		int button(-1);
		while (l--)
		{
			button = 0;
			int i,j;
			cin >> i >> j;
			arr[i - 1][j - 1] = 'b';
		}
		solve(0,0,arr,button,v);
		for(vector<pair<bool,long long> >::iterator it = v.begin(); it != v.end(); ++it)
			cout << it->second  << " ";
		cout << endl;
		// ans.second %= 1000000007;
		// cout << ans.second << endl;
	}
}