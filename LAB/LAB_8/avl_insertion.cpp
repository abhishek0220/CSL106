#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left, right;
};

class AVL{
public:
	Node *root;
	AVL(){
		root = NULL;
	}
	Node* create_node(int da){
		Node *new_node = new Node;
		new_node->data = da;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	void insert(int da){
		Node *new_node;
		new_node = create_node(da);
		if(root == NULL)
			root = new_node;
		else{
			
		}
	}
};
int main(){
	AVL tree;
	tree.insert(5);
	return 0;
}