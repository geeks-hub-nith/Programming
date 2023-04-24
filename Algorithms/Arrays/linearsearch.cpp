#include<iostream>
using namespace std;
int linear_search(int arr[],int n ,int key)
{
    for(int i=0;i<n;i++)
    {
        if (arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    cout<<"enter array elements"<<endl;
    for (int i=0;i<n;i++)
    {   cin>>arr[i];
    }
    cout<<"enter element to be searched = ";
    int k;
    cin>>k;
    int ans;
    ans=linear_search(arr,n,k);
    if (ans==-1)
        cout<<k<<" not found in the list";
    else cout<<k<<" found in the list at index "<<ans<<" and position "<<ans+1;


}
