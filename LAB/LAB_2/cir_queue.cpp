#include<bits/stdc++.h>
using namespace std;
#define N 3
class qu{
  public:
  int front,rear,number,arr[N];
  qu(){
    number=0;
    front=-1;
    rear=0;
  }
  void enque(int da){
    if(number!=N){
      front++;
      if(front==N)
        front=0;
      arr[front]=da;
      number++;
    }
    else{
      cout<<"overflow"<<endl;
    }
  }
  void deque(){
    if(number==0){
      cout<<"underflow"<<endl;
      return ;
    }
    rear++;
    if(rear==N){
      rear=0;
    }
    number--;
  }
  void print(){
    for(int i=0;i<N;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};
int main(){
  qu q;
  q.enque(3);
  q.enque(2);
  q.enque(1);
  q.print();
  q.deque();
  q.print();
  q.enque(55);
  q.print();
  return 0;
}