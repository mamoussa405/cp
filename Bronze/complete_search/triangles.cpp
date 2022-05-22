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

double area(pii p1, pii p2, pii p3)
{
    return abs((p1.first*(p2.second - p3.second))
                + p2.first*(p3.second - p1.second)
                + p3.first*(p1.second - p2.second) ) / 2.0;
}

bool is_valid(pii p1, pii p2, pii p3)
{
    bool found_x{false};
    bool found_y{false};
    if (p1.first == p2.first || p1.first == p3.first || p2.first == p3.first)
        found_x = true;
    if (p1.second == p2.second || p1.second == p3.second || p2.second == p3.second)
        found_y = true;
    return found_x && found_y;
}
void solve(void)
{
    int n;
    cin >> n;
    vpi fence_posts(n);
    for(auto& x:fence_posts)
        cin >> x.first >> x.second;
    double ans{0.0};
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                if (is_valid(fence_posts[i], fence_posts[j], fence_posts[k]))
                {
                    // cerr << "(" << fence_posts[i].first << "," << fence_posts[i].second
                    // << "),(" << fence_posts[j].first << "," << fence_posts[j].second
                    // << "),(" << fence_posts[k].first << "," << fence_posts[k].second << ")" << nl;
                    double res = area(fence_posts[i], fence_posts[j], fence_posts[k]);
                    ans = max(ans, res);
                }
            }
        }
    }
    // printf("%lf\n", ans*2);
    cout << fixed << (int64)ceil(ans*2) << nl;
}
int main(void)
{
    setIO("triangles");
    int t;
    // read(t);
    t = 1;
    while (t--)
        solve();
    return 0;
}
