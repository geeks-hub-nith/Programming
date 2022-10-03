// Link: https://codeforces.com/contest/1549/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
     cin >> t;
     while(t--){
        long long n, i, c = 0;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        for(i = 0; i < n; i++){
            if(s2[i] == '1'){
                if(s1[i] == '0') c++;
                else if(i != 0 && s1[i - 1] == '1'){
                    s1[i - 1] = '0';
                    c++;
                }
                else if(i != n - 1 && s1[i + 1] == '1'){
                    s1[i + 1] = '0';
                    c++;
                }
            }
        }
        cout << c << endl;
     }
}