// Link: https://codeforces.com/contest/231/problem/A
// Author: cvanshul

#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; cin >> n;
	int ans = 0;
 
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		int tmp = (a + b + c) / 2;
		ans += tmp;
	}
 
	cout << ans << endl;
 
	return 0;
}