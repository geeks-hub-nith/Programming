/*
Link: https://codeforces.com/problemset/problem/282/A
Author: TinyCodersDen
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 0; // Main answer variable
    int n; // Number of test cases
    cin >> n;
    for (int t = 0; t<n; t++){
        string k;
        cin >> k;
        if (k=="++X" || k=="X++"){ // Possibilities of adding to a variable
            x++;
        }
        else{ // Otherwise it's subtraction
            x--;
        }
    }
    cout << x;
    return 0;
}
