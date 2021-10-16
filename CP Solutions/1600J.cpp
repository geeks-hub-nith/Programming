// Link: https://codeforces.com/contest/1600/problem/J
// Author: master._.mind
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n, vector<ll>(m)), vis(n, vector<ll>(m, 0));
    vector<ll> rooms;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> adj[i][j];
        }
    }

    auto valid = [&](ll x, ll y) -> bool {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (vis[x][y]) return false;
        return true;
    };

    ll ctr = 0;
    ll dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
    function<void(ll, ll)> dfs = [&](ll i, ll j) -> void {
        vis[i][j] = 1;
        ctr++;
        for (ll X = 0; X < 4; ++X) {
            ll mask = (1LL << X);
            if (!(adj[i][j] & mask)) {  // not a wall
                ll ni = i + dx[X];
                ll nj = j + dy[X];
                if (!valid(ni, nj)) continue;
                dfs(ni, nj);
            }
        }
    };

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            ctr = 0;
            dfs(i, j);
            if (ctr) rooms.push_back(ctr);
        }
    }

    sort(rooms.begin(), rooms.end(), greater<ll>());
    for (ll &x : rooms) cout << x << ' ';
    return 0;
}