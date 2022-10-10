//Link: https://codeforces.com/contest/1712/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 2e5 + 5;

void solve_case() {

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v)cin >> x;

	if (is_sorted(v.begin(), v.end()))
	{
		cout << "0\n";
		return;
	}

	vector<int> last (n + 1);
	for (int i = 0; i < n; i++) {
		int x = v[i];
		last[x] = i;
	}

	int idx = n - 1;
	for (int i = n - 1; i > 0; i--) {
		if (v[i - 1] <= v[i])continue;
		idx = i;
		break;
	}

	set<int> s;
	int last_id = 0;
	for (int i = 0; i < idx; i++) {
		last_id = max(last_id, last[v[i]]);
	}

	for (int i = 0; i <= last_id; i++) {
		s.insert(v[i]);
	}

	cout << s.size() << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0)
		solve_case();
}