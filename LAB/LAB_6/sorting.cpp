#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
void selectionSort(int dizi[], int elemanSayisi) {
    int i, j, enKucuk, temp;
    for (i = 0; i < elemanSayisi - 1; i++) {
        enKucuk = i;
        for (j = i + 1; j < elemanSayisi; j++) {
            if (dizi[j] < dizi[enKucuk])
                enKucuk = j;
        }
        temp = dizi[i];
        dizi[i] = dizi[enKucuk];
        dizi[enKucuk] = temp;
    }
}
void bubbleSort(int dizi[], int elemanSayisi) {
    int temp;
    int i, j;

    for (i = 1; i < elemanSayisi; i++) {
        for (j = 0; j < elemanSayisi - i; j++) {
            if (dizi[j] > dizi[j + 1]) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void make(int arr2[],int arr[],int n){
  for(int i=0;i<n;i++)
    arr2[i]=arr[i];
}
int main(){
  int n=10000;
  int arr[n];
  for(int i=0;i<n;i++){
    arr[i]=rand();
    //cout<<arr[i]<<" ";
  }
  cout<<endl;
  int arr2[n];
  make(arr2,arr,n);
  auto start = high_resolution_clock::now();  
  selectionSort(arr2,n);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<microseconds>(stop - start); 
  cout << "Time taken by selectionSort: "<< duration.count() << " microseconds" << endl;
  make(arr2,arr,n);
  start = high_resolution_clock::now();  
  bubbleSort(arr2,n);
  stop = high_resolution_clock::now(); 
  duration = duration_cast<microseconds>(stop - start); 
  cout << "Time taken by BubbleSort: "<< duration.count() << " microseconds" << endl; 
  make(arr2,arr,n);
  start = high_resolution_clock::now();  
  quickSort(arr2,0,n-1);
  stop = high_resolution_clock::now(); 
  duration = duration_cast<microseconds>(stop - start); 
  cout << "Time taken by quickSort: "<< duration.count() << " microseconds" << endl; 
  return 0;
}