/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/?ref=lbp
         - https://www.javatpoint.com/os-sjf-scheduling
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mt[10][6];
int aar[10][6];

int main ()
{
    cout<<fixed<<setprecision(2);
    int n;
    cout<<"enter no of processes\n";
    cin>>n;
    int total_time=0;

    cout<<"enter process id,arrival time and burst time for the no processes in the order in which they arrive\n";
   
    for (int i = 0; i < n; i++)
    {
        cin>>aar[i][0]>>aar[i][1]>>aar[i][2];
        total_time += aar[i][2];
    }
    aar[0][3]=aar[0][1]+aar[0][2]; // completion time
    aar[0][5] = aar[0][2];         // turnaround time
    aar[0][4]= 0;                  //waiting time
    for (int i = 1; i < n; i++)
    {
        int x,y,val;
        x = aar[i - 1][3];
        y = aar[i][2];
        for (int j = i; j < n; j++) {
            if (x >= aar[j][1] && y >= aar[j][2]) {
                y = aar[j][2];
                val = j;
            }
        }
        aar[val][3] = x + aar[val][2];
        aar[val][5] = aar[val][3] - aar[val][1];
        aar[val][4] = aar[val][5] - aar[val][2];
        for (int k = 0; k < 6; k++) {
            swap(aar[val][k], aar[i][k]);
            
        }
    }
    double avg_turnaround=0,avg_waiting=0;
    int t_turn=0,t_wait=0;
    for (int i = 0; i < n; i++)
    {
        t_turn += aar[i][5];
        t_wait += aar[i][4];
    }
    avg_turnaround= (double)t_turn/double(n);
    avg_waiting= (double)t_wait/(double)n;
    
    cout<<"Process Id\tArrival time\tBurst time\tCompletion time\tTurnaround time\tWaiting time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<aar[i][0]<<"\t\t"<<aar[i][1]<<"\t\t"<<aar[i][2]<<"\t\t"<<aar[i][3]<<"\t\t"<<aar[i][5]<<"\t\t"<<aar[i][4]<<"\n";
    }

    cout<<"\t\t\t\t\t\t\t\t"<<avg_turnaround<<"\t\t"<<avg_waiting<<"\n";
    cout<<"Throughput = "<<double(n*100)/total_time;
return 0;
}
