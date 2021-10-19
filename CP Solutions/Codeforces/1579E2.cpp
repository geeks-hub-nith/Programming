// Link: https://codeforces.com/contest/1579/problem/E2
// Author: jesuswr

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2e5 + 69; 

// Segment tree for sum in a range
int N, A[MAXN], B[MAXN];
struct STN {
    int sm = 0;
    void merge(STN& L, STN& R) {
        sm = L.sm + R.sm;
    }
    void operator=(int a) {
        sm += a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id].sm = 0;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

// compress coordinates because the only important thing is that they remain is their relative orders,
// for example, we care that a > b, the values of a and b are not important, so we can make them smaller
// so we can use the segment tree 
void comp() {
    FOR(i, 0, N) B[i] = A[i];
    sort(B, B + N);
    FOR(i, 0, N) A[i] = (lb(B, B + N, A[i]) - B) + 1;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    comp();
    int M = N; N += 10;
    STB();
    ll ans = 0;
    FOR(i, 0, M) {
        // choose to put the current element before or after the previous ones, 
        ans += min(STQ(0, A[i]).sm, STQ(A[i] + 1, N).sm);
        STU(A[i], 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
