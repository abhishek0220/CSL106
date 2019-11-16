#include<bits/stdc++.h>
using namespace std;
#define COUNT 5 
class Node{
public:
	int data;
	int height;
	Node* left, *right;
};

class AVL{
public:
	Node *root;
	AVL(){
		root = NULL;
	}
	int difference(Node *tem)  
	{  
	    if (tem == NULL)  
	        return 0;  
	    return height(tem->left) - height(tem->right);   
	} 
	int height(Node *tem){
		if(tem == NULL)
			return 0;
		return tem->height;
	} 
	Node* create_node(int da){
		Node *new_node = new Node;
		new_node->data = da;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->height = 1;
		return new_node;
	}
	Node* leftRotate(Node *tem){
		Node* tem2 = tem->right;
		Node* tem3 = tem2->left;
		tem2->left = tem;
		tem->right = tem3;
		tem->height = max(height(tem->left),height(tem->right))+1;
		tem2->height = max(height(tem2->left),height(tem2->right))+1;
		return tem2;
	}
	Node* rightRotate(Node *tem){
		Node* tem2 = tem->left;
		Node* tem3 = tem2->right;
		tem2->right = tem;
		tem->left = tem3;
		tem->height = max(height(tem->left),height(tem->right))+1;
		tem2->height = max(height(tem2->left),height(tem2->right))+1;
		return tem2;
	}
	Node* insert_func(int data, Node *tem){
		if(tem == NULL)
			return create_node(data);
		if(tem->data > data)
			tem->left = insert_func(data, tem->left);
		else
			tem->right = insert_func(data, tem->right);
		tem->height = max(height(tem->left), height(tem->right)) + 1;
		int balance = difference(tem);
		if(balance > 1){
			if(data < tem->left->data)
				tem->left = leftRotate(tem->left);
			return rightRotate(tem);
		}
		else if(balance < -1){
			if(data < tem->right->data)
				tem->right = rightRotate(tem->right);
			return leftRotate(tem);
		}
		return tem;

	}
	void insert(int da){
		root = insert_func(da, root);
		root->height = max(height(root->left), height(root->right)) + 1;
	}
	void print2DUtil(Node *tem, int space)  
	{  
	    // Base case  
	    if (tem == NULL)  
	        return;   
	    space += COUNT;  
	    print2DUtil(tem->right, space);  
	    cout<<endl;  
	    for (int i = COUNT; i < space; i++)  
	        cout<<" ";  
	    cout<<tem->data;    
	    print2DUtil(tem->left, space);  
	}  
	void print2D()  
	{  
	    print2DUtil(root, 0);  
	    cout<<endl;
	}
};
int main(){
	freopen ("C:/Users/abhis/Documents/output.txt","w",stdout);
	AVL tree;
	int arr[] = {1,2,3,4,5,6,7};
	for(auto i : arr){
		tree.insert(i);
	}
	
	return 0;
}