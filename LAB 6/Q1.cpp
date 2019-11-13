#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

using namespace std;
#define MAX INT_MAX

// =====================================
//           PRINT
// =====================================

void print(int *a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n\n";
}



// =====================================
//           MERGE PROCEDURE
// =====================================

void merge(int *a, int p, int q, int r)  // Merge subarray1 -> (p to q) & subarray2 -> (q + 1 to r )
 {
    int n1 = q - p + 1 ;                 // n1 = size of subarray1
    int n2 = r - q;                      // n2 = size of subarray2

    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for(int i = 0; i < n1; i++)
        L[i] = a[p+i];                   
    L[n1] = MAX;                         

    //print(L,n1+1);

    for(int i = 0; i < n2; i++)         
        R[i] = a[q + 1 + i];
    R[n2] = MAX;                         

    //print(R,n2+1);


    int j = 0,i = 0;                      

    for(int k = p; k <= r; k++)           // Merging two subarrays
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
    //cout << "MERGED:\n";
    //print(a,r+1);
    //cout << "**************\n";
}




// =================================
//        MERGE SORT
// =================================


void mergeSort(int *a, int p, int r)    
{
    if(p<r)
    {
        int q = p + (r-p)/2;           
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);

    }
}


// =====================================
//              MAIN
// =====================================


// CODE AUTHOR : Vishisht Priyadarshi
// DATE : 25 Sept 2019


int main()
{
    /*cout << "Enter size:\n";
    int size;
    cin >> size;

    cout << "Enter array:\n";
    int *a = new int[size];

    for(int i = 0; i < size; i++)
        cin >> a[i];*/
    int k = 0;
  
    cout << "Enter k:\n";
    
    cin >> k;
    
    int size = pow(10,k) - 1;
    int *a = new int[size];
  
    clock_t c1,c2;
    c1 = clock();
    srand(c1);
    
    for(int i = 0; i<size; i++) 
      a[i] = rand()%1000;
    
    int *temp = a;
    
    cout << "k = " << k << "\n\n\n*************Unsorted Array :***************\n\n";
    print(a,size);
    
    for(int i = 0;i < 1000; i++)
    {
      mergeSort(a,0,size-1);
    
      if(i == 0)
      {
        cout << "\n**************Sorted array:****************\n\n";
        print(a,size);
      }
      
      a = temp;
    }
    
    c2 = clock();
    cout << "Runtime :" << (float)(c2 - c1)/(CLOCKS_PER_SEC) << "ms\n\n";
    return 0;
}
