/*
    Author :   Sahil (sahil180702@gmail.com)
*/
//Binary Search
// Time complexity :  O(n) , Space complexity  : O(1)

#include <iostream>
using namespace std;


template <class T>
bool binary_search(T *a,T key,int low,int high){
    int mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==key) return true; 
        if(a[mid]<key) low = mid+1;
        else high = mid-1;
    }
    return false;
}

int main(){
    int a[]={1,3,5,7,10}; // Array must be sorted 
    cout<<binary_search<int>(a,3,0,5)<<endl;
    cout<<binary_search<int>(a,13,0,5)<<endl;
    return 0;
}