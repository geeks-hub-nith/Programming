/*
Link to the problem :https://codeforces.com/contest/814/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--){
        int repaint;
        cin >> repaint;
        char c;
        cin >> c;
        int begin = 0;
        int end = 0;
        int koyomity = 0;
        while (begin < n && end < n){
            while (end < n){
                if (s[end] != c){
                    if (repaint == 0){
                        break;
                    }
                    repaint--;
                }
                end++;
            }
            koyomity = max(koyomity, end - begin);
            if (s[begin] != c){
                repaint++;
            }
            begin++;
        }
        cout << koyomity << endl;
    }
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
    solve();
    cerr << fixed << setprecision(10);
    cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}