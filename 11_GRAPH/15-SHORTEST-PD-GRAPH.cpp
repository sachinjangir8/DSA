#include <iostream>
#include<iomanip>
#include <vector>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<pair<int, int>>> adj; // adjacency list: (neighbor, weight)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // add directed edge with weight
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});  // directed: only u -> v
    }

    // print the graph
    void printGraph() {
        cout << "Directed Weighted Graph (Adjacency List):\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto edge : adj[i]) {
                cout << "(" << edge.first << ", w=" << edge.second << ") ";
            }
            cout << endl;
        }
    }

    // getter for adjacency list
    const vector<vector<pair<int,int>>>& getAdj() const {
        return adj;
    }
};

int main() {
    Graph g(5);  // graph with 5 vertices (0–4)

    // add directed weighted edges
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);

    g.printGraph();
    return 0;
}
