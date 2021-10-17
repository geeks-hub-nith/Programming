// Link: https://codeforces.com/contest/315/problem/A
// Author: aryanpathania
#include <bits/stdc++.h>
#define MOD 1'000'000'007
//#define MOD = 998'244'353
#define int int64_t
typedef long long ll;
typedef long double ld;
using namespace std;
 
void solve(){
    int n;
    std::cin >> n;
    int a[n],b[n];
    for (int i = 0; i < n; i++){
        std::cin >> a[i] >> b[i];
    }
    int count = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i] == b[j] && i!=j){
                // std::cout << a[i] << '\n';
                count --;
                break;
            }
        }
        
    }
    std::cout << count << '\n';
}
 
int32_t main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    solve();
 
    return 0;
}//main
