#include<bits/stdc++.h>
using namespace std;

//sorting condition function
bool condition(const tuple<int, int>& a,const tuple<int, int>& b) 
{ 
    return (get<1>(a) > get<1>(b)); 	//comparing second element
} 
//main driver fucntion
int main(){
	int N;
	map<int, int> dir;
	map<int, int>::iterator itr;
	vector<tuple<int, int> > freq;
	printf("Enter no of elemetns : ");
	scanf("%d",&N);	//taking no of element as input
	int lst[N];
	printf("Enter space seprated %d elemetns\n",N);
	for(int i=0;i<N;i++){
		scanf("%d",&lst[i]);	//taking array as input
	}

	//creating map table with value 0
	for(int i=0;i<N;i++){
		dir[lst[i]]=0;
	}

	//maintaing frequency of each number
	for(int i=0;i<N;i++){
		dir[lst[i]]++;
	}

	//making vector of tuple from map table
	for (itr = dir.begin(); itr != dir.end(); ++itr) {
       	freq.push_back(make_tuple(itr->first,itr->second));
    }

    //sorting vector on basis of second element of tuple
    sort(freq.begin(), freq.end(), condition); 
    int k=0;

    //creating array from frequency vector
    for (int i = 0; i < freq.size(); i++){
    	for(int j=0;j<get<1>(freq[i]);j++){
    		lst[k]=get<0>(freq[i]);
    		k++;
    	}
    }

    //printing sorted vector
    printf("Sorted array is");
    for(int i=0;i<N;i++)
    	cout<<lst[i]<<" ";
	return 0;
}