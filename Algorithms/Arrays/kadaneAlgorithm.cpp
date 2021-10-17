/*
    Author: Anurag Tripathi
    Link: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

// Largest Sum Contiguous Subarray (Kadane's Algorithm)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr1[n],currentSum=0,MAX=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        currentSum+=arr1[i];
        if(currentSum<0){
            currentSum=0;
        }
        MAX=max(currentSum,MAX);
    }
    cout<<MAX;
}