//
// Created by Vishisht Priyadarshi on 16-10-2019.
//

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;


int n;                                   // Size of Dynamic Array
int ct;                                  // Size of Heap

void maxHeapify(int *arr, int i)
{
    int l = 2*i + 1;                     // Left Child
    int r = 2*i + 2;                     // Right Child
    
    int largest = 0;
    
    if(l < n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    
    if(r < n && arr[r] > arr[largest])
        largest = r;
        
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        maxHeapify(arr, largest);
    }
}


void buildMaxHeap(int *arr)
{
  for(int i = n/2 + 1; i >= 0; i--)
    maxHeapify(arr, i);
}



int* addArray(int el, int *A)
{
    if(ct < n)                            // For Insertions without the need of doing Resizing Array
    {
        A[ct] = el;                       // Insertion in O(1) time
        ct++;
        
        buildMaxHeap(A);
        return A;
    }
    else                                  // For Insertions with resizing the Array
    {
        int *A2 = new int[ct*2];       // Dynamic Memory allocation to double the size of Array
        n = ct*2;

        for(int i = 0; i<ct; i++)
            A2[i] = A[i];                 // Copying the elements of the old array into resized array

        A2[ct] = el;                      // Insertion in O(n) time
        ct++;
    
    
    
        buildMaxHeap(A2);
        return A2;
    }
}





void deleteMax(int *a)
{
    a[0] = a[ct-1];
    n--;
    ct--;
    
    buildMaxHeap(a);
}



void printMax(int *a)
{
    cout << "\n\nMax element = " << a[0] << "\n";
}



void print(int *a)
{
    cout << "\n\n********  Heap  *********\n";
    for(int i = 0; i < ct; i++)
    {
        if(ceil(log2(i+1)) == floor(log2(i+1)))
            cout << "\n";
        cout << a[i] << " ";
    }
}


void heapIncreaseKey(int *a, int i, int key)
{
    if(key < a[i])
    {
        cout << "*** NOT ALLOWED ***\nNEW KEY IS SMALLER THAN CURRENT VALUE.\n\n";
        return;
    }
    
    a[i] = key;
    
    while(i > 0 && a[i/2] < a[i])
    {
        int temp = a[i/2];
        a[i/2] = a[i];
        a[i] = temp;
        
        i = i/2;
    }
}



int main()
{
    int *A = new int[1];
    cout << "Enter elements:\n\n*****ENTER -1 TO STOP******\n\n\n";

    n = 1;                                 // SIZE of the Array
    ct = 0;                                // Position of last inserted element
    
    int a;
    cin >> a;
    
    while(a != -1)
    {
        A = addArray(a,A);                 // Adding elements to Array
        cin >> a;
        
    }

    // ***** SOME OPERATIONS *******
    print(A);
    printMax(A);
    deleteMax(A);
    print(A);
    
    heapIncreaseKey(A, 3 , 91);
    print(A);
    
    deleteMax(A);
    deleteMax(A);
    
    print(A);
    
    return 0;
}
