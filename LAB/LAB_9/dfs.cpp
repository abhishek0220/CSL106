#include <bits/stdc++.h>
using namespace std;

class Graph 
{
public: 
    int V;
    list<int> *adj; 

    Graph(int da) 
    { 
        V = da; 
        adj = new list<int>[V]; 
    }
    void DFS_func(int v, bool visited[]) 
    {
        visited[v] = true; 
        cout << v << " ";  
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFS_func(*i, visited); 
    }
    void addEdge(int v, int w) 
    { 
        adj[v].push_back(w);
        adj[w].push_back(v);
    } 
    void DFS(int v) 
    {
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
        DFS_func(v, visited); 
    } 
};
// Driver code 
int main() 
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.DFS(2); 
  
    return 0; 
} 