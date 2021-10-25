
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

vector<int> merge_sort(vector<int> v, int s, int e)
{
	if (v.size() <= 1)
		return v;
	int mid = (s + e) / 2;
	vector<int> left(v.begin() + s, v.begin() + mid + 1), right(v.begin() + mid + 1, v.begin() + e + 1);
	cout << "------- call ---------" << endl;
	for(auto x:left)
		cout << x << " ";
	cout << endl;
	for(auto x:right)
		cout << x << " ";
	cout << endl;
	cout << "----------------------" << endl;
	return (merge(merge_sort(left, s, mid), merge_sort(right, mid + 1, e)));
}


int main(void)
{
	ifstream cin("input.in");
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& x:v)
		cin >> x;
	v = merge_sort(v, 0 , v.size() - 1);
	for(auto x:v)
		cout << x << " ";
	cout << endl;
	return 0;
}