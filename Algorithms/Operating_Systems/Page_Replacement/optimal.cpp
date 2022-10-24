/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main ()
{
    cout<<"\nEnter size of reference string: ";
    int n; cin>>n;

    cout<<"Enter the refernce string: \n";
    vector<int> v(n),v_frames;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i==0) v_frames.push_back(v[i]);
    }
    int frm,faults=0;
    cout<<"enter the no of page frames: ";
    cin>>frm;
    int x;

    for (int i = 1; i < n; i++)
    {
        bool flag= true;
        for (int j = 0; j < v_frames.size() ; j++)
        {
            if(v[i]== v_frames[j])
            {
                flag= false;
                x=j;
                break;
            }
        }
        if(flag)
        {
            
            if(v_frames.size() < frm)
            {
                v_frames.push_back(v[i]);
                faults++;
            }
            else
            {
                vector<pair<int,int>> vec;
                for (int a = 0; a < frm;a++)
                {
                    for (int j = i+1; j < n ; j++)
                    {
                        if(v_frames[a]==v[j])
                        {
                            vec.push_back({j,a});
                            break;
                        }
                        vec.push_back({n+1,a});

                    }
                    
                }
                
                sort(vec.begin(),vec.end());
                x =  vec[frm-1].second;

                v_frames[x]=v[i];
                faults++;
                
            }
        }
    
    }
    cout<<"faults are: "<<faults+1;
    
return 0;
}
