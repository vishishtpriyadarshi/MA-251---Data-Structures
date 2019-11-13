#include<bits/stdc++.h>
using namespace std;


struct node
{
 int data; 
 struct node *next;
};

void print(node* head)                  // Printing the Linked List
{
  node* curr = head; 
  while(curr != NULL)
  { 
    cout << curr->data << "  ";
    curr = curr->next; 
  }
  
  cout << "\n\n\n\n";
}




// ==============================
//       CREATE NODE
// ==============================


node* creatnode(int d)                       
{
  node* temp=(node*)malloc(sizeof(node));     // Creating a Node
  temp->data=d;
  temp->next=NULL;
  return temp;
}


// ================================
//         MERGING
// ================================


node* mergeList(node* s1,node* s2)           // Merging the Linked List 
{
  node* newNode=NULL;
  
  if(s1==NULL)
    return s2;
  
  
  if(s2==NULL)
    return s1;
  
  if(s1->data <= s2->data)
  {
    newNode = s1;
    newNode->next = mergeList(s1->next, s2);
  }
  else
  {
    newNode = s2;
    newNode->next = mergeList(s1, s2->next);
  }
  
  return newNode;
  
}




// ==================================
//          SPLITTING
// ==================================


void split(node* head,node** s1,node** s2)    // Finding the Mid Position of Linked List using FLOYD'S TORTOISE AND HARE Algorithm
{
  
  node* slow = head;
  node* fast = head->next;
  
  while(fast != NULL)
  {
    fast = fast->next;
    if(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  
  *s1 = head;                                 // Points to End of List
  *s2 = slow->next;                           // Points to Mid element of List
  
  slow->next = NULL;
}



// =================================
//        MERGE SORT
// =================================


void mergeSort(node** refHead)
{
  node* head=*refHead;
  node* s1,*s2;
  
  if(head == NULL || head->next == NULL)
  {
    return;
  }
 
  split(head, &s1, &s2);
  
  mergeSort(&s1);
  mergeSort(&s2);
  
  *refHead = mergeList(s1, s2);
  
  return;
  
}


// =====================================
//              MAIN
// =====================================

// CODE AUTHOR : Vishisht Priyadarshi
// DATE : 25 Sept 2019


int main()
{
  cout << "Enter k = \n";
  int k1;
  cin >> k1;
  clock_t c1,c2;
  for(int m = 1; m <= 1000;m++)
  {
  
  int k;
  node* curr,*temp;
  
  
  k = rand()%1000;
  node* head = creatnode(k);
  
  
  k = rand()%1000;
  temp = head;
  
  
  for(int i = pow(10,k1) - 2; i >= 1; i--)                        // Inputting the Values
  {
    curr = creatnode(k);
    temp->next = curr;
    temp = temp->next;
    k = rand()%1000;
  }
  
  if(m == 1){
    cout << "\n\n**************Unsorted Linked List:******************\n\n";
    print(head);
  
    
    c1 = clock();
    mergeSort(&head);
  
    
    cout << "**************Sorted Linked List:********************\n\n";
    print(head);
    }
  }
  c2 = clock();
  cout << "Runtime : " << (float)(c2 - c1)/(CLOCKS_PER_SEC) << "ms\n\n";
  return 0;
}
