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

		void popFront();

		void popBack();

		int search(string key);

		void insertRand(string key);

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





void Doubly_List::popFront()  // CHECK IF CONDITION IN BOTH POP
{
	if(sentinel->next = NULL)                    // If Linked List is EMPTY
        {
		cout << "Empty Linked List\n";
		return;
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
		
		

		cout << ret << " - " << del->count << "\n";

		delete del;

	}
	else
	{
		del->count--;
	}

        
}


void Doubly_List::popBack()
{
	if(sentinel->next = NULL)                    // If Linked List is EMPTY
        {
		cout << "Empty Linked List\n";
		return;
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
		
		
		cout << ret << " - " << del->count << "\n";

		delete del;
		
		
	}
	else
	{
		del->count--;
		
	}

}

void Doubly_List::pushFront(string key)
{
	Node *a = new Node;
	a->word = key;
	a->count = 1;

	Node *curr = sentinel->next;

	if(curr == sentinel)
	{
		Node *newN = new Node;
		newN->word = key;
		newN->count = 1;

		newN->next = sentinel;
		newN->prev = sentinel;

		sentinel->next = newN;
		sentinel->prev = newN;

		tail = newN;
	}
	
	while(curr!=sentinel)
	{
		if(curr->word.compare(key)>0)
		{
			curr = curr->next;
			continue;
		}
		else if(curr->word.compare(key) == 0)
		{	
			curr->count++;
			break;
		}
		
		else
		{
			
			Node *newNode = new Node;

			if(newNode == NULL)                     // If Creation of Node fails
				return;
		
			Node *curr = sentinel->next;
			Node *curr2 = curr->next;

			while(1)
			{
				if(curr->word.compare(key) < 0 )
				{
					newNode->word = key;
					newNode->count = 1;
			
					sentinel->next = newNode;
					newNode->prev = sentinel;
			
					newNode->next = curr;
					curr->prev = newNode;

					return;
				}
				else if(curr2->word.compare(key) < 0)
				{
					newNode->word = key;
					newNode->count = 1;

					curr->next = newNode;
					newNode->prev = curr;

					newNode->next = curr2;
					curr2->prev = newNode;

					return;
				}

				curr = curr->next;
				curr2 = curr2->next;
			}
		}

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

int main()
{
	Doubly_List list1;

	cout << "1 :Push at Front\n2 :Pop at Front\n3 :Pop from Back\n4 :Search a key\n0 :Terminate the Process\n\n";
	
	list1.initialise();
	
	int a;
	cin >> a;

	while(a != 0)
	{
		if(a == 1)
		{
			string key;
			cin >> key;
				
			list1.pushFront(key);
		
			cout << "\n";
		}
		else if(a == 2)
		{
			list1.popFront();
		}
		else if(a == 3)
		{
			list1.popBack();

		}
		else if(a == 4)
		{
			string key;
			cin >> key;
			
			cout << list1.search(key) << "\n";
		}
		
		cin >> a;
	}

	return 0;
}
                                    

