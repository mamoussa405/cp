#include <bits/stdc++.h>

using namespace std;

int ans{0};

void myreverse(vector<int>& v, int i, int m)
{
	while (i < m)
	{
		swap(v[i], v[m]);
		++i;
		--m;
	}
}
void print(vector<int>& v)
{
	for(auto& x:v)
		cout << x << " ";
	cout << endl;
}
void foo(vector<int>& v)
{
	int i,j,m;
	for(i = 0; i < 5; ++i)
	{
		m = i;
		for(j = i; j < 5; j++)
		{
			++ans;
			if (v[j] > v[m])
			{
				m = j;
			}
			myreverse(v, i,m);
		}
	}
}
int main(void)
{
	vector<int> v;
	for(int i = 0; i < 5; ++i)
		v.push_back(i);
	foo(v);
	cout << ans << endl;
	return 0;
}