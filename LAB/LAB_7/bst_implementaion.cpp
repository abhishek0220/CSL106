#include<bits/stdc++.h>
using namespace std;
#define COUNT 5 
class Node{
public:
	int data;
	Node *left, *right;
	//Node *parent;
};
class BST{
public:
	Node* root;
	BST(){
		root = NULL;
	}
	void insert(int da){
		Node* new_node=new Node();
		new_node->data=da;
		new_node->left=NULL;
		new_node->right=NULL;
		if(root == NULL){
			//new_node->parent = root;
			root = new_node;
		}
		else{
			Node *tem;
			tem=root;
			while(true){
				if(tem->data < da){
					if(tem->right == NULL){
						tem ->right = new_node;
						//new_node->parent = tem;
						break;
					}
					tem = tem->right;
				}
				else{
					if(tem->left == NULL){
						tem ->left = new_node;
						//new_node->parent = tem;
						break;
					}
					tem = tem->left;
				}
			}
		}
	}
	void search(int da){
		Node *tem;
		tem = root;
		int con=0;
		while(tem != NULL){
			if(tem->data == da){
				con=1;
				break;
			}
			if(tem->data < da)
				tem = tem->right;
			else
				tem = tem->left;
		}
		if(con)
			printf("Found\n");
		else
			printf("Element not found\n");
	}
	void deletion(int da){
		Node *tem, *t2, *pr, *t3;
		pr=NULL;
		tem = root;
		int con=0;
		while(tem != NULL){
			if(tem->data == da){
				t2=tem;
				if(t2->right == NULL && t2->left == NULL){
					t3 = NULL;
				}
				else if(t2->right == NULL){
					t3 = t2->left;
				}
				else if(t2->left == NULL){
					t3 = t2->right;
				}
				else{
					t3 = t2->left;
					tem=t3;
					while(tem->right != NULL){
						tem = tem->right;
					}
					tem->right = t2->right;
				}
				if(pr->data < t2->data ){
					pr->right = t3;
					//pr->right->parent = pr;
				}
				else{
					pr->left = t3;
					//pr->left->parent = pr;
				}
				free(t2);
				con=1;
				break;
			}
			pr=tem;
			if(tem->data < da)
				tem = tem->right;
			else
				tem = tem->left;
		}
		if(con)
			printf("Found and deleted\n");
		else
			printf("Element not found\n");
	}
	void inorder(Node *tem) 
	{ 
	    if (tem != NULL) 
	    { 
	        inorder(tem->left); 
	        printf("%d ", tem->data); 
	        inorder(tem->right); 
	    } 
	}
	void inorder_sucessor(int da) 
	{ 
	    Node *tem,*pr;
	    pr=NULL;
		tem = root;
		int di;
		while(tem != NULL){
			if(tem->data == da){
				if(tem->right == NULL)
					di = pr->data;
				else{
					tem = tem->right;
					while(tem->left !=NULL){
						tem = tem->left;
					}
					di = tem->data;
				}
				break;
			}
			pr=tem;
			if(tem->data < da)
				tem = tem->right;
			else
				tem = tem->left;
		} 
		cout<<"inorder_sucessor is "<<di<<endl;
	} 
	void inorder_predessor(int da) 
	{ 
	    Node *tem,*pr;
	    pr=NULL;
		tem = root;
		int di;
		while(tem != NULL){
			if(tem->data == da){
				if(tem->left == NULL)
					di = pr->data;
				else{
					tem = tem->left;
					while(tem->right !=NULL){
						tem = tem->right;
					}
					di = tem->data;
				}
				break;
			}
			pr=tem;
			if(tem->data < da)
				tem = tem->right;
			else
				tem = tem->left;
		} 
		cout<<"inorder_predessor is "<<di<<endl;
	}
	void BST_max(){
		Node *tem;
		tem=root;
		if(tem == NULL){
			printf("Empty BST Tree\n");
			return;
		}
		while(tem->right != NULL){
			tem = tem->right;
		}
		printf("Max element is %d\n",tem->data);
	}
	void BST_min(){
		Node *tem;
		tem=root;
		if(tem == NULL){
			printf("Empty BST Tree\n");
			return;
		}
		while(tem->left != NULL){
			tem = tem->left;
		}
		printf("Min element is %d\n",tem->data);
	}
	void display_inorder(){
		inorder(root);
		printf("\n");
	}

	//just for testing is tree is working fine code taken fromm
	// Geeksofgeeks
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
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);	
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);
	//tree.search(30);
	//tree.BST_max();
	//tree.BST_min();
	tree.display_inorder();
	//tree.print2D();
	//tree.inorder_sucessor(50);
	//tree.inorder_predessor(50);
	//tree.deletion(30);
	//tree.print2D();
	//tree.insert(30);
	//tree.print2D();
	cout<<"done"<<endl;
	return 0;
}
