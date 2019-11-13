//
// Created by Vishisht Priyadarshi on 16-10-2019.
//

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string>

using namespace std;


int n;                                   // Size of Dynamic Array
int ct;                                  // Size of Heap

struct node
{
  string name;
  string date;
};

void swap(node* a, node* b)                // Swapping
{
  node t = *a;
  *a = *b;
  *b = t;
}


int find(string arr[], int len, string seek)
{
  for (int i = 0; i < len; ++i)
  {
    if (arr[i] == seek)
      return i;
  }
  return -1;
}


bool isNumericChar(char x) 
{ 
  return (x >= '0' && x <= '9') ? true : false; 
} 

int convert(string str) 
{ 
  
  int res = 0;  
  int sign = 1; 
  int i = 0; 
  
  for (; str[i] != '\0'; ++i)
  { 
    if (isNumericChar(str[i]) == false) 
      return 0; 
    
    res = res * 10 + str[i] - '0'; 
  } 
  
  
  return sign * res; 
} 

bool isGreater(node a, node b)
{
  string ya = a.date.substr((a.date).length() - 4);
  string yb = b.date.substr((b.date).length() - 4);
  
  if(ya > yb)
    return true;
  else if(ya < yb)
    return false;
  else
  {
    string amon = a.date.substr(3,(a.date).length() - 5);
    string bmon = b.date.substr(3,(b.date).length() - 5);
    
    string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    if(find(month, 12, amon) > find(month, 12, bmon)) 
      return true;
    else if(find(month, 12, amon) < find(month, 12, bmon))
      return false;
    else
    {
      string adate = (a.date).substr(0,2);
      string bdate = (a.date).substr(0,2);
      if(convert(adate) > convert(bdate))
        return true;
      else
        return false;
    }
    
  }
}


void minHeapify(node *arr, int i)
{
    int l = 2*i + 1;                     // Left Child
    int r = 2*i + 2;                     // Right Child
    
    int sm = 0;
    
    if(l < n && isGreater(arr[l], arr[i]))
        sm = l;
    else
        sm = i;
    
    if(r < n && isGreater(arr[r], arr[sm]))
        sm = r;
        
    if(sm != i)
    {
        swap(&arr[i], &arr[sm]);
        
        minHeapify(arr, sm);
    }
}


void buildMinHeap(node *arr)
{
  for(int i = n/2 + 1; i >= 0; i--)
    minHeapify(arr, i);
}



void deleteMin(node *a)
{
    a[0] = a[n-1];
    cout << n-1 << endl;
    n--;
    //ct--;
    
    buildMinHeap(a);
}



void printMin(node *a)
{
    cout << "\n\nMin element =\n" << a[0].name << " " << a[0].date << "\n";
}


void insert(node *a, node el)
{
  int i = n-1;
  a[n-1] = el;
  
  while(i != 0)
  {
    if(isGreater(a[i], a[i/2]))
      swap(&a[i], &a[i/2]);
    
    i = i/2;
  }
}


int main()
{
   
    
    cout << "Enter Size of Heap:\n\n";
    cin >> ct;
    node *A = new node[ct];
    
    cout << "************* MENU ***************\n\n";
    cout << "1. Insert\n";
    cout << "2. Return Min\n";
    cout << "3. Extract and Return Min\n";
    cout << "0. EXIT\n\n";

    n = 0;                                 // SIZE of the Array
    
    int choice;
    node el2;
 
    cin >> choice;
    cin >> el2.name >> el2.date;
    A[0] = el2;
    n++;
    
    cin >> choice;
    while(choice != 0)
    {
      switch(choice)
      {
      case 1: 
              cin >> el2.name >> el2.date;
              insert(A,el2);
              n++;
              break;
      case 2: printMin(A);
              break;
      case 3: printMin(A);
              deleteMin(A);
              break;
      case 0: cout << "Program Terminated\n\n";
      }
      
      cin >> choice;
    }
    cout << "Program Terminated\n\n";
    
    
    
    return 0;
}
