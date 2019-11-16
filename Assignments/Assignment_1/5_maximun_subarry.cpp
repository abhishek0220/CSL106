#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	printf("Enter no of elements ");
	scanf("%d",&N);  //taking no of element as input
	int lst[N];
	printf("Enter space seperated %d elements\n",N);
  for(int i=0;i<N;i++)
    scanf("%d",&lst[i]);  //taking array as input
  int start_index=0,end_index=0,max_sum=0,curr_sum=0,tem=0;
  for(int i=0;i<N;i++){
    curr_sum+=lst[i];
    if(curr_sum<0){ //if sum till now get negative then make it zero  
      curr_sum=0;
      tem=i+1;  //change starting index
    }
    else if(max_sum<curr_sum){  //if max sum is less then current sum
      max_sum=curr_sum;   //update max_sum
      start_index=tem;    //update starting index
      end_index=i;        //update end_index
    }
  }

  //printing subarray with maximum sum
  printf("Subarray with maximum sum ");
  for(int i=start_index;i<=end_index;i++)
    printf("%d ",lst[i]);
  printf("\n");
  printf("Having maximum sum is %d",max_sum);
	return 0;
}