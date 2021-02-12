#include <stdio.h>
#include <malloc.h>

 typedef struct node_tag {
    int val;
    struct node_tag * next;
 } node;

 node_tag * head;
  void insertAtHead(int data)
 {
 	 struct  node_tag* new_node = (struct node_tag*)malloc(sizeof(struct node_tag));

  // insert the item
  new_node->item = data;
  new_node->next = head;

  // Move head to new node
  head = new_node;
 }
 void insertAfter (int after, int data)
 {
 	 if (head == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct  node_tag * new_node = (struct  node_tag*)malloc(sizeof(struct  node_tag));
  new_node->item = data;
  new_node->next = after->next;
  after->next = new_node;
 }
 void insertBefore (int before,int data){
 struct  node_tag* new_node = (struct  node_tag*)malloc(sizeof(struct  node_tag));
  if (head == NULL) {
    printf("the given previous node cannot be NULL");
    return;
    if(head==data){
    head=new_node;
    return;
	}
    else{
    	struct  node_tag* prev = (struct  node_tag*)malloc(sizeof(struct  node_tag));
    	while(prev!=0&&prev->next==data){
    		prev=prev->next;
		}
		if(prev==0)
		printf("error");
		prev->next=new_node;
	}
 }
 void deleteItem(int item){
 	struct  node_tag* temp = *head, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == item) 
    { 
        head = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != item) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
 }


 int main () {

 int i,n, before, after, itemBefore, itemAfter, itemDelete;
 void insertAtHead(int  );
  void insertAfter (int , int );
   void insertBefore (int );
   void deleteItem(int item);
   void traverse(void);
 scanf("%d",&n);
 scanf("%d",&itemBefore);
 scanf("%d",&before);
 scanf("%d",&itemAfter);
 scanf("%d",&after);
 scanf("%d",&itemDelete);

 insertAtHead(0);

 for (i = 2; i<=n; i+=2)
     insertAfter(i,i-2);

 insertAfter(itemAfter, after);
 insertBefore(itemBefore, before);
 deleteItem(itemDelete);
 traverse();
 
 return 0;
}

/* your functions go here */
/* Please use the traverse function provided below so that there is no confusion in output */

void traverse (void) {
    node * n = head;
    while (n) { 
		printf("->%d",n->val); 
		n = n->next;
	}
}
