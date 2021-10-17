// link- https://cses.fi/problemset/task/1638/
// AUTHOR :SHIVANSH
#include <iostream>
using namespace std;
#define M 1000000007
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char arr[n + 1][n + 1];
    long long int ar[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &arr[i][1]);
    }
    arr[0][0] = 0;
    for (int j = 1; j <= n; j++)
    {
        ar[0][j] = 0;
    }
    for (int j = 1; j <= n; j++)
    {
        ar[j][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                if (arr[1][1] != '*')
                {
                    ar[1][1] = 1;
                }
                else
                {
                    ar[1][1] = 0;
                }
            }
            else
            {
                if (arr[i][j] != '*')
                {
                    ar[i][j] = (ar[i - 1][j] + ar[i][j - 1]) % M;
                }
                else
                {
                    ar[i][j] = 0;
                }
            }
        }
    }
    printf("%d", ar[n][n]);
    return 0;
}
