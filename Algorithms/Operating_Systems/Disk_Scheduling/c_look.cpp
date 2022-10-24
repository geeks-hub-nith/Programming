// C-LOOK
/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/c-look-disk-scheduling-algorithm/?ref=lbp
         - https://www.javatpoint.com/os-look-and-c-look-scheduling
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,sum=0, head;
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
    // moving to left first
    sort(v.begin(),v.end());
    auto it = find(v.begin(),v.end(),head);
    int ind = it- v.begin();
    sum = v[n]- v[0];
    sum += head - v[0];
    sum += (v[n]-v[ind+1]);
    cout<<sum<<endl;

return 0;
}
