// fcfs disk
/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.javatpoint.com/os-fcfs-scheduling-algorithm
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    int head;
    cout<<"enter the size of refrence string :";
    cin>>n;
    cout<<"enter head :";
    cin>>head;
    vector<int> v(n+1);

    int sum=0;
    cout<<"enter string :\n";
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    v[0]= head;
    for (int i = 1; i <= n; i++)
    {
        sum += max((v[i]-v[i-1]),(v[i-1]-v[i]));
    }
    cout<<sum<<endl;
    
return 0;
}
