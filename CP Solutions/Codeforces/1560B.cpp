// Link: https://codeforces.com/contest/1560/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    while(t--){
        long long a, b, c, n;
        cin >> a >> b >> c;
        n = (b - a) * 2;
        if(n < 0) n *= -1;
        if(b > n || a > n || c > n){
            cout << "-1" << endl;
        }
        else{
            long long x = c - n / 2;
            x > 0 ? cout << x << endl : cout << n + x << endl;
        }
    }
}