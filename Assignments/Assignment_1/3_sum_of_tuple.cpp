#include<bits/stdc++.h>
using namespace std;

set<tuple<int, int, int, int>> uniq;	//set having type tuple

//funtion to add unique tuples to set
void combine(int a,int b,int c,int d){
	int tem[4];
	tem[0]=a;
	tem[1]=b;
	tem[2]=c;
	tem[3]=d;
	sort(tem, tem+4);	//first sort to store tuple to identify repetion
	uniq.insert(make_tuple(tem[0],tem[1],tem[2],tem[3]));	//inserting tuple in set uniq
}

//main driver function 
int main(){
	int N,SUM;
	printf("Enter SUM : ");
	scanf("%d",&SUM);	//taking sum as input
	printf("Enter no of elements in array : ");
	scanf("%d",&N);		//taking no of elements as input
	int lst[N],tem;
	unordered_map<int, pair<int, int>> dir;
	pair<int, int> tem2;
	printf("Enter space seprated %d elements\n",N);
	for(int i=0;i<N;i++){	//taking array as input
		scanf("%d",&lst[i]);
	}

	//creating map of sum of two digit number having values index of them
	for (int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++) 
            dir[lst[i] + lst[j]] = {i, j}; 
	}

	//loop to find thirt forth index number 
	for (int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++){
        	tem=lst[i]+lst[j];
        	if(dir.find(SUM-tem)!=dir.end()){	//checking if sum-tem present in map
        		tem2= dir[SUM - tem]; 
        		//taking only diffrent values
                if (tem2.first != i && tem2.first != j && tem2.second != i && tem2.second != j)
                	combine(lst[i],lst[j],lst[tem2.first],lst[tem2.second]);
        	}
        }
    }
    
    //printing set uniq
    printf("All tuples of 4 having sum equal to %d are:-\n",SUM);
    for (auto it=uniq.begin(); it != uniq.end(); ++it) 
        cout <<get<0>(*it)<<" "<<get<1>(*it)<<" "<<get<2>(*it)<<" "<<get<3>(*it)<<endl; 
	return 0;
}