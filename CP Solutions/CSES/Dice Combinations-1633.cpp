// Problem Link - https://cses.fi/problemset/task/1633/
// AUTHOR - DEEPAK SRIVASTAVA

#include <bits/stdc++.h>
 
using namespace std;
 
const int m = (int) 1e9 + 7;
int cache[1000005];
 
int dp(int req) {
        if (req == 0) return 1;
        if (req < 0) return 0;
        int &res = cache[req];
        if (res != -1) return res;
        res = 0;
        for (int i = 1; i <= 6; ++i) {
                res = (res + dp(req - i)) % m;
        }
        return res;
}
 
int main() {
        ios_base::sync_with_stdio(!cin.tie(nullptr));
        int n;
        cin >> n;
        memset(cache, -1, sizeof cache);
        cout << dp(n);
}