// Link: https://codeforces.com/contest/1547/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
     cin >> t;
     while(t--){
        string s;
        cin >> s;
        vector<char> v;
        for(auto letter: s) v.push_back(letter);
        char prev = '0';
        while(v.begin() != v.end()){
            vector<char> :: iterator max = v.end();
            max--;
            if(*(v.begin()) > *max) max = v.begin();
            if(prev != '0' && *max != prev - 1){
                cout << "NO\n";
                break;
            }
            prev = *max;
            v.erase(max);
        }
        if(v.begin() == v.end()){
            if(*(v.begin()) == 'a') cout << "YES\n";
            else cout << "NO\n";
        }
     }
}