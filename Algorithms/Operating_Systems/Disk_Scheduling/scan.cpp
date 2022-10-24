// SCAN
/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/scan-elevator-disk-scheduling-algorithms/?ref=lbp
         - https://www.javatpoint.com/os-scan-and-c-scan-algorithm
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int head,n,sum=0;
    cout<<"enter size of string :";
    cin>>n;
    vector<int> v(n+1);
    cout<<"enter the string \n";
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    cout<<"enter head :";
    cin>>v[0];
    head= v[0];
    v.push_back(0);
    sort(v.begin(),v.end());
    //moving towards left first
    sum = v[n+1];
    cout<<sum+head;
    
return 0;
}
