// Link: https://codeforces.com/contest/1593/problem/E
// Author: master._.mind
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)

// ----------------------------<optimizations>----------------------------

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

// ---------------------------</optimizations>----------------------------

// ---------------------------------<PBDS>--------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using o_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using o_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
//member functions :
// 1. order_of_key (val): returns the no. of values less than val
// 2. find_by_order (k): returns the iterator to kth largest element.(0-based)
// for ordered_multiset, lower_bound and upper_bound swap roles
// --------------------------------</PBDS>--------------------------------

// -------------------------<Defines and typedefs>------------------------
using ll = int64_t;
using db = double;
using ld = long double;
using str = string;
using ull = unsigned long long;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define set_bits(x) __builtin_popcountll(x)
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define rall(x) (x).rbegin(), (x).rend()
#define ps(x, y) fixed << setprecision(y) << x
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define sz(x) ((ll)(x).size())
template <class T>
using V = vector<T>;
template <class T, class U = T>
using P = pair<T, U>;
// ------------------------</Defines and typedefs>------------------------

// -------------------------------<Safe-Map>------------------------------
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2>  // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;
// -------------------------------</Safe-Map>-----------------------------

// --------------------------------<Consts>-------------------------------
constexpr ll mod = 1e9 + 7;  //1000000007
constexpr ll mod2 = 998244353;
constexpr ll inf = LLONG_MAX;
constexpr db eps = 1e-12;
const double PI = acos(-1);
// -------------------------------</Consts>-------------------------------

// -------------------------------<Templates>-----------------------------
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }
// ------------------------------</Templates>-----------------------------

// ---------------------------------<Solve>-------------------------------
// clang-format on

void Solution() {
    ll n, k, u, v;
    cin >> n >> k;
    V<V<ll>> adj(n);
    V<ll> deg(n, 0), vis(n, 0);
    fo(_, n - 1) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    // multisource bfs
    queue<ll> q;
    fo(i, n) if (deg[i] <= 1) {
        vis[i] = 1;
        q.push(i);
    }
    ll ans = n;  // 0 removed
    while (k-- > 0) {
        queue<ll> qq;
        while (!q.empty()) {
            ans--;
            if (ans == 0) return void(cout << "0\n");
            ll parent = q.front();
            q.pop();
            for (auto child : adj[parent]) {
                deg[child]--;
                if (deg[child] <= 1 && vis[child] == 0) {
                    vis[child] = 1;
                    qq.push(child);
                }
            }
        }
        q = qq;
    }
    cout << ans << '\n';
}

// https://codeforces.com/contest/1593/submission/131840493
void Better() {
    ll n, k, u, v;
    cin >> n >> k;
    V<V<ll>> adj(n);
    V<ll> deg(n, 0), dist(n, 0), vis(n, 0);
    fo(_, n - 1) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[v]++, deg[u]++;
    }
    queue<ll> Q;
    fo(i, n) {
        if (deg[i] <= 1) {
            dist[i] = 1;
            Q.push(i);
            vis[i] = 1;
        }
    }
    while (!Q.empty()) {
        ll parent = Q.front();
        Q.pop();
        for (ll child : adj[parent]) {
            if (vis[child]) continue;
            dist[child] = max(dist[parent] + 1, dist[child]);
            deg[child]--;
            if (deg[child] <= 1) {
                vis[child] = 1;
                Q.push(child);
            }
        }
    }
    ll ans = 0;
    fo(i, n) if (dist[i] > k) ans++;
    cout << ans << "\n";
}

// --------------------------------</Solve>-------------------------------

// clang-format off
int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
#ifdef NCR
    init();
#endif
    ll tc = 1; cin >> tc; while (tc--)
    Better();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}

/*
    ? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * n % mod = (n % mod + mod) % mod; (Handling negatives)
    * When using a set, lower_bound(all(set),l) is slower than set.lower_bound(l) because of random iterators
    * string .append() or += is O1, but s = s + s is On (as it creates a copy first), use wisely
    * DONT GET STUCK ON ONE APPROACH
    * use __lg(n) instead of log2(n), int: 32 - __builtin_clz(n), ll: 63 - __builtin_clzll(n), https://codeforces.com/blog/entry/45966
    * string.rfind() finds first occurence from end
    * (a & b) + (a | b) = a + b
    * TLE due to ll ? or multiple copies of large DS?
    * didnt use inv() in modular combinatorics? 
*/
