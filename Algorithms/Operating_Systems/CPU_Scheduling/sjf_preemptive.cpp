/*
    Author - Sahil Verma (sahil19-19)
    link - https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/?ref=lbp
         - https://www.javatpoint.com/os-sjf-scheduling
*/
#include<bits/stdc++.h>
using namespace std;

int arr[10][6];
//[][0]-PID,[][1]- arrival time, [][2]- burst time, [][3]- waiting time, [][4]-turn_around time
  
int main()
{
    int n;

    cout << "Enter number of Process: ";
    cin >> n;
    int total_time=0;
    cout<<"enter process id,arrival time and burst time for the no processes \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        total_time += arr[i][2];
    }

    int remaining_t[n];
    for (int i = 0; i < n; i++)
    {
       remaining_t[i] = arr[i][2];
    }
    
    int complete = 0, t = 0, min_time = INT_MAX,shortest = 0, completion_time;
    bool check = false;

    while (complete != n) {
 
        for (int j = 0; j < n; j++) {
            if ((arr[j][1] <= t) &&(remaining_t[j] < min_time) && remaining_t[j] > 0) {
                min_time = remaining_t[j];
                shortest = j;
                check = true;
            }
        }
 
        if (check == false) {
            t++;
            continue;
        }
 
        remaining_t[shortest]--;
        min_time = remaining_t[shortest];

        // when the process gets completely executed
        if (min_time == 0)
            {
            min_time = INT_MAX;
            complete++;
            check = false;
            completion_time = t + 1;
            arr[shortest][5]= completion_time; // completion time
            arr[shortest][3] = completion_time -arr[shortest][2] - arr[shortest][1];
            // waiting time = completion time - burst time - arrival time
 
            if (arr[shortest][3] < 0)
                arr[shortest][3] = 0;
            }
 
        t++;
    }
    int total_turnaround=0,total_waiting=0;
    for (int i = 0; i < n; i++)
    {
        arr[i][4]=arr[i][3]+ arr[i][2];
        // turnaround time = waiting time + burst time
        total_waiting+= arr[i][3];
        total_turnaround += arr[i][4];

    }

    cout<<"Process Id\tArrival time\tBurst time\tTurnaround time\tWaiting time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i][0]<<"\t\t"<<arr[i][1]<<"\t\t"<<arr[i][2]<<"\t\t"<<arr[i][4]<<"\t\t"<<arr[i][3]<<"\n";
    }
    cout<<"\t\t\t\t\t\t"<<double(total_turnaround)/double(n)<<"\t\t"<<double(total_waiting)/double(n)<<"\n";
    cout<<"Throughput = "<<double(n*100)/total_time;

}
    
