// Link: https://codeforces.com/contest/1735/problem/B
#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long int ll;
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define vl vector<long long>
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

void solve_case()
{
 	ll n ; cin>>n;

 	vl a(n);
 	for(int i=0 ; i<n ; i++)
 	cin>>a[i];

 	ll mn = 2*a[0] - 1;
 	ll ans = 0;
 	for(int i=1 ; i<n ; i++)
 	{
 		ans += (a[i]/mn) ;
 		if(a[i]%mn == 0)
 			ans-- ;
 	}

 	cout<<ans<<endl;	 
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve_case();
    }
    return 0;
}
