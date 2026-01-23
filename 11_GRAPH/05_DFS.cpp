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


    // Helper function for DFS
    void dfsHelper(int node, vector<bool> &visited, vector<int> &dfsans) {
        visited[node] = true;
        dfsans.push_back(node);

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited, dfsans);
            }
        }
    }

    // DFS (Recursive)
    vector<int> dfs(int start) {
        vector<int> dfsans;
        vector<bool> visited(V, false);
        dfsHelper(start, visited, dfsans);
        return dfsans;
    }

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

    int start;
    cout << "\nEnter starting vertex for BFS & DFS: ";
    cin >> start;

    vector<int> dfsAns = g.dfs(start);
    cout << "DFS Traversal: ";
    for (auto it : dfsAns) cout << it << " ";
    cout << endl;

    return 0;
}
