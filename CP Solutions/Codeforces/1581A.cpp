// Link: https://codeforces.com/contest/1581/problem/A
// Author: master._.mind
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

#define NCR
const ll N = 200043;
ll MOD = 1e9 + 7;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
ll fact[N];
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
// a**(p - 1) % p == 1
// a*(a**(p - 2)) % p == 1
// a**(p - 2) % p == 1 / a
ll inv(ll a, ll mod) { return modpow(a, mod - 2, mod); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv(fact[b], MOD)), inv(fact[a - b], MOD));
}

void Solution() {
    ll n;
    cin >> n;
    cout << mul(fact[2 * n], inv(2LL, MOD)) << '\n';  // (2n)!/2
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        Solution();
    }
    return 0;
}