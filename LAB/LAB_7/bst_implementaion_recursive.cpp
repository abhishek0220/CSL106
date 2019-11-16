#include <bits/stdc++.h>
using namespace std;
#define COUNT 5 
class Node{
public:
	int data;
	Node *left, *right;
};
//this tree can perform following tasks - 
//insertion
//searching
//min
//max
//successor
//predessor
class BST{
public:
	Node *root;
	BST(){
		root = NULL;
	}
	Node* root_pointer(){
		return root;
	}
	Node* create_node(int data){
		Node *tem;
		tem = new Node;
		tem->data = data;
		tem->left = NULL;
		tem->right = NULL;
		return tem;
	}
	int min_ele(Node *tem){
		if(tem->left == NULL)
			return tem->data;
		return min_ele(tem->left);
	}
	int max_ele(Node *tem){
		if(tem->right == NULL)
			return tem->data;
		return max_ele(tem->right);
	}
	void in_successor(int data){
		int con = successor(data, root);
		printf("Successor of %d is %d\n",data,con);
	}
	int successor(int data, Node *tem){
		if(tem->data == data){
			if(tem->right != NULL)
				return min_ele(tem->right);
			return -1;
		}
		int con;
		if(tem->data > data)
			con = successor(data, tem->left);
		else
			con = successor(data, tem->right);
		if(con == -1 and tem->data >= data)
			con = tem->data;
		return con;
	}
	void in_predecessor(int data){
		int con = predecessor(data, root);
		printf("Predecessor of %d is %d\n",data,con);
	}
	int predecessor(int data, Node *tem){
		if(tem->data == data){
			if(tem->left != NULL)
				return max_ele(tem->left);
			return -1;
		}
		int con;
		if(tem->data > data)
			con = predecessor(data, tem->left);
		else
			con = predecessor(data, tem->right);
		if(con == -1 and tem->data <= data)
			con = tem->data;
		return con;
	}
	void search(int data){
		bool con = search_da(data, root);
		if(con)
			printf("%d present in the tree\n",data);
		else
			printf("%d not present in the tree\n",data);
	}
	bool search_da(int data, Node *tem){
		if(tem == NULL)
			return false;
		if(tem->data == data)
			return true;
		if(tem->data > data)
			return search_da(data, tem->left);
		return search_da(data, tem->right);
	}
	void insert(int data){
		root = insert_func(data, root);
	}
	Node* insert_func(int data, Node *tem){
		if(tem == NULL)
			return create_node(data);
		if(tem->data > data)
			tem->left = insert_func(data, tem->left);
		else
			tem->right = insert_func(data, tem->right);
		return tem;
	}
};


int main(){
	BST tree;
	int arr[] = {6,2,8,7,9,1,4};
	for(auto i : arr){
		tree.insert(i);
	}
	tree.in_successor(7);
	tree.in_predecessor(7);
	return 0;
}