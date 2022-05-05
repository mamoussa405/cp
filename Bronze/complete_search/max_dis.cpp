#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
  int n;
  cin >> n;
  vector<ll> x(n),y(n);
  ll ans{0};
  for (auto &e:x)
      cin >> e;
  for (auto &e:y)
      cin >> e;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = i + 1; j < n; ++j)
    {
      ll dis = ((x[j] - x[i]) * (x[j] - x[i])) + ((y[j] - y[i]) * (y[j] - y[i]));
      ans = max(ans, dis);
    }
  }
  cout << ans << std::endl;
  return 0;
}
