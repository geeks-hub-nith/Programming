// Link: https://codeforces.com/contest/1592/problem/B
// Author: master._.mind
#include "bits/stdc++.h"
using namespace std;

// ----------------------------<optimizations>----------------------------
/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
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
using str = string;
using ull = unsigned long long;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
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
using vl = V<ll>;
using vvl = V<vl>;
template <class T, class U = T>
using P = pair<T, U>;
using pl = P<ll, ll>;
using vpl = V<pl>;
// ------------------------</Defines and typedefs>------------------------

// --------------------------------<Consts>-------------------------------
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db eps = 1e-12;
const double PI = acos(-1);
// -------------------------------</Consts>-------------------------------

// -------------------------------<Templates>-----------------------------
template <class T, class U = T>
bool amin(T& a, U&& b) {
    return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool amax(T& a, U&& b) {
    return a < b ? a = std::forward<U>(b), true : false;
}
// ------------------------------</Templates>-----------------------------

// ---------------------------------<Solve>-------------------------------

void Solution() {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    vl sorted(n);
    fo(i, n) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(all(sorted));
    ll L, R;
    if (n % 2 == 1) {
        L = n / 2;
        R = n / 2;
    } else {
        L = (n / 2) - 1;
        R = L + 1;
    }
    if (L >= x) {
        cout << "YES\n";
        return;
    }
    while (L >= 0 && R < n) {
        if (a[L] != sorted[L] && L < x && n - L - 1 < x) {
            cout << "NO\n";
            return;
        }
        L--;
        if (a[R] != sorted[R] && R < x && n - R - 1 < x) {
            cout << "NO\n";
            return;
        }
        R++;
        if (n - L - 1 >= 0 && R >= x) break;
    }
    cout << "YES\n";
}

//! BETTER approach
void solve() {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    fo(i, n) cin >> a[i];
    vl v(a);
    sort(all(v));
    if (v == a) return void(cout << "YES\n");
    fo(i, n) {
        if (a[i] != v[i]) {
            if (i + x >= n and i - x < 0) {
                return void(cout << "NO\n");
            }
        }
    }
    cout << "YES\n";
}

// --------------------------------</Solve>-------------------------------

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef NCR
    init();
#endif
    ll tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
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
