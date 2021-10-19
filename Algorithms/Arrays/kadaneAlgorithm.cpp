/*
    Author: Anurag Tripathi
    Link: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

// Largest Sum Contiguous Subarray (Kadane's Algorithm)

#include<bits/stdc++.h>
using namespace std;
int main(){
    // Enter the array's size
    int n;
    cin>>n;

    // MAX variable denotes the maximum sum of subarray observed in whole process
    int arr1[n],currentSum=0,MAX=INT_MIN;

    // Enter elemets of the array
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        currentSum+=arr1[i];

        // if currentSum becomes less than 0, we start new sum of subarray from the next element
        if(currentSum<0){
            currentSum=0;
        }

        // Updating MAX value with currentSum
        MAX=max(currentSum,MAX);
    }
    cout<<MAX;
}