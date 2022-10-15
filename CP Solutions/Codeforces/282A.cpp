/*
Link: https://codeforces.com/problemset/problem/282/A
Author: TinyCodersDen
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 0;
    int n;
    cin >> n;
    for (int t = 0; t<n; t++){
        string k;
        cin >> k;
        if (k=="++X" || k=="X++"){
            x+=1;
        }
        else{
            x-=1;
        }
    }
    cout << x;
    return 0;
}
