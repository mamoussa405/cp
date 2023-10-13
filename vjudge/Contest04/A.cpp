#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
using namespace std;
typedef long long ll;
bool get_min_dis(pair<int,int>& key, vector<pair<int, int>>& shifts, int dis) {
    float min_dis;
    for (auto& shift:shifts) {
        min_dis = sqrt((float)((key.first - shift.first) * (key.first - shift.first)) +
        ((key.second - shift.second) * (key.second - shift.second)));
        if (min_dis <= dis) {
            return true;
        }
    }
    return false;
}
void solve(void)
{
    int n,m,x;
    cin >> n >> m >> x;
    map<char, pair<int, int>>  keys;
    vector<pair<int, int>> shifts;
    vector<bool> v(26, false);
    int i = 0;
    while (n--) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'S') shifts.push_back({i, j});
            else {
                keys[s[i]] = {i , j};
                v[s[i] - 'a'] = true;
            }
        }
        ++i;
    }
    int k;
    string q;
    int ans{0};
    cin >> k >> q;
    for (char& c:q) {
        if (c >= 'a' && c <= 'z' && v[c - 'a'])
            continue;
        if (c >= 'A' && c <= 'Z' && v[c + 20 - 'a']) {
            if (get_min_dis(keys[c + 20], shifts, x)){
                ++ans;
                continue;
            }
        }
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
int main(void)
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
