/*

**************** Problem Description ****************
Sort the given Linked List using quicksort, which takes O(n^2) time in worst case and O(nLogn) in average and best cases,
otherwise you may get TLE.

  Example 1 : 

  Input:
  2
  3
  1 6 2
  4
  1 9 3 8

  Output:
  1 2 6
  1 3 8 9

  Explanation:
  Testcase 1: After sorting the nodes, we have 1, 2 and 6.
  Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.

*/

#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

void swap (struct node *i, struct node *j) {
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}

struct node* partition(struct node *head, struct node *last) {
    struct node *pivot = head;
    struct node *prev = head;
    struct node *curr = head->next;
    
    while (curr != last->next) {
        if (curr->data < pivot->data) {
            prev = prev->next;
            swap(prev, curr);
        }
        curr = curr->next;
    }
    
    swap(pivot, prev);
    return prev;
}

void quickSortRec(struct node *head, struct node *last) {
    if (head == last || !head || !last) return;
    
    struct node *pivot = partition(head, last);
    
    quickSortRec(head, pivot);
    quickSortRec(pivot->next, last);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    struct node *last = *headRef;
    while (last->next != NULL) last = last->next;
    
    quickSortRec(*headRef, last);
}
