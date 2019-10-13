#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
};
class linked{
  public:
  Node *Head,*ch;
  linked(){
    Head=NULL;
  }
  void push(int da){
    Node* new_node=new Node();
    new_node->data=da;
    new_node->next=Head;
    Head=new_node;
  }
  void append(int da){
    Node *tem=Head;
    Node* new_node=new Node();
    new_node->data=da;
    new_node->next=NULL;
    while(tem->next!=NULL){
      tem=tem->next;
    }
    tem->next=new_node;
  }
  void insert(int key,int da){
    Node *tem=Head;
    Node* new_node=new Node();
    new_node->data=da;
    while(tem->next!=NULL && tem->data!=key){
      tem=tem->next;
    }
    new_node->next=tem->next;
    tem->next=new_node;
  }
  void display(){
    Node *tem=Head;
    while(tem!=NULL){
      cout<<tem->data<<" ";
      tem=tem->next;
    }
    cout<<endl;
  }
  void delete_ele(int da){
    Node *tem=Head,*t2;
    if(tem->data==da){
      Head=tem->next;
      free(tem);
    }
    else{
      t2=tem->next;
      while(t2!=NULL){
        if(t2->data==da){
          tem->next=t2->next;
          free(t2);
          break;
        }
        tem=tem->next;
        t2=tem->next;
      }
    }
  }
  void middle()  
  {  
      Node *slow_ptr = Head;  
      Node *fast_ptr = Head;  
      if (Head!=NULL)  
      {  
          while (fast_ptr != NULL && fast_ptr->next != NULL)  
          {  
              fast_ptr = fast_ptr->next->next;  
              slow_ptr = slow_ptr->next;  
          }  
          printf("The middle element is %d\n", slow_ptr->data);  
      }  
  }
};
int main(){
  linked list;
  list.push(1);
  list.push(1);
  list.push(2);
  list.push(6);
  list.push(6);
  list.push(6);
  list.push(6);
  list.push(7);
  list.push(7);
  list.display();
  list.middle();
  return 0;
}