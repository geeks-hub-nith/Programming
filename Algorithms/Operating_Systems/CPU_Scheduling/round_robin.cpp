/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/?ref=lbp
         - https://www.javatpoint.com/os-round-robin-scheduling-algorithm
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main ()
{
    cout<<fixed<<setprecision(2);
    int n;
    cout<<"Enter no of processes : ";
	cin>>n;
    int arr[n][3];
    //[][0]-PID,[][1]- burst time, [][2]- waiting time, [][3]-turn_around time

    int total_time=0;
    int rem_time[n];
    cout<<"enter process id and burst time for the no processes \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        total_time += arr[i][1];
        rem_time[i]=arr[i][1];
    }
    int complete=0,quan;
    cout<<"enter time quantum: ";
    cin>>quan;
    int t=0;
    while (complete != n)
    {
        for (int i = 0; i < n; i++)
        {
            if(rem_time[i]>0)
            {
                int x;
                x= min(quan,rem_time[i]);
                t += max(x,0);         // increasing time
                rem_time[i]-=quan;
                if(rem_time[i]<=0) 
                {
                    complete++;        // incrementing "complete" when a process in=s completed
                    arr[i][3]=t;
                }
            }
        }

    }
    int total_turn=0,total_wait=0;
    for (int i = 0; i < n; i++)
    {
        arr[i][2]=arr[i][3]-arr[i][1]; // turnaround time = waiting time + burst time
        total_wait+= arr[i][2];
        total_turn+= arr[i][3];
    }
    
    cout<<"Process Id\tBurst time\tTurnaround time\tWaiting time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i][0]<<"\t\t"<<arr[i][1]<<"\t\t"<<arr[i][3]<<"\t\t"<<arr[i][2]<<"\n";
    }
    cout<<"\t\t\t\t"<<double(total_turn)/double(n)<<"\t\t"<<double(total_wait)/double(n)<<"\n";
    cout<<"Throughput = "<<double(n*100)/total_time;

return 0;
}