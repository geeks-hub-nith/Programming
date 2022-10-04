// Link: https://codeforces.com/contest/1721/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    while(t--){
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        if(((abs(n - x) + abs(m - y)) <= d) || (m - y <= d && n - x <= d) || (x - 1 <= d && n - x <= d) || (y - 1 <= d && m - y <= d) || (x - 1 <= d && y - 1 <= d)) cout << "-1\n";
        else cout << n + m - 2 << endl;
    }
}