#include<bits/stdc++.h>
using namespace std;
//function to print array
void display(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//funtion merge_sort
void merge(int arr[],int n){ //takes array as well as its size
  if(n==1)  //the base case if n==1 i.e array having only one element then return 
    return;
  int len_a,len_b;
  len_a=n/2;  //array 1 size
  len_b=n-len_a;  //array 2 size
  int lst1[len_a],lst2[len_b];
  for(int i=0;i<len_a;i++){ //making array one from arr
    lst1[i]=arr[i];
  }
  for(int i=len_a;i<n;i++){ //making array two from arr
    lst2[i-len_a]=arr[i];
  }
  merge(lst1,len_a);  //calling merge function with array one
  merge(lst2,len_b);  //calling merge function with array two
  int point_1=0,point_2=0;  //point_1 stores index of top element on lst1 same point_2 stores lst2 top element
  int con=0;  //con work as flag, 1 to take element from lst1 and 2 to take from lst2
  for(int i=0;i<n;i++){
    if(point_2==len_b)  //if all elements of b copied to arr then con=1
      con=1;
    else if(point_1==len_a) //if all elements of a copied to arr then con=2
      con=2;
    if(con==0){ //in case in both array elements remain then take smaller one
      if(lst1[point_1]<lst2[point_2]) //if lst1 have no less than lst2
        con=1;
      else 
        con=2;
    }
    if(con==1){ //to take lst1 element
      arr[i]=lst1[point_1];
      point_1++;  //incrementing to store index of next element
    }
    else{ //to take lst2 element
      arr[i]=lst2[point_2];
      point_2++;  //incrementing to store index of next element
    }
    con=0;  //making con 0 again as it will be used again
  }
}

//main function
int main(){
  int arr[]={9,8,7,6,5,5,3,2,1};
  int n=sizeof(arr)/sizeof(arr[0]);
  merge(arr,n); //calling merge function
  display(arr,n); //calling display function
  return 0;
}