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
        ifstream cin(name + ".in");
        ofstream cout(name + ".out");
    }
}

int64 process(vector<int>& a, vector<int>& b)
{
    int64 ans_a = 0, ans_b = 0;

    for(size_t i = 0; i < a.size() - 1; ++i)
    {
        ans_a += abs(a[i] - a[i+1]);
        ans_b += abs(b[i] - b[i+1]);
    }
    return ans_a+ans_b;
}

void solve(void)
{
    int n;
    cin >> n;
    int64 ans = 1e18;
    vector<int> a(n), b(n);
    for(auto& x:a)
        cin >> x;
    for(auto& x:b)
        cin >> x;
    for(size_t i = 0; i < n; ++i)
    {
        // n n
        ans = min(ans, process(a,b));
        // n s
        swap(a[i+1], b[i+1]);
        ans = min(ans, process(a,b));
        swap(a[i+1], b[i+1]);
        // s n
        swap(a[i], b[i]);
        ans = min(ans, process(a,b));
        // s s
        swap(a[i+1], b[i+1]);
        ans = min(ans, process(a,b));
        // n n
        swap(a[i], b[i]);
        swap(a[i + 1], b[i + 1]);
    }
    cout << ans << nl;
}
int main(void)
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}