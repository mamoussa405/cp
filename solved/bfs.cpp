#include "std++.h"

using namespace std;

int main(void)
{
	ifstream cin("bfs.in");
	int n,s,t;
	cin >> n >> s >> t;
	vector<int> v(n);
	queue<int> q;
	set<int> 	visited;
	for (auto &x:v)
		cin >> x;
	int index = s - 1;
	if (t - 1 >= v.size() || t - 1 < 0)
	{
		cout << "NO\n";
		return 0;
	}
	while (true)
	{
		if (index + v[index] < v.size() && !visited.count(index + v[index]))
		{
			q.push(index + v[index]);
			visited.insert(index + v[index]);
		}
		if (index - v[index] >= 0 && !visited.count(index - v[index]))
		{
			q.push(index - v[index]);
			visited.insert(index - v[index]);
		}
		index = q.front();
		q.pop();
		if (v[index] == v[t - 1])
		{
			cout << "YES\n";
			return 0;
		}
		if (q.empty())
		{
			cout << "NO\n";
			return 0;
		}
	}
	
}