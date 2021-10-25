#include "std++.h"
using namespace std;

vector<int> merge(vector<int> lhs, vector<int> rhs)
{
	vector<int> res;

	int i(0), j(0);
	while (i < lhs.size() && j < rhs.size())
	{
		if (lhs[i] < rhs[j])
			res.push_back(lhs[i++]);
		else
			res.push_back(rhs[j++]);
	}	
	while (i < lhs.size())
		res.push_back(lhs[i++]);
	while (j < rhs.size())
		res.push_back(rhs[j++]);
	return res;
}

vector<int> quick_sort(vector<int> v)
{
	if (v.size() == 1 || v.empty())
		return v;
	vector<int> smaller, equal, bigger;
	int pivot = v[0];
	for(auto x:v)
	{
		if (x == pivot)
			equal.push_back(x);
		else if (x < pivot)
			smaller.push_back(x);
		else
			bigger.push_back(x);
	}
	smaller = quick_sort(smaller);
	bigger = quick_sort(bigger);
	return merge(merge(smaller, bigger), equal);
}

int main(void)
{
	ifstream cin("input.in");
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& x:v)
		cin >> x;
	v = quick_sort(v);
	for(auto x:v)
		cout << x << " ";
	cout << endl;
	return 0;
}