// Link: https://codeforces.com/contest/451/problem/A
// Author: cvanshul

#include <iostream>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    
    if (min(n,m)%2==0)
    {
        cout<<"Malvika"<<endl;
    }
    else{
        cout<<"Akshat"<<endl;
    }
 
    return 0;
}
 

