/*
    Author :   Sahil (sahil180702@gmail.com)
    Link : https://www.geeksforgeeks.org/binary-search/
*/

#include <iostream>
using namespace std;
/*
Binary Search
Binary Search: Search a sorted array by repeatedly dividing the search interval in half.
Begin with an interval covering the whole array.


Time complexity :  O(n) , Space complexity  : O(1)
*/

template <class T>
bool binary_search(T *a,T key,int low,int high){
    int mid;
    while (low<=high) // it is the  base condition to terminate the loop 
    {
        mid = (low+high)/2;
        if(a[mid]==key) return true; // if value at mid of array is equal to key , then we return true and function stop executing.
        if(a[mid]<key) low = mid+1; // if value at mid is less then the value of key then we proceed with the second half of the array.
        else high = mid-1; // if value at mid is greater then the value of key then we proceed with the first half of the array.
    }
    return false; // by default we return false (if key is not found in given internval)
}

int main(){
    int a[]={1,3,5,7,10}; // Array must be sorted 
    cout<<binary_search<int>(a,3,0,5)<<endl;
    cout<<binary_search<int>(a,13,0,5)<<endl;
    return 0;
}