#include<bits/stdc++.h>
using namespace std;

//Node containing data and next poinet
class Node{
	public:
	int data;
	Node *next;
};
//class linked used to bind nodes in single class
class linked{
	public:
	Node *Head;
	linked(){	//default constructor
		Head=NULL;	//initialized head with NULL
	}

	//function to add data in the begining of linked list
	void push(int da){
		Node* new_node=new Node();
		new_node->data=da;
		new_node->next=Head;
	  	Head=new_node;
	}

	//function to add data in the last of linked list
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

	//function to add data at location given in the linked list
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

	//function to print data in linked list
	void display(){
	  	Node *tem=Head;
	  	while(tem!=NULL){
	    	cout<<tem->data<<" ";
	    	tem=tem->next;
	  	}
	  	cout<<endl;
	}

	//function to delete data from linked list
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

	//mergesort adder funtion
	Node* SortedMerge(Node* a, Node* b){ 
	    Node* head = NULL;
	    if (a == NULL) 	//base continitons
	        return (b); 
	    else if (b == NULL) 
	        return (a);
	    if (a->data <= b->data) { 
	        head = a; 
	        head->next = SortedMerge(a->next, b); //calling mergesort adder again for next elements
	    } 
	    else { 
	        head = b; 
	        head->next = SortedMerge(a, b->next); //calling mergesort adder again for next elements
	    } 
	    return (head); 
	}

	//merge sort funtion
	void merge_sort(Node **head) 
	{ 
	    Node *tem = *head;
	    Node *a,*b; //creating two pointer to divide linked list into two
	    if ((tem == NULL) || (tem->next == NULL)) { //base contition
	        return; 
	    } 
	    Node *t1,*t2; 
	    t1 = tem; 
	    t2 = tem->next;
	    //mid finder
	    while (t2 != NULL) { 
	        t2= t2->next; 
	        if (t2 != NULL) { 
	            t1 = t1->next; 
	            t2 = t2->next; 
	        } 
	    } 
	    a = tem; //a to first
	    b = t1->next; //b to mid
	    t1->next = NULL;
	    merge_sort(&a); //caliing merge_sort with a
	    merge_sort(&b); //caliing merge_sort with b
	    *head = SortedMerge(a, b); //combining sorted a and b
	} 
	//mergesort caller funtion with arg head
	void mergesort(){
		merge_sort(&Head);
	}
	 
};
//main function to call mergesort
int main(){
	linked list;	
	list.push(1);
	list.push(2);
	list.push(6);
	list.push(8);
	list.display();
	list.mergesort();
	list.display();
	return 0;
}