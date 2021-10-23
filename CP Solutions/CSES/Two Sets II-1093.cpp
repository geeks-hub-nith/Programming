// AUTHOR -SHIVANSH
//LINK-https://cses.fi/problemset/task/1093/
#include <iostream>
using namespace std;
#define M 1000000007
int arr[502][62627];
long long int modinverse(long long int c, long long int m);
void extendeuclid(long long int a, long long int b);
long long int d, x, y;
long long int modinverse(long long int c, long long int m)
{
  extendeuclid(c, m);
  return (x % m + m) % m;
}
void extendeuclid(long long int a, long long int b)
{
  if (b == 0)
  {
    d = a;
    x = 1;
    y = 0;
  }
  else
  {
    extendeuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  int s = (n * (n + 1)) / 2;
  if (s % 2)
  {
    printf("0\n");
  }
  else
  {
    s = s / 2;
    arr[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      int p = (i * (i + 1)) / 2;
      if(i==n)
      {
        p=s;
      }
      for (int j = 0; j <= p; j++)
      {
        if (j < i)
        {
          arr[i][j] = arr[i - 1][j];
        }
        else
        {
          arr[i][j] = ((arr[i - 1][j - i]) + (arr[i - 1][j])) % M;
        }
      }
    }
    long long int q = modinverse(2, M), r = arr[n][s];
    // printf("%lld %lld\n", q, r);
    printf("%lld\n", (q * r) % M);
  }
  return 0;
}
