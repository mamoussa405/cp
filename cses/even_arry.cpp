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
#define INF (int)1e9
#define EPS 1e-9
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
const double pi = acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,i,ans = 0;
        cin >> n;
        vector<int> v(n);
        for(auto &x:v)
            cin >> x;
        REP(i, n) 
        {
            if (!(v[i]%2) && (i%2))
            {
                for(int j = i+1; j < n; ++j)
                {
                    if (v[j]%2)
                    {
                        swap(v[i], v[j]);
                        ans++;
                        break;
                    }
                }
            }
            else if (v[i]%2 && !(i%2))
            {
                for(int j = i+1; j < n; ++j)
                {
                    if (!(v[j]%2))
                    {
                        swap(v[i], v[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
        bool possible = true;
        for(int k = 0; k < n; ++k)
        {
            if ((!(v[k]%2) && (k%2)) || (v[k]%2 && !(k%2)))
            {
                cout << -1 << nl;
                possible = false;
                break;
            }
        }
        if (possible)
            cout << ans << nl;
    }
    return 0;
}