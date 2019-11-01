#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	int count;
	string word;
	Node *prev = NULL;
	Node *next = NULL;
};


int i =0;

class Doubly_List
{
	
	Node *tail = new Node;
	Node *sentinel = new Node;

	
	public:
		
		void initialise();

		void pushFront(string key);

		string popFront();

		string popBack();

		int search(string key);

};

// **************************************
//          Member Functions
// **************************************

void Doubly_List::initialise()
{
	
   	if(sentinel == NULL)                    // If Creation of Node fails
        {
		cout << "Error in Creating Node\n";
		return;
	}
	
	
    	sentinel->next = sentinel;
    	sentinel->prev = sentinel;
	
	tail = sentinel;

    	sentinel->count = -1;
	sentinel->word = "";

}


void Doubly_List::pushFront(string key)
{
	Node *newNode = new Node;

    	if(newNode == NULL)                    // If Creation of Node fails
        {
		cout << "Error in Creating Node\n";
		return;
	}

	/*newNode->next = sentinel->next;
	newNode->prev = sentinel;
		
	sentinel->next = newNode;

	newNode->word = key;
	newNode->count = 1;

	if(sentinel->next == NULL)
	{
		tail = newNode;
	}*/

	tail->next = newNode;
	newNode->next = sentinel;
	newNode->prev = tail;
	
	tail = newNode;
	sentinel->prev = tail;
	
	newNode->word = key;
	newNode->count = 1;

	if(i == 0)
	{
		sentinel->next = newNode;
	}
	i++;
	
	/*Node *newNode = new Node;
	newNode->next = sentinel->next;
	sentinel->next->prev = newNode;
	sentinel->next = newNode;
	newNode->prev = sentinel;

	newNode->word = key;
	newNode->count = 1;

	Node *fin = new Node;
	fin = sentinel;
	
	while(1)
	{
		if(fin->next == sentinel) break;
		else fin = fin->next;
	}

	tail = fin;*/

	
	
}


string Doubly_List::popFront()  // CHECK IF CONDITION IN BOTH POP
{
	if(sentinel->next = NULL)                    // If Linked List is EMPTY
        {
		cout << "Empty Linked List\n";
		return "ERROR";
	}

	Node *del = sentinel->next;
	string ret = del->word;
	
	//cout << "Key = " << del->word << "	Count = " << del->count << "\n";

	if(del->count == 1)
	{
		/*Node *Sec = del->next;
		sentinel->next = Sec;
		Sec->prev = sentinel;*/
		
		del->prev->next = del->next;
		del->next->prev = del->prev;
		
		delete del;

		return ret;

	}
	else
	{
		del->count--;
		return "Count decremented";
	}

        
}


string Doubly_List::popBack()
{
	if(sentinel->next = NULL)                    // If Linked List is EMPTY
        {
		cout << "Empty Linked List\n";
		return "error";
	}

	Node *del = tail;
	string ret = del->word;
	
	cout << ret << "\n\n";

	if(del->count == 1)
	{
		Node *last2 = tail->prev;

		tail = last2;

		last2->next = sentinel;
		sentinel->prev = last2;
		
		

		delete del;
		
		return ret;
	}
	else
	{
		del->count--;
		return "Count decremented";
	}

}

int Doubly_List::search(string key)
{
	if(sentinel->next == NULL)
	{
		cout << "List is EMPTY";
		return -1;
	}

	Node *n = sentinel->next;
	
	while(n != sentinel)
	{

		int cmp = key.compare(n->word);
		
		if(cmp == 0)
			return 1;
		
		else if(cmp>0)
			return 2;
		else
			return 0;

		n = n->next;
	}
	
	return -1;

}


// *******************************************
//           Main Function
// *******************************************

int main()
{

	Doubly_List list;

	cout << "1 :Push at Front\n2 :Pop at Front\n3 :Pop from Back\n4 :Search a key\n0 :Terminate the Process\n\n";
	
	list.initialise();
	
	int a;
	cin >> a;

	while(a != 0)
	{
		if(a == 1)
		{
			string key;
			cin >> key;
				
			list.pushFront(key);
		
			cout << "\n";
		}
		else if(a == 2)
		{
			cout << "\n" << list.popFront() << "\n";
		}
		else if(a == 3)
		{
			cout << "\n" << list.popBack() << "\n";

		}
		else if(a == 4)
		{
			string key;
			cin >> key;
			
			cout << "\n" << list.search(key) << "\n";
		}
		
		cin >> a;
	}

	return 0;
}
			
			

	

	
		
