/*

**************** Problem Description ****************
Given a linked list of N nodes. The task is to reverse this list.

  Example 1 : 

  Input:
  LinkedList: 1->2->3->4->5->6
  
  Output: 6 5 4 3 2 1

  Example 2 : 

  Input:
  LinkedList: 2->7->8->9->10
  
  Output: 10 9 8 7 2

*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

//User function Template for C

struct Node* reverseList(struct Node *head)
{
    // With Recursion
    if (head == NULL || head->next == NULL) return head;
    
    struct Node *rest = reverseList(head->next);
    
    head->next->next = head;
    
    head->next = NULL;
    
    return rest;
    
    
    // Without Recursion
    // struct Node *curr = head;
    // struct Node *prev = NULL;
    // while (curr != NULL) {
    //     head = head->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = head;
    // }
    // return prev;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      start = reverseList(start);
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 
 void display(struct Node *head)
{
   while(head!=NULL)
  {
   printf("%d ",head->data);
    head=head->next;
  }
}
