#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int>& v, vector<int>& sub, int cur)
{
	if (sub.size())
	{
		for(auto& x:sub)
			cout << x << " ";
		cout << endl;
	}
	for(int i = cur; i < v.size(); ++i)
	{
		sub.push_back(v[i]);
		subsets(v, sub, i + 1);
		sub.pop_back();
	}
}

int main(void)
{
	vector<int> v ={1,2,3}, sub;
	subsets(v,sub,0);
	return 0;
}