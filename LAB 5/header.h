
#include <iostream>
#include <string.h>

using namespace std;


void sparseRead(int **b1, int size)
{
  for(int i = 0; i<size; i++)
  {
    cout << "ENTER (ROW, COLUMN, VALUE): ";
    cin >> b1[i][0] >> b1[i][1] >> b1[i][2];
  }
}

void sparsePrint(int **b1, int size)
{
  for(int i =0; i < size; i++)
    cout << b1[i][0] << " " << b1[i][1] << " " << b1[i][2] << endl;
}

void transpose(int **b1, int **b2, int size,int col)
{
 
  int *rowSize = new int[col+1];
  int *rowStart = new int[col+1];
  
  for(int i =1; i <= col; i++)
    rowSize[i] = 0;
  
  for(int i =0; i < size; i++)
    rowSize[b1[i][1]]++;
  
  
  rowStart[1] = 0;
  for(int i =2; i <= col; i++)
    rowStart[i] = rowStart[i-1] + rowSize[i - 1];
  
  for(int i =0; i < size; i++)
  {
    int j = rowStart[b1[i][1]];
    b2[j][0] = b1[i][1];
    b2[j][1] = b1[i][0];
    b2[j][2] = b1[i][2];
    rowStart[b1[i][1]]++;
    
  }
 
  
}










