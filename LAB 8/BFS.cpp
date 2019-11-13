// Created by Vishisht Priyadarshi on 23/10/2019

#include<bits/stdc++.h>
using namespace std; 

vector <int> route;

// Creating a Graph Class
class Graph 
{ 
    int V; 
    list<int> *adj; 
    void DFS_Visit(int v, bool visited[]); 
    
public: 
    Graph(int V);  
    void addEdge(int v, int w); 
    bool DFS(int v,int w); 
}; 



// Constructor
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 



// Adds Edges in the Adjacency List
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
} 



//A helper function for Main DFS function
void Graph::DFS_Visit(int v, bool visited[]) 
{ 

    visited[v] = true; 
    route.push_back(v+1);

    list<int>::iterator i; 
    
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i]) 
            DFS_Visit(*i, visited); 
    }
} 


// Main DFS Function
bool Graph::DFS(int v, int w) 
{ 
    bool *visited = new bool[V]; 
  
    for(int i = 0; i < V; i++) 
        visited[i] = false; 

    DFS_Visit(v, visited); 
    
    if(visited[w])
    	return true;
    
    return false;
} 


int main()
{
  cout << "This code is written by Vishisht Priyadarshi\n\n";
  
  // ****************** Creating Graph *****************************
  cout << "Enter Nodes:\n";
	int nodes;
	cin >> nodes;
	
	cout << "Enter Edges:\n";
	int edges;
	cin >> edges;
	
	Graph g(nodes);
	int a,b;
	
	cout << "\n\nStart adding Edges:\n\n";
	for(int i = 0; i < edges; i++)
	{
		cin >> a >> b;
		g.addEdge(a-1, b-1);
	}

	
	// ******************** QUERY SECTION ****************************
	
	int ct;
	cout << "\n\nEnter no. of test cases: \n\n";
	cin >> ct;
	
	while(ct--)
	{
		cout << "\nEnter the Starting Node and Ending Node: ";
		cin >> a >> b;
		route.clear();
		
		if(g.DFS(a-1,b-1))
		{
			cout << "\n\nReachable =>";
			for(int i = 0; i < route.size(); i++)
			{
				cout << route[i];
				if(route[i] == b)
				  break;
				else
				  cout << " -> ";
			}	
		}
		else
			cout << "Not Reachable\n\n";
				
	}

	cout << "This code is written by Vishisht Priyadarshi\n\n";
	return 0;
}
