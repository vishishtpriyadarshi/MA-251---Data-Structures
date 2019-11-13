// This code is created by Vishisht Priyadarshi on 30.10.2019

#include <bits/stdc++.h>
#define si 100

#define x 263
#define p 107
#define m 100

#define a 100
#define b 5


using namespace std;

string *value = new string[si];
int *key = new int[si];
int *flag = new int[si];

int h1(int x1)
{
  return ((a*x1 + b) % p) % m;
}


// Insert an entry to the Hash Table

void insert(string k, int v)
{
    //int h = hashValue(k) % si;
    int h = (h1(v)) % m;
    
    int i = 0;
    while(1)
    {
        if(key[h] == v)
        {
          value[h] = k;
          return ;
        }
        else if(key[h] == -1 || flag[h] == 1)      
        {
            key[h] = v;
            value[h] = k;
            
            if(flag[h] == 1)
              flag[h] = 0;
            return;
        }
        else
            h = (h + (i*i)) % si;              // Linear Probing Sequence
        i++;  
    }
}


// Prints the Hash Table

void print()
{
    cout << "\n*************************\n\n";
    for(int i = 0; i < si; i++)
    {
        if(flag[i] != 1)
        {
            if(key[i] == -1)
                continue;
            else
                cout << value[i] << " = " << key[i] << "\n";
        }
        
    }
    cout << "\n*************************\n\n";
}


// Checks if an element is present in the Hash Table

bool isPresent(int k)
{
    int i = 0;
    int h = (h1(k)) % m;
    
    while(i < si)
    {
        if(key[i] == k && flag[i] != 1)
        {
          //cout << value[i] << "\n";
          return true;
        }
        else
            h = (h + (i*i)) % si;
        i++;
            
    }
    return false;
}


// Prints the Value corresponding to a key

void findValue(int k)
{
  int i = 0;
  int h = (h1(k)) % m;
  
  while(i < si)
  {
    if(key[i] == k)
    {
      cout << value[i] << "\n";
      return;
    }
    else
      h = (h + (i*i)) % si;
    
    i++;
    
  }
}


// Removes an element from the Table

void removeKey(int k)           
{
    int h = (h1(k)) % m;
    
    int i = 0;
    if(isPresent(k))
    {
        while(1)
        {
            if(key[h] == k)
            {
              if(flag[h] == 1)
                break;
              flag[h] = 1;
              cout << "Key Removed\n\n";
              return;
            }
            else
                h = (h + (i*i)) % si;
                
        }
    }
    
    cout << "Key Not Present\n\n";
    
}

int main()
{
    
    for(int i = 0; i < si; i++)
    {
        value[i] = "";
        key[i] = -1;
        flag[i] = -1;
    }
        
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
        case 'a': cin >> v >> k;
                if(floor(log10(v) + 1) <= 7)
                  insert(k, v);
                else
                  cout <<"\nNumber Size Exceeded\n\n";
                break;
                
        case 'f': cin >> v;
                if(isPresent(v))
                  findValue(v);
                else
                  cout << "Value Doesn't Exist in the Table\n\n";
                break;
                
        case 'd': cin >> v;
                if(isPresent(v))
                {
                    removeKey(v);
                }
                else
                    cout << "Key Doesn't Exist\n\n";
                    
                break;
                
        case 'p': print();
                break;
                
        case '0': cout << "TERMINATED.....";
                break;
        }
                
        //cout << "**************** MENU *********************\n1: Insert\n2: Check Existence of A Key-Value\n3: Remove a Key-Value Pair\n4: Print the Hash Table\n0: TERMINATE\n\n";
        cin >> choice;
                
    }
    
    
    return 0;
}
