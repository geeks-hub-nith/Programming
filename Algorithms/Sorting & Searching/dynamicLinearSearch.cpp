/*[PROG] -> LINEAR SEARCH USING C++

In this program, linear search algorithm is implemented on a dynamic array.
If the element is present in the array, then print the index number else print "Element not found"

Time Complexity : O(n)

*/

#include<iostream>
using namespace std;

int main(){

    // Creating a dynamic array
    int n,*arr,key,i;

    //Entering the size of array
    cout<<"Enter the size of array: ";
    cin>>n;
    arr = new int [n];

    //Inserting the values in the array
    cout<<"Enter the values in the array: ";
    for(int j=0;j<n;j++){
        cin>>*(arr+j);
    }

    //Entering the search value
    cout<<"Enter the value to search: ";
    cin>>key;

    //Traversing the array to search the value which was entered by the user
    for(i=0;i<n;i++){
        if(*(arr+i)==key){
            cout<<"Element found at "<<i+1<<" position"<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"Element not found"<<endl;
    }

    //Freeing up the space occupied by the array
    delete [] arr;

    return 0;
}


/*
OUTPUT:

1.
Enter the size of array: 5
Enter the values in the array: 12 23 43 2 45
Enter the value to seacrh: 23
Element found at 2 position

2.
Enter the size of array: 5
Enter the values in the array: 12 23 34 56 67
Enter the value to seacrh: 90
Element not found

Program by Ayush Anand: @ayushanand09 --> github username
*/
