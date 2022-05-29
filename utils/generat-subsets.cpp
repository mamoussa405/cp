#include <bits/stdc++.h>
using namespace std;

void generate_subsets(vector<int>& v, vector<int>& subset, int cur_index)
{
	for(auto& x:subset)
		cout << x << " ";
	cout << '\n';
	for(int i = cur_index; i < v.size(); ++i)
	{
		subset.push_back(v[i]);
		generate_subsets(v, subset, i + 1);
		subset.pop_back();
	}
	return;
}
int main(void)
{
	vector<int> v = {1,2,3};
	vector<int> subset;
	generate_subsets(v, subset, 0);
}