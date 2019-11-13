// This code is created by Vishisht Priyadarshi on 30.10.2019

#include <bits/stdc++.h>
#define si 10

#define x 263
#define p 1000000007
#define m 10

using namespace std;

struct node
{
    int data;
    string key;
    node *ptr;
};


// Create a node for the Linked List

node *create(int d, string key)
{
    node *n = new node;
    n->data = d;
    n->key = key;
    n->ptr = NULL;
    
    return n;
}


// Hash Function

int hashValue(string key)
{
    int n = key.length();
    int h = 0;
    
    for(int i = 0; i < n; i++)
       h += (key[i] * (int)pow(x,i)) % p; 
       
    return h%m;
}



// Checks if an element is present in the Hash Table

bool isPresent(node **a, string key)
{
  for(int i = 0; i < si; i++)
  {
    node *curr = a[i];
    while(curr != NULL)
    {
      if(curr->key == key)
        return true;
      curr = curr->ptr;
    }
  }
  
  return false;
}


// Insert an entry to the Hash Table

void insert(node **add, string key, int value)
{
    if(!isPresent(add, key))
    {
      int h = hashValue(key);
      node* nxt = add[h];
    
      if(nxt == NULL)
          add[h] = create(value, key);
      else
      {
          while(nxt->ptr != NULL)
          {
              if(nxt->key == key)
              {
                  nxt->data = value;
                  return;
              }
              nxt = nxt->ptr;
          }
            
        
          nxt->ptr = create(value, key);
      }
    }
}


// Prints the Hash Table

void print(node **add)
{
    cout << "\n*************** HASH TABLE******************\n\n";
    for(int i = 0; i < si; i++)
    {
        cout << i << ". ";
        node *next = add[i];
        if(next == NULL)
        {
            //cout << "llow\n";
            cout << "\n";
            continue;
        }
        else
        {
            while(next != NULL)
            {
                cout << next->key;
                next = next->ptr;
            }
            cout << "\b\b\b    \n";
        }

        
    }
    cout << "\n*************************\n\n";
}



// Removes an element from the Table

void removeKey(node **add, string key)
{
    int h = hashValue(key) % si;
    node* nxt = add[h];
    
    if(nxt->key == key)
    {
        if(nxt->ptr != NULL)
            add[h] = nxt->ptr;
        else
            add[h] = NULL;
    }
    else
    {
        while(nxt != NULL && nxt->ptr != NULL)
        {
            if(nxt->ptr->key == key)
            {
                nxt->ptr = nxt->ptr->ptr;
                return;
            }
            
            nxt = nxt->ptr;
        }
    }
    
}


int main()
{
    node **add = new node*[m];
    for(int i = 0; i < si; i++)
        add[i] = NULL;
        
    cout << "Enter Key - Value pairs\nPress \"STOP -1\" to Terminate\n\n";
    string k;
    int v;
    
    cout << "**************** MENU *********************\na: Insert\nf: Find Existence of A Key-Value\nd: Remove a Key-Value Pair\np: Print the Hash Table\n0: TERMINATE\n\n";
    char choice;
    cin >> choice;
    
    while(choice != '0')
    {
        switch(choice)
        {
          
        case 'a': cin >> k;
                insert(add, k, v);
                break;
                
        case 'f': cin >> k;
                if(isPresent(add, k)) cout << "\nRESULT: Value Exists in the Table\n\n";
                else cout << "\nRESULT: Value Doesn't Exist in the Table\n\n";
                break;
                
        case 'd': cin >> k;
                if(isPresent(add,k))
                {
                    removeKey(add, k);
                    cout << "Key Removed\n\n";
                }
                else
                    cout << "Key Doesn't Exist\n\n";
                    
                break;
                
        case 'p': print(add);
                break;
                
        case '0': cout << "TERMINATED.....";
                break;
        }
                
        //cout << "**************** MENU *********************\n1: Insert\n2: Check Existence of A Key-Value\n3: Remove a Key-Value Pair\n4: Print the Hash Table\n0: TERMINATE\n\n";
        cin >> choice;
                
    }
    
    
    return 0;
}
