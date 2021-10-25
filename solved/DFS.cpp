#include <bits/stdc++.h>

using namespace std;


bool ans = false;
void solve(vector<int>& v, int s, int t, vector<int>& visited)
{
	if (s >= v.size() || s < 0)
		return;
	if (visited[s])
		return;
	if (s == t)	
	{
		cout << "YES\n";
		ans = true;
		return;
	}
	if (!visited[s])
		visited[s] = 1;
	if (!ans)
		solve(v, s + v[s], t, visited);
	if (!ans)
		solve(v, s - v[s], t, visited);
}

int main(void)
{
	int n,s,t;
	cin >> n >> s >> t;
	vector<int> v(n), visited(n);
	for(auto &x:v)
		cin>>x;
	solve(v,s - 1,t - 1, visited);
	if (!ans)
		cout << "NO\n";
	return 0;
}