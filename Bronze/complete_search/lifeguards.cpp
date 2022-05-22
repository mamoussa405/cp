#include <bits/stdc++.h>
using namespace std;
// #define sint(t) scanf("%d",&t)
// #define slint(t) scanf("%ld",&t)
// #define sllint(t) scanf("%lld",&t)
// #define sch(t) scanf("%c",&t)
// #define sstr(t) scanf("%s",t)
// #define sf(t) scanf("%f",&t)
// #define slf(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define nl "\n"
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define print(arg) cout << arg << '\n';
#define read(arg) cin >> arg;
#define EPS 1e-9
const int mod  = static_cast<int>(1000000007);
#define imax INT_MAX
#define imin INT_MIN
// const double pi = acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef set<int> si;
typedef multiset<int> msi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
uint64 bexp(uint64 x, uint64 n)
{
    uint64  res = 1;
    while (n)
    {
        if (n&1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res; 
}

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if (name != "")
    {
      FILE* cin = freopen(string(name + ".in").c_str(), "r", stdin);
      FILE* cout = freopen(string(name + ".out").c_str(), "w", stdout);
    }
}

int64 some_reset(vi& time_line)
{
    int64 some{0};
    for(auto& x:time_line)
    {
        if (x == 1)
            some += 1;
        x = 0;
    }
    return some;
}

void solve(void)
{
    int n;
    cin >> n;
    vpi shifts(n);
    for(auto& x:shifts)
    {
        cin >> x.first >> x.second;
        --x.first;
        --x.second;
    }
    vi time_line(1000);
    int64 ans{0};
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                for(int t = shifts[j].first; t <= shifts[j].second; ++t)
                {
                    if (t == shifts[j].second && !time_line[t])
                    {
                        time_line[t] = -1;
                        continue;
                    }
                    if (!time_line[t] || time_line[t] == -1)
                        time_line[t] = 1;
                }
            }
        }
        ans = max(ans, some_reset(time_line));
    }
    cout << ans << nl;
}
int main(void)
{
    setIO("lifeguards");
    int t;
    // read(t);
    t = 1;
    while (t--)
        solve();
    return 0;
}
