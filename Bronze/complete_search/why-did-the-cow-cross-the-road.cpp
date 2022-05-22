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

int first_index(char c, string& s)
{
    for(int i = 0; i < s.size(); ++i)
        if (s[i] == c)
            return i;
    return 0;
}

bool is_crossed(string& s, char c)
{
    for(int i = 0; i < s.size(); ++i)
        if (s[i] == c)
            return true;
    return false;
}

void solve(void)
{
    string s;
    cin >> s;
    string cow = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, string> already_crossed;
    set<char> might_cross;
    int64 ans{0};
    for(int i = 0; i < 26; ++i)
    {
        int index = first_index(cow[i], s);
        for(int j = ++index; j < 52; ++j)
        {
            if (s[j] == cow[i])
                break;
            if (is_crossed(already_crossed[cow[i]], s[j]))
                continue;
            if (might_cross.count(s[j]))
                might_cross.erase(s[j]);
            else
                might_cross.insert(s[j]);
        }
        for(set<char>::iterator it = might_cross.begin(); it != might_cross.end(); ++it)
            already_crossed[*it] += cow[i];
        ans += might_cross.size();
        might_cross.clear();
    }
    cout << ans << nl;
}
int main(void)
{
    setIO("circlecross");
    int t;
    // read(t);
    t = 1;
    while (t--)
        solve();
    return 0;
}
