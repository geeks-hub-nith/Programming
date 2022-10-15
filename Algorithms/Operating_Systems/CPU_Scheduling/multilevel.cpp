/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/?ref=lbp
         - https://www.javatpoint.com/multilevel-queue-scheduling-in-operating-system

    This specific problem-
    multilevel queue scheduling
        queue1 sjf non preemptive
        queue2 fcfs
        queue1 has fixed priority over queue2
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[10][6];
//[][0]-PID,[][1]- queue no., [][2]- burst time, [][3]- waiting time, [][4]-turn_around time
int main ()
{
    cout<<fixed<<setprecision(2);
    int n;
    cout<<"enter no of processes : ";
    cin>>n;
    int total_time=0;            // total time 
    int m=0;
    cout<<"enter queue no. - 0/1 (sjf preemptive/ fcfs) and burst time for the processes\n"; // 0-> sjf preemptive 1-> fcfs
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i][1]>>arr[i][2]; // queue, burst time
        arr[i][0]=i+1;             // PID
        if(arr[i][1]==0) m++;      // number of processes in queue 1
        total_time+= arr[i][2];   
        
    }
    int remaining_t[n];
    for (int i = 0; i < n; i++)
    {
       remaining_t[i] = arr[i][2];
    }

    int complete = 0, min_time = INT_MAX,shortest = 0, completion_time=0;
    // bool check = false;


    // queue 1 will be given priority over and processes in queue 1 will undergo sf=jf non preemptive scheduling
    while (complete != m) {
 
        for (int j = 0; j < n; j++) {
            if ((remaining_t[j] < min_time) && remaining_t[j] > 0  && !arr[j][1]) {
                min_time = remaining_t[j];
                shortest = j;
            }
        }
 
        remaining_t[shortest]=0;
        min_time = 0;

        // when the process gets completely executed
        if (min_time == 0)
            {
            min_time = INT_MAX;
            complete++;
            completion_time += arr[shortest][2];
            arr[shortest][4]= completion_time; // completion time
            arr[shortest][3] = completion_time -arr[shortest][2];
            // waiting time = completion time - burst time - arrival time( arrival time is 0 for all processes)
 
            if (arr[shortest][3] < 0)
                arr[shortest][3] = 0;
            }
 
    }

    // Now remaining processes of queue 2 will be done according to fcfs
    for (int i = 0; i < n ; i++)
    {
        if(arr[i][1])
        {
            arr[i][3]= completion_time;
            arr[i][4]= arr[i][3]+ arr[i][2];
            completion_time+= arr[i][2];
        }
    }

    int total_turnaround=0,total_waiting=0;
    for (int i = 0; i < n; i++)
    {
        total_waiting+= arr[i][3];
        total_turnaround += arr[i][4];
    }

     cout<<"Process Id\tBurst time\tTurnaround time\tWaiting time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i][0]<<"\t\t"<<arr[i][2]<<"\t\t"<<arr[i][4]<<"\t\t"<<arr[i][3]<<"\n";
    }
    cout<<"\t\t\t\t"<<double(total_turnaround)/double(n)<<"\t\t"<<double(total_waiting)/double(n)<<"\n";
    cout<<"Throughput = "<<double(n*100)/total_time;

return 0;
}
