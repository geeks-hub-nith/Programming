// Link-https://cses.fi/problemset/task/1145/
// AUTHOR- SHIVANSH

#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1], ar[n + 1], p = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    ar[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] > ar[p] || arr[i] <=ar[1])
        {
            if (arr[i] > ar[p])
            {
                p++;
                ar[p] = arr[i];
            }
            else
            {
                ar[1] = arr[i];
            }
        }
        else
        {
            int l = 1, r = p;
            while (r - l > 1)
            {
                int mid = (r + l) / 2;
                if (ar[mid] < arr[i])
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            ar[r] = arr[i];
        }
    }
    printf("%d", p);
    return 0;
}
