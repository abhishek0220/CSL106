#include <bits/stdc++.h> 
using namespace std; 
  
// Function for insertion sort using recursion
void insertionSort(int arr[], int n) 
{ 
    // Base case 
    if (n <= 1) 
        return; 
  
    // Sort n-1 elements 
    insertionSort( arr, n-1 ); 

    //insert element at index n-1 in between 0 to n-1
    int end = arr[n-1]; 
    int j = n-2; 
    while (j >= 0 && arr[j] > end) 
    { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = end; 
} 
  
// Function to print an array of size n 
void display(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] <<" "; 
    cout << endl;
} 
  
int main() 
{ 
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("C:/Users/abhis/Pictures/input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("C:/Users/abhis/Pictures/output.txt", "w", stdout);
	#endif

    int arr[] = {12, 11, 13, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    insertionSort(arr, n); 
    display(arr, n); 
    return 0; 
} 