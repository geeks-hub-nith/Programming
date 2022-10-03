// Link: https://codeforces.com/contest/1538/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> v;
        long long int i, div = 0;
        for(i = 0; i < n; i++){
            long long int x;
            cin >> x;
            v.push_back(x);
            div += x;
        }
        if(div % n != 0){
            cout << "-1\n";
            continue;
        }
        div /= n;
        sort(v.begin(), v.end());
        long long int need = 0;
        for(auto value: v){
            if(div - value > 0) need += div - value;
            else break;
        }
        auto it = v.end();
        long long int total = 0, count = 0;
        while(total - count * div < need){
            it--;
            count++;
            total += *it;
        }
        cout << count << endl;
    }
}