// Link: https://codeforces.com/contest/315/problem/A
// Author: aryanpathania
#include <bits/stdc++.h>
#define MOD 1'000'000'007
//#define MOD = 998'244'353
#define int int64_t
typedef long long ll;
typedef long double ld;
using namespace std;
 
int countDigits(int n);
 
void solve(){
    int a,b,n,m,k,p,q,r,count = 0, sum = 0, ans = 0;
    std::cin >> a >> b >> n;
    if(a%b == 0){
        std::cout << a;
        for (int i = 0; i < n; i++){
            std::cout << 0;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if((10*a + i)%b == 0){
            std::cout << a << i;
            for (int i = 0; i < n-1; i++){
                std::cout << 0;
            }
            return;
        }
    }
    std::cout << -1 << '\n';
}//solve
 
int32_t main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    auto time_start = chrono::high_resolution_clock::now();
 
    int testcases = 1;
    // std::cin >> testcases;
 
    while(testcases--) {
        solve();
    }//testcases
 
    auto time_end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count();
 
    time_taken *= 1e-9;
    cerr << setprecision(6) << time_taken << " ms" << '\n';
    return 0;
}//main
 
int count_digit(int number) {
   return int(log10(number) + 1);
}
