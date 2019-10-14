#include<bits/stdc++.h>
using namespace std;

//function to print array
void display(int arr[], int n){
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

//insertion sort function
void insertion_sort(int arr[], int n){
  int key;
  for(int i = 1; i < n; i++){
    key = arr[i];
    int j = i-1;
    //finding suitable index for key
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    //inserting key
    arr[j+1] = key;
  }
}
int main(){
  int arr[] = {9,8,7,6,5,5,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  insertion_sort(arr, n); //calling insertion_sort function
  display(arr, n); //calling display function
  return 0;
}