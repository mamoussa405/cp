#include <bits/stdc++.h>
// #include "std++.h"
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
void print_vec(vector<int>& v)
{
    for(auto x:v)
        cout << x << " ";
    cout << nl;
}
void reverse(vector<int> &v, vector<int> &a)
{
    auto _max  = max(*v.begin(), *(v.end() - 1));
    a.push_back(_max);
    (*v.begin() > *(v.end() - 1)) ? v.erase(v.begin()) : v.erase(v.end() - 1);
    while (v.size() > 2)
    {
        auto _min = min(*v.begin(), *(v.end() - 1));
        if (_min == *v.begin())
        {
            a.insert(a.begin(), _min);
            v.erase(v.begin());
        }
        else
        {
            a.push_back(_min);
            v.erase(v.end() - 1);
        }
    }
    auto _min = min(*v.begin(), *(v.end() - 1));
    if (_min == *v.begin())
    {
        a.insert(a.begin(), _min);
        v.erase(v.begin());
        a.push_back(*v.begin());
    }
    else
    {
        a.push_back(_min);
        v.erase(v.end() - 1);
        a.insert(a.begin(), *v.begin());
    }
}

void reverse_left(vector<int> a, vector<int> &res)
{
    while (a.size() > 2)
    {
        auto _min = min(*a.begin(), *(a.end() - 1));
        if (_min == *a.begin())
        {
            res.insert(res.begin(), _min);
            a.erase(a.begin());
        }
        else
        {
            res.push_back(_min);
            a.erase(a.end() - 1);
        }
    }
    auto _min = min(*a.begin(), *(a.end() - 1));
    if (_min == *a.begin())
    {
        res.insert(res.begin(), _min);
        a.erase(a.begin());
    }
    else
    {
        res.push_back(_min);
        a.erase(a.end() - 1);
    }
    res.insert(res.begin(), *a.begin());
}

void reverse_right(vector<int> a, vector<int> &res)
{
    while (a.size() > 2)
    {
        auto _min = min(*a.begin(), *(a.end() - 1));
        if (_min == *a.begin())
        {
            res.insert(res.begin(), _min);
            a.erase(a.begin());
        }
        else
        {
            res.push_back(_min);
            a.erase(a.end() - 1);
        }
    }
    auto _min = min(*a.begin(), *(a.end() - 1));
    if (_min == *a.begin())
    {
        res.insert(res.begin(), _min);
        a.erase(a.begin());
        res.push_back(*a.begin());
    }
    else
    {
        res.push_back(_min);
        a.erase(a.end() - 1);
    }
}
void solve(void)
{
    int n;
    read(n);
    vector<int> v(n), a, res;
    for( auto& x:v)
        cin >> x;
    if (v.size() == 1)
    {
        print_vec(v);
        return;
    }
    vector<int> cp(v.begin(), v.end());
    reverse(v, a);
    reverse_left(a, res);
    if (res == cp)
    {
        print_vec(a);
        return;
    }
    res.clear();
    reverse_right(a, res);
    if (res == cp)
        print_vec(a);
    else
        cout << -1 << nl;
}
int main(void)
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}