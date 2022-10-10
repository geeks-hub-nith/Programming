//Link: https://codeforces.com/contest/1719/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 2e5 + 5;
int n, q;
int a[N];

void solve_case() {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<vector<int>> qs(n);
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (a[i] > a[idx]) {
			idx = i;
		}
		qs[idx].push_back(i);
	}

	while (q--) {
		int i, k;
		cin >> i >> k;
		i--;

		int wins = lower_bound(qs[i].begin(), qs[i].end(), k + 1) - qs[i].begin();
		if (i == idx)
			wins += max(0LL, k - (n - 1));

		cout << wins << '\n';
	}
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0)
		solve_case();
}