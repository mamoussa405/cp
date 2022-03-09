// #include <bits/stdc++.h>
#include "std++.h"
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
    int64 n;
    cin >> n;
    int64 max = 0;
    vector<int> v,sorted_v;
    while (n--)
    {
        int64 num;
        cin >> num;
        v.push_back(num);
        sorted_v.push_back(num);
    }
    sort(sorted_v.begin(), sorted_v.end());
    int i = 0, j = 0; 
    while (i < v.size() || j < sorted_v.size())
    {
        if (v[i] > sorted_v[j] && ((v[i] + sorted_v[j]) % 2 == 0))
        {
            cout << "NO" << nl;
            return;
        }
        if (sorted_v[j] > v[i] && i < v.size())
            i++;
        else if (v[i] > sorted_v[j] && j < sorted_v.size())
            j++;
        else
        {
            if (i < v.size())
                i++;
            if (j < sorted_v.size())
                j++;
        }
    }
    cout << "YES"  << nl;
}
int main(void)
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}