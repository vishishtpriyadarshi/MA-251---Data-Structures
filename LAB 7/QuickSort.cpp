//
// Created by Vishisht Priyadarshi on 16-10-2019.
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


using namespace std;

void swap(int* a, int* b)                     // Swapping
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int *a, int p, int r)           // Partitioning
{
    int i = p-1;

    for(int j = p; j < r ; j++)
    {
        if(a[j] <= a[r])
        {
            i = i + 1;
            swap(&a[i], &a[j]);
            
        }

    }

    swap(&a[i+1], &a[r]);

    return i+1;
}


int Randomized_Partition(int *a, int p, int r)  // Random Pivot Choosing
{
    int i = p + (rand() % (r - p));             // i = Random index between p and r
    swap(&a[r], &a[i]);
    return Partition(a, p, r);
}

int First_Partition(int *a, int p, int r)  
{
  swap(&a[r], &a[p]);                           // Choosing pivot as first element of subarray
  return Partition(a, p, r);
}

int Median_Partition1(int *a, int p, int r)  
{
  int n1 = p;
  int n2 = (r-p)/2;
  int n3 = r;
  
  //int med;
  if((a[n1] > a[n2] && a[n1] < a[n3]) || (a[n1] > a[n3] && a[n1] < a[n2]))
    swap(&a[r], &a[n1]);
  else if((a[n2] > a[n1] && a[n2] < a[n3]) || (a[n2] > a[n3] && a[n2] < a[n1]))
    swap(&a[r], &a[n2]);
  else
    swap(&a[r], &a[n3]);
  
  //swap(&a[r], &a[p]);
  return Partition(a, p, r);
}

int Median_Partition2(int *a, int p, int r)  
{
  int n1 = (r-p)/4;
  int n2 = (r-p)/2;
  int n3 = 3 * (r-p)/4;
  
  //int med;
  if((a[n1] > a[n2] && a[n1] < a[n3]) || (a[n1] > a[n3] && a[n1] < a[n2]))
    swap(&a[r], &a[n1]);
  else if((a[n2] > a[n1] && a[n2] < a[n3]) || (a[n2] > a[n3] && a[n2] < a[n1]))
    swap(&a[r], &a[n2]);
  else
    swap(&a[r], &a[n3]);
  
  //swap(&a[r], &a[p]);
  return Partition(a, p, r);
}

void QuickSortR(int *a , int p , int r)
{
    if(p < r)
    {
        int q = Randomized_Partition(a, p, r);
        QuickSortR(a, p, q-1);
        QuickSortR(a, q+1, r);
    }
}

void QuickSortF(int *a , int p , int r)
{
  if(p < r)
  {
    int q = First_Partition(a, p, r);
    QuickSortF(a, p, q-1);
    QuickSortF(a, q+1, r);
  }
}

void QuickSortM1(int *a , int p , int r)
{
  if(p < r)
  {
    int q = Median_Partition1(a, p, r);
    QuickSortM1(a, p, q-1);
    QuickSortM1(a, q+1, r);
  }
}

void QuickSortM2(int *a , int p , int r)
{
  if(p < r)
  {
    int q = Median_Partition2(a, p, r);
    QuickSortM2(a, p, q-1);
    QuickSortM2(a, q+1, r);
  }
}

void GeneralQuicksort(int *a, int n, int pivot)
{
  if(pivot == 0)
    QuickSortF(a, 0, n-1);
  else if(pivot == 1)
    QuickSortR(a, 0 ,n-1);
  else if(pivot == 2)
    QuickSortM1(a, 0 ,n-1);
  else
    QuickSortM2(a, 0 ,n-1);
    
}

void print(int *a, int size)
{
    cout << "\n\nSorted Array:\n";
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
}

int main()
{
    
    int pivot;
    int size;
    
    cout << "n    Pivot Type                    Time\n\n";
    for(int i = 1; i<=3; i++)
    {
      size = pow(10,i);
      int mod = pow(10,3) - 1;
      int *a = new int[size];
      for(int j = 0; j < size; j++)
      {
        //a[j] = rand() % mod;
        a[j] = j;
      }
      
      for(int j = 0; j <=3; j++)
      {
        pivot = j;
        
        clock_t c1,c2;
        c1 = clock();
        srand(c1);
        
        GeneralQuicksort(a,size,pivot);
        
        c2 = clock();
        
        string str;
        if(pivot == 0)
          str = "FIRST";
        else if(pivot == 1)
          str = "RANDOM";
        else if(pivot == 2)
          str = "MEDIAN OF THREE (1)";
        else
          str = "MEDIAN OF THREE (2)";
        
        cout << size << "   " << str << "                   " << (float)(c2 - c1)/(CLOCKS_PER_SEC) << "ms\n";
      }
      cout << "\n\n";
    }

    return 0;
}
