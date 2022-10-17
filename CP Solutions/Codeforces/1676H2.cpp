/*
Link to the problem: https://codeforces.com/contest/1676/problem/H2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define endl "\n";
#define ceil(x, y) x / y + (x % y != 0)
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

//____________________________________________________________________________________________________________________________________________________________

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print_(x);cerr<<endl;
#else
#define debug(x)
#endif

//____________________________________________________________________________________________________________________________________________________________

void _print_(ll t) { cerr << t; }
void _print_(int t) { cerr << t; }
void _print_(string t) { cerr << t; }
void _print_(char t) { cerr << t; }
void _print_(long double t) { cerr << t; }
void _print_(double t) { cerr << t; }

//____________________________________________________________________________________________________________________________________________________________

template <class T, class V> void _print_(pair <T, V> p);
template <class T, class V> void _print_(pair <T, V> p) { cerr << "{"; _print_(p.first); cerr << ","; _print_(p.second); cerr << "}"; }
template <class T> void _print_(set <T> v);
template <class T> void _print_(set <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print_(map <T, V> v);
template <class T, class V> void _print_(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(multiset <T> v);
template <class T> void _print_(multiset <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(vector <T> v);
template <class T> void _print_(vector <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }

//____________________________________________________________________________________________________________________________________________________________

typedef tree<int, null_type, less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_MultiSet;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vect(n);
    for (ll i = 0; i < n; i++){
        cin >> vect[i];
    }
    ll key = 0;
    ordered_MultiSet s1;
    s1.insert(vect[0]);
    ll inv_count = 0;
    for (int i = 1; i < n; i++){
        key = s1.order_of_key(vect[i]);
        inv_count += (s1.size() - key);
        s1.insert(vect[i]);
    }
    cout << inv_count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    ll testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    cerr << fixed << setprecision(10);
    cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}