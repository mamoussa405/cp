#include "std++.h"
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& res)
{
	int i(0), j(0);
	while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j])
			res.push_back(a[i++]);
		else
			res.push_back(b[j++]);
	}
	while (i < a.size())
		res.push_back(a[i++]);
	while (j < b.size())
		res.push_back(b[j++]);
}

int main(void)
{
	int na,nb;
	cin >> na >> nb;
	vector<int> a(na), b(nb), res;
	for(auto& x:a)
		cin >> x;
	for(auto& x:b)
		cin >> x;
	merge(a, b, res);
	for(auto x:res)
		cout << x << " ";
	cout << endl;
	return 0;
}