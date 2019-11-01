
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

int main()
{
  int size = 0;
  
  cout << "Enter the size of matrix(rows, columns): ";
  int row, col;
  
  cin >> row >> col;
  
  cout << "Enter total no of non-zero values: ";
  cin >> size;
  
  int** b1 = new int*[size];
  for(int i = 0; i < size; ++i)
    b1[i] = new int[3];
  
  int** b2 = new int*[size];
  for(int i = 0; i < size; ++i)
    b2[i] = new int[3];
  
  sparseRead(b1, size);
  sparsePrint(b1,size);
  cout << "\n";
  transpose(b1, b2, size,col);
  
  cout << "AFTER TRANSPOSE:\n\n";
  
  cout << size << " " << row << " " << col <<"\n\n\n";
  sparsePrint(b2,size);

  return 0;
  
}







