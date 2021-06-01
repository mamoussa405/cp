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

void setIO(string name = "")
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    ifstream cin(name + ".in");
    ofstream cout(name + ".out");
}

int main(void)
{
    int n, i, num = 1;
    cin >> n;
    vi v(n-1);
    REP(i, n-1)
        cin >> v[i];
    sort(all(v));
    if (*lower_bound(all(v), n) != n)
    {
        cout << n << nl;
        return 0;
    }
    REP(i, n-1) 
    {
        if (num != v[i])
        {
            cout << num << nl;
            break;
        }
        num++;
    }
    return 0;
}