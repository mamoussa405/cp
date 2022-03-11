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

void solve(void)
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> valid_keys;
    while (k--)
    {
        char c;
        cin >> c;
        valid_keys.insert(c);
    }
    vector<int64> dp(n);
    if (valid_keys.count(s[0]))
        dp[0] = 1;
    else
        dp[0] = 0;
    for(size_t i = 1; i < s.size(); ++i)
    {
        if (valid_keys.count(s[i]))
            dp[i] = dp[i - 1] + 1;
        else    
            dp[i] = 0;
    }
    int64 sum = 0;
    for(size_t i = 0; i < dp.size(); ++i)
        sum += dp[i];
    cout << sum << nl;
}
int main(void)
{
    int t;
    // read(t);
    t = 1;
    while (t--)
        solve();
    return 0;
}