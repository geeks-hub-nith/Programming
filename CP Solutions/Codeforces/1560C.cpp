// Link: https://codeforces.com/contest/1560/problem/C
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long k, i = 1, sum = 1;
        cin >> k;
        while(k > i * i){
            sum += 2 * i;
            // cout << "added " << 2 * i << endl;
            i++;
        }
        // cout << "sum is " << sum << endl;
        if(k < sum){
            cout << i - (sum - k) << " " << i << endl;
        }
        else{
            cout << i << " " << i - (k - sum) << endl;
        }
    }
}