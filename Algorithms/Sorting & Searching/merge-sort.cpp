/*
    Author :- Sanchit Sharma (sanchitsharma543@gmail.com)
    Reference :- https://www.geeksforgeeks.org/merge-sort/
*/

// Merge-Sort Algorithm

#include <iostream>
using namespace std;


void merge(int arr[], int start, int mid, int end) {
    
    // temp array to store array before merging
    int A[end - start + 1];
    
    // using two variables to index first and second half of the given array
    int f = start, s = mid + 1;
    
    // to index array temp A
    int k = 0; 
    
    while (k <= end - start + 1) {
        // checks if first iterator has crossed mid mark if yes then just push element in second half
        if (f > mid) {
            A[k++] = arr[s++];
        } 
        // same check for the second half 
        else if (s > end) {
            A[k++] = arr[f++];
        } 
        // if none of the above holds true then just add the min element from the two indexes in the temp array
        else {
            if (arr[f] < arr[s]) {
                A[k++] = arr[f++];
            } else {
                A[k++] = arr[s++];
            }
        }
        
    }
    // overriding the given array with the temp array
    for (int i = 0; i < k; i++) {
        arr[start++] = A[i];
    }
    
}

void merge_sort(int A[], int start, int end) {

    if (start < end) {

        int mid = (start + end) / 2;

        merge_sort(A, start, mid);
        merge_sort(A, mid+1, end);

        merge(A, start, mid, end);

    }

}

// This algorithm sorts an array in non-decreasing order with worst case time complexity of O(nlogn).

int main() {
    int arr[5] = {-1, 4, -2, 2, 11};
    
    merge_sort(arr, 0, 4);
    
    for (int i = 0; i < 5; i++) cout << arr[i] << ' ';

    return 0;
}
