/*
    Author : prashant_th18
                            :)
*/
// Bubble Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void BubbleSort(vector<int> &v)
{
    int size = (int)v.size();
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 0; j < size - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                v[j] = v[j] + v[j + 1];
                v[j + 1] = v[j] - v[j + 1];
                v[j] = v[j] - v[j + 1];
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    BubbleSort(v);
    for(auto val : v)
    {
        cout << val << space;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}