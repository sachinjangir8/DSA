#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Graph {
    map<int, vector<int>> adj; // adjacency list
    bool directed;             // flag for directed/undirected
public:
    Graph(bool isDirected = false) {
        directed = isDirected;
    }

    // Add edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!directed) {  // if undirected, add both ways
            adj[v].push_back(u);
        }
    }

    // Print adjacency list
    void printGraph() {
        for (auto &pair : adj) {
            cout << pair.first << " -> ";
            for (int v : pair.second) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, edges, type;
    cout << "Enter 0 for Undirected graph, 1 for Directed graph: ";
    cin >> type;

    Graph g(type == 1);

    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nAdjacency List of Graph:\n";
    g.printGraph();

    return 0;
}
