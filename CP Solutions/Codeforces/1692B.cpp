// Link: https://codeforces.com/contest/1692/problem/B
// Author: darkwhite0
#include <stdio.h>
int countDistinct(int a[], int n) 
{
   int i, j, count = 1;
   for (i = 1; i < n; i++)  
   {
      for (j = 0; j < i; j++)   
      {
         if (a[i] == a[j]) 
         {
            break;             
         }
      }
      if (i == j)
      {
         count++;
      }
   }
   return count;      
}
int main(){
    int t, i, n, j, x;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d", &n);
        int arr[n];
        for(j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        x = countDistinct(arr, n);
        if((n - x) % 2 == 0){
            printf("%d\n", x);
        } else{
            printf("%d\n", x - 1);
        }
    }
}