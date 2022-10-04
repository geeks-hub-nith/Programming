// Link: https://codeforces.com/contest/1712/problem/B
// Author: darkwhite0
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for(i = 0; i < n; i++) arr[i] = i + 1;
        for(i = n - 1; i > 0; i--){
            if((n - i) % 2 == 1){
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        for(auto val: arr) cout << val << " ";
        cout << endl;
    }
    return 0;
}