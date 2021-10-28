
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200006];
int b[200006];
pair <int,int> c[200006];
pair <int, pair <int,int> > d[200006];
int n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        c[i] = {b[i],i};
    }
    sort(a,a+n,greater<int>());
    sort(c,c+n);
    for(int i = 0; i < n; i++){
        d[i] = {c[i].second,{i,c[i].first}};
    }
    sort(d,d+n);
    for(int i = 0; i < n; i++){
        cout << a[((d[i].second).first)] << " ";
    }
    
	return 0;
}