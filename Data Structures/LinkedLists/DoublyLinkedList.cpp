#include<iostream>


//Doubly linked list program
using namespace std;

struct Node{
	string data;
	struct Node  *next;
	struct Node *prev;
};




struct Node* head  = new Node() ;

void InsertPos(struct Node **head,int data,int pos);
		
Node* traverse(struct Node *head);
		
string delPos(int pos);
		


void InsertHead(string data) {
	
	Node *new_node = new Node();
	
	new_node->data= data;
	
	new_node->next = head;
	new_node->prev= NULL;
	
	head->prev = new_node;
	
	head = new_node;
	
}

void InsertLast(struct Node** head , string data) {
	
	Node *new_node = new Node();
	
	Node *temp = *head;
	
	new_node->data= data;
	
	while(temp->next != NULL) {
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	new_node->next = NULL;
	
}


//fuction to handle both insertion at last and intermediate position
void InsertPos(int pos,string data) {
	
	Node *new_node = new Node();
	
	Node *temp = head;
	
	new_node->data= data;
	int k=1;
	while( (k < pos-1) && temp->next!=NULL ) {
		k++;
		temp=temp->next; //temp is the node next to which we want to insert a new node
	}
	
	new_node->next = temp->next;
	new_node->prev = temp;
	
	temp->next->prev = new_node;
	temp->next = new_node;
}


//void InsertPos( int data,int pos) {
//	struct Node *new_node ,*temp;
//	new_node = new Node(); //allocating a new memory block to node dynamically in HEAP
//	
//	
//	
//	new_node->data = data;
//	
//	if(!new_node) {
//		cout<<"Memory Error"<<endl;
//		return;
//	}
//	int k = 1;
//	
//	 
//	if(pos==1) {
//		
//		
//		
//		new_node->next = head;
//		new_node -> prev = NULL;
//		head->prev = new_node;
//		head = new_node;
//		
//		return;
//		
//		
//		
//		
//		
//	}
//	
//	
//	
//	temp=head;
//	
//		
//		while(( k < pos-1) && (temp->next!=NULL)) {
//			
//			temp=temp->next;
//			k++;
//			
//		
////		
////		if(k!=pos) {
////			cout<<"Enter appropiate position to insert"<<endl;
////		}
//		
//		new_node->next=temp->next;
//		new_node->prev= temp;
//	
//		temp->next->prev= new_node;
//		
//		temp->next=new_node;
//		return;
//		
//		
//		
//	
//		
//		
//		
//	}
//}

string  delHead() {
	Node *temp;
	temp=head;
	if(head==NULL) {
		cout<<"List is empty"<<endl;
	}
	
	else {
		
		head = temp->next;
		head->prev = NULL;
	
	}
	
	return temp->data;
	delete(temp);
	
	
}


string delPos(int pos) 
{
	Node *temp,*temp1;
	int k=1;
	temp= head;
	if(pos<=0) {
		cout<<"Not a valid index"<<endl;
	} 
	
	if(pos==1) {
		
		head= head->next;
		head->prev = NULL;
		return temp->data;
		delete(temp);
	}
	
	//traversing the list
	while((k < pos) && temp->next!=NULL) {
		
		
		temp=temp->next;
		k++;
		
	}
	
	temp1 = temp->prev;
	temp1->next = temp->next;
	temp->next->prev = temp1;
	
	return temp->data;
	delete(temp);
	
	
	
	

	
	
	
}


Node* traverse(struct Node *head) {
	
	Node *temp=head;
	
	while(temp->next!=NULL) {
		
		
		cout<<temp->data<<"->";
		temp=temp->next;
		
		
	}
	cout<<"NULL";
	
	return head;
	
}


/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    Node *temp = head;
   if(head==NULL) {
       return head;
   }
     
    while(temp->next!=NULL) {
        temp = temp->next;
    }
        
    Node *temp1 = temp;
    head = temp1;
   while(temp->prev!=NULL) {
        temp = temp->next;
    }
   
   
   return head;
}


//int DLL::delPos(int pos) {
//	
//	
//	return
//}


int main() {
	
	
//	
//	struct Node *n1 = new Node();
//	struct Node *n2 = new Node();
//	n1->data=20;
//	n2->data=30;	
//	
//	n1->next = n2;
//	
//	
//	n2->next=NULL;
//	n2->prev = n1;
//	
//	n.traverse(n1);
	
	
	
//	InsertPos(20,1);
//////
//	InsertPos(30,2);
//	InsertPos(100,3);
////	

	InsertHead("anish");
	InsertPos(2,"Mrinal");
	InsertPos(3,"Vaibhav");
	InsertPos(4,"Rasila");
	InsertPos(5,"gandu");
	InsertPos(6,"mc");
	
	cout<<"The list is: "<<endl;
	
//	traverse(head);	
//	cout<<"\n";
//	cout<<"After deletion:"<<endl;
//	
//	delHead();
//	delPos(4);
	
	Reverse(head);
	
//	InsertLast(&head,20);
	traverse(head);
	
	return 0;
}
