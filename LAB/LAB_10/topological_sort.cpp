#include<bits/stdc++.h>
using namespace std; 
class Graph 
{
public: 
    int V;
    vector<int> *adj;
    Graph(int l) 
    { 
        V = l; 
        adj = new vector<int>[V]; 
    } 
    void addEdge(int v, int w) 
    { 
        adj[v].push_back(w);
    } 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
    {  
        visited[v] = true; 
        int i;
        for (i = 0; i < adj[v].size(); ++i) {
            int k = adj[v][i];
            if (!visited[k]) 
                topologicalSortUtil(k, visited, Stack); 
        }
        Stack.push(v); 
    }
    void topologicalSort() 
    { 
        stack<int> Stack; 
        bool *visited = new bool[V]; 

        for (int i = 0; i < V; i++) 
            visited[i] = false;

        for (int i = 0; i < V; i++) 
          if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
        while (Stack.empty() == false) 
        { 
            cout << Stack.top() << " "; 
            Stack.pop(); 
        } 
    }
}; 
int main() 
{  
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 
  
    return 0; 
} 