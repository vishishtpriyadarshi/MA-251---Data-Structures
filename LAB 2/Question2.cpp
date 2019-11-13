#include <iostream>
using namespace std;

int copies = 0;
int insertions = 0;
int itr = 0;

void arrayCpy(int *srcArray, int srcLen, int *dstArray, int dstLen)
{
	int local = 0;
	itr++;
	for(int i = 0; i < srcLen; i++)
	{
		dstArray[i] = srcArray[i];
		copies++;
		local++;
	}

	cout << "---------------------\n";	
	cout << "No of copies in #" << itr << " = " << local << endl;	
	cout << "\nNew Array:\n";
	for(int i = 0; i < srcLen; i++)
	{
		cout << dstArray[i] << " " ;
	}

	cout << "\n---------------------\n\n";
}




int main()
{
	cout << "Enter size of array:\n";
	int size = 0;
	cin >> size;

	cout << "Enter elements of Array:\n";

	int t_size = size;
	
        int *A = new int[1];
	int ct = 0;
	int capacity = 1;

	while(t_size--)
	{	
		int a = 0;
		cin >> a;
		
		
		if(ct < capacity)
		{
			A[ct] = a;
			ct++;
			insertions++;

		}
		else
		{
			capacity = 2*capacity;
			int *B = new int[capacity];
			
			arrayCpy(A,ct,B,capacity);
			
			B[ct] = a;
			ct++;
			insertions++;

			A = B;

		}
	}
	cout << "\n\nFINAL ARRAY:\n";
	for(int i = 0; i < ct; i++)
	{
		cout << A[i] << " ";

	}
	
	cout << "\nCopies = " << copies << endl;
	cout << "Insertions = " << insertions << endl;
	cout << "Average = " << (double)(copies+insertions)/size << endl;;

	return 0;

}
