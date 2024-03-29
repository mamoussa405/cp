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
#define SZ size()
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
    for(int i = 0; i < v.SZ; ++i) 
    {
        if (i != v.SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i) 
    {
        if (i != v.SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i) 
    {
        if (i != v.SZ - 1)
            cout << v[i] << ", ";
        else
            cout << v[i];
    }
    cout << "]\n";
    return out;
}
ostream& operator<<(ostream& out, vvi& v)
{ 
    for(int i = 0; i < v.SZ; ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < v[i].SZ; ++j)
        {
            if (j != v[i].SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < v[i].SZ; ++j)
        {
            if (j != v[i].SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i) 
    {
        cout << i << "-->";
        cout << '[';
        for(int j = 0; j < v[i].SZ; ++j)
        {
            if (j != v[i].SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i)
    {
        if (i != v.SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i)
    {
        if (i != v.SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i)
    {
        if (i != v.SZ - 1)
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
    for(int i = 0; i < v.SZ; ++i)
    {
        if (i != v.SZ - 1)
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

void solve(void)
{
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    if (n%2)
    {
        cout << "NO" << nl;
        return;
    }
    vi _min,_max;
    sort(v.begin(), v.end());
    int a = v[0];
    int count{1};
    for(int i = 1; i < n; ++i)
    {
        if (v[i] == a)
            count++;
        else
        {
            if (count > n / 2)
            {
                cout << "NO" << nl;
                return;
            }
            count = 1;
            a = v[i];
        }
    }
    if (count > n / 2)
    {
        cout << "NO" << nl;
        return;
    }
    int i;
    for(i = 0; _min.SZ < n / 2; ++i)
        _min.push_back(v[i]);
    for(; _max.SZ < n / 2 && i < n; ++i)
        _max.push_back(v[i]);
    if (_min.SZ == _max.SZ)
    {
        cout << "YES" << nl;
        for(int i = 0; i < _min.SZ; ++i)
            cout << _min[i] << " " << _max[i] << " ";
        cout << nl;
    }
    else
        cout << "NO" << nl;
}
int main(void)
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
