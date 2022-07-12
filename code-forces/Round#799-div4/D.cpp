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

void add_x(string& s, int x)
{
    string tmp;
    string tmp_h, tmp_m;
    tmp_h += s[0];
    tmp_h += s[1];
    tmp_m += s[3];
    tmp_m += s[4];
    int h = stod(tmp_h),m = stod(tmp_m); 
    h = (h + x/60) % 24;
    m = (m + x%60);
    if (m > 59)
    {
        m = (m % 60);
        h += 1;
    }
    if (h > 23)
    {
        h = (h % 24);
        m = 0;
    }
    if (h < 10)
        tmp += "0" + to_string(h);
    else tmp += to_string(h);
    tmp += ":";
    if (m < 10)
        tmp += "0" + to_string(m);
    else tmp += to_string(m);
    s = tmp;
}

bool is_palindrom(string& s)
{
    string left, right;
    left += s[0];
    left += s[1];
    right += s[3];
    right += s[4];
    reverse(all(left));
    return left == right; 
}

void solve(void)
{
    string s;
    int ans{0};
    int x;
    cin >> s >> x;
    ans += is_palindrom(s);
    string tmp = s;
    add_x(tmp, x);
    while (tmp != s)
    {
        ans += is_palindrom(tmp);
        add_x(tmp, x);
    }
    cout << ans << nl;
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
