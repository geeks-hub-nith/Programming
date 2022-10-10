#include<iostream>
using namespace std;

/*question: https://practice.geeksforgeeks.org/problems/heap-sort/1*/


//function to swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        swap(&arr[index], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    
    buildHeap(arr,n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    int arr[10] = {3,42,1,4,76,9,54,8,87,23};
    heapSort(arr,10);
    for(int i=0; i<10; ++i){
        cout<< arr[i] << " ";
    }
    return 0;
}