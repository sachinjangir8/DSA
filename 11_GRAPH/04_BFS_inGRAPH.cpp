#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;                  // number of vertices
    vector<list<int>> adj;  // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {  // if undirected graph, add reverse edge too
            adj[v].push_back(u);
        }
    }
    vector<int>bfs(int st){
        queue<int>q;
        q.push(st);
        vector<bool>visited(st,false);
        visited[st]=true;
        vector<int>bfsans;
        int node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            bfsans.push_back(node);
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        return bfsans;
    };

    void printGraph() {
        cout << "\nGraph connections (Adjacency List):\n";
        for (int i = 0; i < V; i++) {
            cout << i;
            for (int neighbor : adj[i]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false); // false = undirected
    }

     g.printGraph();
     int startNode;
    cout<<"Enter starting node for BFS: ";  
    cin>>startNode;
    vector<int> ans = g.bfs(startNode);
    cout<<"BFS Traversal is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    

    return 0;
}
