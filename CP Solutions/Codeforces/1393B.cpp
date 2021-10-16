// link - https://codeforces.com/problemset/problem/1393/B
// AUTHOR : SHIVANSH

#include <iostream>
#include <unordered_map>
#include <utility>
#include <set>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    unordered_map<int, int> hr;
    unordered_map<int, int>::iterator it;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        hr[arr[i]]++;
    }
    pair<int, int> a;
    set<pair<int, int>> st;
    set<pair<int, int>>::reverse_iterator ti;
    for (it = hr.begin(); it != hr.end(); it++)
    {
        a.second = (*it).first;
        a.first = (*it).second;
        st.insert(a);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char p;
        int b;
        pair<int, int> e, u, v, s;
        getchar();
        scanf("%c %d", &p, &b);
        if (p == '+')
        {
            e.first = hr[b];
            e.second = b;
            st.erase(e);
            hr[b]++;
            e.first = hr[b];
            e.second = b;
            st.insert(e);
        }
        else
        {
            e.first = hr[b];
            e.second = b;
            st.erase(e);
            hr[b]--;
            e.first = hr[b];
            e.second = b;
            st.insert(e);
        }
        u = *(st.rbegin());
        ti = st.rbegin();
        if (st.size() >= 2)
        {
            ti++;
            v = *ti;
        }
        if (st.size() >= 3)
        {
            ti++;
            s = *ti;
        }
        if (u.first >= 8)
        {
            printf("YES\n");
        }
        else
        {
            if (st.size() >= 2)
            {
                if (u.first >= 4)
                {
                    if (u.first >= 6 && v.first >= 2)
                    {
                        printf("YES\n");
                    }
                    else if (v.first >= 4)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        if (st.size()>= 3 && s.first >= 2)
                        {
                            printf("YES\n");
                        }
                        else
                        {
                            printf("NO\n");
                        }
                    }
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
