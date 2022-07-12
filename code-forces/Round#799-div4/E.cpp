#include <bits/stdc++.h>
using namespace std;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define iter(it, l) for (auto it = l.begin(); it != l.end(); ++it)
#define riter(it, l) for (auto it = --l.end(); it != l.begin(); --it)
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

void closest_to_1(auto& it, auto& it2)
{
    int dis1{0},dis2{0};
    auto tmp = it;
    auto tmp2 = it2;
    while (*tmp != 1)
    {
        ++dis1;
        ++tmp;
    }
    while (*tmp2 != 1)
    {
        ++dis2;
        --tmp2;
    }
    if (dis1 < dis2) 
        ++it;
    else
        --it2; 
}

void solve(void)
{
    int n,s;
    int sum{0};
    int ans{0};
    cin >> n >> s;
    vi v(n);
    cin >> v;
    sum = accumulate(all(v), 0);
    if (sum < s)
    {
        cout << -1 << nl;
        return;
    }
    else if (sum == s)
    {
        cout << 0 << nl;
        return;
    }
    int res{0};
    int left = n / 2;
    int right = left - 1; 
    int el{0};
    while (1)
    {
        if (right < n)
        {
            if (v[right] == 1)
                res += 1;
            ++right;
            el++;
        }
        if (res == sum)
        {
            while (right < n && v[right] == 0)
            {
                el++;
                ++right;
            }
            while (left >= 0 && v[left] == 0)
            {
                el++;
                --left;
            }
           cout << n - el << nl; 
           return;
        }
        if (left >= 0)
        {
            if (v[left] == 1)
                res += 1;
            --left;
        }
        if (res == sum)
        {
            while (right < n && v[right] == 0)
            {
                el++;
                ++right;
            }
            while (left >= 0 && v[left] == 0)
            {
                el++;
                --left;
            }
           cout << n - el << nl; 
           return;
        }
    }
    
    
    
}
int main(void)
{
    setIO("");
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
