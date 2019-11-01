
#include <iostream>
#include <string.h>
#include "Q1.cpp"
using namespace std;



void sparseRead(int **b1, int size);

void sparsePrint(int **b1, int size);


void transpose(int **b1, int **b2, int size,int col);


void multiply(int **b1, int **b2, int size)
{
  int** mult = new int*[6];
  for(int i = 0; i < 6; ++i)
    mult[i] = new int[3];
  int i,k;
  for(i=1; i<=size; i++)
  {
    for(k=1; k<=size; k++)
    {
      if(b1[i-1][1] == b2[k-1][1])
      {
        mult[b1[i-1][0]-1][b2[k-1][0]-1] = mult[b1[i-1][0]-1][b2[k-1][0]-1] + (b1[i-1][2]*b2[k-1][2]);
      }
    }
  }
  cout << "MATRIX AFTER MULTPLICATION:\n\n";
  for(int i = 0; i<4;i++)
  {
    for(int j = 0 ; j<4;j++)
    {
      if(mult[i][j] != 0)
        cout << i+1 << " " << j+1 << " " << mult[i][j] << endl;
    }
  }
}
int main()
{
  int size = 0;
  
  cout << "Enter the size of matrix(rows, columns): ";
  int row,col, s;
  
  cin >> row >> col;
  
  cout << "Enter total no of non-zero values: ";
  cin >> s;
  
  int** b1 = new int*[s];
  for(int i = 0; i < s; ++i)
    b1[i] = new int[3];
  
  int** b1T = new int*[s];
  for(int i = 0; i < s; ++i)
    b1T[i] = new int[3];
  
  sparseRead(b1, s);
  sparsePrint(b1,s);
  cout << "\n";
  transpose(b1, b1T, s,col);
  
  cout << "AFTER TRANSPOSE:\n\n";
  
  cout << size << " " << row << " " << col <<"\n\n\n";
  sparsePrint(b1T,s);
  
  cout << "MATRIX 2:\n\n";
 
  
  int** b2 = new int*[s];
  for(int i = 0; i < s; ++i)
    b2[i] = new int[3];
  
  int** b2T = new int*[s];
  for(int i = 0; i < s; ++i)
    b2T[i] = new int[3];
  
  for(int i = 0; i<size; i++)
  {
    cout << "ENTER (ROW, COLUMN, VALUE): ";
    cin >> b2[i][0] >> b2[i][1] >> b2[i][2];
  }
  
  sparseRead(b2, s);
  sparsePrint(b2,s);
  cout << "\n";
  transpose(b2, b2T, s,col);
  
  cout << "AFTER TRANSPOSE:\n\n";
  
  cout << size << " " << row << " " << col <<"\n\n\n";
  sparsePrint(b2T,s);
  
  // ==========================================
  // MULTIPLICATION
  // ==========================================
  
  multiply(b1,b2T,s);

  return 0;
  
}









