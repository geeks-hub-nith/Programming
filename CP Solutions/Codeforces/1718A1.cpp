// Link: https://codeforces.com/contest/1718/problem/A1

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5010, M = 8191, inf = 1e9;


void solve_case() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<int>>dp(n + 2, vector<int>(M + 1, inf));


	for (int i = 0; i <= M; i++)
		dp[0][i] = 0;

	dp[1][0] = 0;

	for (int i = 1; i <= M; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][a[i - 1]];
		for (int j = 1; j <= M; j++)
			dp[i][j] = min(dp[i - 1][a[i - 1]] + 1, 1 + dp[i - 1][a[i - 1] ^ j]);
	}

	cout << dp[n][a[n]] << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0)
		solve_case();
}