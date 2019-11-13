// Created by Vishisht Priyadarshi on 23/10/2019

#include <bits/stdc++.h> 
using namespace std; 


// Creating Adjacency List
void add_edge(vector<int> adj[], int begin, int end) 
{ 
    adj[begin - 1].push_back(end - 1); 
    adj[end - 1].push_back(begin - 1); 
} 


// Running BFS to check if a path exists between Source and Destination
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int d[]) 
{ 
    list<int> queue; 
    bool visited[v]; 

    for (int i = 0; i < v; i++) 
    { 
        visited[i] = false; 
        d[i] = INT_MAX; 
        pred[i] = -1; 
    } 

    visited[src] = true; 
    d[src] = 0; 
    queue.push_back(src); 

    while (!queue.empty())
    { 
        int u = queue.front(); 
        queue.pop_front();
        
        for(int i = 0; i < adj[u].size(); i++)
        { 
            if(visited[adj[u][i]] == false)
            { 
                visited[adj[u][i]] = true; 
                d[adj[u][i]] = d[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 

                if (adj[u][i] == dest)          // There exits a path between Source and Destination
                   return true; 
            } 
        } 
    } 
  
    return false; 
} 


// Finds Shortest path between two Nodes
void short_Dist(vector<int> adj[], int s, int dest, int v) 
{ 
    int pred[v], d[v]; 
    if (BFS(adj, s, dest, v, pred, d) == false) 
    { 
        cout << "\n\nThere exists no path between source and destination\n\n";
        return; 
    } 

    vector<int> route; 
    
    int fin = dest; 
    route.push_back(fin); 
    
    while (pred[fin] != -1)
    { 
        route.push_back(pred[fin]); 
        fin = pred[fin]; 
    } 

    cout << "The Shortest Path Length =  " << d[dest] << "\n\nPath is:\n\n"; 
    
    for (int i = route.size() - 1; i >= 0; i--)
    {
        cout << route[i]+1;
        if(i > 0)
          cout << " -> "; 
    }
    
   
} 

int main() 
{ 
    cout << "This code is written by Vishisht Priyadarshi\n\n";
    int v = 30;  
    vector<int> adj[v];       // Adjacency List
    
    // Adding Edges to The Adjacency List
    
    add_edge(adj, 1, 2); 
    add_edge(adj, 2, 3); 
    add_edge(adj, 3, 4); 
    add_edge(adj, 4, 5); 
    add_edge(adj, 5, 6); 
    add_edge(adj, 6, 12); 
    add_edge(adj, 12, 11); 
    add_edge(adj, 11, 10); 
    add_edge(adj, 10, 9); 
    add_edge(adj, 9, 15); 
    add_edge(adj, 15, 16);  
    add_edge(adj, 16, 17);
    add_edge(adj, 17, 18); 
    add_edge(adj, 18, 24); 
    add_edge(adj, 24, 30);         
    add_edge(adj, 30, 29);         
    add_edge(adj, 29, 28);         
    add_edge(adj, 28, 27);         
    add_edge(adj, 27, 26);         
    add_edge(adj, 26, 20); 
    add_edge(adj, 20, 21);     
    add_edge(adj, 21, 22);     
    add_edge(adj, 22, 23);     
    add_edge(adj, 20, 19);     
    add_edge(adj, 19, 25);     
    add_edge(adj, 19, 13);     
    add_edge(adj, 13, 7);     
    add_edge(adj, 2, 8);     
    add_edge(adj, 8, 14);     
    add_edge(adj, 14, 15);     
    add_edge(adj, 1, 7);  
  
    int src = 0;
    int dest = 29;
    
    short_Dist(adj, src, dest, v); 
    cout << "\n\n";
    cout << "This code is written by Vishisht Priyadarshi\n\n";
    
    
    return 0; 
} 

