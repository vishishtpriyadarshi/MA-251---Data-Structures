#include <iostream>
using namespace std;

void arrayCpy(int *srcArray, int srcLen, int *dstArray, int dstLen)
{
	for(int i = 0; i < srcLen; i++)
	{
		dstArray[i] = srcArray[i];
	}	
		
}


int main()
{
	cout << "Enter size of Array 1: ";
	int size1 = 0;
	
	cin >> size1;
	int *A = new int[size1];

	cout << "Enter elements of Array:\n";

	for(int i = 0; i < size1; i++)
	{
		cin >> A[i];
	}

	cout << "\n\nEnter size of Array 2: ";
	int size2 = 0;
	
	cin >> size2;
	int *B = new int[size2];

	cout << "Enter elements of Array:\n";

	for(int i = 0; i < size2; i++)
	{
		cin >> B[i];
	}
	
	arrayCpy(A,size1,B,size2);

	cout << "New Array:\n";

	for(int i = 0; i < size2; i++)
	{
		cout << B[i] << " ";
	}
	

	return 0;

}
