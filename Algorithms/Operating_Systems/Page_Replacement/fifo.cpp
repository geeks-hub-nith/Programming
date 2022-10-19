/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main ()
{
    cout<<"Enter size of reference string: ";
    int n; cin>>n;

    cout<<"Enter the refernce string: \n";
    vector<int> v(n),v_frames;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i==0) v_frames.push_back(v[i]);
    }
    int frm,faults=0;;
    cout<<"enter the no of page frames: ";
    cin>>frm;
    
    
    for (int i = 1; i < n; i++)
    {
        bool flag= true;
        for (int j = 0; j < v_frames.size() ; j++)
        {
            if(v[i]== v_frames[j]){
                flag= false;
                break;
            }
        }
        if(!flag) continue;
        if(v_frames.size()<frm)
        {
            v_frames.push_back(v[i]);
            faults++;
        }
        else {
            v_frames.erase(v_frames.begin());
            v_frames.push_back(v[i]);
            faults++;  
        }
    }
    cout<<"faults are: "<<faults+1;

return 0;
}
