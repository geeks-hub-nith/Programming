#include<iostream>
using namespace std;
void swapp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int median(int arr[],int l,int h,int k)
{
    int i=h-l+1;
    int index=rand()%i;
    int s1[h];
    int s2[h];
    int s3[h];
    int j=0,m=0,n=0;
    for(int i=0;i<=h;i++)
    {
        if(arr[i]==arr[index])
        {
            s2[j]=arr[i];
             j++;
        }
        else if(arr[i]<arr[index])
        {
            s1[m]=arr[i];
            m++;
        }
        else{
            s3[n]=arr[i];
            n++;
        }
    }
    if(m>=k)
    {
        median(s1,0,m-1,k);
    }
    else if(j+m>=k)
    {
        return arr[index];
    }
    else{
        median(s3,0,n-1,k-j-m);
    }
}
void selection(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int imin=i;
        for(int j=i+1;j<=n;j++)
        {
            if(arr[j]<=arr[imin])
            {
                imin=j;
            }
        }
        swapp(&arr[i],&arr[imin]);

    }
}
int partitionn(int arr[],int h,int l)
{
    int pivot=arr[h];
    int pi=l-1;
    for(int i=l;i<h;i++)
    {
        if(arr[i]<=pivot)
        {
            pi++;
            swapp(&arr[i],&arr[pi]);
        }
    }
    swapp(&arr[pi+1],&arr[h]);
    return (pi+1);
}
void qsort(int arr[],int h,int l)
{
    if(l<h)
    {
        int pi=partitionn(arr,h,l);
        qsort(arr,pi-1,l);
        qsort(arr,h,pi+1);
    }
}
void insertion(int arr[],int n)
{

    for(int i=0;i<=n;i++)
    {
        int val=arr[i];
        int hole=i;
        while(hole>0&&arr[hole-1]>val)
        {
            arr[hole]=arr[hole-1];
            hole=hole-1;
        }
        arr[hole]=val;
    }
}
void mergee(int L[],int R[],int arr[],int l,int r)
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<l)
    {
        arr[k]=L[i];
            i++;
            k++;
    }
    while(j<r)
    {
        arr[k]=R[j];
            j++;
            k++;
    }
}
void mergesort(int arr[],int n)
{
    if(n<2)
        return;
    int mid=n/2;
    int left[mid];
    int right[n-mid];
    for(int i=0;i<=mid-1;i++)
    {
        left[i]=arr[i];
    }
    for(int i=mid;i<=n-1;i++)
    {
        right[i-mid]=arr[i];
    }
    mergesort(left,mid);
    mergesort(right,n-mid);
    mergee(left,right,arr,mid,n-mid);
}
void countsort(int arr[],int n,int div)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    int countt[m]={0};
    for(int i=0;i<n;i++)
    {
        countt[(arr[i]/div)%10]++;
    }
    for(int i=1;i<=m;i++)
    {
         countt[i]+=countt[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--countt[(arr[i]/div)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radix(int arr[],int n)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    for(int div=1;(m/div)>0;div=div*10)
    {
        countsort(arr,n,div);
    }
}
void print(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main()
{
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
for(int i=0;i<n;i++){
    cout<<"Enter the element "<<i+1<<" : ";
    cin>>a[i];

}


    //cout<<median(a,0,n-1,3);
    //selection(a,n-1);
    //qsort(a,n-1,0);
    //insertion(a,n-1);
    //mergesort(a,n);
    //countsort(a,n);
    radix(a,n);
    cout<<endl<<"Sorted Array : "<<endl;
    print(a,n);


}
