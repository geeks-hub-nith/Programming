//Link: https://codeforces.com/contest/1720/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 3e5 + 5;
const int Maxm = 260;

int a[N], dp[N];
int n;

void solve_case() {
	cin >> n;
	int res(0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
		for (int j = max(0LL, i - Maxm); j < i; j++) {
			if ((a[j]^i) < (a[i]^j))
				dp[i] = max(dp[i], dp[j] + 1);
			res = max(res, dp[i]);
		}
	}


	cout << res << '\n';

}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0)
		solve_case();
}