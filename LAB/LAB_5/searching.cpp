#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class searching{
    public:
    int* arr;
    int size;
    searching(int ar[],int n){
        size = n;
        arr = new int[size];
        for(int i=0;i<n;i++)
            arr[i]=ar[i];
    }  
    void bubbleSort() {
        int temp;
        int i, j;
        for (i = 1; i < size; i++) {
            for (j = 0; j < size - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void linear(int da){
        int con=-1;
        for(int i=0;i<size;i++){
            if(arr[i]==da){
                con=i;
                break;
            }
        }
        if(con==-1)
            cout<<"NOT Found"<<endl;
        else
            cout<<"Found at index "<<con<<endl;
    }
    void display(){
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }  
};
int main(){
    int n=10000;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand();
        //cout<<arr[i]<<" ";
    }
    int tem=arr[0];
    searching sr(arr,n);
    sr.bubbleSort();
    auto start = high_resolution_clock::now();
    sr.linear(tem);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by linear search: "<< duration.count() << " microseconds" << endl;
    return 0;
}