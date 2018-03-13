#include<iostream>
#include<queue>

using namespace std;

/*Program to find inorder successor of a node in a binary tree
Inorder sucessor-: inorder successor of a node n is the next node which is to be traversed after n in inorder fashion.
Inorder successor of last node in inorder traverasl is NULL, i.e the right most node in a tree in right subtree. 
*/



struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//function to make a new node
BinaryTreeNode *newNode(int data)
{
	BinaryTreeNode *temp = new BinaryTreeNode();
	
	temp->data = data;
	
	temp->right = temp->left = NULL;
	
	return temp;
}


//function to find the lest most node in a tree
BinaryTreeNode* leftMost(BinaryTreeNode *root)
{
	
	//recursive solutuion
//	if(!root) return NULL;
//	
//	//when left most leaf is found
//	if(root->left==NULL && root->right==NULL)
//		return root;
//	
//	//otherwise simply recur to the left subtree of each node
//	leftMost(root->left);

//iterative solution
	while(root!=NULL && root->left!=NULL)
	{
		root = root->left;
	}
	
	return root;
	
		
	
}


BinaryTreeNode *rightMost(BinaryTreeNode *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}



BinaryTreeNode *RecursiveInorderSuccessor(BinaryTreeNode *root,BinaryTreeNode *x)
{
	BinaryTreeNode *temp;
	if(!root) return NULL;
	
	if(root == x || (temp == RecursiveInorderSuccessor(root->left,x)) || 
		(temp == RecursiveInorderSuccessor(root->right,x)))
		{
			if(temp)
			{
				if(root->left == temp)
				{
					//root is the inorder successor of temp
					cout<<root->data<<endl;
					return NULL;
				}	
			}
			
			return root;
		}
		
		
		return NULL;	
		
		
}


void InorderSuccessor(BinaryTreeNode *root,BinaryTreeNode *x)
{
	//Case1-if right child is not NULL-then its inorder successor is the left most node in its right subtree
	if(x->right!=NULL)
	{
		BinaryTreeNode *leftmost = leftMost(x->right);
		
		cout<<leftmost->data<<endl;
		
	}
	
	//Case 2:if right child is NULL
	if(x->right==NULL)
	{
		//Case 3: if x is the right most node in tree-then its inorder succcessor is NULL
		BinaryTreeNode *rightmost = rightMost(root);
		
		if(x==rightmost)
		{
			cout<<"NULL, as it is right most node"<<endl;
		}
		else
		{
			RecursiveInorderSuccessor(root,x);
		}
	}
}

int main()
{


	BinaryTreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	
//	cout<<leftMost(root)->data;
//	cout<<endl;
//	cout<<rightMost(root)->data;

	InorderSuccessor(root,root->right->left);	
	

	
	
}
