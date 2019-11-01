#include <iostream>
#define SIZE 50
using namespace std;

struct S1{
    int p;
    int *arr = new int[SIZE];
};


// ====================================
//         Stacks Class Specification
// ====================================

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


// ===================================
//           Helper Functions
// ===================================

Stacks::Stacks() {
    stack1.p = -1;           // Initialising index counter
}


void Stacks::push(int a)
{
    if(stack1.p < 99)
    {
        stack1.arr[stack1.p+1] = a;
        stack1.p++;
        return;               // Flag showing "Push" operation is successful
    }

    
}


int Stacks::pop()
{
    if(stack1.p >= 0)
    {
        int e = stack1.arr[stack1.p];
	stack1.p--;
	return e;

    }

    else return -1;            // Flag showing "Pop" operation is unsuccessful
}


int Stacks::top(){
    if(stack1.p>=0)
        return stack1.arr[stack1.p];  // Returns Topmost value

    return -1;                 // Flag showing "Top" operation is unsuccessful
}

bool Stacks::is_empty(){
    if(stack1.p + 1 == 0)
	return true;
    else
	return false;
}

bool Stacks::is_full(){
    if(stack1.p + 1 == 100)
	return true;
    else
	return false;
}
// ====================================
//          Main Function
// ====================================


/*int main()
{
    Stacks s1;

    s1.push(1);
    
   
    cout << s1.top() << endl;

    
    

    cout << s1.is_full() << endl;



    return 0;
}*/
