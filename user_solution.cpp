// #include <bits/stdc++.h>
#include "std++.h"
using namespace std;

// using ll = long long int;
// using ull = unsigned long long int;

int N, M;
int d, s;
int speedLim[100];
int curr;
int ans;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> d >> s;
		for (int j = 0; j < d; ++j) {
			speedLim[curr++] = s;
		}
	}
	curr = 0;
	for (int i = 0; i < M; ++i) {
		cin >> d >> s;
		for (int j = 0; j < d; ++j) {
			ans = max(ans, s - speedLim[curr++]);
		}
	}
	cout << ans << '\n';
}

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.length()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("speeding");

	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
