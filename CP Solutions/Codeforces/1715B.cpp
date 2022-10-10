// Link: https://codeforces.com/contest/1715/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 2e5 + 5;

void solve_case() {
	int n, k, b, s;
	cin >> n >> k >> b >> s;

	if (s >= k * b && s <= k * b + n * (k - 1)) {

		int rem = s - k * b;
		for (int i = 0; i < n - 1; ++i) {
			int mn = min(rem, k - 1);
			cout << mn << ' ';
			rem -= mn;
		}
		cout << rem + b*k << '\n';
	}

	else
		cout << "-1\n";
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0)
		solve_case();
}
