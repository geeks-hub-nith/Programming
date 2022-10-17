//Link: https://codeforces.com/contest/1715/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 2e5 + 5;
constexpr short M = 30;
int n, q;
vector<array<int, 2>> queries[N];

int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;

	bool bit_zero[n][M + 1] = {};
	bool bit_one[n][M + 1] = {};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= M; j++) {
			bit_one[i][j] = bit_zero[i][j] = false;
		}
	}


	for (int i = 0, a, b, x; i < q; i++) {
		cin >> a >> b >> x;
		a--, b--;

		if (a > b)
			swap(a, b);
		if (a != b)
			queries[a].push_back({b, x});
		for (int j = M; j >= 0; j--) {
			int bit_x = x >> j & 1;
			if (a != b && !bit_x)
				bit_zero[a][j] = bit_zero[b][j] = true;
			if (a == b && bit_x) {
				bit_one[a][j] = true;
			}
			if (a == b && !bit_x)
				bit_zero[a][j] = true;
		}
	}





	for (int i = 0; i < n; i++) {
		for (auto [j, x] : queries[i]) {
			for (int b = M; b >= 0; b--) {
				int bit_x = (x >> b & 1);
				if (bit_x == 1) {
					if (bit_zero[i][b] == true) {
						bit_one[j][b] = true;
					}
					if (bit_zero[j][b] == true) {
						bit_one[i][b] = true;
					}
				}
			}
		}
	}


	for (int i = 0; i < n; i++) {

		for (int b = M; b >= 0; b--)
			if (bit_zero[i][b] == false && bit_one[i][b] == false)
				bit_zero[i][b] = true;

		for (auto [j, x] : queries[i]) {
			for (int b = M; b >= 0; b--) {
				int bit_x = (x >> b & 1);
				if (bit_x == 1 && bit_zero[i][b]) {
					bit_one[j][b] = true;
				}
			}
		}
	}

	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		for (int b = M; b >= 0; b--) {
			if (bit_one[i][b])
				res[i] += (1LL << b);
		}
	}

	for (auto &x : res)cout << x << ' ';
	cout << '\n';
	return 0;
}