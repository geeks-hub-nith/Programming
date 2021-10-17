// Problem Link - https://cses.fi/problemset/task/2183/
// AUTHOR - DEEPAK SRIVASTAVA

#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
                if (sum + 1 < a[i]) {
                        cout << sum + 1;
                        exit(0);
                }
                sum += a[i];
        }
        cout << sum + 1;
}