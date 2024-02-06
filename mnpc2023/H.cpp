// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define iter(it, l) for (auto it = l.begin(); it != l.end(); ++it)
#define riter(it, l) for (auto it = l.rbegin(); it != l.rend(); ++it)
#define nl "\n"
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define sz(x) (int)(x.size())
#define L length()
#define F first
#define S second
const int mod  = static_cast<int>(1000000007);
#define imax INT_MAX
#define imin INT_MIN
/*----------------------------- pair<T, T> -------------------------*/
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<char, char> pcc;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
/*------------------------------------------------------------------*/
/*----------------------------- vector<T> -------------------------*/
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pss> vpss;
typedef vector<pic> vpic;
typedef vector<pci> vpci;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
/*------------------------------------------------------------------*/
/*----------------------------- map<T, T> -------------------------*/
typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<char, string> mcs;
typedef map<string, char> msc;
/*------------------------------------------------------------------*/
/*----------------------------- set<T> -------------------------*/
typedef set<int> si;
typedef set<string> ss;
typedef set<char> sc;
/*------------------------------------------------------------------*/
/*----------------------------- number types -------------------------*/
typedef long long ll;
typedef unsigned long long ull;
/*------------------------------------------------------------------*/
ostream& operator<<(ostream& out, vi& v)
{ 
    cout << '['; 
    for(int i = 0; i < sz(v); ++i) 
    {
        if (i != sz(v) - 1)
            cout << v[i] << ", ";
        else
            cout << v[i];
    }
    cout << "]\n";
    return out;
}
ostream& operator<<(ostream& out, vc& v)
{ 
    cout << '['; 
    for(int i = 0; i < sz(v); ++i) 
    {
        if (i != sz(v) - 1)
            cout << v[i] << ", ";
        else
            cout << v[i];
    }
    cout << "]\n";
    return out;
}
ostream& operator<<(ostream& out, vs& v)
{ 
    cout << '['; 
    for(int i = 0; i < sz(v); ++i) 
    {
        if (i != sz(v) - 1)
            cout << v[i] << ", ";
        else
            cout << v[i];
    }
    cout << "]\n";
    return out;
}
ostream& operator<<(ostream& out, vvi& v)
{ 
    for(int i = 0; i < sz(v); ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < sz(v[i]); ++j)
        {
            if (j != sz(v[i]) - 1)
                cout << v[i][j] << " ";
            else
                cout << v[i][j];
        }
        cout << "]\n";
    }
    return out;
}
ostream& operator<<(ostream& out, vvc& v)
{ 
    for(int i = 0; i < sz(v); ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < sz(v[i]); ++j)
        {
            if (j != sz(v[i]) - 1)
                cout << v[i][j] << " ";
            else
                cout << v[i][j];
        }
        cout << "]\n";
    }
    return out;
}
ostream& operator<<(ostream& out, vvs& v)
{ 
    for(int i = 0; i < sz(v); ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < sz(v[i]); ++j)
        {
            if (j != sz(v[i]) - 1)
                cout << v[i][j] << " ";
            else
                cout << v[i][j];
        }
        cout << "]\n";
    }
    return out;
}
ostream& operator<<(ostream& out, vpii& v)
{ 
    cout << "[ ";
    for(int i = 0; i < sz(v); ++i)
    {
        if (i != sz(v) - 1)
            cout << '{' << v[i].F << ", " << v[i].S << '}' << ", ";
        else
            cout << '{' << v[i].F << ", " << v[i].S << '}';
    }
    cout << " ]\n";
    return out;
}
ostream& operator<<(ostream& out, vpic& v)
{ 
    cout << "[ ";
    for(int i = 0; i < sz(v); ++i)
    {
        if (i != sz(v) - 1)
            cout << '{' << v[i].F << ", " << v[i].S << '}' << ", ";
        else
            cout << '{' << v[i].F << ", " << v[i].S << '}';
    }
    cout << " ]\n";
    return out;
}
ostream& operator<<(ostream& out, vpci& v)
{ 
    cout << "[ ";
    for(int i = 0; i < sz(v); ++i)
    {
        if (i != sz(v) - 1)
            cout << '{' << v[i].F << ", " << v[i].S << '}' << ", ";
        else
            cout << '{' << v[i].F << ", " << v[i].S << '}';
    }
    cout << " ]\n";
    return out;
}
ostream& operator<<(ostream& out, vpss& v)
{ 
    cout << "[ ";
    for(int i = 0; i < sz(v); ++i)
    {
        if (i != sz(v) - 1)
            cout << '{' << v[i].F << ", " << v[i].S << '}' << ", ";
        else
            cout << '{' << v[i].F << ", " << v[i].S << '}';
    }
    cout << " ]\n";
    return out;
}
/*--------------------------- extraction operator overloads -------------------*/
void operator>>(istream& in, vi& v) { for(auto& x:v) in >> x; }
void operator>>(istream& in, vc& v) { for(auto& x:v) in >> x; }
void operator>>(istream& in, vs& v) { for(auto& x:v) in >> x; }
/*---------------------------------------------------------------------------*/
ull bexp(ull x, ull n)
{
    ull  res = 1;
    while (n)
    {
        if (n&1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res; 
}

vi brep(ll n)
{
	vi res;
	for(int i = 63; i >= 0; --i)
		(n&(1<<i)) ? res.pb(1) : res.pb(0);
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

struct PathScore
{
    ll score;
    ll max_sink_idx;
    PathScore(ll score, ll max_sink_idx): score(score), max_sink_idx(max_sink_idx){}
};
struct Node
{
    ll node_idx;
    ll score;
    ll max_sink_idx;
    Node(ll node_idx, ll score, ll max_sink_idx): node_idx(node_idx), \
    score(score), max_sink_idx(max_sink_idx) {}
};

vector<PathScore> path_score;

void get_path_score(vi& v, vvi& g, ll n)
{
    queue<Node> q;
    vector<bool>  vis(n + 1, 0);

    q.push(Node(1, v[0], 0));
    vis[1] = 1;
    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();
        if (g[curr.node_idx].empty())
            path_score.push_back(PathScore(curr.score, curr.max_sink_idx));
        for (ll i = 0; i < sz(g[curr.node_idx]); ++i)
        {
            ll ne = g[curr.node_idx][i];
            if (!vis[ne])
            {
                ll power = v[ne - 1];
                ll idx;
                if (min((ll)v[curr.max_sink_idx], power) == v[curr.max_sink_idx])
                    idx = curr.max_sink_idx;
                else
                    idx = ne - 1;
                q.push(Node(ne, curr.score + power, idx));
                vis[ne] = 1;
            }
        }
    }
}

void solve(void)
{
    ll n;
    cin >> n;
    vi v(n);
    cin >> v;
    vvi g(n + 1);
    ll e = n - 1;

    while (e--)
    {
        ll x,y;
        cin >> x >> y;
        g[x].pb(y);
    }
    get_path_score(v, g, n);
    ll curr_score = 0;
    ll ans = 0;
    // cout << path_score.size() << nl;
    for (PathScore& x : path_score)
        curr_score += x.score;
    PathScore *sink_adr = NULL;
    ll sink_idx;
    for (PathScore& x : path_score) 
    {
        if (v[x.max_sink_idx] >= 0)
            continue;
        ll new_score = curr_score - x.score + (x.score - v[x.max_sink_idx]);
        if (new_score > ans)
        {
            ans = new_score;
            sink_adr = &x;
            sink_idx = x.max_sink_idx;
        }
    }
    cout << ans << nl;
    if (sink_adr)
    {
        for (PathScore& x : path_score)
        {
            if (&x == sink_adr)
                continue;
            if (x.max_sink_idx == sink_idx)
                ans += (x.score + (x.score - v[x.max_sink_idx]));
        }
    }
    cout << ans << nl;
}

int main(void)
{
    setIO("input");
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
