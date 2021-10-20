// Problem Link - https://codeforces.com/problemset/problem/810/C
// Author - DEEPAK SRIVASTAVA

#include <bits/stdc++.h>

#define int long long

using namespace std;

long long Binexp(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
                if (b & 1)
                        res = res * a % m;
                a = a * a % m;
                b >>= 1;
        }
        return res;
}

signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        const int M = (int) 1e9 + 7;
        int A = 0, B = 0;
        for (int i = n - 1, x; i >= 0; --i) {
                x = Binexp(2LL, i, M) - 1;
                A = (A + (a[i] * x) % M) % M;
                B = (B + (a[n - 1 - i] * x) % M) % M;
        }
        cout << (A - B + M) % M;
        return 0;
}