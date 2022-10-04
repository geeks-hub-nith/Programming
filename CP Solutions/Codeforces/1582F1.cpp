// Author: prashant_th18
#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<bool> ans(513, false);
	vector<vector<int>> dp(2, vector<int>(513, 1e6));
	// dp[i][j] -> If we consider values from a[1] to a[i], and we have a sub-sequence whose xor is j
	// then what is the minimum last value for that subsequence
	dp[0][0] = 0; ans[0] = true;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 512; ++j) {
			// j banana hai
			// j ^ v[i - 1]
			dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j]);
			if(dp[(i - 1) % 2][j ^ v[i - 1]] < v[i - 1]) {
				dp[i % 2][j] = min(dp[i % 2][j], v[i - 1]);
				ans[j] = true;
			}
		}
	}
	int t = 0; for(int i = 0; i < 512; ++i) t += ans[i];
	cout << t << '\n';
	for(int i = 0; i < 512; ++i) {
		if(ans[i]) cout << i << ' ';
	}
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!

