#include <iostream>


using namespace std;


struct S1{
    int p;
    int *arr = new int[100];
};

class Stacks
{
    S1 stack1;

public:
    Stacks();               // Constructor

    void push(int a);        // Push element into the stack

    int pop();              // Pop element from the Stack

    int top();              // Returns element at the top of the stack

    bool is_empty();        // Returns if stack is Empty
  
    bool is_full();         // Returns if stack is Full
};




int main()
{
    Stacks s1;

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *T = new int[n];

    cout << "Enter temperatures:\n";

    for(int i = 0; i<n; i++)
    {
	cin >> T[i];
    }

    int *sp = new int[n];


   // TEMPERATURE SPAN PROBLEM implementation


   s1.push(0);

   sp[0] = 1;                                           // Span of First element is always 1
  
   for(int i=1; i<n; i++)
   {
	while(!(s1.is_empty()) && T[s1.top()] <= T[i])
	{
		int element = s1.pop();                 // Popping those values which are less than given i
	}
	
	if(s1.is_empty())
		sp[i] = i + 1;
        else
		sp[i] = i - s1.top();
        
	s1.push(i);
   }

  // Printing Span
  
  cout << "SPAN VALUES:\n";
  for(int i=0; i<n; i++)
  {
	cout << sp[i] << " ";
  }


  return 0;


}
