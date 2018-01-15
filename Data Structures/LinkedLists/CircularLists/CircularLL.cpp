#include<iostream>

//CIRCULAR LINKED LIST IMPLEMENTATION- NO NODE points to a NULL pointer, LAST NODE POINTS TO THE HEAD NODE

using namespace std;


typedef struct CLLNode {
	int data;
	struct CLLNode* next;
};


//1)Function to traverse the circular linked list and return the count of elements

//TIME COMPLEXITY =  O(n) , SPCAE COMPLEXITY = O(1) , for creating a temp node 
int traverseCLL(struct CLLNode* head) {
	CLLNode* curr=head;
	int count= 0;
	if(head==NULL) {
		return 0;
	} 
	
	do{
		cout<<"-->";
		cout<<curr->data;
		curr=curr->next;
		count++;
		
	} while(curr!=head);
	
	return count;
}


//2) Function to insert a node at head
void InsertFirst(CLLNode **head,int data) {
	struct CLLNode* new_node = new CLLNode();
	struct CLLNode* tail = *head;
	
	new_node->data= data;
	//initially new node next points to itself
	new_node->next = new_node;
	//if list is empty
	if(*head==NULL) {
		*head= new_node;
		return;
	}
	
	new_node->next = *head;
	//traversing the list till end to update the tail and connect it with the new node
	while(tail->next != *head) {
		tail=tail->next;
	}
	tail->next = new_node;
	//now head is new node
	*head = new_node;
	return;	
} //TIME COMPLEXITY=O(n),SPACE COMPLEXITY = O(1)



//3)Function to insert at tail of CLL

void InsertLast(struct CLLNode** head,int data) {
	struct CLLNode* new_node=  new CLLNode();
	struct CLLNode* tail = *head;
	
	new_node->data= data;
	new_node->next = new_node;
	
	if(*head==NULL) {
		*head = new_node;
		return;
	
	}
	
	while(tail->next!=*head) {
		tail = tail->next;
	}
	
	tail->next = new_node;
	new_node->next = *head;
	return;
} //TIME COMPLEXITY = O(n) , SPCAE COMPLEXITY = O(1)


//function to insert at random position
void InsertPos(struct CLLNode** head,int pos ,int data) {
	struct CLLNode* new_node = new CLLNode();
	struct CLLNode* temp = *head;
	struct CLLNode* temp1;
	
	new_node->data = data;
	new_node->next = new_node;
	
	//if list is empty or inseeting at first position
	if(pos==1 || head==NULL) {
		
		*head=new_node;
	}
	
	else {
		int k=1;
		while( (k<pos) && temp->next!=*head)
		{
			k++;
			temp1 = temp;//node previous to temp
			temp=temp->next;
		}
		temp1->next = new_node;
		new_node->next = temp ; 
		
		
	}
}


//4) Deleting a node at head
void DelFirst(struct CLLNode **head) {
	struct CLLNode* tail = *head;
	struct CLLNode* temp=*head;//node to delete
	
	if(*head==NULL){
		cout<<"List Empty"<<endl;
		return;
	}
	
	//traversing till end of list
	while(tail->next!=*head) {
		tail=tail->next;
	}
	
	tail->next = temp->next;
	//moving head to point to next node
	*head=temp->next;
	cout<<"Deleted: "<<temp->data<<endl;
	delete(temp);
} //TIME COMPLEXITY = O(n), SPACE COMPLEXITY = O(1)


//5)Deleting a node at tail of CLL

void DelLast(struct CLLNode** head){
	struct CLLNode* tail;
	struct CLLNode* prev=*head;
	
	if(*head==NULL) {
		cout<<"List Empty"<<endl;
		return;
	}
	
	//traversing till 2nd last node
	while(prev->next->next!=*head) {
		prev=prev->next;
	}
	
	tail = prev->next ; //tail is the last node
	prev->next = tail->next;
	cout<<"Deleted : "<<tail->data<<endl;
	delete(tail);
}


int main() {
	
//	struct CLLNode *head = new CLLNode();
//	struct CLLNode* sec = new CLLNode();
//	struct CLLNode* third = new CLLNode();
//	head->data = 10;
//	sec->data=20;
//	third->data=30;
//	
//	head->next = sec;
//	sec->next = third;
//	third->next = head;
//	cout<<traverseCLL(head);


	struct CLLNode* head = NULL;
	
	InsertPos(&head,1,200);
	InsertFirst(&head,10);
	InsertFirst(&head,20);
	InsertLast(&head,40);
	InsertLast(&head,100);
	InsertFirst(&head,90);
	
	
//	DelLast(&head);
	
	traverseCLL(head);	
	
	 
	
	return 0;
	
}
