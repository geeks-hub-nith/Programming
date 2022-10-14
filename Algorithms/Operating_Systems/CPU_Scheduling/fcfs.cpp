/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/?ref=lbp
         - https://www.javatpoint.com/os-fcfs-scheduling
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    cout<<fixed<<setprecision(2);
    int n;
    cout<<"enter no of processes :";
    cin>>n;
    int total_time=0;
    vector<int> process(n),burst(n),arrival(n),waiting(n),turnaround(n);
    cout<<"enter arrival time and burst time for the processes\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arrival[i]>>burst[i];
        total_time+= burst[i];
        process[i]=i+1;
    }
    vector<int> rep(n);
    rep[0]=0;
    for (int i = 1; i < n; i++)
    {
        rep[i]=rep[i-1] +burst[i-1];
        if(rep[i]-arrival[i]<0) waiting[i]=0;
        else waiting[i]=(rep[i]-arrival[i]);
    }
    for (int i = 0; i < n; i++)
    {
        turnaround[i]= waiting[i]+burst[i];
    }
    
    cout<<"Process  | Arrival time  | Burst time  | Turnaround time  | Waiting time  | \n";
    for (int i = 0; i < n; i++)
    {
        cout<<setw(5)<<"P"<<process[i]
            <<setw(15)<<arrival[i]
            <<setw(15)<<burst[i]
            <<setw(15)<<turnaround[i]
            <<setw(15)<<waiting[i]
            <<"\n";
    }
    double x= accumulate(turnaround.begin(),turnaround.end(),0);
    cout<<setw(50)<<"avg = "<<double(accumulate(turnaround.begin(),turnaround.end(),0))/double(n);
    cout<<setw(10)<<"avg = "<<double(accumulate(waiting.begin(),waiting.end(),0))/double(n);
    cout<<"\nThroughput = "<<double(n*100)/total_time;
return 0;
}
