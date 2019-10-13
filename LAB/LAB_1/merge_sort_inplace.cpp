#include <bits/stdc++.h> 
using namespace std; 

void merge(int arr[], int l, int r) 
{
	if (l < r) { 
	    int m = l + (r - l) / 2; 
	    merge(arr, l, m); 
	    merge(arr, m + 1, r); 
	    int t2 = m + 1;
	    if (arr[m] > arr[r]) { 
		    while (l <= m && t2 <= r) { 
		        if (arr[l] <= arr[t2]) { 
		            l++; 
		        } 
		        else { 
		            int val = arr[t2]; 
		            int in = t2;  
		            while (in != l) { 
		                arr[in] = arr[in - 1]; 
		                in--; 
		            } 
		            arr[l] = val; 
		            l++; 
		            m++; 
		            t2++; 
		        } 
		    } 
		}
  	} 
} 
void display(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	  cout<<arr[i]<<" ";
	cout<<endl;
} 
int main() 
{
  int arr[]={9,8,7,6,5,5,3,2,1};
  int n=sizeof(arr)/sizeof(arr[0]);
  merge(arr,0,n-1); //calling merge function
  display(arr,n); //calling display function
  return 0; 
} 