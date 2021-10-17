// Link: https://cses.fi/problemset/task/1755
// Author: aryanpathania
#include <bits/stdc++.h>
#define MOD 1'000'000'007
//#define MOD = 998'244'353
#define fo(x) for(int i=0;i<x;i++)
#define fo2(x) for(int j=0; j<x; j++)
#define int int64_t
typedef long long ll;
typedef long double ld;
using namespace std;
 
void solve(){
    int n,m,k,p,q,r,count = 0, sum = 0, ans = 0; std::string s;
    std::cin >> s;
    std::map<char,int> mp;
    for (auto &&i : s){
        mp[i]++;
    }
    int oddc = 0;
    char oddchar;
    for (auto &&i : mp)
    {
        if(i.second&1){
            oddchar = i.first;
            oddc++;
        }
    }
    if(oddc > 1){
        std::cout << "NO SOLUTION" << '\n';
        return;
    }
 
    std::string opt;
    for (auto &&i : mp){
        for (int r = 0; r < i.second/2; r++){
            opt += i.first;
        }
    }
    std::cout << opt;
    if(oddc){
        std::cout << oddchar;
    }
    std::reverse(opt.begin(),opt.end());
    std::cout << opt;
    std::cout << '\n';
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
